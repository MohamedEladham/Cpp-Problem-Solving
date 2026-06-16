#include <iostream>
using namespace std;

enum enNameOrder { First, Second, Last };

struct stPersonName
{
	string FirstName;
	string SecondName;
	string LastName;
};

stPersonName readInfo()
{
	stPersonName info;

	cout << "\n> Please Enter First Name: ";
	cin >> info.FirstName;

	cout << "\n> Please Enter Second Name: ";
	cin >> info.SecondName;

	cout << "\n> Please Enter Last Name: ";
	cin >> info.LastName;

	return info;
}

string getFullName(stPersonName info, enNameOrder order)
{
	string fullName;

	if (order == enNameOrder::First)
		fullName = info.FirstName + " " + info.SecondName + " " + info.LastName;

	else if (order == enNameOrder::Second)
		fullName = info.SecondName + " " + info.FirstName + " " + info.LastName;

	else
		fullName = info.LastName + " " + info.SecondName + " " + info.FirstName;

	return fullName;
}

void printFullName(string fullName)
{
	cout << "\n> Your Full Name Is " << fullName << endl;
}

int main()
{
	printFullName(getFullName(readInfo(), enNameOrder::Second));
	return 0;
}