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

int ColumnSum(short Matrix[3][3], short Rows, short ColumnIndex)
{
	short ColumnSum = 0;

	for (short i = 0; i < Rows; i++)
	{
		ColumnSum += Matrix[i][ColumnIndex];
	}

	return ColumnSum;
}

void PrintColumnsSum(short Matrix[3][3], short Rows, short Columns)
{
	cout << "\nThe Following Are The Sum Of Each Column In The Matrix:\n";

	for (short i = 0; i < Columns; i++)
	{
		cout << "Column " << i + 1 << " Sum = "
			<< ColumnSum(Matrix, Rows, i) << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3;
	const short Columns = 3;

	short Matrix[Rows][Columns];

	FillMatrixWithRandomNumbers(Matrix, Rows, Columns);

	PrintMatrix(Matrix, Rows, Columns);
	cout << endl;

	PrintColumnsSum(Matrix, Rows, Columns);
	cout << endl;

	return 0;
}