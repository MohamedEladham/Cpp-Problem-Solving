#include <iostream>
#include <string>
using namespace std;

float ReadAPositiveNumber(string Message)
{
	float Number;

	do
	{
		cout << Message;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

float CalculateMonths(float LoanAmount, float MonthlyPayment)
{
	if (MonthlyPayment == 0)
		return 0;

	return LoanAmount / MonthlyPayment;
}

void PrintMonths(float NumberOfMonths)
{
	cout << "\n> Number Of Months = " << NumberOfMonths << " Month.\n";
}

int main()
{
	float LoanAmount = ReadAPositiveNumber("\n> Please Enter Loan Amount: ");
	float MonthlyPayment = ReadAPositiveNumber("\n> Please Enter Monthly Payment: ");

	float Months = CalculateMonths(LoanAmount, MonthlyPayment);

	PrintMonths(Months);

	return 0;
}