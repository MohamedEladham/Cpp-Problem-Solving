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

	return (IsLeapYear(Year) && Month == 2) ? 29 : NumberOfDays[Month];
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
	string DayNames[] =
	{
		"SunDay",
		"MonDay",
		"TuesDay",
		"WednesDay",
		"ThursDay",
		"FriDay",
		"SaturDay"
	};

	return DayNames[DayOrder];
}

bool IsWeekend(stDate Date)
{
	return GetDayName(DayOfWeekOrder(Date)) == "FriDay" ||
		GetDayName(DayOfWeekOrder(Date)) == "SaturDay";
}

bool IsBusinessDay(stDate Date)
{
	return !IsWeekend(Date);
}

short CalculateVacationDays(stDate Date1, stDate Date2)
{
	short ActualVacationDays = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		if (IsBusinessDay(Date1))
		{
			ActualVacationDays++;
		}

		Date1 = IncreaseDateByOneDay(Date1);
	}

	return ActualVacationDays;
}

int main()
{
	stDate DateFrom, DateTo;

	cout << "\nVacation Starts: \n";
	DateFrom = ReadFullDate();

	cout << "\nVacation Ends: \n";
	DateTo = ReadFullDate();

	cout << "\nVacation From: ";
	cout << GetDayName(DayOfWeekOrder(DateFrom)) << ", ";
	cout << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;

	cout << "\nVacation To: ";
	cout << GetDayName(DayOfWeekOrder(DateTo)) << ", ";
	cout << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;

	cout << "\nActual Vacation Days Is: ";
	cout << CalculateVacationDays(DateFrom, DateTo) << endl;

	return 0;
}