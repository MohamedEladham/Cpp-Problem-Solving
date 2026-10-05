#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

const string FileName = "RecordClient.txt";

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

stClient ReadNewClient()
{
	stClient Client;

	cout << "Enter Account Number : ";
	getline(cin >> ws, Client.AccountNumber);
	cout << "Enter Pin Code       : ";
	getline(cin, Client.PinCode);
	cout << "Enter Name           : ";
	getline(cin, Client.Name);
	cout << "Enter Phone Number   : ";
	getline(cin, Client.Phone);
	cout << "Enter Account Balance: ";
	cin >> Client.AccountBalance;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Invalid Balance: \n";
		cout << "Enter Account Balance: ";
		cin >> Client.AccountBalance;
	}

	return Client;
}

string ConvertRecordToLine(stClient Client, string Delimiter = "#//#")
{
	string RecordLine = "";

	RecordLine += Client.AccountNumber + Delimiter;
	RecordLine += Client.PinCode + Delimiter;
	RecordLine += Client.Name + Delimiter;
	RecordLine += Client.Phone + Delimiter;
	RecordLine += to_string(Client.AccountBalance);

	return RecordLine;
}

void AddRecordLineToFile(string FileName, string RecordLine)
{
	fstream File;
	File.open(FileName, ios::out | ios::app);

	if (File.is_open())
	{
		File << RecordLine << endl;

		File.close();
	}
}

void AddNewClient()
{
	stClient Client;
	Client = ReadNewClient();

	AddRecordLineToFile(FileName, ConvertRecordToLine(Client));
}

void AddClients()
{
	char AddMore = 'Y';

	do
	{
		system("cls");
		cout << "\nAdd New Client: \n";
		AddNewClient();

		cout << "\n> Client Added Successfully, Do You Want To Add More Clients Y/N: ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

int main()
{
	AddClients();

	return 0;
}