// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int MAXMONTHS = 12;

//bank Account generic class
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

//Method Bank Account withdraw
	virtual int withdraw(float wAmount)=0;
	virtual float deposit(float dAmount) =0;
	virtual float getBalance() = 0;

	virtual void Display() =0;
};


//Savings Class with Inheritance from account
class savingsAccount : public bankAccount
{
public:
	savingsAccount(int a, float i, float b) : bankAccount(a, i, b)

	{

		//Caculate intreset rates savings
		if (balance <= 10000)
		{
			interestRate = .1 / MAXMONTHS;
			balance = balance + balance * interestRate;
		}
		if (balance >= 10000)
		{
			interestRate = .2 / MAXMONTHS;
			balance = balance + balance * interestRate;
		}
	}
	//Method Savings Accouunt withdraw
	int withdraw(float wAmount)
	{
		if (balance - wAmount >= 0)
		{
			balance = (balance -2) - wAmount;
			return 0;
		}
		else
			return -1;
	}

	//Method Savings Account Deposit
	float deposit(float dAmount)
	{
		balance = balance + dAmount;
		return balance;
	}

	//Get Balance for Saving
	float getBalance()
	{
		return balance;
	};

	//Display Savings Account
	void Display()
	{
		cout << "Savings Account Number: " << accountNumber << endl;
		
		/*cout << "Interest Rate: " << interestRate << endl;*/
		cout << "Savings Account Bal: " << balance << endl;
	}
};


//Checcking Class with Inheritance from account
//class checkingAccount : public bankAccount
//{
//	int order = 15;
//
//
//public:
//
//	checkingAccount(int a, float i, float b, float amt, int o) : bankAccount(a, i, b, amt)
//	{
//		//If Checking account Balance below 500
//		if (balance <= 500)
//		{
//			balance = balance - 5;
//		}
//	}
//
//	//Method order checks
//	void orderChecks()
//	{
//		balance = balance - order;
//	}
//	
//	//Method Checking Account Withdraw
//	void withdraw(float amount)
//	{
//		balance = ((balance - 2) - amount);
//	}
//
//	//Get Balance for Checking
//	float getBalance()
//	{
//		return balance;
//	};
//
//	//Display Checking Account Information
//	void Display()
//	{
//		cout << "\nChecking Account Number: " << accountNumber << endl;
//		cout << "Interest Rate: " << interestRate << endl;
//		cout << "Checking Account Bal: " << balance << endl;
//	}
//};
//
////CD Class with Inheritance from account
//class certificateofDeposit : public bankAccount
//{
//	int term;
//public:
//	certificateofDeposit(int a, float i, float b, float amt, int t) : bankAccount(a, i, b, amt)
//	{
//
//		//If CD term <5 or CD term < 5 years 
//		if (term > 5)
//		{
//			interestRate = .1 / MAXMONTHS;
//			balance = balance + balance * interestRate;
//		}
//		if (balance < 5)
//		{
//			interestRate = .05 / MAXMONTHS;
//			balance = balance + balance * interestRate;
//		}
//	}
//
//	// Method withdraw 10% fee
//	void withdraw()
//	{
//		balance = balance - ((balance - amount) * .1);
//	}
//	//Method CD Deposit
//	void deposit()
//	{
//		balance = balance + amount;
//	}
//	
//	//Method CD Get Balance
//	float getBalance()
//	{
//		return balance;
//	};
//	//Display CD Information
//	void Display()
//	{
//		cout << "\nCD Account Number: " << accountNumber << endl;
//		cout << "Interest Rate: " << interestRate << endl;
//		cout << "CD Account Bal: " << balance << endl;
//	}
//};


int main()
{
	int nBankAccounts = 10;
	
		
		bankAccount **acc = new bankAccount*[nBankAccounts];
		acc[0] = new savingsAccount(100,0, 10000); //Open Savings
		acc[0]->Display();									//Display Savings
		//
		//acc[1] = new checkingAccount(200, 0, 600, 600,0); //Open Checking
		//acc[1]->Display();								//Display Checking

		//acc[2] = new certificateofDeposit(300, 0, 10000, 10000, 3); //Open CD
		//acc[2]->Display();											//Display CD



		delete acc[0];
		//delete acc[1];
		//delete acc[2];
		//delete[] acc;

	return 0;
}

 