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

float CalculateInstallmentMonths(float LoanAmount, float MonthlyInstallment)
{
	if (MonthlyInstallment == 0)
		return 0;

	return LoanAmount / MonthlyInstallment;
}

int main()
{
	float LoanAmount = ReadAPositiveNumber("\n> Please Enter Loan Amount: ");
	float MonthlyInstallment = ReadAPositiveNumber("\n> Please Enter Monthly Installment: ");

	cout << "\n> Number Of Installment Months: "
		<< CalculateInstallmentMonths(LoanAmount, MonthlyInstallment)
		<< endl;

	return 0;
}