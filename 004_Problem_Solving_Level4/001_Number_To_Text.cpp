#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "\nEnter a Number: ";
	cin >> Number;
	return Number;
}

string NumberToText(int Number)
{
	if (Number == 0)
	{
		return "";
	}

	if (Number >= 1 && Number <= 19)
	{
		string Words[] =
		{
			"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
			"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
			"Eighteen", "Nineteen"
		};
		return Words[Number];
	}

	if (Number >= 20 && Number <= 99)
	{
		string Words[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

		return Words[Number / 10] + " " + NumberToText(Number % 10);
	}

	if (Number >= 100 && Number <= 999)
	{
		return NumberToText(Number / 100) + " Hundreds " + NumberToText(Number % 100);
	}

	if (Number >= 1000 && Number <= 1999)
	{
		return "One Thousand " + NumberToText(Number % 1000);
	}

	if (Number >= 2000 && Number <= 999999)
	{
		return NumberToText(Number / 1000) + " Thousands " + NumberToText(Number % 1000);
	}

	if (Number >= 1000000 && Number <= 1999999)
	{
		return "One Million " + NumberToText(Number % 1000000);
	}

	if (Number >= 2000000 && Number <= 999999999)
	{
		return NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000);
	}

	if (Number >= 1000000000 && Number <= 1999999999)
	{
		return "One Billion " + NumberToText(Number % 1000000000);
	}
	else
	{
		return NumberToText(Number / 1000000000) + " Billion " + NumberToText(Number % 1000000000);
	}
}

int main()
{
	int Number = ReadNumber();
	cout << NumberToText(Number) << endl;
	cout << endl;
	return 0;
}