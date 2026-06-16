#include <iostream>
#include <string>
using namespace std;

enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

float ReadNumber(string Msg)
{
	float Number;
	cout << Msg;
	cin >> Number;
	return Number;
}

void ShowOperationTypeMenu()
{
	cout << "\n\n>-------------------------------\n";
	cout << " {+} \n";
	cout << " {-} \n";
	cout << " {*} \n";
	cout << " {/}  \n";
	cout << "> Choose Operation Type: ";
}

enOperationType GetOperationType()
{
	ShowOperationTypeMenu();

	char Op;
	cin >> Op;

	enOperationType Operation = enOperationType(Op);
	return Operation;
}

float Calculator(float Num1, float Num2, enOperationType Operation)
{
	switch (Operation)
	{
	case enOperationType::Add:
		cout << Num1 << " + " << Num2 << " = ";
		return Num1 + Num2;

	case enOperationType::Subtract:
		cout << Num1 << " - " << Num2 << " = ";
		return Num1 - Num2;

	case enOperationType::Multiply:
		cout << Num1 << " * " << Num2 << " = ";
		return Num1 * Num2;

	case enOperationType::Divide:
		cout << Num1 << " / " << Num2 << " = ";
		return Num1 / Num2;

	default:
		cout << Num1 << " + " << Num2 << " = ";
		return Num1 + Num2;
	}
}

int main()
{
	float Num1 = ReadNumber("\n> Please Enter Number 1: ");
	float Num2 = ReadNumber("\n> Please Enter Number 2: ");

	enOperationType Operation = GetOperationType();

	cout << "\n> Result = ";
	cout << Calculator(Num1, Num2, Operation);

	return 0;
}