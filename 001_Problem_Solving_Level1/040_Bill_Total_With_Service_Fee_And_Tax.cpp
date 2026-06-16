#include <iostream>
#include <string>
using namespace std;

float ReadPositiveNumber(string Msg)
{
	float Number;

	do
	{
		cout << Msg;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

float CalculateServiceFee(float BillValue)
{
	const float ServiceRate = 0.10;
	return BillValue * ServiceRate;
}

float CalculateSalesTax(float BillValue)
{
	const float TaxRate = 0.16;
	return BillValue * TaxRate;
}

float CalculateTotalBill(float BillValue)
{
	float ServiceFee = CalculateServiceFee(BillValue);
	float SalesTax = CalculateSalesTax(BillValue);

	return BillValue + ServiceFee + SalesTax;
}

int main()
{
	float BillValue = ReadPositiveNumber("\n> Enter Bill Value: ");

	cout << "\n> Total Bill = " << BillValue << endl;

	cout << "\n> Total Bill After Adding Service Fee And Sales Tax = "
		<< CalculateTotalBill(BillValue) << endl;

	return 0;
}