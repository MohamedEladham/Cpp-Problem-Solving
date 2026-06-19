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

	} while (Number < 0);

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
		Array[i] = RandomNumber(100, 1000);
	}
}

int GetMaxElement(int Array[], int ArraySize)
{
	int MaxValue = Array[0];

	for (int i = 1; i < ArraySize; i++)
	{
		if (Array[i] > MaxValue)
			MaxValue = Array[i];
	}

	return MaxValue;
}

int GetSecondMaxElement(int Array[], int ArraySize)
{
	int Max1 = GetMaxElement(Array, ArraySize);
	int SecondMax = Array[0];

	bool Initialized = false;

	for (int i = 0; i < ArraySize; i++)
	{
		if (Array[i] != Max1)
		{
			if (!Initialized || Array[i] > SecondMax)
			{
				SecondMax = Array[i];
				Initialized = true;
			}
		}
	}

	return SecondMax;
}

int GetThirdMaxElement(int Array[], int ArraySize)
{
	int Max1 = GetMaxElement(Array, ArraySize);
	int Max2 = GetSecondMaxElement(Array, ArraySize);
	int ThirdMax = Array[0];

	bool Initialized = false;

	for (int i = 0; i < ArraySize; i++)
	{
		if (Array[i] != Max1 && Array[i] != Max2)
		{
			if (!Initialized || Array[i] > ThirdMax)
			{
				ThirdMax = Array[i];
				Initialized = true;
			}
		}
	}

	return ThirdMax;
}

void PrintArray(int Array[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
		cout << Array[i] << " ";
}

int main()
{
	srand((unsigned)time(0));

	int Array[100], ArraySize;

	ArraySize = ReadPositiveNumber("\n> How Many Elements: ");

	FillArrayWithRandomNumbers(Array, ArraySize);

	cout << "\n> Array Elements: ";
	PrintArray(Array, ArraySize);

	cout << "\n\n> Max 1 Element Is: " << GetMaxElement(Array, ArraySize);
	cout << "\n> Max 2 Element Is: " << GetSecondMaxElement(Array, ArraySize);
	cout << "\n> Max 3 Element Is: " << GetThirdMaxElement(Array, ArraySize);

	return 0;
}