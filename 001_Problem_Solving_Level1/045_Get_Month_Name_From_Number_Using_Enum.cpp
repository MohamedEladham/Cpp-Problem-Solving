#include <iostream>
#include <string>
using namespace std;

enum enMonthOfYear
{
	January = 1,
	February = 2,
	March = 3,
	April = 4,
	May = 5,
	June = 6,
	July = 7,
	August = 8,
	September = 9,
	October = 10,
	November = 11,
	December = 12
};

int ReadNumberInRange(string Message, int From, int To)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;

	} while (Number < From || Number > To);

	return Number;
}

enMonthOfYear ReadMonthOfYear()
{
	return (enMonthOfYear)ReadNumberInRange("\n> Please Enter A Number Between 1 To 12: ", 1, 12);
}

string GetMonthOfYear(enMonthOfYear Month)
{
	switch (Month)
	{
	case enMonthOfYear::January: return "January";
	case enMonthOfYear::February: return "February";
	case enMonthOfYear::March: return "March";
	case enMonthOfYear::April: return "April";
	case enMonthOfYear::May: return "May";
	case enMonthOfYear::June: return "June";
	case enMonthOfYear::July: return "July";
	case enMonthOfYear::August: return "August";
	case enMonthOfYear::September: return "September";
	case enMonthOfYear::October: return "October";
	case enMonthOfYear::November: return "November";
	case enMonthOfYear::December: return "December";

	default: return "Invalid Month";
	}
}

void PrintMonth(string Month)
{
	cout << "\n> The Month Is: " << Month << endl;
}

int main()
{
	PrintMonth(GetMonthOfYear(ReadMonthOfYear()));
	return 0;
}