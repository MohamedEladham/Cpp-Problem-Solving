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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	if (Date1.Year != Date2.Year)
		return Date1.Year < Date2.Year;

	if (Date1.Month != Date2.Month)
		return Date1.Month < Date2.Month;

	return Date1.Day < Date2.Day;
}

int main()
{
	stDate Date1, Date2;

	Date1 = ReadFullDate();
	cout << endl;

	Date2 = ReadFullDate();
	cout << endl;

	if (IsDate1BeforeDate2(Date1, Date2))
		cout << "Yes, Date1 Is Less Than Date2 \n";
	else
		cout << "No, Date1 Is Not Less Than Date2 \n";

	return 0;
}