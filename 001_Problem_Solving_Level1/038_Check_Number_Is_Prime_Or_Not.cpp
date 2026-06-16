#include <iostream>
#include <string>
using namespace std;

enum enPrimeStatus { Prime = 1, NotPrime = 2 };

int ReadNumber(string Msg)
{
	int Number;

	do
	{
		cout << Msg;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

enPrimeStatus IsPrime(int Number)
{
	int M = Number / 2;

	for (int i = 2; i <= M; i++)
	{
		if (Number % i == 0)
			return enPrimeStatus::NotPrime;
	}

	return enPrimeStatus::Prime;
}

void PrintResult(int Number)
{
	if (IsPrime(Number) == enPrimeStatus::Prime)
		cout << "\n> " << Number << " IS Prime Number.\n";
	else
		cout << "\n> " << Number << " IS Not Prime Number.\n";
}

int main()
{
	int Number = ReadNumber("\n> Please Enter A Positive Number: ");

	PrintResult(Number);

	return 0;
}