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

	cout << "\n\nEnter End Date: ";
	Period.EndDate = ReadFullDate();

	return Period;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	if (Date1.Year != Date2.Year)
		return Date1.Year < Date2.Year;

	if (Date1.Month != Date2.Month)
		return Date1.Month < Date2.Month;

	return Date1.Day < Date2.Day;
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return Date1.Year == Date2.Year &&
		Date1.Month == Date2.Month &&
		Date1.Day == Date2.Day;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return !IsDate1BeforeDate2(Date1, Date2) &&
		!IsDate1EqualDate2(Date1, Date2);
}

bool IsLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[] =
	{
		0, 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

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

bool DoPeriodsOverlap(stPeriod Period1, stPeriod Period2)
{
	if (IsDate1BeforeDate2(Period2.EndDate, Period1.StartDate) ||
		IsDate1AfterDate2(Period2.StartDate, Period1.EndDate))
	{
		return false;
	}

	return true;
}

bool IsDateWithinPeriod(stDate Date, stPeriod Period)
{
	return !(IsDate1BeforeDate2(Date, Period.StartDate) ||
		IsDate1AfterDate2(Date, Period.EndDate));
}

int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
	int Period1LengthInDays = PeriodLengthInDays(Period1, true);
	int Period2LengthInDays = PeriodLengthInDays(Period2, true);
	int OverlapDays = 0;

	if (!DoPeriodsOverlap(Period1, Period2))
		return 0;

	if (Period1LengthInDays < Period2LengthInDays)
	{
		while (!IsDate1AfterDate2(Period1.StartDate, Period1.EndDate))
		{
			if (IsDateWithinPeriod(Period1.StartDate, Period2))
				OverlapDays++;

			Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
		}
	}
	else
	{
		while (!IsDate1AfterDate2(Period2.StartDate, Period2.EndDate))
		{
			if (IsDateWithinPeriod(Period2.StartDate, Period1))
				OverlapDays++;

			Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
		}
	}

	return OverlapDays;
}

int main()
{
	cout << "\nEnter Period1: \n";
	stPeriod Period1 = ReadPeriod();

	cout << "\n----------------------\n";

	cout << "\nEnter Period2: \n";
	stPeriod Period2 = ReadPeriod();

	cout << "\nOverlap Days Count Is: ";
	cout << CountOverlapDays(Period1, Period2) << endl;

	return 0;
}