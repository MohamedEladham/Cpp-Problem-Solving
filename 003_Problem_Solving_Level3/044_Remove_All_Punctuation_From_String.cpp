#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string RemoveAllPunctuationFromString(string Text)
{
	string Result = "";

	for (int Index = 0; Index < Text.length(); Index++)
	{
		if (!ispunct(Text[Index]))
		{
			Result += Text[Index];
		}
	}

	return Result;
}

int main()
{
	string Text = "Welcome To jordan, Jordan Is A Nice Country; It's Amazing";

	cout << "Original String: \n";
	cout << Text << endl;
	cout << endl;

	cout << "Punctuations Removed: \n";
	cout << RemoveAllPunctuationFromString(Text) << endl;
	cout << endl;

	return 0;
}