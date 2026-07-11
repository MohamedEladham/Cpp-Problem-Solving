#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString(string Message)
{
	string Text;

	cout << Message;
	getline(cin >> ws, Text);

	return Text;
}

string UpperFirstLetterOfEachWord(string Text)
{
	bool IsFirstLetter = true;

	for (short i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ' && IsFirstLetter)
			Text[i] = toupper(Text[i]);

		IsFirstLetter = (Text[i] == ' ' ? true : false);
	}

	return Text;
}

int main()
{
	string Text;

	Text = ReadString("Please Enter Your Name: ");

	Text = UpperFirstLetterOfEachWord(Text);

	cout << Text << endl;

	cout << endl;

	return 0;
}