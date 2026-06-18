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

void PrintDigitsInReverse(int Number)
{
	int Digit = 0;

	while (Number > 0)
	{
		Digit = Number % 10;
		Number = Number / 10;

		cout << Digit << endl;
	}
}

int main()
{
	PrintDigitsInReverse(ReadPositiveNumber("\n> Please Enter Positive Number: "));
	return 0;
}