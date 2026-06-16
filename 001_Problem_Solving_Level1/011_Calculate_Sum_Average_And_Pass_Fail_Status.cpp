#include <iostream>
#include <string>
using namespace std;

enum enPassFail { Pass, Fail };

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

enPassFail getPassFailStatus(float average)
{
	if (average >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void printSumResult(string message, float sum)
{
	cout << message << sum << endl;
}

void printAverageResult(string message, float average)
{
	cout << message << average << endl;
}

void printPassFailResult(string message, enPassFail status)
{
	if (status == enPassFail::Pass)
		cout << message << "'Pass'\n";
	else
		cout << message << "'Fail'\n";
}

int main()
{
	float number1, number2, number3;

	readThreeNumbers(number1, number2, number3);

	printSumResult("\n> Result Sum Of Numbers = ", sumThreeNumbers(number1, number2, number3));

	printAverageResult("\n> Result Average Of Numbers = ", calculateAverage(number1, number2, number3));

	printPassFailResult(
		"\n> Result Pass Or Fail Average Is ",
		getPassFailStatus(calculateAverage(number1, number2, number3))
	);

	return 0;
}