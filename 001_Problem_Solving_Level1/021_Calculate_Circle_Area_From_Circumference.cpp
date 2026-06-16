#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float readCircumference()
{
	float circumference;

	cout << "\n> Enter Circle Circumference: ";
	cin >> circumference;

	return circumference;
}

float calculateCircleAreaFromCircumference(float circumference)
{
	const float PI = 3.14159265359;
	return (circumference * circumference) / (4 * PI);
}

void printArea(float area)
{
	cout << "\n> Circle Area From Circumference = " << area << endl;
}

int main()
{
	printArea(calculateCircleAreaFromCircumference(readCircumference()));
	return 0;
}