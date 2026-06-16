#include <iostream>
#include <string>
using namespace std;

int readAge()
{
	int age;

	cout << "\n> Please Enter Your Age Between 18 To 45: ";
	cin >> age;

	return age;
}

bool isNumberInRange(int number, int minAge, int maxAge)
{
	return (number >= minAge && number <= maxAge);
}

int getValidatedAge(int minAge, int maxAge)
{
	int age;

	do
	{
		age = readAge();

	} while (!isNumberInRange(age, minAge, maxAge));

	return age;
}

void printResult(int age)
{
	cout << "\n> '" << age << "' Is Valid Age \n";
}

int main()
{
	printResult(getValidatedAge(18, 45));
	return 0;
}