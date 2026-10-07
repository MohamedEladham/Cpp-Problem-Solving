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

	Date.Day = ReadNumber("Enter a Day  : ");
	Date.Month = ReadNumber("Enter a Month: ");
	Date.Year = ReadNumber("Enter a Year : ");

	return Date;
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year &&
		Date1.Month == Date2.Month &&
		Date1.Day == Date2.Day);
}

int main()
{
	stDate Date1, Date2;

	Date1 = ReadFullDate();
	Date2 = ReadFullDate();

	if (IsDate1EqualDate2(Date1, Date2))
		cout << "Yes, Date1 Is Equal To Date2 \n";
	else
		cout << "No, Date1 Is Not Equal To Date2 \n";

	return 0;
}