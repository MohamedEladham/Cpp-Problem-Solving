#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enCharacterType
{
	CapitalLetters = 1,
	SmallLetters = 2,
	SpecialCharacter = 3,
	Digit = 4
};

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

char GetRandomChar(enCharacterType Type)
{
	switch (Type)
	{
	case CapitalLetters:
		return (char)RandomNumber(65, 90);

	case SmallLetters:
		return (char)RandomNumber(97, 122);

	case SpecialCharacter:
		return (char)RandomNumber(37, 47);

	case Digit:
		return (char)RandomNumber(48, 57);

	default:
		return char();
	}
}

string GenerateWord(enCharacterType Type, short Length)
{
	string Word = "";

	for (int i = 0; i < Length; i++)
	{
		Word += GetRandomChar(Type);
	}

	return Word;
}

string GenerateFormattedKey()
{
	string Key = "";

	Key += GenerateWord(Digit, 4) + "-";
	Key += GenerateWord(Digit, 4) + "-";
	Key += GenerateWord(Digit, 4) + "-";
	Key += GenerateWord(Digit, 4);

	return Key;
}

void FillArrayWithRandomKeys(string KeysArray[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		KeysArray[i] = GenerateFormattedKey();
	}
}

void PrintArray(string KeysArray[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		cout << "> Key [" << i << "] : " << KeysArray[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int ArraySize = ReadPositiveNumber("\n> Enter Number Of Keys: ");

	string KeysArray[100];

	FillArrayWithRandomKeys(KeysArray, ArraySize);

	cout << "\n> Generated Keys:\n";
	PrintArray(KeysArray, ArraySize);

	return 0;
}