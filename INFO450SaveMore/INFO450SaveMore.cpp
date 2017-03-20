// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Account
{
	float accountNum;
	float interestRate;
	float balance;

public:
	Account();
	void withdraws();
	void deposits();

		
	virtual void display() {};
		
};

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

