#include <iostream>
#include <cstdlib>

using namespace std;

enum enOddOrEvenNumbers
{
	Odd = 1,
	Even = 2
};

enOddOrEvenNumbers GetNumberType(int Number)
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

void FillArrayWithRandomNumber(int SourceArray[], int SourceArraySize)
{
	for (int i = 0; i < SourceArraySize; i++)
	{
		SourceArray[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int Array[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		cout << Array[i] << " ";
	}
}

void AddArrayElement(int Number, int Array[], int& ArraySize)
{
	Array[ArraySize] = Number;
	ArraySize++;
}

void CopyOddNumbersToArray(int SourceArray[],
	int OddNumbersArray[],
	int SourceArraySize,
	int& OddArraySize)
{
	for (int i = 0; i < SourceArraySize; i++)
	{
		if (GetNumberType(SourceArray[i]) == Odd)
		{
			AddArrayElement(SourceArray[i], OddNumbersArray, OddArraySize);
		}
	}
}

int main()
{
	srand((unsigned)time(0));

	int SourceArray[100];
	int SourceArraySize =
		ReadPositiveNumber("\n> Please Enter Array Size: ");

	FillArrayWithRandomNumber(SourceArray, SourceArraySize);

	cout << "\n> Array Elements:\n";
	PrintArray(SourceArray, SourceArraySize);

	int OddNumbersArray[100];
	int OddArraySize = 0;

	CopyOddNumbersToArray(
		SourceArray,
		OddNumbersArray,
		SourceArraySize,
		OddArraySize);

	cout << "\n\n> Odd Numbers:\n";
	PrintArray(OddNumbersArray, OddArraySize);

	return 0;
}