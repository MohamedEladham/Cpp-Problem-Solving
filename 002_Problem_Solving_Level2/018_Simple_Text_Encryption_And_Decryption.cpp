#include <iostream>
#include <string>
using namespace std;

string ReadText(string Message)
{
	string Text;

	cout << Message;
	getline(cin, Text);

	return Text;
}

string EncryptText(string Text, const short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char(Text[i] + EncryptionKey);
	}

	return Text;
}

string DecryptText(string Text, const short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char(Text[i] - EncryptionKey);
	}

	return Text;
}

int main()
{
	const short EncryptionKey = 2;

	string Text = ReadText("\n> Please Enter The Name: ");

	string EncryptedText = EncryptText(Text, EncryptionKey);
	string DecryptedText = DecryptText(EncryptedText, EncryptionKey);

	cout << "\n> Text Before Encryption: " << Text << endl;
	cout << "\n> Text After Encryption: " << EncryptedText << endl;
	cout << "\n> Text After Decryption: " << DecryptedText << endl;

	return 0;
}