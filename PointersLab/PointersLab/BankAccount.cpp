#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(double initialBalance)
{
	this->balance = initialBalance;
}

BankAccount::~BankAccount()
{
}

double BankAccount::getBalance() const
{
	return this->balance;
}

void BankAccount::deposit(double amount)
{
	this->balance += amount;
}

void BankAccount::withdraw(double amount)
{
	if (amount <= balance) {
		this->balance -= amount;
	}
	else {
		std::cout << "Amount is greater than balance!" << std::endl;
	}
	
}
