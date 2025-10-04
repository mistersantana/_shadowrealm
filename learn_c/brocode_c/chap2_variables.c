#include <stdio.h>
#include <stdbool.h>

int main() {
	
	// variable = A reusable container for a value.
	// Behaves as if it were the value it contains.
	
	// int = whole number (4 bytes in modern systems)
	// float = single-precision decimal number (4 bytes)
	// double = double-precision decimal number (8 bytes)
	// char = single character (1 byte)
	// char[] = array of characters (size varies)
	// bool = true or false (1 byte, requires <stdbool.h>)


	int age = 25;
	int year = 2025;
	int quantity = 2;

	float gpa = 2.5;
	float price = 19.99;
	float temperature = -10.1;

	double pi = 3.14159265358979;
	double e = 2.7182818284590;

	char grade = 'F';
	char symbol = '!';
	char currency = '$';

	char name[] = "Mr. Santana";
	char food[] = "lasagna";
	char email[] = "thisemail@email.com";

	bool isOnline = true;


	printf("You are %d years old\n", age);
	printf("The year is %d\n", year);
	printf("You have ordered %d x items\n", quantity);

	printf("Your GPA is %f\n", gpa);
	printf("The price is $%f\n", price);
	printf("The temperature is %fF\n", temperature);

	printf("The value of pi is %.15lf\n", pi);
	printf("The value of e is %.15lf\n", e);

	printf("Your grade is %c\n", grade);
	printf("Your favorite symbol is %c\n", symbol);
	printf("The currency is %c\n", currency);

	printf("Hello %s\n", name);
	printf("Your favorite food is %s\n", food);
	printf("Your email is %s\n", email);

	printf("%d\n", isOnline);


	return 0;
}
