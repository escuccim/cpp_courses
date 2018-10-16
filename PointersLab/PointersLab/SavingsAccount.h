#pragma once
#include "BankAccount.h"
#include "Freezable.h"
#include "Loggable.h"
#include <list>
#include <iostream>

class SavingsAccount : public BankAccount, public Freezable, public Loggable
{
private:
	double interestRate;
	bool frozen;

public:
	SavingsAccount(double initialBalance, double interestRate = 0);
	virtual ~SavingsAccount();

	void earnInterest();

	virtual void deposit(double amount);
	virtual void withdraw(double amount);

	// implement virtual functions from bank account class
	virtual std::string getTermsAndConditions();
	virtual double getGuaranteedLimit();

	// virtual functions from freezable
	virtual void freeze();
	virtual void unfreeze();

	// virtual functions from loggable
	virtual void log(const std::string &message) const;
};

