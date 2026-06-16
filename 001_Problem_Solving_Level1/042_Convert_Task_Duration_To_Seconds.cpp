#include <iostream>
#include <string>
using namespace std;

struct stTaskDuration
{
	float Days, Hours, Minutes, Seconds;
};

float ReadPositiveNumber(string Message)
{
	float Number;

	do
	{
		cout << Message;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

stTaskDuration ReadTaskDuration()
{
	stTaskDuration TaskDuration;

	TaskDuration.Days = ReadPositiveNumber("\n> Please Enter Number Of Days: ");
	TaskDuration.Hours = ReadPositiveNumber("\n> Please Enter Number Of Hours: ");
	TaskDuration.Minutes = ReadPositiveNumber("\n> Please Enter Number Of Minutes: ");
	TaskDuration.Seconds = ReadPositiveNumber("\n> Please Enter Number Of Seconds: ");

	return TaskDuration;
}

float ConvertDurationToSeconds(stTaskDuration TaskDuration)
{
	float DurationInSeconds = 0;

	DurationInSeconds = TaskDuration.Days * 24 * 60 * 60;
	DurationInSeconds += TaskDuration.Hours * 60 * 60;
	DurationInSeconds += TaskDuration.Minutes * 60;
	DurationInSeconds += TaskDuration.Seconds;

	return DurationInSeconds;
}

int main()
{
	stTaskDuration TaskDuration = ReadTaskDuration();

	cout << "\n> Total Seconds = " << ConvertDurationToSeconds(TaskDuration) << endl;

	return 0;
}