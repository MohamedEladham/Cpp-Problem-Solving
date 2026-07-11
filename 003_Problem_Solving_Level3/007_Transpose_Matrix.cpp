#include <iostream>

using namespace std;

void FillMatrixWithOrderedNumbers(short Matrix[3][3], short Rows, short Columns)
{
	short CurrentNumber = 1;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			Matrix[i][j] = CurrentNumber;
			CurrentNumber++;
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

void TransposeMatrix(short TransposeMatrix[3][3], short Matrix[3][3], short Rows, short Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			TransposeMatrix[i][j] = Matrix[j][i];
		}
	}
}

void PrintTransposeMatrix(short TransposeMatrix[3][3], short Rows, short Columns)
{
	cout << "\nThe Following Is The Transposed Matrix:\n";

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			cout << " " << TransposeMatrix[i][j] << "\t";
		}

		cout << endl;
	}
}

int main()
{
	const short Rows = 3;
	const short Columns = 3;

	short Matrix[Rows][Columns];
	short TransposeMatrix[Rows][Columns];

	FillMatrixWithOrderedNumbers(Matrix, Rows, Columns);

	PrintMatrix(Matrix, Rows, Columns);
	cout << endl;

	TransposeMatrix(TransposeMatrix, Matrix, Rows, Columns);

	PrintTransposeMatrix(TransposeMatrix, Rows, Columns);
	cout << endl;

	return 0;
}