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

void PrintNumberFromNTo1_UsingForLoop(int N)
{
	cout << "\n> Range Printed Using For Statement \n";

	for (int i = N; i >= 1; i--)
	{
		cout << i;
		if (i > 1) cout << ", ";
	}
}

void PrintNumberFromNTo1_UsingWhileLoop(int N)
{
	int i = N;

	cout << "\n> Range Printed Using While Statement \n";

	while (i >= 1)
	{
		cout << i;
		if (i > 1) cout << ", ";
		i--;
	}
}

void PrintNumberFromNTo1_UsingDoWhileLoop(int N)
{
	int i = N;

	cout << "\n> Range Printed Using Do While Statement \n";

	do
	{
		cout << i;
		if (i > 1) cout << ", ";
		i--;
	} while (i >= 1);
}

int main()
{
	int N = ReadNumberN();

	PrintNumberFromNTo1_UsingForLoop(N);
	cout << endl;

	PrintNumberFromNTo1_UsingWhileLoop(N);
	cout << endl;

	PrintNumberFromNTo1_UsingDoWhileLoop(N);

	return 0;
}