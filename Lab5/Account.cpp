#include "Account.h"

BankAccount::BankAccount(double s)
{
	this->savings = s;
}

void BankAccount::interest()
{
	savings = 1.02 * savings;
}

void BankAccount::print()
{
	std::cout << savings << std::endl;
}
