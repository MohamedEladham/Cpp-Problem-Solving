#include <iostream>

using namespace std;

void PrintFibonacciUsingLoop(short TermsCount)
{
	int FibonacciNumber = 0;

	int PreviousTwo = 0;
	int PreviousOne = 1;

	cout << PreviousOne << "\t";

	for (short i = 2; i <= TermsCount; i++)
	{
		FibonacciNumber = PreviousOne + PreviousTwo;

		cout << FibonacciNumber << "\t";

		PreviousTwo = PreviousOne;
		PreviousOne = FibonacciNumber;
	}
}

int main()
{
	PrintFibonacciUsingLoop(10);

	cout << endl;

	return 0;
}