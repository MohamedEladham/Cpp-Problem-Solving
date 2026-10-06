#include <iostream>
using namespace std;


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

bool IsLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return IsLeapYear(Year) && Month == 2 ? 29 : NumberOfDays[Month];
}

stDate DateAfterAddedDays(short DaysAdded, stDate Date)
{
	short NumberOfDaysInMonth;

	while (DaysAdded > 0)
	{
		NumberOfDaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day == NumberOfDaysInMonth)
		{
			if (Date.Month == 12)
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}

		DaysAdded--;
	}

	return Date;
}

int main()
{
	stDate Date = ReadFullDate();
	short DaysAdded = ReadNumber("\nHow Many Days To Add: ");

	Date = DateAfterAddedDays(DaysAdded, Date);

	cout << "\nDate After Adding [" << DaysAdded << "] Days Is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	cout << endl;

	return 0;
}