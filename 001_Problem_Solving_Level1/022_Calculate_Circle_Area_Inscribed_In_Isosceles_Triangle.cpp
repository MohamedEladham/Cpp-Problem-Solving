#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void readIsoscelesTriangleSides(float& sideA, float& sideB)
{
	cout << "\n> Enter Triangle Side A: ";
	cin >> sideA;

	cout << "\n> Enter Triangle Side B: ";
	cin >> sideB;
}

float calculateCircleAreaInIsoscelesTriangle(float sideA, float sideB)
{
	const float PI = 3.14159265359;

	return PI * (pow(sideB, 2) / 4) * ((2 * sideA - sideB) / (2 * sideA + sideB));
}

void printArea(float area)
{
	cout << "\n> Circle Area Inscribed In Isosceles Triangle = " << area << endl;
}

int main()
{
	float sideA, sideB;

	readIsoscelesTriangleSides(sideA, sideB);

	printArea(calculateCircleAreaInIsoscelesTriangle(sideA, sideB));

	return 0;
}