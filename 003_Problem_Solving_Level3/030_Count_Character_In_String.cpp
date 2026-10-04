#include <iostream>
#include <string>
using namespace std;

string ReadName(string Prompt)
{
	string Name;
	cout << Prompt;
	getline(cin, Name);

	return Name;
}

int CountCharacterInString(string Text, char Character)
{
	int Counter = 0;

	for (int i = 0; i < Text.length(); i++)
		if (Text[i] == Character)
			Counter++;

	return Counter;
}

int main()
{
	string Name;
	Name = ReadName("Please Enter Your Name: ");

	char Character;
	cout << "Please Enter A Character: ";
	cin >> Character;

	cout << "Letter \'" << Character << "\' Count = ";
	cout << CountCharacterInString(Name, Character) << endl;
	cout << endl;

	return 0;
}