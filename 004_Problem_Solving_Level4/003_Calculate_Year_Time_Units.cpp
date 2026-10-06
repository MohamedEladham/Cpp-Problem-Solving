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

short NumberOfDaysInYear(int Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

int NumberOfHoursInYear(int Year)
{
	return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutesInYear(int Year)
{
	return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(int Year)
{
	return NumberOfMinutesInYear(Year) * 60;
}

int main()
{
	int Year = ReadNumber("\nPlease Enter a Year To Check: ");

	cout << "\nNumber Of Days    In Year [" << Year << "] Is: ";
	cout << NumberOfDaysInYear(Year) << endl;

	cout << "Number Of Hours   In Year [" << Year << "] Is: ";
	cout << NumberOfHoursInYear(Year) << endl;

	cout << "Number Of Minutes In Year [" << Year << "] Is: ";
	cout << NumberOfMinutesInYear(Year) << endl;

	cout << "Number Of Seconds In Year [" << Year << "] Is: ";
	cout << NumberOfSecondsInYear(Year) << endl;


	return 0;
}