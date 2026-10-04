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

short CountEachWordInString(string Text)
{
	short Counter = 0;
	short Position = 0;
	string Word, Delimiter = " ";

	while ((Position = Text.find(Delimiter)) != std::string::npos)
	{
		Word = Text.substr(0, Position);

		if (Word != "")
		{
			Counter++;
		}

		Text.erase(0, Position + Delimiter.length());
	}

	if (Text != "")
	{
		Counter++;
	}

	return Counter;
}

int main()
{
	string Text;
	Text = ReadString("Please Enter Your String: ");

	cout << "The Number Of Words In Your String Is: ";
	cout << CountEachWordInString(Text) << endl;
	cout << endl;

	return 0;
}