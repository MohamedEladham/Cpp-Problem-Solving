#include <iostream>
#include <limits>
using namespace std;


int ReadNumber(string Message)
{
	int Number;
	cout << Message;
	cin >> Number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalid Number, Please Try Again: \n";
		cout << Message;
		cin >> Number;
	}

	return Number;
}

bool IsLeapYear(int Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short DayOrderOfWeek(short Day, short Month, short Year)
{
	short a, y, m, d;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string DaysShortName(short DayOrder)
{
	string DayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return DayName[DayOrder];
}

int main()
{
	short Day = ReadNumber("\nPlease Enter a Day: ");
	short Month = ReadNumber("\nPlease Enter a Month: ");
	short Year = ReadNumber("\nPlease Enter a Year: ");


	cout << "\nDate   : ";
	cout << Day << "/" << Month << "/" << Year << endl;

	cout << "Day Order: ";
	cout << DayOrderOfWeek(Day, Month, Year) << endl;

	cout << "Day Name : ";
	cout << DaysShortName(DayOrderOfWeek(Day, Month, Year)) << endl;

	return 0;
}