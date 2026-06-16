#include <iostream>
#include <string>
using namespace std;

void readTriangleDimensions(float& base, float& height)
{
	cout << "\n> Please Enter Triangle Base: ";
	cin >> base;

	cout << "\n> Please Enter Triangle Height: ";
	cin >> height;
}

float calculateTriangleArea(float base, float height)
{
	return (base * height) / 2;
}

void printArea(float area)
{
	cout << "\n> Triangle Area = " << area << endl;
}

int main()
{
	float base, height;

	readTriangleDimensions(base, height);

	printArea(calculateTriangleArea(base, height));

	return 0;
}