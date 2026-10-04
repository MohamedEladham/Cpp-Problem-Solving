#include <iostream>
#include <string>
using namespace std;

string ReadString(string Prompt)
{
	string Text;
	cout << Prompt;
	getline(cin, Text);

	return Text;
}

string TrimLeft(string Text)
{
	for (short Index = 0; Index < Text.length(); Index++)
	{
		if (Text.at(Index) != ' ')
		{
			return Text.substr(Index);
		}
	}

	return "";
}

string TrimRight(string Text)
{
	for (short Index = Text.length() - 1; Index >= 0; Index--)
	{
		if (Text.at(Index) != ' ')
		{
			return Text.substr(0, Index + 1);
		}
	}

	return "";
}

string Trim(string Text)
{
	return (TrimLeft(TrimRight(Text)));
}

int main()
{
	string Text;
	Text = "      Mohammed Nasr      ";

	cout << "Trim Left  = ";
	cout << TrimLeft(Text) << endl;
	cout << endl;

	cout << "Trim Right = ";
	cout << TrimRight(Text) << endl;
	cout << endl;

	cout << "Trim       = ";
	cout << Trim(Text) << endl;
	cout << endl;

	return 0;
}