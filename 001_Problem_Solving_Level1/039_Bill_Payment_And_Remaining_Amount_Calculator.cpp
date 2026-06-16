#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float ReadTotalBill(string Msg)
{
	float TotalBill;
	float Sum = 0;

	do
	{
		cout << Msg;
		cin >> TotalBill;

		if (TotalBill == 0)
			break;

		Sum += TotalBill;

	} while (true);

	return Sum;
}

float ReadCashPaid(string Msg)
{
	float CashPaid;
	cout << Msg;
	cin >> CashPaid;
	return CashPaid;
}

float ReadTotalBillWrapper()
{
	return ReadTotalBill("\n> Enter Total Bill (0 to stop): ");
}

float CalculateRemainder(float CashPaid, float TotalBill)
{
	return CashPaid - TotalBill;
}

void PrintPaymentRemainder(float Remainder)
{
	if (Remainder < 0)
		cout << "\n> You Need To Pay More: " << abs(Remainder) << endl;
	else
		cout << "\n> Remaining Amount: " << Remainder << endl;
}

int main()
{
	float TotalBill = ReadTotalBillWrapper();

	cout << "\n> Total Bill = " << TotalBill << endl;

	float CashPaid = ReadCashPaid("\n> Enter Cash Paid: ");

	float Remainder = CalculateRemainder(CashPaid, TotalBill);

	PrintPaymentRemainder(Remainder);

	return 0;
}