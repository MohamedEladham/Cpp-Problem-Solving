#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadName(string Prompt)
{
	string Text;
	cout << Prompt;
	getline(cin, Text);

	return Text;
}

bool IsVowelCharacter(char Letter)
{
	Letter = tolower(Letter);

	return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
}

short CountAllVowelsInString(string Text)
{
	short Counter = 0;

	for (short i = 0; i < Text.length(); i++)
	{
		if (IsVowelCharacter(Text.at(i)))
			Counter++;
	}

	return Counter;
}

void PrintVowels(string Text)
{
	for (short i = 0; i < Text.length(); i++)
	{
		if (IsVowelCharacter(Text.at(i)))
			cout << Text.at(i) << " ";
	}
}

int main()
{
	string Text;
	Text = ReadName("Please Enter Your String: ");

	short NumOfVowels;
	NumOfVowels = CountAllVowelsInString(Text);

	cout << "Number Of Vowels Is: " << NumOfVowels << endl;
	cout << endl;

	cout << "Vowel Characters Are: ";
	PrintVowels(Text);
	cout << endl;

	return 0;
}