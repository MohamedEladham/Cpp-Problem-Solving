#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString(string Prompt)
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

void PrintAllVowelLetters(string Text)
{
	for (int i = 0; i < Text.length(); i++)
		if (IsVowelCharacter(Text[i]))
			cout << Text[i] << "  ";
}

int main()
{
	string Text;
	Text = ReadString("Please Enter Your String: ");

	cout << "Vowels In String Are: \n";
	PrintAllVowelLetters(Text);
	cout << endl;

	return 0;
}