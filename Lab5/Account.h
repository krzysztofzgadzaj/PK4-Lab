#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class BankAccount {
	double savings;
public:
	BankAccount(double s);
	void interest();
	void print();
};

#endif // !ACCOUNT_H
