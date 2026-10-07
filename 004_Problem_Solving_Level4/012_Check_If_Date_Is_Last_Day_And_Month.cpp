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

int main()
{
    stDate Date;
    Date = ReadFullDate();

    if (IsLastDayInMonth(Date))
        cout << "Yes, Day Is Last Day In Month \n";
    else
        cout << "No, Day Is Not Last Day In Month \n";

    if (IsLastMonthInYear(Date.Month))
        cout << "Yes, Month Is Last Month In Year \n";
    else
        cout << "No, Month Is Not Last Month In Year \n";

    return 0;
}