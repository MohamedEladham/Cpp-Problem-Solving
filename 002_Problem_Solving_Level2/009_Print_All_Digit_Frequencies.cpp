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

int GetDigitFrequency(int DigitToCheck, int Number)
{
	int Digit = 0;
	int Frequency = 0;

	while (Number > 0)
	{
		Digit = Number % 10;
		Number = Number / 10;

		if (DigitToCheck == Digit)
		{
			Frequency++;
		}
	}

	return Frequency;
}

void PrintDigitFrequencies(int Number)
{
	int Frequency = 0;

	for (int i = 0; i <= 9; i++)
	{
		Frequency = GetDigitFrequency(i, Number);

		if (Frequency > 0)
		{
			cout << "\n> Digit '" << i
				<< "' Frequency Is '" << Frequency
				<< "' Time(s).\n";
		}
	}
}

int main()
{
	int Number = ReadPositiveNumber("\n> Please Enter Number: ");

	PrintDigitFrequencies(Number);

	return 0;
}