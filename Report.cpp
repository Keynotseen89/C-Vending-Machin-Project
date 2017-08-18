#include "Report.h"
#include <iostream>
#include <string>

using namespace std;

/*
	Default Constructor
*/
Report::Report()
{
	balance = 0;
	currentBalance = 0;
	for (int i = 0; i<4; i++)
	{
		amountOfCash[i] = 0;
		currentAmount[i] = 0;
	}
	transactions = 0;
}

/*
	@Param of  int balanceLeft
	@Param of int amount of quarter
	@Param of int amount of dimes 
	@Param of int amount of nickels
*/
void Report::init100A(int balanceLeft, int qAm, int dAm, int nAm)
{
	balance = balanceLeft;
	amountOfCash[0] = 0;
	amountOfCash[1] = qAm;
	amountOfCash[2] = dAm;
	amountOfCash[3] = nAm;
}

/*
	@Param of string item selected
	@Param of int of item price
	@Param of int of transation paid
	@Param of int of dollar bills paid
	@Param of int change given back
	@Param of int the change in dollars
	@Param of int change of Quarter
	@Param of int change of Dimes
	@Param of int change of Nickels
*/
void Report::trans100A(std::string choice, int priceOfItem, int tran_paid, int paid_dollars, int givenChange, int changeDollars, int changeInQ, int changeInD, int changeInN)
{
	pickedItem.push_back(choice);
	itemPrice.push_back(priceOfItem);
	amountPaid.push_back(tran_paid);
	billPaid.push_back(paid_dollars);
	change.push_back(givenChange);
	dollarC.push_back(changeDollars);
	quarterC.push_back(changeInQ);
	dimeC.push_back(changeInD);
	nickelsC.push_back(changeInN);
}

/*
	@Param of int balance
	@Param of int current amount Dollar bills
	@Param of int current amount Quarter
	@Param of int current amount of Dimes
	@Param of int current amount of Nickels
*/
void Report::roundUp100A(int balance, int currentDol, int qCurrent, int cDimes, int cNickels)
{
	currentBalance = balance;			//balance into currentBalance
	
	//Add values into index of vector of currentAmount
	currentAmount[0] = currentDol;		
	currentAmount[1] = qCurrent;
	currentAmount[2] = cDimes;
	currentAmount[3] = cNickels;
}
//Report::~Report()
//{
//}
