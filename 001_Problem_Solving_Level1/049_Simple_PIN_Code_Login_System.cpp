#include <iostream>
#include <string>
using namespace std;

const string CORRECT_PIN = "K9003174";
const float ACCOUNT_BALANCE = 7500;

string ReadPinCode()
{
	string PinCode;

	cout << "\n> Please Enter Pin Code: ";
	cin >> PinCode;

	return PinCode;
}

bool AuthenticateUser()
{
	string PinCode = ReadPinCode();

	if (PinCode == CORRECT_PIN)
	{
		return true;
	}
	else
	{
		system("Color 4F");
		cout << "\n> Wrong PIN Code\n";
		return false;
	}
}

void ShowAccountInfo()
{
	if (AuthenticateUser())
	{
		system("Color 2F");

		cout << "\n--------------------------------------\n";
		cout << "> Your Account Balance Is: " << ACCOUNT_BALANCE << endl;
	}
}

int main()
{
	ShowAccountInfo();
	return 0;
}