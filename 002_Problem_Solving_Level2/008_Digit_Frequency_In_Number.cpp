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

int CountDigitFrequency(int DigitToCheck, int Number)
{
	int Digit = 0;
	int Counter = 0;

	while (Number > 0)
	{
		Digit = Number % 10;
		Number /= 10;

		if (DigitToCheck == Digit)
		{
			Counter++;
		}
	}

	return Counter;
}

int main()
{
	int Number = ReadPositiveNumber("\n> Please Enter Positive Number: ");
	int DigitToCheck = ReadPositiveNumber("\n> Please Enter Digit To Check: ");

	int Frequency = CountDigitFrequency(DigitToCheck, Number);

	cout << "\n Digit " << DigitToCheck << " Frequency Is "
		<< Frequency << " Time(s).\n";

	return 0;
}