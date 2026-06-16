#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float readDiameter()
{
	float diameter;

	cout << "\n> Enter Circle Diameter: ";
	cin >> diameter;

	return diameter;
}

float calculateCircleAreaFromDiameter(float diameter)
{
	const float PI = 3.14159265359;
	return (PI * diameter * diameter) / 4;
}

void printArea(float area)
{
	cout << "\n> Circle Area Through Diameter = " << area << endl;
}

int main()
{
	printArea(calculateCircleAreaFromDiameter(readDiameter()));
	return 0;
}