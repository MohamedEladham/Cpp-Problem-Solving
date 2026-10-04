#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString(string Prompt)
{
	string Text;
	cout << Prompt;
	getline(cin, Text);

	return Text;
}

vector <string> SplitString(string Text, string Delimiter)
{
	vector <string> Words;

	short Position = 0;
	string Word;

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

void PrintWords(vector <string> Words)
{
	cout << "Tokens: " << Words.size() << endl;
	cout << endl;

	for (string& Word : Words)
	{
		cout << Word << endl;
	}
}

int main()
{
	string Text;
	Text = ReadString("Please Enter Your String: ");

	vector <string> Words;
	Words = SplitString(Text, " ");

	PrintWords(Words);

	return 0;
}