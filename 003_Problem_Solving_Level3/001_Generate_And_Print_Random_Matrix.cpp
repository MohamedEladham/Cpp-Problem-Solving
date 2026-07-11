#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
    int RandomValue = rand() % (To - From + 1) + From;
    return RandomValue;
}

void FillMatrixWithRandomNumber(short Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(short Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
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
    const short Cols = 3;

    short Matrix[Rows][Cols];

    FillMatrixWithRandomNumber(Matrix, Rows, Cols);

    cout << "The Following Is A 3x3 Random Matrix:\n";
    PrintMatrix(Matrix, Rows, Cols);

    return 0;
}