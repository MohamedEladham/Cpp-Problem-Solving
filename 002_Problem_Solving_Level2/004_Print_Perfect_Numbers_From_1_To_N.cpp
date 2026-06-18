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

void PrintPerfectNumbers(int Number)
{
	cout << "\n> Print Perfect Numbers From 1 To " << Number << endl;

	for (int i = 1; i <= Number; i++)
	{
		if (IsPerfectNumber(i))
		{
			cout << i << endl;
		}
	}
}

int main()
{
	int Number = ReadPositiveNumber("\n> Please Enter Positive Number: ");

	PrintPerfectNumbers(Number);

	return 0;
}