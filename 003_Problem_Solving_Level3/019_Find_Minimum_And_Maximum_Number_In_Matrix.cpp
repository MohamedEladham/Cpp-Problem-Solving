#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(short Matrix[3][3], short Rows, short Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			cout << setw(3) << Matrix[i][j] << "\t";
		}

		cout << endl;
	}
}

short FindMinimumNumberInMatrix(short Matrix[3][3], short Rows, short Columns)
{
	short MinimumValue = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			if (Matrix[i][j] < MinimumValue)
			{
				MinimumValue = Matrix[i][j];
			}
		}
	}

	return MinimumValue;
}

short FindMaximumNumberInMatrix(short Matrix[3][3], short Rows, short Columns)
{
	short MaximumValue = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			if (Matrix[i][j] > MaximumValue)
			{
				MaximumValue = Matrix[i][j];
			}
		}
	}

	return MaximumValue;
}

int main()
{
	const short Rows = 3;
	const short Columns = 3;

	short Matrix[Rows][Columns] =
	{
		{77, 5, 12},
		{22, 20, 6},
		{14, 3, 9}
	};

	cout << "Matrix\n";
	PrintMatrix(Matrix, Rows, Columns);

	cout << endl;

	short MinimumValue = FindMinimumNumberInMatrix(Matrix, Rows, Columns);
	cout << "Minimum Number Is: " << MinimumValue << endl;

	cout << endl;

	short MaximumValue = FindMaximumNumberInMatrix(Matrix, Rows, Columns);
	cout << "Maximum Number Is: " << MaximumValue << endl;

	cout << endl;

	return 0;
}