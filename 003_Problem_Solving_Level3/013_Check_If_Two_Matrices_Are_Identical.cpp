#include <iostream>
#include <cstdio>

using namespace std;

void PrintMatrix(short Matrix[3][3], short Rows, short Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			printf(" %0*d\t", 2, Matrix[i][j]);
		}

		cout << endl;
	}
}

bool AreMatricesIdentical(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
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

	short Matrix1[Rows][Columns] =
	{
		{1, 3, 4},
		{0, 1, 5},
		{7, 0, 1}
	};

	short Matrix2[Rows][Columns] =
	{
		{1, 3, 4},
		{0, 1, 5},
		{7, 0, 0}
	};

	cout << "Matrix 1\n";
	PrintMatrix(Matrix1, Rows, Columns);
	cout << endl;

	cout << "Matrix 2\n";
	PrintMatrix(Matrix2, Rows, Columns);
	cout << endl;

	if (AreMatricesIdentical(Matrix1, Matrix2, Rows, Columns))
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}

	return 0;
}