#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int RandomNumber(int From, int To)
{
	int RandomValue = rand() % (To - From + 1) + From;
	return RandomValue;
}

void FillMatrixWithRandomNumbers(short Matrix[3][3], short Rows, short Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			Matrix[i][j] = RandomNumber(1, 100);
		}
	}
}

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

bool AreMatricesEqual(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Columns)
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

void PrintComparisonResult(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Columns)
{
	if (AreMatricesEqual(Matrix1, Matrix2, Rows, Columns))
	{
		cout << "Yes, Both Matrices Are Equal.\n";
	}
	else
	{
		cout << "No, Both Matrices Are Not Equal.\n";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3;
	const short Columns = 3;

	short Matrix1[Rows][Columns];
	short Matrix2[Rows][Columns];

	cout << "Matrix 1:\n";
	FillMatrixWithRandomNumbers(Matrix1, Rows, Columns);
	PrintMatrix(Matrix1, Rows, Columns);

	cout << endl;

	cout << "Matrix 2:\n";
	FillMatrixWithRandomNumbers(Matrix2, Rows, Columns);
	PrintMatrix(Matrix2, Rows, Columns);

	cout << endl;

	PrintComparisonResult(Matrix1, Matrix2, Rows, Columns);

	cout << endl;

	return 0;
}