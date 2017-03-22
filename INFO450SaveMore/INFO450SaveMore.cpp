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
	float amount;
	float interestRate;
	float balance;

public:
	bankAccount(int a, float i, float b, float amt)
	{
		accountNumber = a;
		amount = amt;
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
	savingsAccount(int a, float i, float b, float amt) : bankAccount(a, i, b, amt)
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

	void withdraw()
	{
		balance = ((balance - 2) - amount);
	}

	void deposit()
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
		cout << "Depo Amount: " << amount << endl;
		/*cout << "Interest Rate: " << interestRate << endl;*/
		cout << "Savings Account Bal: " << balance << endl;
	}
};


//Checcking Class with Inheritance from account
class checkingAccount : public bankAccount
{
	int order = 15;


public:
	checkingAccount(int a, float i, float b, float amt, int o) : bankAccount(a, i, b, amt)
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
	certificateofDeposit(int a, float i, float b, float amt, int t) : bankAccount(a, i, b, amt)
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
		acc[0] = new savingsAccount(100, 0,10000,10000);
		acc[0]->Display();

		delete acc[0];

	return 0;
}

