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

void PrintPowerOfNumber(int Number)
{
	int Power2 = Number * Number;
	int Power3 = Number * Number * Number;
	int Power4 = Number * Number * Number * Number;

	cout << "\n> Power Of 2 = " << Power2 << endl;
	cout << "\n> Power Of 3 = " << Power3 << endl;
	cout << "\n> Power Of 4 = " << Power4 << endl;
}

int main()
{
	PrintPowerOfNumber(ReadNumber());
	return 0;
}