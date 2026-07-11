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

int main()
{
	const short Rows = 3;
	const short Columns = 3;

	short Matrix[Rows][Columns] =
	{
		{9, 1, 12},
		{0, 9, 1},
		{0, 9, 9}
	};

	cout << "Matrix 1\n";
	PrintMatrix(Matrix, Rows, Columns);

	cout << endl;

	short Number;

	cout << "Enter A Number To Count In Matrix: ";
	cin >> Number;

	cout << endl;

	short OccurrencesCount = CountNumberInMatrix(Matrix, Rows, Columns, Number);

	printf("Number %d Count In Matrix Is %d\n", Number, OccurrencesCount);

	return 0;
}