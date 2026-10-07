#include <iostream>
using namespace std;

enum enDateComparison { Before = -1, Equal = 0, After = 1 };

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

enDateComparison CompareDate(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateComparison::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateComparison::Equal;

	return enDateComparison::After;
}

bool DoPeriodsOverlap(stPeriod Period1, stPeriod Period2)
{
	if (CompareDate(Period2.EndDate, Period1.StartDate) == enDateComparison::Before ||
		CompareDate(Period2.StartDate, Period1.EndDate) == enDateComparison::After)
	{
		return false;
	}

	return true;
}

int main()
{
	cout << "\nEnter Period 1: \n";
	stPeriod Period1 = ReadPeriod();

	cout << "\n_________________________\n";

	cout << "\nEnter Period 2: \n";
	stPeriod Period2 = ReadPeriod();

	if (DoPeriodsOverlap(Period1, Period2))
		cout << "\nYes, Period Overlap \n";
	else
		cout << "\nNo, Period Not Overlap \n";

	return 0;
}