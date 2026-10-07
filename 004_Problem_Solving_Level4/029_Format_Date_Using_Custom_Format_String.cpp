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

vector<string> SplitString(string String, string Delimiter = "/")
{
	vector<string> StringParts;

	size_t Position = 0;
	string Part = "";

	while ((Position = String.find(Delimiter)) != String.npos)
	{
		Part = String.substr(0, Position);

		if (Part != "")
		{
			StringParts.push_back(Part);
		}

		String = String.erase(0, Position + Delimiter.length());
	}

	if (String != "")
	{
		StringParts.push_back(String);
	}

	return StringParts;
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

string ReplaceWordInStringUsingBuiltInFunction(
	string String,
	string ToReplace,
	string ReplaceWith)
{
	size_t Position = 0;

	while ((Position = String.find(ToReplace)) != string::npos)
	{
		String = String.replace(
			Position,
			ToReplace.length(),
			ReplaceWith);
	}

	return String;
}

string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormattedDateString = "";

	FormattedDateString =
		ReplaceWordInStringUsingBuiltInFunction(
			DateFormat,
			"dd",
			to_string(Date.Day));

	FormattedDateString =
		ReplaceWordInStringUsingBuiltInFunction(
			FormattedDateString,
			"mm",
			to_string(Date.Month));

	FormattedDateString =
		ReplaceWordInStringUsingBuiltInFunction(
			FormattedDateString,
			"yyyy",
			to_string(Date.Year));

	return FormattedDateString;
}

int main()
{
	string DateString = ReadDateString();

	stDate Date = ConvertStringToDate(DateString);

	cout << "\n" << FormatDate(Date) << "\n";
	cout << "\n" << FormatDate(Date, "yyyy/mm/dd") << "\n";
	cout << endl
		<< FormatDate(Date, "Month:mm, Day:dd, Year:yyyy")
		<< endl;

	return 0;
}