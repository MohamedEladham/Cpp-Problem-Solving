#include <iostream>
#include <string>
using namespace std;

struct stTaskDuration
{
	int NumberOfDays;
	int NumberOfHours;
	int NumberOfMinutes;
	int NumberOfSeconds;
};

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

stTaskDuration SecondsToTaskDuration(int TotalSeconds)
{
	stTaskDuration TaskDuration;

	const int SecondsPerDay = 24 * 60 * 60;
	const int SecondsPerHour = 60 * 60;
	const int SecondsPerMinute = 60;

	int Remainder = 0;

	TaskDuration.NumberOfDays = TotalSeconds / SecondsPerDay;

	Remainder = TotalSeconds % SecondsPerDay;
	TaskDuration.NumberOfHours = Remainder / SecondsPerHour;

	Remainder = Remainder % SecondsPerHour;
	TaskDuration.NumberOfMinutes = Remainder / SecondsPerMinute;

	Remainder = Remainder % SecondsPerMinute;
	TaskDuration.NumberOfSeconds = Remainder;

	return TaskDuration;
}

void PrintTaskDuration(stTaskDuration TaskDuration)
{
	cout << "\n"
		<< TaskDuration.NumberOfDays << ":"
		<< TaskDuration.NumberOfHours << ":"
		<< TaskDuration.NumberOfMinutes << ":"
		<< TaskDuration.NumberOfSeconds << endl;
}

int main()
{
	int TotalSeconds = ReadPositiveNumber("\n> Enter Total Seconds: ");

	stTaskDuration Duration = SecondsToTaskDuration(TotalSeconds);

	PrintTaskDuration(Duration);

	return 0;
}