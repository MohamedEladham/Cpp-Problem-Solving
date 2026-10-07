#include <iostream>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
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

stPeriod ReadPeriod()
{
	stPeriod Period;

	cout << "Enter Start Date: \n";
	Period.StartDate = ReadFullDate();

	cout << "\n\nEnter End Date: \n";
	Period.EndDate = ReadFullDate();

	cout << endl;

	return Period;
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

bool IsLastMonthOfYear(short Month)
{
	return Month == 12;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	if (Date1.Year != Date2.Year)
		return Date1.Year < Date2.Year;

	if (Date1.Month != Date2.Month)
		return Date1.Month < Date2.Month;

	return Date1.Day < Date2.Day;
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthOfYear(Date.Month))
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

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int DifferenceInDays = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		DifferenceInDays++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludeEndDay ? ++DifferenceInDays : DifferenceInDays;
}

int PeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false)
{
	return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}

int main()
{
	stPeriod Period = ReadPeriod();

	cout << "\nPeriod Length Is: ";
	cout << PeriodLengthInDays(Period) << endl;

	cout << "\nPeriod Length (Include End Day) Is: ";
	cout << PeriodLengthInDays(Period, true) << endl;

	return 0;
}