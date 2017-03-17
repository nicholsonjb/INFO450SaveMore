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
		void withdraws();
		void deposits();

		
		virtual void display() = 0;		
		
};



int main()
{
    return 0;
}

