#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "\n> Please Enter A Number: ";
	cin >> Number;
	return Number;
}

int ReadPower()
{
	int Power;
	cout << "\n> Please Enter Power Of Number: ";
	cin >> Power;
	return Power;
}

int CalculatePower(int Base, int Exponent)
{
	if (Exponent == 0)
		return 1;

	int Result = 1;

	for (int i = 1; i <= Exponent; i++)
	{
		Result *= Base;
	}

	return Result;
}

void PrintResult(int Result)
{
	cout << "\n> Power Of Number = " << Result << endl;
}

int main()
{
	int Base = ReadNumber();
	int Exponent = ReadPower();

	PrintResult(CalculatePower(Base, Exponent));

	return 0;
}