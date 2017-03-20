// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Account
{
	static int accountNumGenerator;
	int accountID;
	float interestRate;
	float balance;

public:
	Account();
	void withdraws();
	void deposits();
	int getAccountID();

		
	virtual void display() {};
		
};

int Account::accountNumGenerator = 1;

Account::Account()
{
	accountID = accountNumGenerator ++;
}

int Account::getAccountID()
{
	return accountID;
}
class Savings: public Account
{
	


};

class Checking : public Account
{
	
};

class CertificateofDeposit : public Account
{
	
};


int main()
{
    return 0;
}

