#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinStrings(vector <string> Words, string Separator)
{
	string Result = "";

	for (string& Word : Words)
	{
		Result = Result + Word + Separator;
	}

	return Result.substr(0, Result.length() - Separator.length());
}

int main()
{
	vector <string> Words = { "Mohammed", "Faid", "Ali", "Maher" };

	cout << "Vector After Join: \n";
	cout << JoinStrings(Words, ", ") << endl;
	cout << endl;

	return 0;
}