#include <iostream>
#include <string>
using namespace std;

float ReadNumberOfHours(string Msg)
{
	float Hours;

	do
	{
		cout << Msg;
		cin >> Hours;

	} while (Hours <= 0);

	return Hours;
}

float CalculateDays(float Hours)
{
	return Hours / 24;
}

float CalculateWeeks(float Hours)
{
	float Days = CalculateDays(Hours);
	return Days / 7;
}

int main()
{
	float Hours = ReadNumberOfHours("\n> Please Enter Number Of Hours: ");

	cout << "\n> Number Of Weeks = " << CalculateWeeks(Hours) << endl;
	cout << "\n> Number Of Days = " << CalculateDays(Hours) << endl;

	return 0;
}