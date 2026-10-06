#include <iostream>
using namespace std;


short ReadYear()
{
	short Year;
	cout << "\nEnter a Year To Check: ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month;
	cout << "Enter a Month To Check: ";
	cin >> Month;
	return Month;
}

bool IsLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	if (Month == 2)
		return IsLeapYear(Year) ? 29 : 28;

	short MonthsWith31Days[7] = { 1, 3, 5, 7, 8, 10, 12 };
	for (short i = 0; i < 7; i++)
	{
		if (MonthsWith31Days[i] == Month)
			return 31;
	}

	return 30;
}

short NumberOfHoursInMonth(short Year, short Month)
{
	return NumberOfDaysInAMonth(Year, Month) * 24;
}

int NumberOfMinutesInMonth(short Year, short Month)
{
	return NumberOfHoursInMonth(Year, Month) * 60;
}

int NumberOfSecondsInMonth(short Year, short Month)
{
	return NumberOfMinutesInMonth(Year, Month) * 60;
}


int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\n\n";
	cout << "Number Of Days       In Month [" << Month << "] Is: "
		<< NumberOfDaysInAMonth(Year, Month) << endl;
	cout << "Number Of Hours      In Month [" << Month << "] Is: "
		<< NumberOfHoursInMonth(Year, Month) << endl;
	cout << "Number Of Minutes    In Month [" << Month << "] Is: "
		<< NumberOfMinutesInMonth(Year, Month) << endl;
	cout << "Number Of Seconds    In Month [" << Month << "] Is: "
		<< NumberOfSecondsInMonth(Year, Month) << endl;

	return 0;
}