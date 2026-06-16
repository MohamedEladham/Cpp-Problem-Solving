#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Msg)
{
	int Number;

	do
	{
		cout << Msg;
		cin >> Number;

	} while (Number < 0);

	return Number;
}

int CalculateFactorial(int Number)
{
	int Factorial = 1;

	for (int i = Number; i >= 1; i--)
	{
		cout << Factorial << " * " << i << " = " << Factorial * i << endl;
		Factorial *= i;
	}

	return Factorial;
}

void PrintFactorialResult(int Factorial)
{
	cout << "\n> Factorial Of Number = " << Factorial << endl;
}

int main()
{
	int Number = ReadPositiveNumber("\n> Enter A Positive Number N: ");

	int Result = CalculateFactorial(Number);

	PrintFactorialResult(Result);

	return 0;
}