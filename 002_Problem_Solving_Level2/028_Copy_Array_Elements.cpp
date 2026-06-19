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

void CopyArray(int SourceArray[], int DestinationArray[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		DestinationArray[i] = SourceArray[i];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int ArraySize = ReadPositiveNumber("\n> Enter Number Of Elements: ");

	int SourceArray[100], DestinationArray[100];

	FillArrayWithRandomNumber(SourceArray, ArraySize);
	CopyArray(SourceArray, DestinationArray, ArraySize);

	cout << "\n> Source Array Elements \n";
	PrintArray(SourceArray, ArraySize);

	cout << "\n> Destination Array After Copy \n";
	PrintArray(DestinationArray, ArraySize);

	return 0;
}