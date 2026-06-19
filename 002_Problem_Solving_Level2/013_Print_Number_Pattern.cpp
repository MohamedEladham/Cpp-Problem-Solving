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

void PrintNumberPattern(int PatternSize)
{
	for (int i = 1; i <= PatternSize; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}

		cout << "\n";
	}
}

int main()
{
	int PatternSize = ReadPositiveNumber("\n> Please Enter Number: ");

	PrintNumberPattern(PatternSize);

	return 0;
}