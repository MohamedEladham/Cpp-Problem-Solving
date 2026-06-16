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

int SumOddNumbersFrom1ToN_UsingForLoop(int Number)
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

int SumOddNumbersFrom1ToN_UsingWhileLoop(int Number)
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

int SumOddNumbersFrom1ToN_UsingDoWhileLoop(int Number)
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
	int N = ReadNumber();

	cout << SumOddNumbersFrom1ToN_UsingForLoop(N) << endl;
	cout << SumOddNumbersFrom1ToN_UsingWhileLoop(N) << endl;
	cout << SumOddNumbersFrom1ToN_UsingDoWhileLoop(N) << endl;

	return 0;
}