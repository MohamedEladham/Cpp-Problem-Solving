#include <iostream>
#include <string>
using namespace std;

bool IsUpperCaseWord(string Text)
{
	for (short i = 0; i < Text.length(); i++)
	{
		if (Text.at(i) != toupper(Text.at(i)))
			return false;
	}

	return true;
}

string ReplaceWordInString(string Text, string WordToReplace, string ReplacementWord, bool IsCaseSensitive = true)
{
	short Position = 0;
	string Result = "", Word = "";
	string Delimiter = " ";

	// Text => "Country"

	// Result => "Welcome To USA , USA Is A Nice "

	if (IsCaseSensitive)
	{
		if (IsUpperCaseWord(WordToReplace))
		{
			while ((Position = Text.find(Delimiter)) != std::string::npos)
			{
				Word = Text.substr(0, Position);

				if (Word == WordToReplace)
				{
					Word = ReplacementWord;
				}

				Result += Word + Delimiter;

				Text = Text.erase(0, Position + Delimiter.length());
			}

			if (Text != "")
			{
				Result += Text;
			}
		}
		else
		{
			return Text;
		}
	}
	else
	{
		while ((Position = Text.find(Delimiter)) != std::string::npos)
		{
			Word = Text.substr(0, Position);

			if (Word == WordToReplace)
			{
				Word = ReplacementWord;
			}

			Result += Word + Delimiter;

			Text = Text.erase(0, Position + Delimiter.length());
		}

		if (Text != "")
		{
			Result += Text;
		}
	}

	return Result;
}

int main()
{
	string Text = "Welcome To Jordan , Jordan Is A Nice Country";
	string WordToReplace = "Jordan";
	string ReplacementWord = "USA";

	cout << ReplaceWordInString(Text, WordToReplace, ReplacementWord, false) << endl;

	return 0;
}