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
			printf(" %0*d\t", 2, Matrix[i][j]);
		}

		cout << endl;
	}
}

short CalculateMatrixSum(short Matrix[3][3], short Rows, short Columns)
{
	short MatrixSum = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			MatrixSum += Matrix[i][j];
		}
	}

	return MatrixSum;
}

void PrintMatrixSum(short Matrix[3][3], short Rows, short Columns)
{
	short MatrixSum = CalculateMatrixSum(Matrix, Rows, Columns);

	cout << "Sum Of Matrix = " << MatrixSum << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3;
	const short Columns = 3;

	short Matrix[Rows][Columns];

	cout << "Matrix:\n";

	FillMatrixWithRandomNumbers(Matrix, Rows, Columns);
	PrintMatrix(Matrix, Rows, Columns);

	cout << endl;

	PrintMatrixSum(Matrix, Rows, Columns);

	cout << endl;

	return 0;
}