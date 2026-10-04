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

void SplitStringAndPrintEachWord(string Text)
{
	string Delimiter = " ";	// Delimiter
	short Position = 0;
	string Word;	// Define A String Variable

	// Use Find() Function To Get Position Of The Delimiters
	while ((Position = Text.find(Delimiter)) != std::string::npos)
	{
		Word = Text.substr(0, Position);	// Store The Word

		if (Word != "")
		{
			cout << Word << endl;
		}

		Text.erase(0, Position + Delimiter.length());
	}

	if (Text != "")
	{
		cout << Text << endl;	// It Prints Last Word Of The String
	}
}

int main()
{
	string Text;
	Text = ReadString("Please Enter Your String: ");

	SplitStringAndPrintEachWord(Text);
	cout << endl;

	return 0;
}