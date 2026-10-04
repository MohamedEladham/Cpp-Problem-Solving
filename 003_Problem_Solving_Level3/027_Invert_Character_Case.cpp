#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char ReadChar()
{
	char Character;
	cout << "Please Enter A Character: ";
	cin >> Character;

	return Character;
}

char InvertCharacterCase(char Letter)
{
	return isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

int main()
{
	char Character;
	Character = ReadChar();

	Character = InvertCharacterCase(Character);
	cout << Character << endl;
	cout << endl;

	return 0;
}