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

	short NumberOfDays[] =
	{
		0, 31, 28, 31, 30, 31,
		30, 31, 31, 30, 31, 30, 31
	};

	return IsLeapYear(Year) && Month == 2 ? 29 : NumberOfDays[Month];
}

bool IsValidDay(stDate Date)
{
	return Date.Day >= 1 &&
		Date.Day <= NumberOfDaysInMonth(Date.Month, Date.Year);
}

bool IsValidMonth(short Month)
{
	return Month >= 1 && Month <= 12;
}

bool IsValidYear(short Year)
{
	return Year >= 1900;
}

bool IsValidDate(stDate Date)
{
	return IsValidMonth(Date.Month) &&
		IsValidYear(Date.Year) &&
		IsValidDay(Date);
}

int main()
{
	cout << "\nEnter A Date: \n";
	stDate Date = ReadFullDate();

	if (IsValidDate(Date))
		cout << "\nYes, Date Is a Valid Date. \n";
	else
		cout << "\nNo, Date Is Not a Valid Date. \n";

	return 0;
}