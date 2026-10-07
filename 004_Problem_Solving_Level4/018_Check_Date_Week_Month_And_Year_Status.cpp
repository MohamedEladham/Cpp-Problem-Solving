#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
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

    Date.Day = ReadNumber("\nEnter A Day: ");
    Date.Month = ReadNumber("Enter A Month: ");
    Date.Year = ReadNumber("Enter A Year : ");

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

    short NumberOfDays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return IsLeapYear(Year) && Month == 2 ? 29 : NumberOfDays[Month];
}

stDate GetDateNow()
{
    stDate Date;

    time_t t = time(0);
    tm* Now = localtime(&t);

    Date.Day = Now->tm_mday;
    Date.Month = Now->tm_mon + 1;
    Date.Year = Now->tm_year + 1900;

    return Date;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m, d;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;
}

short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string GetDayName(short DayOrder)
{
    string DayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return DayNames[DayOrder];
}

void PrintDate(stDate Date)
{
    cout << "\nToday Is " << GetDayName(DayOfWeekOrder(Date)) << ", ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

bool IsEndOfWeek(stDate Date)
{
    return GetDayName(DayOfWeekOrder(Date)) == "Sat";
}

bool IsWeekend(stDate Date)
{
    return GetDayName(DayOfWeekOrder(Date)) == "Fri" ||
        GetDayName(DayOfWeekOrder(Date)) == "Sat";
}

bool IsBusinessDay(stDate Date)
{
    return !IsWeekend(Date);
}

short DaysUntilTheEndOfWeek(stDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}

short DaysUntilEndOfMonth(stDate Date)
{
    return NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day;
}

short DaysUntilEndOfYear(stDate Date)
{
    short DifferenceInDays = 0;

    for (short i = Date.Month; i <= 12; i++)
    {
        DifferenceInDays += NumberOfDaysInMonth(i, Date.Year);
    }

    return DifferenceInDays - Date.Day;
}

int main()
{
    stDate Date = ReadFullDate();

    PrintDate(Date);

    cout << "\nIs It End Of Week? \n";

    if (IsEndOfWeek(Date))
        cout << "Yes, It Is The End Of Week \n";
    else
        cout << "No, It Is Not The End Of Week \n";

    cout << "\nIs It Weekend? \n";

    if (IsWeekend(Date))
        cout << "Yes, It Is A Weekend \n";
    else
        cout << "No, It Is Not A Weekend \n";

    cout << "\nIs It Business Day? \n";

    if (IsBusinessDay(Date))
        cout << "Yes, It Is A Business Day \n";
    else
        cout << "No, It Is Not A Business Day \n";

    cout << "\nDays Until End Of Week: ";
    cout << DaysUntilTheEndOfWeek(Date) << " Day(s). \n";

    cout << "\nDays Until End Of Month: ";
    cout << DaysUntilEndOfMonth(Date) << " Day(s). \n";

    cout << "\nDays Until End Of Year: ";
    cout << DaysUntilEndOfYear(Date) << " Day(s). \n";

    return 0;
}