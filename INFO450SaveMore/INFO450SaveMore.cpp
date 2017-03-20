// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

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

//Savings Class with Inheritance from account
class Savings: public Account
{
	


};

//Checcking Class with Inheritance from account
class Checking : public Account
{
	
};

//CD Class with Inheritance from account
class CertificateofDeposit : public Account
{
	
};


int main()
{
    return 0;
}

