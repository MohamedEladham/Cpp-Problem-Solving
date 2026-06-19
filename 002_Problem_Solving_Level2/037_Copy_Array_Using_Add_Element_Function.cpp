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

void AppendElement(int Number, int Array[], int& ArraySize)
{
	Array[ArraySize] = Number;
	ArraySize++;
}

void CopyArrayByAppend(int SourceArray[], int DestinationArray[],
	int SourceSize, int& DestSize)
{
	for (int i = 0; i < SourceSize; i++)
	{
		AppendElement(SourceArray[i], DestinationArray, DestSize);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int SourceArray[100], DestinationArray[100];
	int SourceSize = ReadPositiveNumber("\n> Enter Array Size: ");

	FillArrayWithRandomNumber(SourceArray, SourceSize);

	cout << "\n> Source Array:\n";
	PrintArray(SourceArray, SourceSize);

	int DestSize = 0;
	CopyArrayByAppend(SourceArray, DestinationArray, SourceSize, DestSize);

	cout << "\n\n> Copied Array:\n";
	PrintArray(DestinationArray, DestSize);

	return 0;
}