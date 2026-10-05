#include <iostream>
#include <string>
using namespace std;

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double AccountBalance;
};

stClient ReadClientInfo()
{
	stClient Client;

	cout << "Enter Account Number: ";
	getline(cin, Client.AccountNumber);
	cout << "Enter PinCode: ";
	getline(cin, Client.PinCode);
	cout << "Enter Name: ";
	getline(cin, Client.Name);
	cout << "Enter Phone: ";
	getline(cin, Client.PhoneNumber);
	cout << "Enter Account Balance: ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(stClient Client, string Delimiter = "#//#")
{
	string Record = "";

	Record += Client.AccountNumber + Delimiter;
	Record += Client.PinCode + Delimiter;
	Record += Client.Name + Delimiter;
	Record += Client.PhoneNumber + Delimiter;
	Record += to_string(Client.AccountBalance);

	return Record;
}

int main()
{
	stClient Client;
	Client = ReadClientInfo();
	cout << endl;

	cout << "Client Record For Saving Is: \n";
	cout << ConvertRecordToLine(Client) << endl;
	cout << endl;

	return 0;
}