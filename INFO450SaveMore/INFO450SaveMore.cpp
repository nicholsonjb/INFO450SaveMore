// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
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
		balance = b;
	}

//Method Bank Account
	virtual int withdraw(float wAmount)=0;
	virtual float deposit(float dAmount) =0;
	virtual float getBalance() = 0;
	virtual float calculateIntrest() = 0;
		void orderChecks();
	virtual void Display() =0;
};


//Savings Class with Inheritance from account
class savingsAccount : public bankAccount
{
public:
	savingsAccount(int a, float i, float b) : bankAccount(a,i, b)
	{}
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
		
		balance  = balance + dAmount;
		return balance;
		
	}

	//Get Balance for Saving
	float getBalance()
	{
		return balance;
	}
	//monthly intrest for savings
	float calculateIntrest()
	{
		if (balance < 10000)
		{
			balance = balance*pow((1 + .01 / 12), 12);
			return balance;
		}
		if (balance >= 10000)
		{
			balance = balance*pow((1 + .02 / 12), 12);
			return balance;
		}
		;
	}
	//Display Savings Account
	void Display()
	{
		cout << "Savings Account Number: " << accountNumber << endl;
		cout << "Savings Account Bal: " << balance << endl;
	}


};

//Checcking Class with Inheritance from account
class checkingAccount : public bankAccount
{



public:

	checkingAccount(int a, float i, float b) : bankAccount(a, i, b){}
	
	//Method checking Accouunt withdraw
	int withdraw(float wAmount)
	{
		if (balance - wAmount >= 0)
		{
			balance = balance - wAmount;
			return 0;
		}
		 if (balance > 500)
		 {
			 balance = balance - 5;
			 return 0;
		 }
		else
			return -1;
	}

	//Method checking Account Deposit
	float deposit(float dAmount)
	{

		balance = balance + dAmount;
		return balance;

	}

	//Get Balance for Saving
	float getBalance()
	{
		return balance;
	}

	void orderChecks()
	{
		balance = balance - 15;
	}
	//monthly intrest for checking
	float calculateIntrest()
	{
		return 0;
	}
	//Display checking Account
	void Display()
	{
		cout << "Checking Account Number: " << accountNumber << endl;
		cout << "Checking Account Bal: " << balance << endl;
	}

};


//CD Class with Inheritance from account
class certificateofDeposit : public bankAccount
{
	int term;
public:
	certificateofDeposit(int a, float i, float b) : bankAccount(a, i, b)

	{}
	//Method Savings Accouunt withdraw
	int withdraw(float wAmount)
	{
		if (balance - wAmount >= 0)
		{
			balance = balance  - wAmount;
			return 0;
		}
		if (term >= term )
		{
			balance = (balance *(1+.1)) - wAmount;
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
	}

	//monthly intrest for savings
	float calculateIntrest()
	{
		if (term < 5)
		{
			balance = balance*pow((1 + .1 / 12), 12);
			return balance;
		}
		if (term > 5)
		{
			balance = balance*pow((1 + .5 / 12), 12);
			return balance;
		}
		
	}
	//Display Savings Account
	void Display()
	{
		cout << "CD Account Number: " << accountNumber << endl;
		cout << "CD Account Bal: " << balance << endl;
	}
};


int main()
{
	int nBankAccounts = 10;
	
		
		bankAccount **acc = new bankAccount*[nBankAccounts];
		acc[0] = new savingsAccount(100,0,0); //Open Savings
		acc[1] = new checkingAccount(101, 0, 0); //Open Checking
		
	//Savings Account Deposit
		acc[0]->deposit(10000);
		

	//Checking account deposit
		acc[1]->deposit(600);

		//displacy savings, checking, cd
		acc[0]->Display();
		acc[1]->Display();

	//Savings Intresest
		cout << "\n---------\n" << endl;
		acc[0]->calculateIntrest();
		acc[0]->Display();
	
	//Savings Withdraw
		/*acc[0]->withdraw(1000)*/;
		

	
		


		
		//acc[1] = new checkingAccount(200, 0, 600, 600,0); //Open Checking
		//acc[1]->Display();								//Display Checking

		//acc[2] = new certificateofDeposit(300, 0, 10000, 10000, 3); //Open CD
		//acc[2]->Display();											//Display CD



		delete acc[0];
		delete acc[1];
		//delete acc[2];
		//delete[] acc;

	return 0;
}

 