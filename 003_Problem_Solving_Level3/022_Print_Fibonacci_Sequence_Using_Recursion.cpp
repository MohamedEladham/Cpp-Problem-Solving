#include <iostream>

using namespace std;

void PrintFibonacciSequence(short TermsCount, int PreviousTwo, int PreviousOne)
{
	if (TermsCount == 0)
	{
		return;
	}

	int FibonacciNumber = PreviousTwo + PreviousOne;

	cout << FibonacciNumber << "\t";

	PrintFibonacciSequence(TermsCount - 1, PreviousOne, FibonacciNumber);
}

int main()
{
	cout << "1\t";

	PrintFibonacciSequence(9, 0, 1);

	cout << endl;

	return 0;
}