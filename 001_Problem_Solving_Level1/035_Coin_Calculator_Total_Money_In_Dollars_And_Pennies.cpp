#include <iostream>
#include <string>
using namespace std;

float ReadPennies()
{
	float Pennies;
	cout << "\n> How Many Pennies Do You Have: ";
	cin >> Pennies;
	return Pennies;
}

float ReadNickels()
{
	float Nickels;
	cout << "\n> How Many Nickels Do You Have: ";
	cin >> Nickels;
	return Nickels;
}

float ReadDimes()
{
	float Dimes;
	cout << "\n> How Many Dimes Do You Have: ";
	cin >> Dimes;
	return Dimes;
}

float ReadQuarters()
{
	float Quarters;
	cout << "\n> How Many Quarters Do You Have: ";
	cin >> Quarters;
	return Quarters;
}

float CalculateTotalPennies(float Pennies, float Nickels, float Dimes, float Quarters, float Dollars)
{
	return (Pennies * 1) + (Nickels * 5) + (Dimes * 10) + (Quarters * 25) + (Dollars * 100);
}

float CalculateTotalDollars(float TotalPennies)
{
	return TotalPennies / 100;
}

int main()
{
	float Pennies = ReadPennies();
	float Nickels = ReadNickels();
	float Dimes = ReadDimes();
	float Quarters = ReadQuarters();

	float TotalPennies = CalculateTotalPennies(Pennies, Nickels, Dimes, Quarters, 0);
	float TotalDollars = CalculateTotalDollars(TotalPennies);

	cout << "\n> Total Pennies = " << TotalPennies << " Pennies.\n";
	cout << "\n> Total Dollars = " << TotalDollars << " Dollars.\n";

	return 0;
}