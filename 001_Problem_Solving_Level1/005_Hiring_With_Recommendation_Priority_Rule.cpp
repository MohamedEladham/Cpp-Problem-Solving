#include <iostream>
using namespace std;

struct stApplicantInfo
{
	short Age;
	char hasDriverLicense;
	char hasRecommendation;
};

stApplicantInfo readInfo()
{
	stApplicantInfo info;

	cout << "\n> Please Enter Your Age: ";
	cin >> info.Age;

	cout << "\n> Do You Have A Driver License Enter Y Or N: ";
	cin >> info.hasDriverLicense;

	cout << "\n> Do You Have A Recommendation Enter Y Or N: ";
	cin >> info.hasRecommendation;

	return info;
}

bool isAccepted(stApplicantInfo info)
{
	if (info.hasRecommendation == 'Y' || info.hasRecommendation == 'y')
		return true;
	else
		return ((info.hasDriverLicense == 'Y' || info.hasDriverLicense == 'y') && info.Age > 21);
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