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

//Method Bank Account withdraw
	void withdraw()
	{
		balance = balance - amount;
	}

	//Method Bank Account Deposit
	void deposit(float)
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
	
		//Caculate intreset rates savings
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
	//Method Savings Accouunt withdraw
	void withdraw()
	{
		balance = ((balance - 2) - amount);
	}

	//Method Savings Account Deposit
	void deposit()
	{
		balance = balance + amount;
	}

	//Get Balance for Savings
	float getBalance()
	{
		return balance;
	};

	//Display Savings Account
	void Display()
	{
		cout << "Savings Account Number: " << accountNumber << endl;
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
		//If Checking account Balance below 500
		if (balance <= 500)
		{
			balance = balance - 5;
		}
	}

	//Method order checks
	void orderChecks()
	{
		balance = balance - order;
	}
	
	//Method Checking Account Withdraw
	void withdraw(float amount)
	{
		balance = ((balance - 2) - amount);
	}

	//Get Balance for Checking
	float getBalance()
	{
		return balance;
	};

	//Display Checking Account Information
	void Display()
	{
		cout << "\nChecking Account Number: " << accountNumber << endl;
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

		//If CD term <5 or CD term < 5 years 
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
	void withdraw()
	{
		balance = balance - ((balance - amount) * .1);
	}
	//Method CD Deposit
	void deposit()
	{
		balance = balance + amount;
	}
	
	//Method CD Get Balance
	float getBalance()
	{
		return balance;
	};
	//Display CD Information
	void Display()
	{
		cout << "\nCD Account Number: " << accountNumber << endl;
		cout << "Interest Rate: " << interestRate << endl;
		cout << "CD Account Bal: " << balance << endl;
	}
};


int main()
{
	int nBankAccounts = 10;
	
		
		bankAccount **acc = new bankAccount*[nBankAccounts];
		acc[0] = new savingsAccount(100, 0,10000,10000); //Open Savings
		acc[0]->Display();									//Display Savings
		
		acc[1] = new checkingAccount(200, 0, 600, 600,0); //Open Checking
		acc[1]->Display();								//Display Checking

		acc[2] = new certificateofDeposit(300, 0, 10000, 10000, 3); //Open CD
		acc[2]->Display();											//Display CD



		delete acc[0];
		delete acc[1];
		delete acc[2];
		delete[] acc;

	return 0;
}

 