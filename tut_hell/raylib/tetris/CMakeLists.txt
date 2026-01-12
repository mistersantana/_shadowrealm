cmake_minimum_required(VERSION 3.15)
project(tetris_raylib
  VERSION 0.1
  LANGUAGES CXX
)

# Build options
option(BUILD_STATIC "Build static executable for distribution" ON)
option(BUILD_UNIVERSAL "Build universal macOS binary" ON)

# Find raylib (system or fetch if not found)
find_package(raylib 3.0 QUIET)
if(NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz
  )
  FetchContent_MakeAvailable(raylib)
  set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
endif()

# Main executable
add_executable(Tetris
  src/main.cpp
  src/assets.cpp
  src/block.cpp
  src/colors.cpp
  src/game.cpp
  src/grid.cpp
  src/position.cpp
)

# Static linking configuration
if(BUILD_STATIC)
  if(WIN32)
    # Static linking for MSVC
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    set(CMAKE_EXE_LINKER_FLAGS "/MT")
  elseif(APPLE)
    # Static linking for macOS (limited support)
    # Note: Full static linking not possible on macOS due to system frameworks
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++")
  elseif(UNIX)
    # Static linking for Linux
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
  endif()
endif()

# Platform-specific linking
target_link_libraries(Tetris PRIVATE raylib)

if(APPLE)
  target_link_libraries(Tetris PRIVATE "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
elseif(UNIX AND NOT APPLE)
  find_package(X11 REQUIRED)
  find_package(ALSA REQUIRED)
  target_link_libraries(Tetris PRIVATE X11::X11 ALSA::ALSA)
endif()

# Asset bundling
file(GLOB FONT_ASSETS "Font/*")
file(GLOB SOUND_ASSETS "Sounds/*")
file(COPY ${FONT_ASSETS} ${SOUND_ASSETS} DESTINATION ${CMAKE_BINARY_DIR})

# Set working directory for assets
if(WIN32)
  set_target_properties(Tetris PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

# CPack configuration for packaging
include(GNUInstallDirs)

if(WIN32)
  # Windows packaging
  install(TARGETS Tetris DESTINATION .)
  install(DIRECTORY ${CMAKE_BINARY_DIR}/Font DESTINATION .)
  install(DIRECTORY ${CMAKE_BINARY_DIR}/Sounds DESTINATION .)
  
  set(CPACK_GENERATOR "ZIP")
  set(CPACK_PACKAGE_NAME "Tetris")
  set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
  set(CPACK_PACKAGE_INSTALL_DIRECTORY "Tetris")
  
elseif(APPLE)
  # macOS app bundle
  if(BUILD_UNIVERSAL)
    # Universal binary configuration
    set_target_properties(Tetris PROPERTIES
      MACOSX_BUNDLE TRUE
      MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/Info.plist
      MACOSX_BUNDLE_BUNDLE_NAME "Tetris"
      MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}"
      MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}"
    )
    
    # Copy assets into bundle
    add_custom_command(TARGET Tetris POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_BUNDLE_DIR:Tetris>/Contents/Resources
      COMMAND ${CMAKE_COMMAND} -E copy_directory
      ${CMAKE_SOURCE_DIR}/Font $<TARGET_BUNDLE_DIR:Tetris>/Contents/Resources/Font
      COMMAND ${CMAKE_COMMAND} -E copy_directory
      ${CMAKE_SOURCE_DIR}/Sounds $<TARGET_BUNDLE_DIR:Tetris>/Contents/Resources/Sounds
    )
  endif()
  
  set(CPACK_GENERATOR "Bundle")
  set(CPACK_BUNDLE_NAME "Tetris")
  set(CPACK_BUNDLE_VERSION "${PROJECT_VERSION}")
  
else()
  # Linux packaging
  install(TARGETS Tetris DESTINATION ${CMAKE_INSTALL_BINDIR})
  install(DIRECTORY ${CMAKE_BINARY_DIR}/Font DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/tetris)
  install(DIRECTORY ${CMAKE_BINARY_DIR}/Sounds DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/tetris)
  
  set(CPACK_GENERATOR "TGZ")
  set(CPACK_PACKAGE_NAME "tetris")
  set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
endif()

include(CPack)
