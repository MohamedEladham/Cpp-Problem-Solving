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

char InvertCharacter(char Letter)
{
	return isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

short CountCharacter(string Text, char Letter, bool IsCaseSensitive = true)
{
	short Counter = 0;

	for (short i = 0; i < Text.length(); i++)
	{
		if (IsCaseSensitive)
		{
			if (Text[i] == Letter)
				Counter++;
		}
		else
		{
			if (tolower(Letter) == tolower(Text[i]))
				Counter++;
		}
	}

	return Counter;
}

int main()
{
	string Name;
	Name = ReadName("Please Enter Your Name: ");

	char Letter;
	cout << "Please Enter A Character: ";
	cin >> Letter;
	cout << endl;


	cout << "Letter \'" << Letter << "\' Count = ";
	cout << CountCharacter(Name, Letter) << endl;
	cout << endl;

	cout << "Letter \'" << Letter << "\' Or \'" <<
		InvertCharacter(Letter) << "\' Count = " <<
		CountCharacter(Name, Letter, false) << endl;
	cout << endl;

	return 0;
}