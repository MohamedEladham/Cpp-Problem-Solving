#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

enPrimeNotPrime IsPrime(int Number)
{
	if (Number <= 1)
		return enPrimeNotPrime::NotPrime;

	int M = floor(Number / 2);

	for (int i = 2; i <= M; i++)
	{
		if (Number % i == 0)
			return enPrimeNotPrime::NotPrime;
	}

	return enPrimeNotPrime::Prime;
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

void FillArrayWithRandomNumber(int Array[], int ArraySize)
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

void CopyPrimeNumbers(int SourceArray[], int SourceSize,
	int PrimeArray[], int& PrimeSize)
{
	int Counter = 0;

	for (int i = 0; i < SourceSize; i++)
	{
		if (IsPrime(SourceArray[i]) == Prime)
		{
			PrimeArray[Counter] = SourceArray[i];
			Counter++;
		}
	}

	PrimeSize = Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int SourceArray[100], PrimeArray[100];
	int ArraySize, PrimeSize;

	ArraySize = ReadPositiveNumber("\n> Enter Number Of Elements: ");

	FillArrayWithRandomNumber(SourceArray, ArraySize);

	CopyPrimeNumbers(SourceArray, ArraySize, PrimeArray, PrimeSize);

	cout << "\n> Source Array Elements:\n";
	PrintArray(SourceArray, ArraySize);

	cout << "\n\n> Prime Numbers:\n";
	PrintArray(PrimeArray, PrimeSize);

	return 0;
}