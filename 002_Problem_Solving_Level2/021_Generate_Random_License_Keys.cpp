#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

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

string GetRandomKeySegment()
{
	string Segment = "";

	for (int i = 1; i <= 2; i++)
	{
		Segment += char(RandomNumber(65, 90));
	}

	return Segment;
}

void GenerateRandomKeys(int KeysCount)
{
	for (int i = 1; i <= KeysCount; i++)
	{
		cout << "> Key [" << i << "] : ";

		for (int j = 1; j <= 4; j++)
		{
			cout << GetRandomKeySegment();
			if (j < 4) cout << '-';
		}

		cout << "\n";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int KeysCount = ReadPositiveNumber("\n> How Many Keys To Generate: ");

	GenerateRandomKeys(KeysCount);

	return 0;
}