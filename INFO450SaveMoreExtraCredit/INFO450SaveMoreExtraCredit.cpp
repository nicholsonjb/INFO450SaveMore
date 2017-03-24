// INFO450SaveMoreExtraCredit.cpp : Defines the entry point for the console application.
//

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
	virtual int withdraw(float wAmount) = 0;
	virtual float deposit(float dAmount) = 0;
	virtual float getBalance() = 0;
	virtual float calculateIntrest() = 0;
	virtual float orderChecks() = 0;
	virtual void Display() = 0;
};


//Savings Class with Inheritance from account
class savingsAccount : public bankAccount
{
public:
	savingsAccount(int a, float i, float b) : bankAccount(a, i, b)
	{
	}

	//Method Savings Accouunt withdraw
	int withdraw(float wAmount)
	{
		if (balance - wAmount >= 0)
		{

			balance = (balance - 2) - wAmount;
			return 0;
		}
		else
			return -1;
	}

	//Method Savings Account Deposit
	float deposit(float dAmount)
	{
		interestRate = 0;
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
		if (balance < 10000)
		{
			interestRate = pow((1 + .01 / 12), 12);
			balance = balance *interestRate;
			return interestRate;
		}
		if (balance >= 10000)
		{
			interestRate = pow((1 + .02 / 12), 12);
			balance = balance * interestRate;
			return interestRate;
		};
	}

	//order checks
	float orderChecks()
	{
		return 0;
	}

	//Display Savings Account
	void Display()
	{
		cout << "Savings Account Number: " << accountNumber << endl;
		cout << "Savings Account Interest: " << interestRate << endl;
		cout << "Savings Account Bal: " << balance;
	}
};

//Checcking Class with Inheritance from account
class checkingAccount : public bankAccount
{
public:

	checkingAccount(int a, float i, float b) : bankAccount(a, i, b)
	{
		interestRate = 0;
	}

	//Method checking Accouunt withdraw
	int withdraw(float wAmount)
	{
		if (balance - wAmount >= 0)
		{

			balance = balance - wAmount;

		}
		if (balance < 500)
		{

			balance = (balance - 5);
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

	//Get Balance for Checking
	float getBalance()
	{
		return balance;
	}

	float orderChecks()
	{
		balance = balance - 15;
		return balance;
	}

	//monthly intrest for checking
	float calculateIntrest()
	{
		return interestRate;
	}

	//Display checking Account
	void Display()
	{
		cout << "Checking Account Number: " << accountNumber << endl;
		cout << "Checking Interest Rate: " << interestRate << endl;
		cout << "Checking Account Bal: " << balance;
	}
};


//CD Class with Inheritance from account
class certificateofDeposit : public bankAccount
{
	int term;
public:
	certificateofDeposit(int a, float i, float b, int t) : bankAccount(a, i, b)

	{
		term = t;
	}

	//Method Savings Accouunt withdraw

	int withdraw(float wAmount)
	{
		if (balance - wAmount >= 0)
		{
			interestRate = 0;
			balance = (balance - (balance * .1)) - wAmount;
			return 0;
		}

		else
			return -1;
	}

	//Method CD Account Deposit
	float deposit(float dAmount)
	{
		interestRate = 0;
		balance = balance + dAmount;
		return balance;
	}

	//Get Balance for CD
	float getBalance()
	{
		return balance;
	}

	//monthly intrest for CD
	float calculateIntrest()
	{
		if (term < 5)
		{
			interestRate = pow((1 + .1 / 12), 12);
			balance = balance * interestRate;
			return interestRate;
		}
		if (term >= 5)
		{
			interestRate = pow((1 + .1 / 12), 12);
			balance = balance *interestRate;
			return interestRate;
		}
	}

	float orderChecks()
	{
		return 0;
	}

	//Display  CD Account
	void Display()
	{
		cout << "CD Account Number: " << accountNumber << endl;
		cout << "CD Interest Rate: " << interestRate << endl;
		cout << "CD Account Bal: " << balance;
	}
};


int main()
{
	int nBankAccounts = 10;

	//allocate memory for bankaccount
	bankAccount** acc = new bankAccount*[nBankAccounts];

	acc[0] = new savingsAccount(100, 0, 0); //Open Savings
	acc[1] = new checkingAccount(101, 0, 0); //Open Checking
	acc[2] = new certificateofDeposit(102, 0, 0, 3); //Open CD

													 //Savings Account Deposit

	acc[0]->deposit(10000);


	//Checking account deposit
	acc[1]->deposit(600);

	//CD Deposit
	acc[2]->deposit(10000);

	//displacy savings, checking, cd
	cout << "Deposit New Savings:" << endl;
	acc[0]->Display();
	cout << "\n" << endl;
	cout << "Deposit New Checking:" << endl;
	acc[1]->Display();
	cout << "\n" << endl;
	cout << "Deposit New CD:" << endl;
	acc[2]->Display();

	//Savings Intresest
	cout << "\n\n---------\n";
	cout << "Savings Intrest:" << endl;
	acc[0]->calculateIntrest();
	acc[2]->calculateIntrest();
	acc[0]->Display();
	cout << "\n\nCD Intrest:" << endl;
	acc[2]->Display();

	//Order checks
	cout << "\n\n---------\n" << endl;
	cout << "Order Checks:" << endl;
	acc[1]->orderChecks();
	acc[1]->Display();

	//Savings Withdraw
	cout << "\n\n---------\n" << endl;
	cout << "Withdraw Savings:" << endl;
	acc[0]->withdraw(1000);
	acc[0]->Display();

	//Withdraw Checking
	cout << "\n" << endl;
	cout << "Withdraw Checking:" << endl;
	acc[1]->withdraw(200);
	acc[1]->Display();

	//withdraw CD
	cout << "\n" << endl;
	cout << "Withdraw CD:" << endl;
	acc[2]->withdraw(2000);
	acc[2]->Display();
	cout << "\n" << endl;


	//clear memory
	delete acc[0];
	delete acc[1];
	delete acc[2];
	delete[] acc;

	return 0;
}
