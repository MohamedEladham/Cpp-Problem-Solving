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

string UpperAllLettersOfString(string Text)
{
	for (short i = 0; i < Text.length(); i++)
		Text[i] = toupper(Text[i]);

	return Text;
}

string LowerAllLettersOfString(string Text)
{
	for (short i = 0; i < Text.length(); i++)
		Text[i] = tolower(Text[i]);

	return Text;
}

int main()
{
	string Name;
	Name = ReadName("Please Enter Your Name: ");

	cout << "String After Upper: \n";
	Name = UpperAllLettersOfString(Name);
	cout << Name << endl;
	cout << endl;

	cout << "String After Lower: \n";
	Name = LowerAllLettersOfString(Name);
	cout << Name << endl;
	cout << endl;

	return 0;
}
```
