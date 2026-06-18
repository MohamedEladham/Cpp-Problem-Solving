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

int SumOfDigits(int Number)
{
	int Digit = 0;
	int Sum = 0;

	while (Number > 0)
	{
		Digit = Number % 10;
		Number = Number / 10;
		Sum += Digit;
	}

	return Sum;
}

void PrintSumOfDigits(int Sum)
{
	cout << "\n> Sum Of Digits = " << Sum << endl;
}

int main()
{
	int Number = ReadPositiveNumber("\n> Please Enter Positive Number: ");

	int Sum = SumOfDigits(Number);

	PrintSumOfDigits(Sum);

	return 0;
}