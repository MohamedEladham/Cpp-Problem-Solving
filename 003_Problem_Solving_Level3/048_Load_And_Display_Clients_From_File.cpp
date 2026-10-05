#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const string ClientFileName = "ClientRecord.txt";

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

stClient ConvertLineToClientRecord(string Text)
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
			Client = ConvertLineToClientRecord(RecordLine);

			Clients.push_back(Client);
		}

		File.close();
	}

	return Clients;
}

void PrintClientRecord(stClient Client)
{
	cout << "| " << left << setw(17) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(27) << Client.Name;
	cout << "| " << left << setw(15) << Client.Phone;
	cout << "| " << left << setw(9) << Client.AccountBalance;
}

void PrintAllClientsData(vector <stClient> Clients)
{
	cout << "                                Client List (" << Clients.size() << ") Client(s)      \n";
	cout << "_______________________________________________________________________________________\n\n";
	cout << "| " << left << setw(17) << "Account Number" << "| " << left << setw(10) << "Pin Code" << "| " <<
		left << setw(27) << "Client Name" << "| " << left << setw(15) << "Phone" << "| " <<
		left << setw(9) << "Balance \n";
	cout << "_______________________________________________________________________________________\n\n";

	for (stClient& Client : Clients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}

	cout << "_______________________________________________________________________________________\n";
}

int main()
{
	vector <stClient> Clients;
	Clients = LoadClientDataFromFile(ClientFileName);

	PrintAllClientsData(Clients);

	return 0;
}