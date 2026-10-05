#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReplaceWordInStringUsingBuiltInFunction(string Text, string WordToReplace, string ReplacementWord)
{
	short Position = 0;

	while ((Position = Text.find(WordToReplace)) != std::string::npos)
	{
		Text = Text.replace(Position, WordToReplace.length(), ReplacementWord);
	}

	return Text;
}

int main()
{
	string Text = "Welcome To Jordan , Jordan Is A Nice Country";
	string WordToReplace = "Jordan";
	string ReplacementWord = "USA";

	cout << "Original String: \n";
	cout << Text << endl;
	cout << endl;

	cout << "String After Replace: \n";
	cout << ReplaceWordInStringUsingBuiltInFunction(Text, WordToReplace, ReplacementWord) << endl;
	cout << endl;

	return 0;
}