#include <iostream>
#include <string>
using namespace std;

const string CORRECT_PIN = "123";
const float ACCOUNT_BALANCE = 7500;

string ReadPINCode()
{
	string PinCode;

	cout << "\n> Please Enter Pin Code: ";
	cin >> PinCode;

	return PinCode;
}

bool AuthenticateUser()
{
	string PinCode;
	int Counter = 3;

	do
	{
		Counter--;
		PinCode = ReadPINCode();

		if (PinCode == CORRECT_PIN)
		{
			return true;
		}
		else
		{
			system("Color 4F");
			cout << "\n> Wrong PIN, You have " << Counter << " More Tries.\n";
		}

	} while (Counter >= 1 && PinCode != CORRECT_PIN);

	return false;
}

void ShowLoginResult()
{
	if (AuthenticateUser())
	{
		system("Color 2F");
		cout << "\n> Your Account Balance IS: " << ACCOUNT_BALANCE << endl;
	}
	else
	{
		system("Color 3F");
		cout << "\n> Your Card Is Blocked, Contact The Bank.\n";
	}
}

int main()
{
	ShowLoginResult();
	return 0;
}