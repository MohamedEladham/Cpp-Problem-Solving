#include <iostream>
#include <ctime>
using namespace std;

enum enRandomCharacter
{
	CapitalLetter = 1,
	SmallLetter = 2,
	Digit = 3,
	Mix = 4
};

void ShowOperationList()
{
	cout << "\n\n-------------------------------\n";
	cout << "(1) Capital Letters\n";
	cout << "(2) Small Letters\n";
	cout << "(3) Digits\n";
	cout << "(4) Mix\n";
	cout << "-------------------------------\n";
	cout << "> Choose Random Operation Type: ";
}

enRandomCharacter ReadOperationType(int From, int To)
{
	int Choice;

	do
	{
		ShowOperationList();
		cin >> Choice;

	} while (Choice < From || Choice > To);

	return (enRandomCharacter)Choice;
}

int RandomNumber(int From, int To)
{
	int RandomValue = rand() % (To - From + 1) + From;

	return RandomValue;
}

char GetRandomCharacter(enRandomCharacter CharacterType)
{
	if (CharacterType == enRandomCharacter::Mix)
	{
		CharacterType = (enRandomCharacter)RandomNumber(1, 3);
	}

	switch (CharacterType)
	{
	case enRandomCharacter::CapitalLetter:
		return char(RandomNumber(65, 90));

	case enRandomCharacter::SmallLetter:
		return char(RandomNumber(97, 122));

	case enRandomCharacter::Digit:
		return char(RandomNumber(48, 57));
	}

	return '\0';
}

int main()
{
	srand((unsigned)time(NULL));

	cout << GetRandomCharacter(enRandomCharacter::Mix) << endl;

	return 0;
}