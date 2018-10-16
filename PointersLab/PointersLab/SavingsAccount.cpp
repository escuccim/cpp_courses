#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(double initialBalance, double interestRate) : BankAccount(initialBalance)
{
	this->interestRate = interestRate;
	this->frozen = false;
}

SavingsAccount::~SavingsAccount()
{
}

void SavingsAccount::earnInterest()
{
	if (!this->frozen) {
		double interest = balance * (interestRate / 100);
		deposit(interest);
	}
}

void SavingsAccount::deposit(double amount)
{
	if (!frozen) {
		BankAccount::deposit(amount);
		log("Deposit: " + std::to_string(amount));
	}
	else {
		log("Account frozen!");
	}
}

void SavingsAccount::withdraw(double amount)
{
	if (!frozen) {
		BankAccount::withdraw(amount);
		log("Withdrawl: " + std::to_string(amount));
	}
	else {
		log("Account frozen!");
	}
}

std::string SavingsAccount::getTermsAndConditions()
{
	return std::string("Terms and conditions");
}

double SavingsAccount::getGuaranteedLimit()
{
	return 75000;
}

void SavingsAccount::freeze()
{
	this->frozen = true;
}

void SavingsAccount::unfreeze()
{
	this->frozen = false;
}

void SavingsAccount::log(const std::string & message) const
{
	std::cout << message << std::endl;
}
