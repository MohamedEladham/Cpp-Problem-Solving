#include <iostream>
#include <iomanip>
#include <cstdlib>

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

short RowSum(short Matrix[3][3], short RowIndex, short Columns)
{
	short Sum = 0;

	for (short j = 0; j < Columns; j++)
	{
		Sum += Matrix[RowIndex][j];
	}

	return Sum;
}

void SumMatrixRowsInArray(short RowSums[], short Matrix[3][3], short Rows, short Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		RowSums[i] = RowSum(Matrix, i, Columns);
	}
}

void PrintRowSums(short RowSums[3], short Rows)
{
	cout << "\nThe Following Are The Sum Of Each Row In The Matrix:\n";

	for (short i = 0; i < Rows; i++)
	{
		cout << "Row " << i + 1 << " Sum: " << RowSums[i] << endl;
	}
}

void PrintMatrix(short Matrix[3][3], short Rows, short Columns)
{
	cout << "The Following Is A 3x3 Random Matrix:\n";

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			cout << setw(3) << Matrix[i][j] << "\t";
		}

		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3;
	const short Columns = 3;

	short Matrix[Rows][Columns];
	short RowSums[Rows];

	FillMatrixWithRandomNumbers(Matrix, Rows, Columns);

	PrintMatrix(Matrix, Rows, Columns);
	cout << endl;

	SumMatrixRowsInArray(RowSums, Matrix, Rows, Columns);

	PrintRowSums(RowSums, Rows);
	cout << endl;

	return 0;
}