#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadName(string Prompt)
{
	string Name;
	cout << Prompt;
	getline(cin, Name);

	return Name;
}

short NumberOfCapitalLettersOfString(string Text)
{
	short Counter = 0;

	for (short i = 0; i < Text.length(); i++)
	{
		if (isupper(Text.at(i)))
			Counter++;
	}

	return Counter;
}

short NumberOfSmallLettersOfString(string Text)
{
	short Counter = 0;

	for (short i = 0; i < Text.length(); i++)
	{
		if (islower(Text.at(i)))
			Counter++;
	}

	return Counter;
}

int main()
{
	string Name;
	Name = ReadName("Please Enter Your Name: ");

	short NameLength = Name.length();
	cout << "String Length = " << NameLength << endl;
	cout << endl;

	cout << "Capital Letters Count = ";
	cout << NumberOfCapitalLettersOfString(Name) << endl;
	cout << endl;

	cout << "Small Letters Count = ";
	cout << NumberOfSmallLettersOfString(Name) << endl;
	cout << endl;

	return 0;
}