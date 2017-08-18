#ifndef REPORT_H
#define REPORT_H
#pragma once
#include <vector>
#include <string>
class Report
{
public:

	int balance;			//Balance of coines
	int currentBalance;		//Current Balance left
	int amountOfCash[4];	//The amount of cash in
	int currentAmount[4];	//Current money 
	int transactions;		//Ones transaction
	std::vector <std::string> pickedItem;		//The product one picked out
	std::vector <int> itemPrice;				//The price of the product

	//This is what was put into the machine
	std::vector <int> amountPaid;
	std::vector <int> billPaid;
	std::vector <int> quarterP;
	std::vector <int> dimeP;
	std::vector <int> nickelsP;

	//This is what was returned back
	std::vector <int> change;
	std::vector <int> dollarC;
	std::vector <int> quarterC;
	std::vector <int> dimeC;
	std::vector <int> nickelsC;

	//This is what is in stock still
	std::vector <int> initialStock;

	Report();
	void init100A(int, int, int, int);											//What was in the Machine 100A
	void trans100A(std::string, int, int, int, int, int, int, int, int);		//The transaction made in Machine 100A
	void roundUp100A(int, int, int, int, int);									//Round up all of coins and dollors in Machine 100A

};

#endif