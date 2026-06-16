#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float readRadius()
{
	float radius;

	cout << "\n> Please Enter Circle Radius: ";
	cin >> radius;

	return radius;
}

float calculateCircleArea(float radius)
{
	const float PI = 3.14159265359;
	return PI * radius * radius;
}

void printArea(float area)
{
	cout << "\n> Circle Area = " << area << endl;
}

int main()
{
	printArea(calculateCircleArea(readRadius()));
	return 0;
}