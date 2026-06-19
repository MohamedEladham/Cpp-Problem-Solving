#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandomValue = rand() % (To - From + 1) + From;

	return RandomValue;
}

int main()
{
	srand((unsigned)time(NULL));

	cout << RandomNumber(12, 17) << endl;
	cout << RandomNumber(12, 17) << endl;
	cout << RandomNumber(12, 17) << endl;

	return 0;
}