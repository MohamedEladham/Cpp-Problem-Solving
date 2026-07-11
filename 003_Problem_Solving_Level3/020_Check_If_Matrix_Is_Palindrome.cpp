#include <iostream>
#include <cstdio>

using namespace std;

void PrintMatrix(short Matrix[3][3], short Rows, short Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns; j++)
		{
			printf(" %d \t", Matrix[i][j]);
		}

		cout << endl;
	}
}

bool AreMatrixRowsPalindrome(short Matrix[3][3], short Rows, short Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Columns / 2; j++)
		{
			if (Matrix[i][j] != Matrix[i][Columns - 1 - j])
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	const short Rows = 3;
	const short Columns = 3;

	short Matrix[Rows][Columns] =
	{
		{1, 2, 1},
		{5, 5, 5},
		{7, 0, 7}
	};

	cout << "Matrix\n";
	PrintMatrix(Matrix, Rows, Columns);

	cout << endl;

	if (AreMatrixRowsPalindrome(Matrix, Rows, Columns))
	{
		cout << "YES, Matrix Rows Are Palindrome.\n";
	}
	else
	{
		cout << "NO, Matrix Rows Are Not Palindrome.\n";
	}

	return 0;
}