#include "Machine.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

/*
  @param empty 
  default function
*/
Machine::Machine()
{
	quarter = 0;
	dimes = 0;
	nickels = 0;
	
	inventoryItem.restInventory();	//Clears Inventory
	
}
/*
	@Param of string pick
	@Param of int number of item
	@Param of int amount of stocked product
*/
void Machine::plusSelectItem(string pick, int numberOfItem, int stockedProduct)
{
	selection.push_back(pick);
	inventoryItem.adjustInventory(numberOfItem, stockedProduct);
	posSelection.push_back(inventoryItem.getLocation(numberOfItem));
}

/*
	Prints the items that were selected
*/
void Machine::printSelect()
{
	for (int i = 0; i < selection.size(); i++)
	{
		//Calls inventory and checks if valided
		if (inventoryItem.checkValid(posSelection[i]) == true)
		{
			//prints out inventory properly
			cout << setw(11) <<setprecision(2) << fixed << selection[i] << " $ "
				<< inventoryItem.getPrice(posSelection[i])
				<< " " << inventoryItem.getProductName(posSelection[i]) << endl;
		}
	}
}

/*
	@Param of vactor mID 
	@Param of int postion of product
*/
void Machine::printReport(vector <string> mID, int posLoction)
{
	//Creates reportDoc
	ofstream reportDoc;
	reportDoc.open("reports.txt", std::ios_base::app);

	//Prints out information into reports.txt file
	reportDoc << "Machine: " << mID[posLoction] << endl;
	reportDoc << "Initial balance: $" << fixed << setprecision(2) << double(outputReport.balance) / 100 <<
		"  ($ " << outputReport.amountOfCash[0] << ", Q " << outputReport.amountOfCash[1] <<
		", D " << outputReport.amountOfCash[2] << ", N " << outputReport.amountOfCash[3] << ")\n\n";
	reportDoc << "Trans   " << "Items       " << "Cost   " << "Paid " << "($, Q, D, N)" << "Change  " << "(D, Q, D, N)" << endl;
	
	//Prints out into reports.txt the transaction that were made 
	//When buying porducts
	for (int i = 0; i<outputReport.transactions; i++)
	{
		reportDoc << "  " << (i + 1) << setw(9) << outputReport.pickedItem[i] << setw(12) << outputReport.itemPrice[i]
			<< setw(7) << outputReport.amountPaid[i] << " (" << outputReport.billPaid[i] << ", " << outputReport.quarterP[i] << ", "
			<< outputReport.dimeP[i] << ", " << outputReport.nickelsP[i] << ")" << setw(3) << outputReport.change[i] <<
			setw(5) << "  (" << outputReport.dollarC[i] << ", " << outputReport.quarterC[i] << ", " << outputReport.dimeC[i] <<
			", " << outputReport.nickelsC[i] << ")" << endl;
	}

	//Sets total cost to zero
	int totalCost = 0;

	//Set total itemPrices and keeps adding values
	//to totalCost untill no more product is purchased
	for (int i = 0; i<outputReport.itemPrice.size(); i++)
	{
		totalCost += outputReport.itemPrice[i];
	}

	//writs to reportDoc currentBallance, amount of Cash with Q, D, N
	reportDoc << "Total Cost:           " << totalCost << endl;
	reportDoc << endl;
	reportDoc << "Current Balance: $" << fixed << setprecision(2) << double(outputReport.currentBalance) / 100 << "($ " <<
		outputReport.amountOfCash[0] << ", Q " << outputReport.amountOfCash[1] << ", D " << outputReport.amountOfCash[2] <<
		", N " << outputReport.amountOfCash[3] << ")" << endl;
	reportDoc << endl;

	//Writes Code, ID, the Description of the product into reportDoc
	reportDoc << "Code      " << "ID      " << "Description " << "     Initial " << "   Current" << endl;
	for (int i = 0; i<selection.size(); i++)
	{
		reportDoc << selection[i] << setw(10) << inventoryItem.getID(posSelection[i]) << setw(20)
			<< inventoryItem.getProductName(posSelection[i]) << setw(10) << outputReport.initialStock[i] << setw(10) <<
			inventoryItem.getProductName(posSelection[i]) << endl;
	}
	reportDoc << "\n\n\n";

	//Closes reprotDoc
	reportDoc.close();
}

/*
	Creates temporary code for transastion
*/
void Machine::trans()
{
	cout << "temporary code." << endl;
}
//Machine::~Machine()
//{
//}
