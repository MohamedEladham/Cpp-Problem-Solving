#include <iostream>
#include <string>
using namespace std;

enum enOddOrEven { Even = 1, Odd = 2 };

int ReadNumber()
{
	int Number;
	cout << "\n> Please Enter A Number: ";
	cin >> Number;

	return Number;
}

enOddOrEven CheckNumberOddOrEven(int Number)
{
	if (Number % 2 == 0)
		return enOddOrEven::Even;
	else
		return enOddOrEven::Odd;
}

int SumOddNumbersFrom1ToN_Using_ForLoop(int Number)
{
	int Sum = 0;

	cout << "\n> Sum Odd Numbers Using For Loop = ";

	for (int i = 1; i <= Number; i++)
	{
		if (CheckNumberOddOrEven(i) == enOddOrEven::Odd)
		{
			Sum += i;
		}
	}

	return Sum;
}

int SumOddNumbersFrom1ToN_Using_WhileLoop(int Number)
{
	int i = 0;
	int Sum = 0;

	cout << "\n> Sum Odd Numbers Using While Loop = ";

	while (i < Number)
	{
		i++;
		if (CheckNumberOddOrEven(i) == enOddOrEven::Odd)
		{
			Sum += i;
		}
	}

	return Sum;
}

int SumOddNumbersFrom1ToN_Using_DoWhileLoop(int Number)
{
	int i = 0;
	int Sum = 0;

	cout << "\n> Sum Odd Numbers Using Do While Loop = ";

	do
	{
		i++;
		if (CheckNumberOddOrEven(i) == enOddOrEven::Odd)
		{
			Sum += i;
		}

	} while (i < Number);

	return Sum;
}

int main()
{
	int Number = ReadNumber();

	cout << SumOddNumbersFrom1ToN_Using_ForLoop(Number) << endl;
	cout << SumOddNumbersFrom1ToN_Using_WhileLoop(Number) << endl;
	cout << SumOddNumbersFrom1ToN_Using_DoWhileLoop(Number) << endl;

	return 0;
}