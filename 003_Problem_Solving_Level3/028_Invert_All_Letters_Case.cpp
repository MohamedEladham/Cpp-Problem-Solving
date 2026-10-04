#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadName(string Prompt)
{
	string Name;
	cout << Prompt;
	getline(cin, Name);

	return Name;
}

char InvertCharacterCase(char Letter)
{
	return isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

string InvertAllLettersInString(string Text)
{
	for (int i = 0; i < Text.length(); i++)
		Text[i] = InvertCharacterCase(Text[i]);

	return Text;
}

int main()
{
	string Name;
	Name = ReadName("Please Enter Your Name: ");

	cout << "String After Inverting All Letters Case: \n";
	Name = InvertAllLettersInString(Name);
	cout << Name << endl;
	cout << endl;

	return 0;
}