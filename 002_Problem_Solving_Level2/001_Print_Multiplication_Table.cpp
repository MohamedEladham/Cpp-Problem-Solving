#include <iostream>
using namespace std;

void PrintTableHeader()
{
	cout << "\n\n\t\t\t Multiplication Table From 1 To 10 \n\n";

	for (short i = 1; i <= 10; i++)
		cout << "\t" << i;

	cout << "\n";
}

string GetColumnSeparator(short RowNumber)
{
	if (RowNumber < 10)
		return "   |";
	else
		return "  |";
}

void PrintMultiplicationTable()
{
	PrintTableHeader();

	char SeparatorCharacter = '-';

	for (short i = 0; i <= 82; i++)
		cout << SeparatorCharacter;

	cout << "\n";

	for (short i = 1; i <= 10; i++)
	{
		cout << " " << i << GetColumnSeparator(i) << "  ";

		for (short j = 1; j <= 10; j++)
			cout << i * j << "\t";

		cout << "\n";
	}
}

int main()
{
	PrintMultiplicationTable();

	cout << "\n\n\n";
	return 0;
}