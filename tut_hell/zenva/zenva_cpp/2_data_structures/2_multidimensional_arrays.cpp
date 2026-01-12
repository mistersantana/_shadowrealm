#include <iostream>

int main() {

  // declare a 2D array with 3 rows and 3 columns
  char gameBoard[3][3];

  // here's an example of what that array would look like:
  /* [[c, c, c],
      [c, c, c],
      [c, c, c]] */

  // create a diagonal of x's from top-right to bottom-left to win the game

  // assign the value at the top row, second column
  gameBoard[0][2] = 'x';
  // assign the value at the middle row. middle column
  gameBoard[1][1] = 'x';
  // assign the value at the last row, first column
  gameBoard[2][0] = 'x';

  //here's what that would look like now:
  /* [[c, c, c],
      [c, c, c],
      [c, c, c]] */  

  // print out an assigned value
  std::cout << gameBoard[2][0] << std::endl;

  // turn the 2D array into a 1D array (flatten)

  // create a 1D array that can hold the total number of elements as the 2D array
  char flatGameBoard[9];

  /* use a nested for-loop to iterate through the rows and columns of the 2D array, and copy each element to the 1D array at the correct index */

  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      int index = (r * 3 ) + c; // calculate the index
      flatGameBoard[index] = gameBoard[r][c];
    }
  }

  /* if the 2D array was flattened correctly, the assigned x's should be at indices 2, 4, and 6 in the 1D array */
  
  std::cout << flatGameBoard[2] << std::endl;
  std::cout << flatGameBoard[4] << std::endl;
  std::cout << flatGameBoard[6] << std::endl;
}
