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

void PrintMiddleRowInMatrix(short Matrix[3][3], short Rows, short Columns)
{
	short MiddleRow = Rows / 2;

	for (short j = 0; j < Columns; j++)
	{
		printf(" %0*d\t", 2, Matrix[MiddleRow][j]);
	}
}

void PrintMiddleColumn(short Matrix[3][3], short Rows, short Columns)
{
	short MiddleColumn = Columns / 2;

	for (short i = 0; i < Rows; i++)
	{
		printf(" %0*d\t", 2, Matrix[i][MiddleColumn]);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3;
	const short Columns = 3;

	short Matrix[Rows][Columns];

	cout << "Matrix\n";

	FillMatrixWithRandomNumbers(Matrix, Rows, Columns);
	PrintMatrix(Matrix, Rows, Columns);

	cout << "\n";

	cout << "Middle Row Of Matrix:\n";
	PrintMiddleRowInMatrix(Matrix, Rows, Columns);

	cout << "\n\n";

	cout << "Middle Column Of Matrix:\n";
	PrintMiddleColumn(Matrix, Rows, Columns);

	cout << "\n\n";

	return 0;
}