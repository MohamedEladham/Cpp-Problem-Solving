#include <iostream>
#include <cctype>
#include <string>
using namespace std;

char ReadCharacter()
{
	char Letter;
	cout << "Please Enter A Character: ";
	cin >> Letter;
	return Letter;
}

bool IsVowelCharacter(char Letter)
{
	Letter = tolower(Letter);

	return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
}

int main()
{
	char Letter = ReadCharacter();

	if (IsVowelCharacter(Letter))
		cout << "YES, Letter \'" << Letter << "\' Is Vowel \n" << endl;
	else
		cout << "No, Letter \'" << Letter << "\' Is Not Vowel \n" << endl;


	return 0;
}