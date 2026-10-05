#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

const string ClientFileName = "T.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

vector <string> SplitString(string Text, string Delimiter = "#//#")
{
	vector <string> Parts;

	short Position = 0;
	string Part = "";

	while ((Position = Text.find(Delimiter)) != Text.npos)
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

sClient ConvertLineToRecord(string Text)
{
	sClient Client;

	vector <string> Parts;
	Parts = SplitString(Text);

	Client.AccountNumber = Parts[0];
	Client.PinCode = Parts[1];
	Client.Name = Parts[2];
	Client.Phone = Parts[3];
	Client.AccountBalance = stod(Parts[4]);

	return Client;
}

vector <sClient> LoadClientDataFromFile(string FileName)
{
	vector <sClient> Clients;

	fstream File;
	File.open(FileName, ios::in);

	if (File.is_open())
	{
		string RecordLine;
		sClient Client;

		while (getline(File, RecordLine))
		{
			Client = ConvertLineToRecord(RecordLine);

			Clients.push_back(Client);
		}

		File.close();
	}

	return Clients;
}

void PrintClientCard(sClient Client)
{
	cout << "The Following Are The Client Details: \n\n";
	cout << "Account Number : " << Client.AccountNumber << endl;
	cout << "Pin Code       : " << Client.PinCode << endl;
	cout << "Name           : " << Client.Name << endl;
	cout << "Phone Number   : " << Client.Phone << endl;
	cout << "Account Balance: " << Client.AccountBalance << endl;
}

string ReadClientAccountNumber()
{
	string AccountNumber;
	cout << "\n> Please Enter Account Number: ";
	getline(cin, AccountNumber);

	return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient>& Clients, sClient& Client)
{
	for (sClient& ClientRecord : Clients)
	{
		if (ClientRecord.AccountNumber == AccountNumber)
		{
			Client = ClientRecord;
			return true;
		}
	}

	return false;
}

sClient ChangeClientRecord(string AccountNumber, string Name)
{
	sClient Client;

	Client.AccountNumber = AccountNumber;
	Client.Name = Name;

	cout << "\n\nEnter Pin Code: ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Phone   : ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance: ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(sClient Client, string Delimiter = "#//#")
{
	string RecordLine = "";

	RecordLine += Client.AccountNumber + Delimiter;
	RecordLine += Client.PinCode + Delimiter;
	RecordLine += Client.Name + Delimiter;
	RecordLine += Client.Phone + Delimiter;
	RecordLine += to_string(Client.AccountBalance);

	return RecordLine;
}

void UpdateClient(string AccountNumber, vector <sClient>& Clients)
{
	for (sClient& Client : Clients)
	{
		if (Client.AccountNumber == AccountNumber)
		{
			Client = ChangeClientRecord(Client.AccountNumber, Client.Name);
			return;
		}
	}
}

void SaveClientUpdateToFile(string FileName, vector <sClient>& Clients)
{
	fstream File;
	File.open(FileName, ios::out);

	string RecordLine;

	if (File.is_open())
	{
		for (sClient& Client : Clients)
		{
			RecordLine = ConvertRecordToLine(Client);

			File << RecordLine << endl;
		}

		File.close();
	}
}

void UpdateClientRecordByAccountNumber(string AccountNumber, vector <sClient>& Clients)
{
	sClient Client;
	char Answer;

	if (FindClientByAccountNumber(AccountNumber, Clients, Client))
	{
		PrintClientCard(Client);

		cout << "\n> Are You Sure You Want Update This Client Y/N: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			UpdateClient(AccountNumber, Clients);
			SaveClientUpdateToFile(ClientFileName, Clients);

			cout << "\n> Client Updated Successfully. \n\n";
		}
	}
	else
	{
		cout << "\n> Client With Account Number [" << AccountNumber << "] Is Not Found. \n\n";
	}
}

void PrintClientRecord(sClient Client)
{
	cout << "| " << left << setw(17) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(27) << Client.Name;
	cout << "| " << left << setw(15) << Client.Phone;
	cout << "| " << left << setw(9) << Client.AccountBalance;
}

void PrintAllClientsData(vector <sClient> Clients)
{
	cout << "                                Client List (" << Clients.size() << ") Client(s)      \n";
	cout << "_______________________________________________________________________________________\n\n";
	cout << "| " << left << setw(17) << "Account Number" << "| " << left << setw(10) << "Pin Code" << "| " <<
		left << setw(27) << "Client Name" << "| " << left << setw(15) << "Phone" << "| " <<
		left << setw(9) << "Balance \n";
	cout << "_______________________________________________________________________________________\n\n";

	for (sClient& Client : Clients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}

	cout << "_______________________________________________________________________________________\n";
}

int main()
{
	vector <sClient> Clients = LoadClientDataFromFile(ClientFileName);
	string AccountNumber = ReadClientAccountNumber();

	UpdateClientRecordByAccountNumber(AccountNumber, Clients);

	PrintAllClientsData(Clients);
	cout << endl;

	return 0;
}