#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Swap(int& A, int& B)
{
	int Temp = A;
	A = B;
	B = Temp;
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

void FillSequentialArray(int Array[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		Array[i] = i + 1;
	}
}

void ShuffleArray(int Array[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		int Index1 = RandomNumber(0, ArraySize - 1);
		int Index2 = RandomNumber(0, ArraySize - 1);

		Swap(Array[Index1], Array[Index2]);
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

	int Array[100];
	int ArraySize = ReadPositiveNumber("\n> Enter Number Of Elements: ");

	FillSequentialArray(Array, ArraySize);

	cout << "\n> Array Before Shuffle: ";
	PrintArray(Array, ArraySize);

	ShuffleArray(Array, ArraySize);

	cout << "\n> Array After Shuffle: ";
	PrintArray(Array, ArraySize);

	return 0;
}