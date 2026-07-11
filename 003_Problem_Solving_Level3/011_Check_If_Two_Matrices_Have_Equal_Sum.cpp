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
			Matrix[i][j] = RandomNumber(1, 5);
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
	short Sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			Sum += Matrix[i][j];
		}
	}

	return Sum;
}

bool AreMatrixSumsEqual(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Columns)
{
	return CalculateMatrixSum(Matrix1, Rows, Columns) ==
		CalculateMatrixSum(Matrix2, Rows, Columns);
}

void PrintComparisonResult(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Columns)
{
	if (AreMatrixSumsEqual(Matrix1, Matrix2, Rows, Columns))
	{
		cout << "Yes, Matrix sums are equal.";
		system("Color 2F");
	}
	else
	{
		cout << "No, Matrix sums are not equal.";
		system("Color 4F");
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

	cout << "\n";

	cout << "Matrix 2:\n";
	FillMatrixWithRandomNumbers(Matrix2, Rows, Columns);
	PrintMatrix(Matrix2, Rows, Columns);

	cout << "\n";

	short Matrix1Sum = CalculateMatrixSum(Matrix1, Rows, Columns);
	short Matrix2Sum = CalculateMatrixSum(Matrix2, Rows, Columns);

	cout << "Matrix 1 Sum = " << Matrix1Sum << endl;
	cout << "Matrix 2 Sum = " << Matrix2Sum << endl;

	cout << endl;

	PrintComparisonResult(Matrix1, Matrix2, Rows, Columns);

	cout << endl;

	return 0;
}