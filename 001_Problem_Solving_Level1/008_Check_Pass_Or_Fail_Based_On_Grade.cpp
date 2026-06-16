#include <iostream>
#include <string>
using namespace std;

enum enPassFail { Pass, Fail };

float readGrade()
{
	float grade;

	cout << "\n> Please Enter The Grade: ";
	cin >> grade;

	return grade;
}

enPassFail getPassFailStatus(float mark)
{
	if (mark >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void printResult(float mark)
{
	if (getPassFailStatus(mark) == enPassFail::Pass)
		cout << "\n> Pass \n";
	else
		cout << "\n> Fail \n";
}

int main()
{
	printResult(readGrade());
	return 0;
}