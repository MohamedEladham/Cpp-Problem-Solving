#include <iostream>
#include <string>
using namespace std;

float ReadNumber(string Msg)
{
	float Number;
	cout << Msg;
	cin >> Number;
	return Number;
}

float SumNumbers()
{
	int Counter = 1;
	float Number = 0;
	float Sum = 0;

	do
	{
		Number = ReadNumber("\n> Please Enter A Number " + to_string(Counter) + ": ");

		if (Number == -99)
			break;

		Sum += Number;
		Counter++;

	} while (true);

	return Sum;
}

int main()
{
	cout << "\n> Result = " << SumNumbers() << endl;
	return 0;
}