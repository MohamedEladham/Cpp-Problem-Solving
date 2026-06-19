#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "\n> Please Enter A Number: ";
	cin >> Number;
	return Number;
}

void AppendToArray(int Number, int Array[], int& ArraySize)
{
	Array[ArraySize] = Number;
	ArraySize++;
}

void FillArrayFromUser(int Array[], int& ArraySize)
{
	int AddMore;

	do
	{
		AppendToArray(ReadNumber(), Array, ArraySize);

		cout << "\n> Do You Want To Add More Numbers? [0]No [1]Yes: ";
		cin >> AddMore;

	} while (AddMore == 1);
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
	int Array[100], ArraySize = 0;

	FillArrayFromUser(Array, ArraySize);

	cout << "\n> Array Size = " << ArraySize << endl;
	cout << "\n> Array Elements: ";
	PrintArray(Array, ArraySize);

	return 0;
}