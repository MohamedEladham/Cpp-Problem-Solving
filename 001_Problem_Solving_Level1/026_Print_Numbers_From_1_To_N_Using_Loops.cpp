#include <iostream>
#include <string>
using namespace std;

int ReadNumberN()
{
	int N;
	cout << "\n> Please Enter Number N: ";
	cin >> N;
	return N;
}

void PrintNumbersFrom1ToN_UsingForLoop(int N)
{
	cout << "\n> Range Printed Using For Statement \n";

	for (int i = 1; i <= N; i++)
	{
		cout << i;
		if (i < N) cout << ", ";
	}
}

void PrintNumbersFrom1ToN_UsingWhileLoop(int N)
{
	int i = 0;

	cout << "\n> Range Printed Using While Statement \n";

	while (i < N)
	{
		i++;
		cout << i;
		if (i < N) cout << ", ";
	}
}

void PrintNumbersFrom1ToN_UsingDoWhileLoop(int N)
{
	int i = 0;

	cout << "\n> Range Printed Using Do While Statement \n";

	do
	{
		i++;
		cout << i;
		if (i < N) cout << ", ";
	} while (i < N);
}

int main()
{
	int N = ReadNumberN();

	PrintNumbersFrom1ToN_UsingForLoop(N);

	cout << "\n\n--------------------------------\n";

	PrintNumbersFrom1ToN_UsingWhileLoop(N);

	cout << "\n\n--------------------------------\n";

	PrintNumbersFrom1ToN_UsingDoWhileLoop(N);

	return 0;
}