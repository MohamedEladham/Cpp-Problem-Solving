#include <iostream>
#include <string>
using namespace std;

enum enWeekDays
{
	Sunday = 1,
	Monday = 2,
	Tuesday = 3,
	Wednesday = 4,
	Thursday = 5,
	Friday = 6,
	Saturday = 7
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

enWeekDays ReadDayOfWeek()
{
	return (enWeekDays)ReadNumberInRange("\n> Please Enter A Week Number Between 1 To 7: ", 1, 7);
}

string GetDayOfWeek(enWeekDays WeekDay)
{
	switch (WeekDay)
	{
	case enWeekDays::Sunday: return "Sunday";
	case enWeekDays::Monday: return "Monday";
	case enWeekDays::Tuesday: return "Tuesday";
	case enWeekDays::Wednesday: return "Wednesday";
	case enWeekDays::Thursday: return "Thursday";
	case enWeekDays::Friday: return "Friday";
	case enWeekDays::Saturday: return "Saturday";

	default: return "Invalid Day";
	}
}

void PrintDay(string Day)
{
	cout << "\n> The Day Is " << Day << endl;
}

int main()
{
	PrintDay(GetDayOfWeek(ReadDayOfWeek()));
	return 0;
}