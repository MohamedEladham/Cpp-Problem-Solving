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

int main()
{
	stDate Date1, Date2;

	Date1 = ReadFullDate();

	cout << endl;

	Date2 = ReadFullDate();

	if (IsDate1AfterDate2(Date1, Date2))
		cout << "\nYes, Date1 Is After Date2 \n";
	else
		cout << "\nNo, Date1 Is Not After Date2 \n";

	return 0;
}