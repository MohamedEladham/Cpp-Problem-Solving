#include <iostream>
#include <string>

using namespace std;

string ReadName(string Message)
{
	string Name;

	cout << Message;
	getline(cin >> ws, Name);

	return Name;
}

void PrintFirstLetterOfString(string Text)
{
	bool IsFirstLetter = true;

	for (short i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ' && IsFirstLetter)
		{
			cout << Text[i] << " ";
		}

		(Text[i] == ' ') ? IsFirstLetter = true : IsFirstLetter = false;
	}
}

int main()
{
	string Text = ReadName("\nEnter The Name: ");

	PrintFirstLetterOfString(Text);

	return 0;
}