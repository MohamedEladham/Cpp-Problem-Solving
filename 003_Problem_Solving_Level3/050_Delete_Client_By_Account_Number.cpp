#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

const string ClientFileName = "Client_Data.txt";

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

string ReadClientAccountNumber()
{
	string AccountNumber;
	cout << "\n> Please Enter Account Number: ";
	getline(cin, AccountNumber);

	return AccountNumber;
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

bool FoundClientByAccountNumber(string AccountNumber, vector <sClient> Clients, sClient& Client)
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

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& Clients)
{
	for (sClient& Client : Clients)
	{
		if (Client.AccountNumber == AccountNumber)
		{
			Client.MarkForDelete = true;
			return true;
		}
	}

	return false;
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

void SaveClientsDataToFile(string FileName, vector <sClient>& Clients)
{
	fstream File;
	File.open(FileName, ios::out);

	string RecordLine;

	if (File.is_open())
	{
		for (sClient& Client : Clients)
		{
			if (Client.MarkForDelete == false)
			{
				RecordLine = ConvertRecordToLine(Client);
				File << RecordLine << endl;
			}
		}

		File.close();
	}
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& Clients)
{
	sClient Client;
	char Answer;

	if (FoundClientByAccountNumber(AccountNumber, Clients, Client))
	{
		PrintClientCard(Client);

		cout << "\n> Are You Sure You Want Delete This Client Y/N: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, Clients);
			SaveClientsDataToFile(ClientFileName, Clients);

			Clients = LoadClientDataFromFile(ClientFileName);

			cout << "\n> Client Deleted Successfully. \n";
			return true;
		}
	}
	else
	{
		cout << "\n> Client With Account Number [" << AccountNumber << "] Is Not Found. ";
		return false;
	}

	return false;
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
	DeleteClientByAccountNumber(AccountNumber, Clients);

	PrintAllClientsData(Clients);
	cout << endl;

	return 0;
}