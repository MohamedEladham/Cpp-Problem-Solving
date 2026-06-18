#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

int ReverseNumber(int Number)
{
	int Digit = 0;
	int ReversedNumber = 0;

	while (Number > 0)
	{
		Digit = Number % 10;
		Number = Number / 10;

		ReversedNumber = ReversedNumber * 10 + Digit;
	}

	return ReversedNumber;
}

void PrintOriginalOrder(int ReversedNumber)
{
	cout << "\n> Print Number Reversed From Left To Right: ";

	while (ReversedNumber > 0)
	{
		int Digit = ReversedNumber % 10;
		ReversedNumber = ReversedNumber / 10;

		cout << Digit;
	}
}

int main()
{
	int Number = ReadPositiveNumber("\n> Please Enter Number: ");

	int Reversed = ReverseNumber(Number);

	cout << "\n> Reverse Number: " << Reversed;

	PrintOriginalOrder(Reversed);

	return 0;
}