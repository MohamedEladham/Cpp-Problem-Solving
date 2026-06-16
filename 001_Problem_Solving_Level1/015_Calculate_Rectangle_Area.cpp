#include <iostream>
#include <string>
using namespace std;

void readRectangleDimensions(float& length, float& width)
{
	cout << "\n> Please Enter Rectangle Length: ";
	cin >> length;

	cout << "\n> Please Enter Rectangle Width: ";
	cin >> width;
}

float calculateRectangleArea(float length, float width)
{
	return length * width;
}

void printArea(float area)
{
	cout << "\n> Rectangle Area = " << area << endl;
}

int main()
{
	float length, width;

	readRectangleDimensions(length, width);

	printArea(calculateRectangleArea(length, width));

	return 0;
}