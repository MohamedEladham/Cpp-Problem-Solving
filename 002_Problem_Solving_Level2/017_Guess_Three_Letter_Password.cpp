#include <iostream>
using namespace std;

string ReadPassword(string Message)
{
	string Password;

	cout << Message;
	cin >> Password;

	return Password;
}

bool GuessPassword(string Password)
{
	string CurrentAttempt = "";
	int TrialCount = 0;

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				TrialCount++;

				CurrentAttempt += char(i);
				CurrentAttempt += char(j);
				CurrentAttempt += char(k);

				cout << "> Trial [" << TrialCount << "] : "
					<< CurrentAttempt << endl;

				if (Password == CurrentAttempt)
				{
					cout << "\n> Password Is: '"
						<< Password << "'\n";

					cout << "\n> Found After: '"
						<< TrialCount
						<< "' Trial(s)\n";

					return true;
				}

				CurrentAttempt = "";
			}
		}
	}

	return false;
}

int main()
{
	string Password =
		ReadPassword("\n> Enter The Password Of 3 Capital Letters: ");

	GuessPassword(Password);

	return 0;
}