#include <iostream>
#include <string>
using namespace std;

int readAge()
{
	int age;

	cout << "\n> Please Enter Your Age: ";
	cin >> age;

	return age;
}

bool isNumberInRange(int number, int minValue, int maxValue)
{
	return (number >= minValue && number <= maxValue);
}

void printValidationResult(int age)
{
	if (isNumberInRange(age, 18, 45))
		cout << "\n> '" << age << "' Is Valid Age \n";
	else
		cout << "\n> '" << age << "' Is Invalid Age \n";
}

int main()
{
	printValidationResult(readAge());
	return 0;
}