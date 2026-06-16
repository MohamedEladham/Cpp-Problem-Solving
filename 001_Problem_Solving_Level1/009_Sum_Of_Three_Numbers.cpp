#include <iostream>
#include <string>
using namespace std;

struct stThreeNumbers
{
	float Number1, Number2, Number3;
};

stThreeNumbers readNumbers()
{
	stThreeNumbers numbers;

	cout << "\n> Enter Number A: ";
	cin >> numbers.Number1;

	cout << "\n> Enter Number B: ";
	cin >> numbers.Number2;

	cout << "\n> Enter Number C: ";
	cin >> numbers.Number3;

	return numbers;
}

float calculateSum(stThreeNumbers numbers)
{
	return numbers.Number1 + numbers.Number2 + numbers.Number3;
}

void printResult(string message, float sum)
{
	cout << message << sum << endl;
}

int main()
{
	printResult("\n> Sum Of 3 Numbers = ", calculateSum(readNumbers()));
	return 0;
}