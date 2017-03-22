// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int MAXMONTHS = 12;

//bank Accouint generic class
class bankAccount
{
protected:
	int accountNumber;
	float interestRate;
	float balance;

public:
	bankAccount(int a, float i, float b)
	{
		accountNumber = a;
		interestRate = i;
		balance = b;
	}

	void withdraw(float amount)
	{
		balance = balance - amount;
	}

	void deposit(float amount)
	{
		balance = balance + amount;
	}

	virtual float getBalance() = 0;

	virtual void Display()
	{
	};
};


//Savings Class with Inheritance from account
class savingsAccount : public bankAccount
{
public:
	savingsAccount(int a, float i, float b) : bankAccount(a, i, b)
	{
		if (balance <= 10000)
		{
			interestRate = .01 / MAXMONTHS;
			balance = balance + balance * interestRate;
		}
		if (balance >= 10000)
		{
			interestRate = .02 / MAXMONTHS;
			balance = balance + balance * interestRate;
		}
	}

	void withdraw(float amount)
	{
		balance = ((balance - 2) - amount);
	}

	void deposit(float amount)
	{
		balance = balance + amount;
	}

	float getBalance()
	{
		return balance;
	};

	void Display()
	{
		cout << "Account Number: " << accountNumber << endl;
		cout << "Interest Rate: " << interestRate << endl;
		cout << "Savings Account Bal: " << balance << endl;
	}
};


//Checcking Class with Inheritance from account
class checkingAccount : public bankAccount
{
	int order = 15;


public:
	checkingAccount(int a, float i, float b, int o) : bankAccount(a, i, b)
	{
		if (balance <= 500)
		{
			balance = balance - 5;
		}
	}

	//Method order checks
	void orderChecks(int order)
	{
		balance = balance - order;
	}

	void withdraw(float amount)
	{
		balance = ((balance - 2) - amount);
	}

	float getBalance()
	{
		return balance;
	};

	void Display()
	{
		cout << "Account Number: " << accountNumber << endl;
		cout << "Interest Rate: " << interestRate << endl;
		cout << "Checking Account Bal: " << balance << endl;
	}
};

//CD Class with Inheritance from account
class certificateofDeposit : public bankAccount
{
	int term;
public:
	certificateofDeposit(int a, float i, float b, int t) : bankAccount(a, i, b)
	{
		if (term > 5)
		{
			interestRate = .1 / MAXMONTHS;
			balance = balance + balance * interestRate;
		}
		if (balance < 5)
		{
			interestRate = .05 / MAXMONTHS;
			balance = balance + balance * interestRate;
		}
	}

	// Method withdraw 10% fee
	void withdraw(float amount)
	{
		balance = balance - ((balance - amount) * .1);
	}

	void deposit(float amount)
	{
		balance = balance + amount;
	}

	float getBalance()
	{
		return balance;
	};

	void Display()
	{
		cout << "Account Number: " << accountNumber << endl;
		cout << "Interest Rate: " << interestRate << endl;
		cout << "CD Account Bal: " << balance << endl;
	}
};


int main()
{
	int nBankAccounts = 10;

		bankAccount **acc = new bankAccount*[nBankAccounts];
		acc[0] = new savingsAccount(100, .01, 10000);
		acc[0]->Display();

		delete acc[0];

	return 0;
}

