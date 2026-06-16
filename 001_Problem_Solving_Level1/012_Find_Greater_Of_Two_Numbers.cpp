#include <iostream>
#include <string>
using namespace std;

void readTwoNumbers(int& number1, int& number2)
{
	cout << "\n> Enter Number 1: ";
	cin >> number1;

	cout << "\n> Enter Number 2: ";
	cin >> number2;
}

bool isFirstNumberGreater(int number1, int number2)
{
	return (number1 > number2);
}

string getResultMessage(int number1, int number2)
{
	string result;

	if (number1 == number2)
		result = "Both Numbers Are Equal";

	else if (isFirstNumberGreater(number1, number2))
		result = to_string(number1) + " Is Greater Than Number " + to_string(number2);

	else
		result = to_string(number2) + " Is Greater Than Number " + to_string(number1);

	return result;
}

int main()
{
	int number1, number2;

	readTwoNumbers(number1, number2);

	cout << "\n> Result = " << getResultMessage(number1, number2) << endl;

	return 0;
}