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

stDate IncreaseDateByXDays(stDate Date, short Days)
{
    for (short i = 1; i <= Days; i++)
        Date = IncreaseDateByOneDay(Date);

    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
    const short Week = 7;

    for (short i = 1; i <= Week; i++)
        Date = IncreaseDateByOneDay(Date);

    return Date;
}

stDate IncreaseDateByXWeeks(stDate Date, short Weeks)
{
    for (short i = 1; i <= Weeks; i++)
        Date = IncreaseDateByOneWeek(Date);

    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }

    short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

    if (Date.Day > DaysInMonth)
        Date.Day = DaysInMonth;

    return Date;
}

stDate IncreaseDateByXMonths(stDate Date, short Months)
{
    for (short i = 1; i <= Months; i++)
        Date = IncreaseDateByOneMonth(Date);

    return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;

    short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

    if (Date.Day > DaysInMonth)
        Date.Day = DaysInMonth;

    return Date;
}

stDate IncreaseDateByXYears(stDate Date, short Years)
{
    for (short i = 1; i <= Years; i++)
        Date = IncreaseDateByOneYear(Date);

    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
    const short Decade = 10;

    for (short i = 1; i <= Decade; i++)
        Date = IncreaseDateByOneYear(Date);

    return Date;
}

stDate IncreaseDateByXDecades(stDate Date, short Decades)
{
    for (short i = 1; i <= Decades; i++)
        Date = IncreaseDateByOneDecade(Date);

    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
    const short Century = 100;

    for (short i = 1; i <= Century; i++)
        Date = IncreaseDateByOneYear(Date);

    return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
    const short Millennium = 1000;

    for (short i = 1; i <= Millennium; i++)
        Date = IncreaseDateByOneYear(Date);

    return Date;
}

int main()
{
    stDate Date = ReadFullDate();

    cout << "\n\nDate After: \n\n";

    Date = IncreaseDateByOneDay(Date);
    cout << "01- Adding One Day Is       : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDays(Date, 10);
    cout << "02- Adding 10 Days Is       : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneWeek(Date);
    cout << "03- Adding One Week Is      : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXWeeks(Date, 10);
    cout << "04- Adding 10 Weeks Is      : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneMonth(Date);
    cout << "05- Adding One Month Is     : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXMonths(Date, 3);
    cout << "06- Adding 3 Months Is      : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneYear(Date);
    cout << "07- Adding One Year Is      : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYears(Date, 10);
    cout << "08- Adding 10 Years Is      : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneDecade(Date);
    cout << "09- Adding One Decade Is    : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecades(Date, 10);
    cout << "10- Adding 10 Decades Is    : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneCentury(Date);
    cout << "11- Adding One Century Is   : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneMillennium(Date);
    cout << "12- Adding One Millennium Is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    return 0;
}