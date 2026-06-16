#include <iostream>
#include <string>
using namespace std;

void readThreeNumbers(float& number1, float& number2, float& number3)
{
	cout << "\n> Enter Number A: ";
	cin >> number1;

	cout << "\n> Enter Number B: ";
	cin >> number2;

	cout << "\n> Enter Number C: ";
	cin >> number3;
}

float sumThreeNumbers(float number1, float number2, float number3)
{
	return number1 + number2 + number3;
}

float calculateAverage(float number1, float number2, float number3)
{
	return sumThreeNumbers(number1, number2, number3) / 3;
}

void printResult(string message, float result)
{
	cout << message << result << endl;
}

int main()
{
	float number1, number2, number3;

	readThreeNumbers(number1, number2, number3);

	printResult("\n> Average Of 3 Numbers = ", calculateAverage(number1, number2, number3));

	return 0;
}