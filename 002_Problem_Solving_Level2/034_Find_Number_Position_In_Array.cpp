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

int FindNumberIndex(int Array[], int ArraySize, int Number)
{
	for (int i = 0; i < ArraySize; i++)
	{
		if (Array[i] == Number)
			return i;
	}

	return -1;
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100];
	int ArraySize = ReadPositiveNumber("\n> Enter Number Of Elements: ");

	FillArrayWithRandomNumber(Array, ArraySize);

	cout << "\n> Array Elements:\n";
	PrintArray(Array, ArraySize);

	int Number;
	cout << "\n\n> Enter Number To Search For: ";
	cin >> Number;

	int Index = FindNumberIndex(Array, ArraySize, Number);

	if (Index == -1)
	{
		cout << "\n> Number Not Found\n";
	}
	else
	{
		cout << "\n> Number Found At Index: " << Index;
		cout << "\n> Number Found At Position: " << Index + 1;
	}

	return 0;
}