#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void readTriangleSides(float& sideA, float& sideB, float& sideC)
{
	cout << "\n> Enter Triangle Side A: ";
	cin >> sideA;

	cout << "\n> Enter Triangle Side B: ";
	cin >> sideB;

	cout << "\n> Enter Triangle Side C: ";
	cin >> sideC;
}

float calculateCircumcircleArea(float sideA, float sideB, float sideC)
{
	const float PI = 3.14159265359;

	float semiPerimeter = (sideA + sideB + sideC) / 2;

	float circumradius = (sideA * sideB * sideC) /
		(4 * sqrt(semiPerimeter * (semiPerimeter - sideA) *
			(semiPerimeter - sideB) *
			(semiPerimeter - sideC)));

	return PI * circumradius * circumradius;
}

void printArea(float area)
{
	cout << "\n> Circle Area Described Around Arbitrary Triangle = " << area << endl;
}

int main()
{
	float sideA, sideB, sideC;

	readTriangleSides(sideA, sideB, sideC);

	printArea(calculateCircumcircleArea(sideA, sideB, sideC));

	return 0;
}