#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float readSquareSide()
{
	float squareSide;

	cout << "\n> Enter Square Side: ";
	cin >> squareSide;

	return squareSide;
}

float calculateCircleAreaFromSquare(float squareSide)
{
	const float PI = 3.14159265359;
	return (PI * squareSide * squareSide) / 4;
}

void printArea(float area)
{
	cout << "\n> Circle Area Inscribed In Square = " << area << endl;
}

int main()
{
	printArea(calculateCircleAreaFromSquare(readSquareSide()));
	return 0;
}