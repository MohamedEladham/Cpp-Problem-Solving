#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(short Matrix[3][3], short Rows, short Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			cout << setw(3) << Matrix[i][j] << "\t";
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
			if (Matrix[i][j] == Number)
			{
				return true;
			}
		}
	}

	return false;
}

void PrintIntersectedNumbersInMatrices(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Columns)
{
	cout << "Intersected Numbers Are:\n\n";

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			short CurrentNumber = Matrix1[i][j];

			if (IsNumberFoundInMatrix(Matrix2, Rows, Columns, CurrentNumber))
			{
				cout << CurrentNumber << "\t";
			}
		}
	}
}

int main()
{
	const short Rows = 3;
	const short Columns = 3;

	short Matrix1[Rows][Columns] =
	{
		{77, 5, 12},
		{22, 20, 1},
		{1, 0, 9}
	};

	short Matrix2[Rows][Columns] =
	{
		{5, 80, 90},
		{22, 77, 1},
		{10, 0, 33}
	};

	cout << "Matrix 1\n";
	PrintMatrix(Matrix1, Rows, Columns);

	cout << endl;

	cout << "Matrix 2\n";
	PrintMatrix(Matrix2, Rows, Columns);

	cout << endl;

	PrintIntersectedNumbersInMatrices(Matrix1, Matrix2, Rows, Columns);

	cout << endl;

	return 0;
}