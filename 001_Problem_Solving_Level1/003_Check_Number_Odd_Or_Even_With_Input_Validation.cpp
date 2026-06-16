#include <iostream>
#include <string>
#include <regex>
using namespace std;

enum enNumberType { Odd = 1, Even = 2 };

bool isValidInteger(string input)
{
	regex intNum("^-?\\d+$");
	return regex_match(input, intNum);
}

int readIntegerNumber(string message, string errorMessage)
{
	int number;
	string input;

	while (true)
	{
		cout << message;
		getline(cin, input);

		if (isValidInteger(input))
		{
			number = stoi(input);
			break;
		}

		cout << errorMessage;
	}

	return number;
}

enNumberType getNumberType(int number)
{
	int remainder = number % 2;

	if (remainder == 0)
		return enNumberType::Even;
	else
		return enNumberType::Odd;
}

void printNumberType(enNumberType numberType)
{
	if (numberType == enNumberType::Even)
		cout << "\n> Number Is Even \n";
	else
		cout << "\n> Number Is Odd \n";
}

int main()
{
	printNumberType(getNumberType(readIntegerNumber("Enter Integer Number: ", "Invalid Number, Please Try Again!\n")));
	return 0;
}