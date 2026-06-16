#include <iostream>
#include <string>
using namespace std;

int readNumber()
{
	int number;

	cout << "\n> Please Enter The Number: ";
	cin >> number;

	return number;
}

float calculateHalfOfNumber(int number)
{
	return (float)number / 2;
}

void printResult(int number)
{
	string result = "\n> Half Of " + to_string(number) + " Is " + to_string(calculateHalfOfNumber(number));

	cout << result << endl;
}

int main()
{
	printResult(readNumber());

	cout << "\n\n\n";
	return 0;
}