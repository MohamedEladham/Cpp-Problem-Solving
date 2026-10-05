#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string ClientFileName = "Client_Data.txt";

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

vector <string> SplitString(string Text, string Delimiter = "#//#")
{
	vector <string> Parts;

	short Position = 0;
	string Part = "";

	while ((Position = Text.find(Delimiter)) != std::string::npos)
	{
		Part = Text.substr(0, Position);

		if (Part != "")
		{
			Parts.push_back(Part);
		}

		Text = Text.erase(0, Position + Delimiter.length());
	}

	if (Text != "")
	{
		Parts.push_back(Text);
	}

	return Parts;
}

stClient ConvertLineToRecord(string Text)
{
	stClient Client;

	vector <string> Parts;
	Parts = SplitString(Text);

	Client.AccountNumber = Parts[0];
	Client.PinCode = Parts[1];
	Client.Name = Parts[2];
	Client.Phone = Parts[3];
	Client.AccountBalance = stod(Parts[4]);

	return Client;
}

vector <stClient> LoadClientDataFromFile(string FileName)
{
	vector <stClient> Clients;

	fstream File;
	File.open(FileName, ios::in);

	if (File.is_open())
	{
		string RecordLine;
		stClient Client;

		while (getline(File, RecordLine))
		{
			Client = ConvertLineToRecord(RecordLine);

			Clients.push_back(Client);
		}

		File.close();
	}

	return Clients;
}

string ReadClientAccountNumber()
{
	string AccountNumber;
	cout << "\n> Please Enter Account Number: ";
	getline(cin, AccountNumber);

	return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, stClient& Client)
{
	vector <stClient> Clients;
	Clients = LoadClientDataFromFile(ClientFileName);

	for (stClient& ClientRecord : Clients)
	{
		if (ClientRecord.AccountNumber == AccountNumber)
		{
			Client = ClientRecord;
			return true;
		}
	}

	return false;
}

void PrintClientCard(stClient Client)
{
	cout << "The Following Are The Client Details: \n\n";
	cout << "Account Number : " << Client.AccountNumber << endl;
	cout << "Pin Code       : " << Client.PinCode << endl;
	cout << "Name           : " << Client.Name << endl;
	cout << "Phone Number   : " << Client.Phone << endl;
	cout << "Account Balance: " << Client.AccountBalance << endl;
}

void PrintIfClientIsFoundOrNot(string AccountNumber, stClient& Client)
{
	if (FindClientByAccountNumber(AccountNumber, Client))
		PrintClientCard(Client);
	else
		cout << "\n> Client With Account Number [" << AccountNumber << "] Is Not Found. ";
}

int main()
{
	stClient Client;
	string AccountNumber;

	AccountNumber = ReadClientAccountNumber();
	cout << endl;

	PrintIfClientIsFoundOrNot(AccountNumber, Client);
	cout << endl;

	return 0;
}