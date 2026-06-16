#include <iostream>
#include <string>
using namespace std;

void readTwoNumbers(int& number1, int& number2)
{
	cout << "\n> Enter Number A: ";
	cin >> number1;

	cout << "\n> Enter Number B: ";
	cin >> number2;
}

void printBeforeSwapping(int number1, int number2)
{
	cout << "\n> Number A Before Swapping: " << number1 << endl;

	cout << "\n> Number B Before Swapping: " << number2 << endl;
}

void swapTwoNumbers(int& number1, int& number2)
{
	int temp = number1;
	number1 = number2;
	number2 = temp;
}

void printAfterSwapping(int number1, int number2)
{
	cout << "\n> Number A After Swapping: " << number1 << endl;
	cout << "\n> Number B After Swapping: " << number2 << endl;
}

int main()
{
	int number1, number2;

	readTwoNumbers(number1, number2);

	printBeforeSwapping(number1, number2);

	swapTwoNumbers(number1, number2);

	printAfterSwapping(number1, number2);

	return 0;
}