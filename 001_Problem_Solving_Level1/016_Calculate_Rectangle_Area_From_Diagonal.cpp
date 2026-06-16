#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void readRectangleSides(float& sideA, float& diagonal)
{
	cout << "\n> Please Enter Rectangle Side A: ";
	cin >> sideA;

	cout << "\n> Please Enter Rectangle Diagonal: ";
	cin >> diagonal;
}

float calculateAreaUsingDiagonal(float sideA, float diagonal)
{
	return sideA * sqrt(pow(diagonal, 2) - pow(sideA, 2));
}

void printArea(float area)
{
	cout << "\n> Rectangle Area Through Diagonal = " << area << endl;
}

int main()
{
	float sideA, diagonal;

	readRectangleSides(sideA, diagonal);

	printArea(calculateAreaUsingDiagonal(sideA, diagonal));

	return 0;
}