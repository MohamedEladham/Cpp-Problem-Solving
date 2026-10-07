#include <iostream>
using namespace std;


struct stDate
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    if (Date1.Year != Date2.Year)
        return Date1.Year < Date2.Year;

    if (Date1.Month != Date2.Month)
        return Date1.Month < Date2.Month;

    return Date1.Day < Date2.Day;
}

bool IsLastDayInMonth(stDate Date)
{
    return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
}

bool IsLastMonthInYear(short Month)
{
    return Month == 12;
}

stDate IncreaseDateByOneDay(stDate Date)
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

void SwapDates(stDate& Date1, stDate& Date2)
{
    stDate TempDate;

    TempDate.Day = Date1.Day;
    TempDate.Month = Date1.Month;
    TempDate.Year = Date1.Year;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;

    Date2.Day = TempDate.Day;
    Date2.Month = TempDate.Month;
    Date2.Year = TempDate.Year;
}

int DifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    short Days = 0;
    short Sign = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        Sign = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Date1 = IncreaseDateByOneDay(Date1);
        Days++;
    }

    return IncludeEndDay ? ++Days * Sign : Days * Sign;
}

int main()
{
    stDate Date1 = ReadFullDate();

    cout << endl;

    stDate Date2 = ReadFullDate();

    cout << "\nDifference Is: ";
    cout << DifferenceInDays(Date1, Date2) << " Day(S). \n";

    cout << "\nDifference (Including End Day) Is: ";
    cout << DifferenceInDays(Date1, Date2, true) << " Day(S). \n";

    return 0;
}