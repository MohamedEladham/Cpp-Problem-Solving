#include <iostream>
#include <string>
using namespace std;

void PrintAlphabetAtoZ()
{
	for (char c = 'A'; c <= 'Z'; c++)
	{
		cout << c << endl;
	}
}

int main()
{
	PrintAlphabetAtoZ();
	return 0;
}