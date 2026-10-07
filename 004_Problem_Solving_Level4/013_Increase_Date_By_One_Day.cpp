#include <iostream>
using namespace std;


struct stDate
{
    short Day;
    short Month;
    short Year;
};

short ReadNumber(string Message)
{
    short Number;
    cout << Message;
    cin >> Number;
    return Number;
}

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadNumber("Enter a Day  : ");
    Date.Month = ReadNumber("Enter a Month: ");
    Date.Year = ReadNumber("Enter a Year : ");

    return Date;
}

bool IsLeapYear(short Year)
{
    return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    short NumberOfDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return IsLeapYear(Year) && Month == 2 ? 29 : NumberOfDays[Month];
}

bool IsLastDayInMonth(stDate Date)
{
    return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
}

bool IsLastMonthInYear(short Month)
{
    return Month == 12;
}

stDate IncreaseDateByOneDay(stDate& Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

int main()
{
    stDate Date;
    Date = ReadFullDate();

    cout << "\n";

    cout << "Date Before Increasing By One Day: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    cout << endl;

    Date = IncreaseDateByOneDay(Date);

    cout << "Date After Increasing By One Day: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    cout << endl;

    return 0;
}