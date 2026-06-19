#include <iostream>
#include <cstdlib>

using namespace std;

enum enParity { Odd = 1, Even = 2 };

enParity GetParity(int Number)
{
	if (Number % 2 == 0)
		return Even;

	return Odd;
}

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

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int Array[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		Array[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int Array[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		cout << Array[i] << " ";
	}
}

int CountOddNumbers(int Array[], int ArraySize)
{
	int Count = 0;

	for (int i = 0; i < ArraySize; i++)
	{
		if (GetParity(Array[i]) == Odd)
			Count++;
	}

	return Count;
}

int main()
{
	srand((unsigned)time(0));

	int Array[100], ArraySize;

	ArraySize = ReadPositiveNumber("\n> Enter Array Size: ");

	FillArrayWithRandomNumbers(Array, ArraySize);

	cout << "\n> Array Elements:\n";
	PrintArray(Array, ArraySize);

	cout << "\n\n> Odd Numbers Count: ";
	cout << CountOddNumbers(Array, ArraySize);

	return 0;
}