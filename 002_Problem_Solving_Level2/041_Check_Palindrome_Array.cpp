#include <iostream>
using namespace std;

bool IsPalindromeArray(int Array[], int ArraySize)
{
	for (int i = 0; i < ArraySize / 2; i++)
	{
		if (Array[i] != Array[ArraySize - i - 1])
			return false;
	}

	return true;
}

void PrintPalindromeResult(int Array[], int ArraySize)
{
	if (IsPalindromeArray(Array, ArraySize))
		cout << "\n> Yes, Array Is A Palindrome Array.\n";
	else
		cout << "\n> No, Array Is NOT A Palindrome Array.\n";
}

int main()
{
	int Array[] = { 10, 20, 30, 30, 20, 10, 0 };
	int ArraySize = size(Array);

	PrintPalindromeResult(Array, ArraySize);

	return 0;
}