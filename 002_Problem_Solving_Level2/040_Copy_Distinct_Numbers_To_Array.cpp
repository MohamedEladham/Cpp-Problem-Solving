#include <iostream>
using namespace std;

void FillArray(int SourceArray[], int& SourceSize)
{
	SourceSize = 10;

	SourceArray[0] = 10;
	SourceArray[1] = 10;
	SourceArray[2] = 10;
	SourceArray[3] = 50;
	SourceArray[4] = 50;
	SourceArray[5] = 70;
	SourceArray[6] = 70;
	SourceArray[7] = 70;
	SourceArray[8] = 70;
	SourceArray[9] = 90;
}

int FindValuePosition(int Number, int SourceArray[], int SourceSize)
{
	for (int i = 0; i < SourceSize; i++)
	{
		if (SourceArray[i] == Number)
			return i;
	}

	return -1;
}

bool IsValueInArray(int Number, int SourceArray[], int SourceSize)
{
	return FindValuePosition(Number, SourceArray, SourceSize) != -1;
}

void AddArrayElement(int Number, int Array[], int& Size)
{
	Array[Size] = Number;
	Size++;
}

void CopyDistinctNumbersToArray(int SourceArray[],
	int UniqueArray[],
	int SourceSize,
	int& UniqueSize)
{
	for (int i = 0; i < SourceSize; i++)
	{
		if (!IsValueInArray(SourceArray[i], UniqueArray, UniqueSize))
		{
			AddArrayElement(SourceArray[i], UniqueArray, UniqueSize);
		}
	}
}

void PrintArray(int Array[], int Size)
{
	for (int i = 0; i < Size; i++)
	{
		cout << Array[i] << " ";
	}
}

int main()
{
	int SourceArray[100], UniqueArray[100];
	int SourceSize = 0, UniqueSize = 0;

	FillArray(SourceArray, SourceSize);

	cout << "\n> Source Array:\n";
	PrintArray(SourceArray, SourceSize);

	CopyDistinctNumbersToArray(SourceArray, UniqueArray, SourceSize, UniqueSize);

	cout << "\n\n> Unique Elements:\n";
	PrintArray(UniqueArray, UniqueSize);

	return 0;
}