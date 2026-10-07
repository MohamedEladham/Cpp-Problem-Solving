#include <iostream>
#include <limits>
using namespace std;


struct stDate
{
    short Day;
    short Month;
    short Year;
};

int ReadNumber(string Message)
{
    int Number;
    cout << Message;
    cin >> Number;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid Number, Please Try Again: \n";
        cout << Message;
        cin >> Number;
    }

    return Number;
}

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadNumber("\nPlease Enter a Day: ");
    Date.Month = ReadNumber("\nPlease Enter a Month: ");
    Date.Year = ReadNumber("\nPlease Enter a Year: ");

    return Date;
}

bool IsLeapYear(int Year)
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

stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }

    return Date;
}

stDate DecreaseDateByXDays(stDate Date, short Days)
{
    for (short i = 1; i <= Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

stDate DecreaseDateByXWeeks(stDate Date, short Weeks)
{
    for (short i = 1; i <= Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }

    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }

    short NumberOfDays = NumberOfDaysInMonth(Date.Month, Date.Year);

    if (Date.Day > NumberOfDays)
        Date.Day = NumberOfDays;

    return Date;
}

stDate DecreaseDateByXMonths(stDate Date, short Months)
{
    for (short i = 1; i <= Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }

    return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
    Date.Year--;

    short NumberOfDays = NumberOfDaysInMonth(Date.Month, Date.Year);

    if (Date.Day > NumberOfDays)
        Date.Day = NumberOfDays;

    return Date;
}

stDate DecreaseDateByXYears(stDate Date, short Years)
{
    for (short i = 1; i <= Years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date, short Years)
{
    Date.Year -= Years;

    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
    for (short i = 1; i <= 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

stDate DecreaseDateByXDecades(stDate Date, short Decades)
{
    for (short i = 1; i <= Decades; i++)
    {
        Date = DecreaseDateByOneDecade(Date);
    }

    return Date;
}

stDate DecreaseDateByXDecadesFaster(stDate Date, short Decades)
{
    Date.Year -= Decades * 10;

    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
    for (short i = 1; i <= 100; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
    for (short i = 1; i <= 1000; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

int main()
{
    stDate Date = ReadFullDate();

    cout << "\n\nDate After: \n\n";

    Date = DecreaseDateByOneDay(Date);
    cout << "01- Subtracting One Day Is        : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDays(Date, 10);
    cout << "02- Subtracting 10 Days Is       : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneWeek(Date);
    cout << "03- Subtracting One Week Is      : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXWeeks(Date, 10);
    cout << "04- Subtracting 10 Weeks Is      : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneMonth(Date);
    cout << "05- Subtracting One Month Is     : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXMonths(Date, 5);
    cout << "06- Subtracting 5 Months Is      : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneYear(Date);
    cout << "07- Subtracting One Year Is      : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYears(Date, 10);
    cout << "08- Subtracting 10 Years Is      : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYearsFaster(Date, 10);
    cout << "09- Subtracting 10 Years (Faster) Is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneDecade(Date);
    cout << "10- Subtracting One Decade Is    : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecades(Date, 10);
    cout << "11- Subtracting 10 Decades Is    : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecadesFaster(Date, 10);
    cout << "12- Subtracting 10 Decades (Faster) Is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneCentury(Date);
    cout << "13- Subtracting One Century Is   : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneMillennium(Date);
    cout << "14- Subtracting One Millennium Is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    return 0;
}