#include <iostream>
#include <cstdio>

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

bool IsScalarMatrix(short Matrix[3][3], short Rows, short Columns)
{
	short FirstDiagonalElement = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			if (i == j && Matrix[i][j] != FirstDiagonalElement)
			{
				return false;
			}
			else if (i != j && Matrix[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	const short Rows = 3;
	const short Columns = 3;

	short Matrix[Rows][Columns] =
	{
		{5, 0, 0},
		{0, 5, 0},
		{0, 0, 5}
	};

	cout << "Matrix\n";
	PrintMatrix(Matrix, Rows, Columns);
	cout << endl;

	if (IsScalarMatrix(Matrix, Rows, Columns))
	{
		cout << "YES, Matrix Is Scalar.\n";
	}
	else
	{
		cout << "NO, Matrix Is Not Scalar.\n";
	}

	return 0;
}