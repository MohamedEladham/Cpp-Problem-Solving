#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber()
{
    float Number;
    cout << "Enter number please: ";
    cin >> Number;
    return Number;
}

float GetFractionPart(float Number)
{
    return Number - (int)Number;
}

int MyFloor(float Number)
{
    int IntegerPart = (int)Number;
    float FractionalPart = GetFractionPart(Number);

    if (FractionalPart != 0)
    {
        if (Number > 0)
            return IntegerPart;

        return IntegerPart - 1;
    }

    return IntegerPart;
}

int main()
{
    float Number = ReadNumber();

    cout << "\nMy floor result: " << MyFloor(Number) << endl;
    cout << "C++ floor result: " << floor(Number) << endl;

    return 0;
}