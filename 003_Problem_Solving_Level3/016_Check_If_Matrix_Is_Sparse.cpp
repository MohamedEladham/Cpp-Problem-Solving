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

short CountNumberInMatrix(short Matrix[3][3], short Rows, short Columns, short Number)
{
	short Count = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			if (Matrix[i][j] == Number)
			{
				Count++;
			}
		}
	}

	return Count;
}

bool IsSparseMatrix(short Matrix[3][3], short Rows, short Columns)
{
	short HalfMatrixSize = (Rows * Columns) / 2;

	return CountNumberInMatrix(Matrix, Rows, Columns, 0) > HalfMatrixSize;
}

int main()
{
	const short Rows = 3;
	const short Columns = 3;

	short Matrix[Rows][Columns] =
	{
		{0, 0, 12},
		{0, 0, 1},
		{0, 0, 9}
	};

	cout << "Matrix\n";
	PrintMatrix(Matrix, Rows, Columns);

	cout << endl;

	short Number = 0;
	short Count = CountNumberInMatrix(Matrix, Rows, Columns, Number);

	printf("Number %d Count In Matrix Is %d\n", Number, Count);

	cout << endl;

	if (IsSparseMatrix(Matrix, Rows, Columns))
	{
		cout << "YES, It's Sparse.\n";
	}
	else
	{
		cout << "NO, It's Not Sparse.\n";
	}

	return 0;
}