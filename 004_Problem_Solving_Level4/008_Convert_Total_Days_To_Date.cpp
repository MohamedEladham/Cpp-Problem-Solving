#include <iostream>
using namespace std;


struct stDate
{
	short Year;
	short Month;
	short Day;
};

short ReadYear()
{
	short Year;
	cout << "Enter a Year: ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month;
	cout << "Enter a Month: ";
	cin >> Month;
	return Month;
}

short ReadDay()
{
	short Day;
	cout << "Enter a Day: ";
	cin >> Day;
	return Day;
}

bool IsLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (IsLeapYear(Year) && Month == 2) ? 29 : NumberOfDays[Month];
}

short TotalDaysFromBeginningOfYear(short Day, short Month, short Year)
{
	short TotalDays = 0;

	for (short i = 1; i < Month; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Year);
	}

	return TotalDays + Day;
}

stDate ConvertTotalDaysToDate(short TotalDays, short Year)
{
	stDate Date;
	short Month = 1;
	short NumberOfDaysInMonth;

	while (true)
	{
		NumberOfDaysInMonth = NumberOfDaysInMonth(Month, Year);

		if (TotalDays > NumberOfDaysInMonth)
		{
			TotalDays -= NumberOfDaysInMonth;
			Month++;
		}
		else
		{
			Date.Day = TotalDays;
			break;
		}
	}

	Date.Month = Month;
	Date.Year = Year;

	return Date;
}

int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short TotalDays = TotalDaysFromBeginningOfYear(Day, Month, Year);

	stDate Date;
	Date = ConvertTotalDaysToDate(TotalDays, Year);

	cout << "\n\n";
	cout << "Number Of Days From The Beginning Of The Year Is: "
		<< TotalDays << endl;
	cout << endl;

	cout << "Date For [" << TotalDays << "] Is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	cout << endl;

	return 0;
}