#include <iostream>
using namespace std;

enum enDateComparison { Before = -1, Equal = 0, After = 1 };

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

int main()
{
	cout << "\nEnter Date1: \n";
	stDate Date1 = ReadFullDate();

	cout << "\nEnter Date2: \n";
	stDate Date2 = ReadFullDate();

	cout << "\nCompare Result = ";
	cout << CompareDate(Date1, Date2) << endl;

	return 0;
}