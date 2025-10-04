#include <stdio.h>

int main () {

	// Format specifier = Special tokens that begin with % symbol,
	//	followed by a character that specifies the data type and
	//	optional modifiers (width, precision, flags). They control
	//	how data is displayed or interpreted.

	int age = 30;
	float price = 19.99;
	double pi = 3.1415926535;
	char currency = '$';
	char name[] = "Mr. Santana";

	// width
	int num1 = 1;
	int num2 = 10;
	int num3 = 100;

	// precision
	float price1 = 19.99;
	float price2 = 1.05;
	float price3 = -100.00;

	printf("%d\n", age);
	printf("%f\n", price);
	printf("%lf\n", pi);
	printf("%c\n", currency);
	printf("%s\n", name);

	printf("%d\n", num1);
	printf("%d\n", num2);
	printf("%d\n", num3);

	printf("%.2f\n", price1);
	printf("%.2f\n", price2);
	printf("%.2f\n", price3);

	return 0;

}
