#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string> Words, string Separator)
{
	string Result = "";

	for (string& Word : Words)
	{
		Result = Result + Word + Separator;
	}

	return Result.substr(0, Result.length() - Separator.length());
}

string JoinString(string Names[], short Count, string Delimiter)
{
	string Result = "";

	for (short Index = 0; Index < Count; Index++)
	{
		Result = Result + Names[Index] + Delimiter;
	}

	return Result.substr(0, Result.length() - Delimiter.length());
}

int main()
{
	vector <string> Words = { "Mohammed", "Faid", "Ali", "Maher" };
	string Names[] = { "Mohammed", "Faid", "Ali", "Maher", "Ahmmed" };
	short Count = size(Names);

	cout << "Vector After Join: \n";
	cout << JoinString(Words, ", ") << endl;
	cout << endl;

	cout << "Array After Join: \n";
	cout << JoinString(Names, Count, ", ") << endl;
	cout << endl;

	return 0;
}