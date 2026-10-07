#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

string ReadDateString()
{
	string DateString;

	cout << "\nPlease Enter Date dd/mm/yyyy: ";
	getline(cin, DateString);

	return DateString;
}

vector<string> SplitString(string S1, string Delimiter = "/")
{
	vector<string> DateParts;

	size_t Position = 0;
	string Part = "";

	while ((Position = S1.find(Delimiter)) != S1.npos)
	{
		Part = S1.substr(0, Position);

		if (Part != "")
		{
			DateParts.push_back(Part);
		}

		S1 = S1.erase(0, Position + Delimiter.length());
	}

	if (S1 != "")
	{
		DateParts.push_back(S1);
	}

	return DateParts;
}

stDate ConvertStringToDate(string DateString)
{
	stDate Date;

	vector<string> DateParts;
	DateParts = SplitString(DateString);

	Date.Day = stoi(DateParts[0]);
	Date.Month = stoi(DateParts[1]);
	Date.Year = stoi(DateParts[2]);

	return Date;
}

void PrintDate(stDate Date)
{
	cout << "\nDay  : " << Date.Day << endl;
	cout << "Month: " << Date.Month << endl;
	cout << "Year : " << Date.Year << endl;
}

string ConvertDateToString(stDate Date, string Delimiter = "/")
{
	string DateString = "";

	DateString += to_string(Date.Day) + Delimiter;
	DateString += to_string(Date.Month) + Delimiter;
	DateString += to_string(Date.Year);

	return DateString;
}

int main()
{
	string DateString = ReadDateString();

	stDate Date;
	Date = ConvertStringToDate(DateString);

	PrintDate(Date);

	cout << "\nYour Entered: ";
	cout << ConvertDateToString(Date) << endl;

	return 0;
}