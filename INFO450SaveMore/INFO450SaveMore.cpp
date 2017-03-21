// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


//bank Accouint generic class
class bankAccount
{
	static int accountNumGenerator;
	int accountID;
	float interestRate;
	float balance;

public:
	bankAccount();
	void withdraw(float amount);
	void deposit(float amount);
	int getAccountID();	
	void displayAccount(int, float);
	float getBalance();
		
};

int bankAccount::accountNumGenerator = 1;

bankAccount::bankAccount()
{
	accountID = accountNumGenerator ++;
}

int bankAccount::getAccountID()
{
	return accountID;
}

void bankAccount::deposit(float amount)
{
	balance = balance + amount;
}

void bankAccount::withdraw(float amount)
{
	balance = balance - amount;
}

float bankAccount::getBalance()
{
	return balance;
}





//Savings Class with Inheritance from account
class savingsAccount: public bankAccount
{
	private: 
		int accountID;
		float interestRate;
		float balance;
public:
	void calculateIntrest(float, float);
		 savingsAccount(int, float, float);
		 void deposit(float amount);
		 void withdraw(float amount);
		 float getBalance();



};


void savingsAccount::deposit(float amount)
{
	balance = balance + amount;
}


void savingsAccount::withdraw(float amount)
{
	balance = balance - amount;
}

float savingsAccount::getBalance()
{
	return balance;
}

void savingsAccount::calculateIntrest(float, float)
{
	if (balance <= 10000)
	{
		interestRate = .01;

	}
	 if (balance >= 10000)
	 {
		 interestRate = .02;
	 }

}


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

