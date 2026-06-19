#include <iostream>
#include <cmath>

using namespace std;

float ReadFloat(string Message)
{
	float Number;
	cout << Message;
	cin >> Number;
	return Number;
}

int MyRound(float Number)
{
	int IntegerPart = (int)Number;
	float FractionalPart = Number - IntegerPart;

	if (FractionalPart >= 0.5)
		return IntegerPart + 1;

	if (FractionalPart <= -0.5)
		return IntegerPart - 1;

	return IntegerPart;
}

int main()
{
	float Number = ReadFloat("\n> Enter Number: ");

	cout << "\n> My Round Result: " << MyRound(Number);
	cout << "\n> Built-in Round Result: " << round(Number);

	return 0;
}