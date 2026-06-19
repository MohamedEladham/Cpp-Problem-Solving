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

bool IsPalindromeNumber(int Number)
{
	return (ReverseNumber(Number) == Number);
}

void PrintPalindromeNumberResult(int Number)
{
	if (IsPalindromeNumber(Number))
		cout << "\n> " << Number << " Yes, It Is A Palindrome Number.\n";
	else
		cout << "\n> " << Number << " No, It Is Not A Palindrome Number.\n";
}

int main()
{
	int Number = ReadPositiveNumber("\n> Please Enter Number: ");

	PrintPalindromeNumberResult(Number);

	cout << "\n\n\n";

	return 0;
}