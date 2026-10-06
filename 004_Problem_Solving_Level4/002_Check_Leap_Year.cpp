#include <iostream>
using namespace std;

int ReadNumber()
{
	int Year;
	cout << "\nEnter Year: ";
	cin >> Year;
	return Year;
}

bool IsLeapYear(int Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

int main()
{
	int Year;

	Year = ReadNumber();
	cout << endl;

	if (IsLeapYear(Year))
		cout << "Leap Year \n";
	else
		cout << "Not Leap Year \n";

	return 0;
}