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

void PrintInvertedLetterPattern(int PatternSize)
{
	for (int i = PatternSize; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << char(i + 64);
		}

		cout << "\n";
	}
}

int main()
{
	int PatternSize = ReadPositiveNumber("\n> Please Enter Number: ");

	PrintInvertedLetterPattern(PatternSize);

	return 0;
}