#include <iostream>
using namespace std;

struct stApplicantInfo
{
	short Age;
	char hasDriverLicense;
};

stApplicantInfo readInfo()
{
	stApplicantInfo info;

	cout << "\n> Please Enter The Age: ";
	cin >> info.Age;

	cout << "\n> Do You Have A Driver License Enter Y Or N: ";
	cin >> info.hasDriverLicense;

	return info;
}

bool isAccepted(stApplicantInfo info)
{
	return ((info.hasDriverLicense == 'y' || info.hasDriverLicense == 'Y') && info.Age > 21);
}

void printResult(stApplicantInfo info)
{
	if (isAccepted(info))
		cout << "\n> Is Hired \n";
	else
		cout << "\n> Is Rejected \n";
}

int main()
{
	printResult(readInfo());
	return 0;
}