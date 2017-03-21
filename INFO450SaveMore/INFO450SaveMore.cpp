// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
 
const int MAXMONTHS = 12;

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
	
		 savingsAccount();
		 void calculateIntrest(float, float);
		 void deposit(float amount);
		 void withdraw(float amount);
		 float getBalance();

};

//Savings accouunt method deposit
void savingsAccount::deposit(float amount)
{
	balance = balance + amount;
}

//Savings accouunt method withdraw with 2 dollar withdraw fee
void savingsAccount::withdraw(float amount)
{
	balance = (balance -2) - amount;
}

//Savings account method to calculate interest
void savingsAccount::calculateIntrest(float, float)
{
	if (balance <= 10000)
	{
		interestRate = .01/MAXMONTHS;
		balance = balance + balance*interestRate;

	}
	 if (balance >= 10000)
	 {
		 interestRate = .02/MAXMONTHS;
		 balance = balance + balance*interestRate;
	 }

}

float savingsAccount::getBalance()
{
	return balance;
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

