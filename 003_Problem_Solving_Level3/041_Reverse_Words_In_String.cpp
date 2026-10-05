#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString(string Prompt)
{
	string Name;
	cout << Prompt;
	getline(cin, Name);

	return Name;
}

vector <string> SplitString(string Text, string Delimiter)
{
	vector <string> Words;

	string Word = "";
	short Position = 0;

	while ((Position = Text.find(Delimiter)) != std::string::npos)
	{
		Word = Text.substr(0, Position);

		if (Word != "")
		{
			Words.push_back(Word);
		}

		Text.erase(0, Position + Delimiter.length());
	}

	if (Text != "")
	{
		Words.push_back(Text);
	}

	return Words;
}

string ReverseWordsInString(string Text)
{
	vector <string> Words;
	Words = SplitString(Text, " ");

	string ReversedText = "";

	vector <string>::iterator Iterator = Words.end();

	while (Iterator != Words.begin())
	{
		Iterator--;

		ReversedText += *Iterator + " ";
	}

	ReversedText = ReversedText.substr(0, ReversedText.length() - 1);

	return ReversedText;
}

int main()
{
	string Text;
	Text = ReadString("Please Enter Your String: ");
	cout << endl;

	cout << "String After Reversing Words: \n";
	cout << ReverseWordsInString(Text) << endl;
	cout << endl;

	return 0;
}