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
		Number /= 10;

		ReversedNumber = ReversedNumber * 10 + Digit;
	}

	return ReversedNumber;
}

int main()
{
	int Number = ReadPositiveNumber("\n> Please Enter Positive Number: ");

	int Reversed = ReverseNumber(Number);

	cout << Reversed;

	return 0;
}