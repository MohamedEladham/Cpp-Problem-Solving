#include <iostream>
#include <cmath>
using namespace std;

enum enPrimeNotPrime
{
	Prime = 1,
	NotPrime = 2
};

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

enPrimeNotPrime CheckIfPrime(int Number)
{
	if (Number <= 1)
		return enPrimeNotPrime::NotPrime;

	int HalfNumber = floor(Number / 2);

	for (int i = 2; i <= HalfNumber; i++)
	{
		if (Number % i == 0)
			return enPrimeNotPrime::NotPrime;
	}

	return enPrimeNotPrime::Prime;
}

void PrintPrimeNumbersFrom1ToN(int Number)
{
	cout << "\n> Print Prime Number From 1 To " << Number << endl;
	cout << "\n> Prime Numbers Are: ";

	for (int i = 1; i <= Number; i++)
	{
		if (CheckIfPrime(i) == enPrimeNotPrime::Prime)
		{
			cout << i;

			if (i < Number - 1)
				cout << ", ";
		}
	}
}

int main()
{
	PrintPrimeNumbersFrom1ToN(
		ReadPositiveNumber("\n> Please Enter Positive Number: ")
	);

	cout << "\n\n\n";
	return 0;
}