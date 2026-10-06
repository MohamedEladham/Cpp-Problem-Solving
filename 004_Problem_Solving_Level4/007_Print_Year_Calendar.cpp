#include <iostream>
#include <iomanip>
using namespace std;


short ReadYear()
{
	short Year;
	cout << "Enter a Year: ";
	cin >> Year;
	return Year;
}

bool IsLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short DayOrderOfWeek(short Day, short Month, short Year)
{
	short a, m, y, d;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (IsLeapYear(Year) && Month == 2 ? 29 : NumberOfDays[Month - 1]);
}

string GetDayName(short DayOrder)
{
	string DayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return DayNames[DayOrder];
}

string GetMonthName(short Month)
{
	string MonthNames[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return MonthNames[Month - 1];
}

void PrintMonthCalendar(short Month, short Year)
{
	short NumberOfDays = NumberOfDaysInMonth(Month, Year);
	short DayPosition = DayOrderOfWeek(1, Month, Year);
	short Counter = DayPosition;


	cout << "\n\n";
	cout << "   __________________[" << GetMonthName(Month) << "]________________\n\n";

	cout << "   Sun   Mon   Tue   Wed   Thu   Fri   Sat   \n\n";

	for (short i = 1; i <= DayPosition; i++)
	{
		cout << "      ";
	}

	for (short j = 1; j <= NumberOfDays; j++)
	{
		cout << setw(6) << j;

		if (++Counter == 7)
		{
			cout << "\n";
			Counter = 0;
		}
	}

	cout << "\n   ________________________________________\n\n";
}

void PrintYearCalendar(short Year)
{
	cout << "\n\n";
	cout << "   _______________________________________\n\n";
	cout << "                 Calendar - " << Year << "\n";
	cout << "   _______________________________________\n\n";

	for (short i = 1; i <= 12; i++)
	{
		PrintMonthCalendar(i, Year);
	}
}

int main()
{
	short Year = ReadYear();
	PrintYearCalendar(Year);
	return 0;
}