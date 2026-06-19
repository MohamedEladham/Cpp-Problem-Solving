#include <iostream>
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

void ReadArray(int Array[], int ArraySize)
{
	cout << "\n";

	for (int i = 0; i < ArraySize; i++)
	{
		cout << "> Enter Element [" << i + 1 << "] : ";
		cin >> Array[i];
	}
}

int CountElementFrequency(int Array[], int ArraySize, int ElementToCheck)
{
	int Counter = 0;

	for (int i = 0; i < ArraySize; i++)
	{
		if (ElementToCheck == Array[i])
		{
			Counter++;
		}
	}

	return Counter;
}

void PrintFrequencyResult(int ElementToCheck, int Frequency)
{
	cout << "\n> Number '" << ElementToCheck
		<< "' Is Repeated '" << Frequency
		<< "' Time(s).\n";
}

void PrintArray(int Array[], int ArraySize)
{
	cout << "\n> Original Array: ";

	for (int i = 0; i < ArraySize; i++)
	{
		cout << Array[i] << " ";
	}

	cout << "\n";
}

int main()
{
	int Array[100], ArraySize, ElementToCheck;

	ArraySize = ReadPositiveNumber("\n> How Many Elements Would You Like To Enter: ");

	ReadArray(Array, ArraySize);

	ElementToCheck = ReadPositiveNumber("\n> Enter Number You Want To Check: ");

	PrintArray(Array, ArraySize);

	int Frequency = CountElementFrequency(Array, ArraySize, ElementToCheck);

	PrintFrequencyResult(ElementToCheck, Frequency);

	return 0;
}