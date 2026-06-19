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
		Array[i] = RandomNumber(1, 10);
	}
}

int GetMinElement(int Array[], int ArraySize)
{
	int MinValue = Array[0];

	for (int i = 1; i < ArraySize; i++)
	{
		if (Array[i] < MinValue)
		{
			MinValue = Array[i];
		}
	}

	return MinValue;
}

void PrintArray(int Array[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		cout << Array[i] << " ";
	}

	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100], ArraySize;

	ArraySize = ReadPositiveNumber("\n> Enter Number Of Elements: ");

	FillArrayWithRandomNumbers(Array, ArraySize);

	cout << "\n> Array Elements: ";
	PrintArray(Array, ArraySize);

	cout << "\n> Min Number Of Array: "
		<< GetMinElement(Array, ArraySize)
		<< endl;

	return 0;
}