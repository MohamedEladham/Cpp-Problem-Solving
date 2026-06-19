#include <iostream>
#include <cstdlib>
#include <ctime>

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

void CopyArrayReversed(int SourceArray[], int ArraySize, int ReversedArray[])
{
	for (int i = 0; i < ArraySize; i++)
	{
		ReversedArray[i] = SourceArray[ArraySize - 1 - i];
	}
}

void PrintArray(int Array[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		cout << Array[i] << " ";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int ArraySize = ReadPositiveNumber("\n> Enter Number Of Elements: ");

	int SourceArray[100], ReversedArray[100];

	FillArrayWithRandomNumbers(SourceArray, ArraySize);
	CopyArrayReversed(SourceArray, ArraySize, ReversedArray);

	cout << "\n> Source Array Elements:\n";
	PrintArray(SourceArray, ArraySize);

	cout << "\n> Reversed Array Elements:\n";
	PrintArray(ReversedArray, ArraySize);

	return 0;
}