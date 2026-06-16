#include <iostream>
#include <string>
using namespace std;

void readThreeNumbers(int& number1, int& number2, int& number3)
{
	cout << "\n> Enter Number 1: ";
	cin >> number1;

	cout << "\n> Enter Number 2: ";
	cin >> number2;

	cout << "\n> Enter Number 3: ";
	cin >> number3;
}

int getMaxOfThreeNumbers(int number1, int number2, int number3)
{
	if (number1 > number2)
		if (number1 > number3)
			return number1;
		else
			return number3;
	else
		if (number2 > number3)
			return number2;
		else
			return number3;
}

void printResult(int maxNumber)
{
	cout << "\n> The Max Number Is " << maxNumber << endl;
}

int main()
{
	int number1, number2, number3;

	readThreeNumbers(number1, number2, number3);

	printResult(getMaxOfThreeNumbers(number1, number2, number3));

	return 0;
}