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

int RowSum(short Matrix[3][3], short RowIndex, short Columns)
{
    int Sum = 0;

    for (short j = 0; j < Columns; j++)
    {
        Sum += Matrix[RowIndex][j];
    }

    return Sum;
}

void PrintEachRowSum(short Matrix[3][3], short Rows, short Columns)
{
    cout << "\nThe Following Are The Sum Of Each Row In The Matrix:\n";

    for (short i = 0; i < Rows; i++)
    {
        cout << "Row " << i + 1 << " Sum: "
            << RowSum(Matrix, i, Columns) << endl;
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
    srand((unsigned)time(0));

    const short Rows = 3;
    const short Columns = 3;

    short Matrix[Rows][Columns];

    FillMatrixWithRandomNumbers(Matrix, Rows, Columns);

    PrintMatrix(Matrix, Rows, Columns);
    cout << endl;

    PrintEachRowSum(Matrix, Rows, Columns);

    return 0;
}