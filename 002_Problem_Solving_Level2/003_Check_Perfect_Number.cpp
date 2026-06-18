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

bool IsPerfectNumber(int Number)
{
	int HalfNumber = Number / 2;
	int DivisorsSum = 0;

	for (int i = 1; i <= HalfNumber; i++)
	{
		if (Number % i == 0)
		{
			DivisorsSum += i;
		}
	}

	return Number == DivisorsSum;
}

void PrintPerfectNumberResult(int Number)
{
	if (IsPerfectNumber(Number))
		cout << "\n> " << Number << " Is Perfect Number.\n";
	else
		cout << "\n> " << Number << " Is Not Perfect Number.\n";
}

int main()
{
	int Number = ReadPositiveNumber("\n> Please Enter Positive Number: ");

	PrintPerfectNumberResult(Number);

	return 0;
}