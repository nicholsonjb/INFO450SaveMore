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
		accountNumber = a; interestRate = i; balance = b;
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
	virtual void Display() = 0;
		
};




//Savings Class with Inheritance from account
class savingsAccount : public bankAccount
{
public:
	savingsAccount(int a, float i, float b) : bankAccount(a,i,b)
	{
		if (balance <= 10000)
		{
			interestRate = .01 / MAXMONTHS;
			balance = balance + balance*interestRate;

		}
		if (balance >= 10000)
		{
			interestRate = .02 / MAXMONTHS;
			balance = balance + balance*interestRate;
		}
	}

	void withdraw(float amount)
	{
		balance = ((balance - 2) - amount);
	}
	void Display();
	void getBalance();
};





//Checcking Class with Inheritance from account
class Checking : public bankAccount
{
	
};

//CD Class with Inheritance from account
class CertificateofDeposit : public bankAccount
{
	
};


int main()
{
    return 0;
}

