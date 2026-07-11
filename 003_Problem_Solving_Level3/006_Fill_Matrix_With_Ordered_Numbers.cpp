#include <iostream>

using namespace std;

void FillMatrixWithOrderedNumbers(short Matrix[3][3], short Rows, short Columns)
{
	short Counter = 1;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			Matrix[i][j] = Counter;
			Counter++;
		}
	}
}

void PrintMatrix(short Matrix[3][3], short Rows, short Columns)
{
	cout << "The Following Is A 3x3 Ordered Matrix:\n";

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			cout << " " << Matrix[i][j] << "\t";
		}

		cout << endl;
	}
}

int main()
{
	const short Rows = 3;
	const short Columns = 3;

	short Matrix[Rows][Columns];

	FillMatrixWithOrderedNumbers(Matrix, Rows, Columns);

	PrintMatrix(Matrix, Rows, Columns);
	cout << endl;

	return 0;
}