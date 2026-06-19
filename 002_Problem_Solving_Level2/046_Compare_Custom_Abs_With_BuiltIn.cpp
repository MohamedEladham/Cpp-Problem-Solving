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

float MyABS(float Value)
{
	if (Value < 0)
		return -Value;

	return Value;
}

int main()
{
	float Number = ReadFloat("\n> Please Enter A Number: ");

	cout << "\n> My ABS Result: " << MyABS(Number);
	cout << "\n> Built-in abs Result: " << fabs(Number);

	return 0;
}