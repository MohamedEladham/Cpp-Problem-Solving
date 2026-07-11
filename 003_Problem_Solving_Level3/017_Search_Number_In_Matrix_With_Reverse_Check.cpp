#include <iostream>

using namespace std;

void PrintMatrix(short Matrix[3][3], short Rows, short Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			printf(" %d\t", Matrix[i][j]);
		}

		cout << endl;
	}
}

bool IsNumberFoundInMatrix(short Matrix[3][3], short Rows, short Columns, short Number)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			if (Matrix[i][j] == Number ||
				Matrix[Rows - 1 - i][Columns - 1 - j] == Number)
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	const short Rows = 3;
	const short Columns = 3;

	short Matrix[Rows][Columns] =
	{
		{77, 5, 12},
		{22, 20, 1},
		{3, 0, 9}
	};

	cout << "Matrix\n";
	PrintMatrix(Matrix, Rows, Columns);

	short Number;

	cout << "\nPlease Enter A Number To Look For In Matrix: ";
	cin >> Number;

	cout << endl;

	bool IsFound = IsNumberFoundInMatrix(Matrix, Rows, Columns, Number);

	cout << "Number Found: " << (IsFound ? "Yes" : "No") << endl;

	return 0;
}