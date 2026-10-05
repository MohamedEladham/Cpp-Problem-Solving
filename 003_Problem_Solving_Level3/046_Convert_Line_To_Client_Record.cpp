#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double AccountBalance;
};

vector <string> SplitString(string Text, string Delimiter)
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

stClient ConvertLineDataToRecord(string Text)
{
	stClient Client;
	vector <string> Parts;
	Parts = SplitString(Text, "#//#");

	Client.AccountNumber = Parts.at(0);
	Client.PinCode = Parts.at(1);
	Client.Name = Parts.at(2);
	Client.PhoneNumber = Parts.at(3);
	Client.AccountBalance = stod(Parts.at(4));

	return Client;
}

void PrintClientRecord(stClient Client)
{
	cout << "Account Number: " << Client.AccountNumber << endl;
	cout << "Pin Code      : " << Client.PinCode << endl;
	cout << "Name          : " << Client.Name << endl;
	cout << "Phone         : " << Client.PhoneNumber << endl;
	cout << "Account Balance: " << Client.AccountBalance << endl;
}

int main()
{
	string Text = "A150#//#1234#//#Mohammed Abo-Hadhoud#//#01208292350#//#5270.000000";

	cout << "Line Record Is: \n";
	cout << Text << endl;
	cout << endl;

	stClient Client;
	Client = ConvertLineDataToRecord(Text);

	cout << "The Following Is The Extracted Client Record: \n";
	PrintClientRecord(Client);
	cout << endl;

	return 0;
}