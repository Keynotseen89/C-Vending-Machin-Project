#ifndef MACHINE_H
#define MACHINE_H

#include "ItemVen.h"
#include "Report.h"
#pragma once
#include <vector>
#include <string>

class Machine
{
protected:

	//values used to hold coines
	int quarter;
	int dimes;
	int nickels;
	
	//Object of ItemVen named items;
	ItemVen inventoryItem;
	static ItemVen totalInven;

	//using vector to keep track of things
	std::vector <std::string> selection;
	
	//using vector to keep track 
	//of postion of product
	std::vector <int> posSelection;

public:
	//transaction for Machine
	Report outputReport;
	virtual void plusSelectItem(std::string, int, int);
	virtual void printSelect();
	void printReport(std::vector <std::string> mID, int);
	virtual void trans();
	
	virtual void printMachine() = 0;
	virtual void reportDoc() = 0;
	Machine();
	//~Machine();
};

#endif