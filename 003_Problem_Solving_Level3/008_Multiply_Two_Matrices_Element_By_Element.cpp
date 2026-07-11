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
			Matrix[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(short Matrix[3][3], short Rows, short Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			printf(" %0*i \t", 2, Matrix[i][j]);
		}

		cout << endl;
	}
}

void MultiplyMatricesElementWise(short ResultMatrix[3][3],
	short Matrix1[3][3],
	short Matrix2[3][3],
	short Rows,
	short Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			ResultMatrix[i][j] = Matrix1[i][j] * Matrix2[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3;
	const short Columns = 3;

	short Matrix1[Rows][Columns];
	short Matrix2[Rows][Columns];
	short ResultMatrix[Rows][Columns];

	cout << "Matrix 1\n";
	FillMatrixWithRandomNumbers(Matrix1, Rows, Columns);
	PrintMatrix(Matrix1, Rows, Columns);
	cout << endl;

	cout << "Matrix 2\n";
	FillMatrixWithRandomNumbers(Matrix2, Rows, Columns);
	PrintMatrix(Matrix2, Rows, Columns);
	cout << endl;

	cout << "Result Matrix\n";
	MultiplyMatricesElementWise(ResultMatrix, Matrix1, Matrix2, Rows, Columns);
	PrintMatrix(ResultMatrix, Rows, Columns);
	cout << endl;

	return 0;
}