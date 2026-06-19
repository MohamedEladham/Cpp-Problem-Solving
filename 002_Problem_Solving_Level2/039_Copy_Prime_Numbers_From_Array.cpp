#include <iostream>
#include <cstdlib>

using namespace std;

enum enPrimeStatus { Prime = 1, NotPrime = 2 };

enPrimeStatus IsPrime(int Number)
{
	if (Number <= 1)
		return NotPrime;

	int M = Number / 2;

	for (int i = 2; i <= M; i++)
	{
		if (Number % i == 0)
			return NotPrime;
	}

	return Prime;
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

void FillArrayWithRandomNumber(int Array[], int Size)
{
	for (int i = 0; i < Size; i++)
	{
		Array[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int Array[], int Size)
{
	for (int i = 0; i < Size; i++)
	{
		cout << Array[i] << " ";
	}
}

void AddArrayElement(int Number, int Array[], int& Size)
{
	Array[Size] = Number;
	Size++;
}

void CopyPrimeNumbersToArray(int SourceArray[],
	int PrimeArray[],
	int SourceSize,
	int& PrimeSize)
{
	for (int i = 0; i < SourceSize; i++)
	{
		if (IsPrime(SourceArray[i]) == Prime)
		{
			AddArrayElement(SourceArray[i], PrimeArray, PrimeSize);
		}
	}
}

int main()
{
	srand((unsigned)time(0));

	int SourceArray[100], SourceSize;
	SourceSize = ReadPositiveNumber("\n> Enter Array Size: ");

	FillArrayWithRandomNumber(SourceArray, SourceSize);

	cout << "\n> Source Array:\n";
	PrintArray(SourceArray, SourceSize);

	int PrimeArray[100], PrimeSize = 0;

	CopyPrimeNumbersToArray(SourceArray, PrimeArray, SourceSize, PrimeSize);

	cout << "\n\n> Prime Numbers:\n";
	PrintArray(PrimeArray, PrimeSize);

	return 0;
}