#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

short ReadShortNumber(string Message)
{
	short Number;
	cout << Message;
	cin >> Number;
	return Number;
}

short RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(short Array[], short ArraySize)
{
	for (short i = 0; i < ArraySize; i++)
		Array[i] = RandomNumber(-100, 100);
}

void PrintArray(short Array[], short ArraySize)
{
	for (short i = 0; i < ArraySize; i++)
		cout << Array[i] << " ";
}

short CountNegativeNumbers(short Array[], short ArraySize)
{
	short Counter = 0;

	for (short i = 0; i < ArraySize; i++)
		if (Array[i] < 0)
			Counter++;

	return Counter;
}

int main()
{
	srand((unsigned)time(0));

	short Array[100], ArraySize;

	ArraySize = ReadShortNumber("\n> Please Enter Array Size: ");

	FillArrayWithRandomNumbers(Array, ArraySize);

	cout << "\n> Array Elements:\n";
	PrintArray(Array, ArraySize);

	cout << "\n\n> Negative Numbers Count Is: ";
	cout << CountNegativeNumbers(Array, ArraySize);

	return 0;
}