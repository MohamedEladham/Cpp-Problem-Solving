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
	return rand() % (To - From + 1) + To;
}

void FillArrayWithRandomNumbers(int Array[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		Array[i] = RandomNumber(1, 100);
	}
}

void SumArraysElementWise(int Array1[], int Array2[], int SumArray[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		SumArray[i] = Array1[i] + Array2[i];
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

	int Array1[100], Array2[100], SumArray[100];
	int ArraySize = ReadPositiveNumber("\n> Enter Number Of Elements: ");

	FillArrayWithRandomNumbers(Array1, ArraySize);
	FillArrayWithRandomNumbers(Array2, ArraySize);

	SumArraysElementWise(Array1, Array2, SumArray, ArraySize);

	cout << "\n> Array 1 Elements:\n";
	PrintArray(Array1, ArraySize);

	cout << "\n> Array 2 Elements:\n";
	PrintArray(Array2, ArraySize);

	cout << "\n> Sum Array Elements:\n";
	PrintArray(SumArray, ArraySize);

	return 0;
}