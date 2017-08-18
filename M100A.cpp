
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "M100A.h"
//#include "Machine.h"
using namespace std;

M100A::M100A() : Machine()
{
	dollarBill = 0;
}
void M100A::trans()
{
	//cout << "This machine accepts one-dollar bills." << endl;

	string custSelection;				//customer selection of product
	int itemSelection;					//Item that were picke	
	int enteredBills = 0;				// bills entered in coins
	int userEntry;						//used to enter coins/bills
	int userEntryTwo;					//used to stop entere values
	bool selectionFound = false;		//used for option


	while (true)
	{
		cout << "Select item -->";
		cin >> custSelection;

		//checks if item selected is in the system
		for (int i = 0; i<selection.size(); i++)
		{
			if (custSelection == selection[i])
			{
				selectionFound = true;
				itemSelection = i;
			}
		}

		//If item is not found do this
		if (selectionFound == false)
		{
			cout << "Input is not one of the selectable items" << endl;
		}
		else
		{
			//This makes the code go to the next 
			//bottom part of the code
			break;
		}
	}

	//Prompt user choice of selection and cost of product
	cout << "You selected " << "\"" << inventoryItem.getProductName(posSelection[itemSelection])<< "\". "  << endl;
	cout << "The cost of this item is $" << fixed << setprecision(2) << inventoryItem.getPrice(posSelection[itemSelection]) << endl;

	//Prompts user to enter amount of money / coins
	cout << "Insert money--> ";
	
	while (true)
	{
		cin >> userEntry >> userEntryTwo;

		//if coins is not ZERO and second input is ZERO
		//countine and do this part of the code 
		if (userEntry != 0 && userEntryTwo == 0)
		{
			//add valued of coins entered into enteredBills
			enteredBills = enteredBills + userEntry;
			cin.clear();									//This clears the input for new input
			
			//Prompts user with amount that was entered by User in coins form not dollar
			cout << "\n\nYou have entered an amount of " << enteredBills << " cents." << endl;
			cout << "Processing your  purchase..." << endl;
			break;
		}

		//If first input is ZERO then 
		//Promp with message of Cancelation
		else if( userEntry == 0)
			{
			
				cout << "You chose to cancel your selection." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
				break;
			}
			

	}

	//Calls validTanstion function
	bool validTrans = calChange(inventoryItem.getPrice(posSelection[itemSelection]) * 100, enteredBills);
	
	//If not enought in the machine then the system shall return
	//User money back to them
	if (!validTrans)
	{
		cout << "Returning money entered... " << endl;
	}

	//Else continue pulling Inventory and print out 
	//
	else
	{
		inventoryItem.pullInventory(posSelection[itemSelection]);
		cout << "Thank you! Please take your item." << endl;

		//report
		outputReport.amountPaid.push_back(enteredBills);
		outputReport.billPaid.push_back(enteredBills / 100);
		outputReport.quarterP.push_back(0);
		outputReport.dimeP.push_back(0);
		outputReport.nickelsP.push_back(0);
		outputReport.pickedItem.push_back(custSelection);
		outputReport.itemPrice.push_back(inventoryItem.getPrice(posSelection[itemSelection]) * 100);
		outputReport.transactions++;
	}

}

/*
	@Param of int cost
	@Param of int entryed amount
*/
bool M100A::calChange(int cost, int entry)
{
	
	int dollarsTemp = dollarBill + (entry / 100);				//Sets dollarTemp to dollarBill 
	int quarterCheck, dimeCheck, nickelCheck, dollarCheck;		//used of Q,D,N,DollarCheck
	int quarterNeed, dimeNeed, nickelNeed, dollarNeed;			//Used for Needed coins and dollarbill
	int changeRequired;											//Used for change needed
	int quarterUsed, dimeUsed, nickelUsed, dollarUsed;			//Used for for keeping track of coins and dollar used
	
	//If bill is entered as zero return false
	if (entry == 0)
	{
		return false;
	}
	
	//determine if enough money was entered for item
	else if (entry<cost)
	{
		cout << "Not enough money entered for item" << endl;
		dollarBill = dollarBill- (entry - 100);
		return false;
	}

	//Used to get change needed
	changeRequired = entry - cost;

	
	int initialChange = changeRequired;

	//dollars
	dollarCheck = changeRequired - (changeRequired % 100);
	dollarNeed = dollarCheck / 100;
	if (dollarsTemp >= dollarNeed)
	{
		changeRequired = changeRequired - dollarCheck;
		dollarUsed = dollarNeed;
	}
	else
	{
		dollarUsed = dollarsTemp;
		changeRequired = changeRequired - (dollarUsed * 100);
	}

	//quarters	
	quarterCheck = changeRequired - (changeRequired % 25);
	quarterNeed = quarterCheck / 25;
	if (quarter >= quarterNeed)
	{
		changeRequired = changeRequired - quarterCheck;
		quarterUsed = quarterNeed;
	}
	else
	{
		quarterUsed = quarter;
		changeRequired = changeRequired - (quarterUsed * 25);
	}

	//dimes
	dimeCheck = changeRequired - (changeRequired % 10);
	dimeNeed = dimeCheck / 10;
	if (dimes >= dimeNeed)
	{
		changeRequired = changeRequired - dimeCheck;
		dimeUsed = dimeNeed;
	}
	else
	{
		dimeUsed = dimes;
		changeRequired = changeRequired - (dimeUsed * 10);
	}

	//nickels
	nickelCheck = changeRequired - (changeRequired % 5);
	nickelNeed = nickelCheck / 5;
	if (nickels >= nickelNeed)
	{
		changeRequired = changeRequired - nickelCheck;
		nickelUsed = nickelNeed;
	}
	else
	{
		nickelUsed = nickels;
		changeRequired = changeRequired - (nickelUsed * 5);
	}

	if (changeRequired != 0)
	{
		cout << "Not enough change in machine." << endl;
		return false;
	}
	else
	{

		dollarBill = dollarsTemp - dollarUsed;
		quarter = quarter - quarterUsed;
		dimes = dimes - dimeUsed;
		nickels = nickels - nickelUsed;

		//This prints out the change returned to the User
		cout << "Your change of " << initialChange << " cents is given as: " << endl;
		
		cout << "\tdollar(s): " << setw(2) << dollarUsed << endl;
		cout << "\tquarter(s): " << quarterUsed << endl;
		cout <<  "\tdime(s): " << setw(4) << dimeUsed << endl;
		cout <<  "\tnickel(s) " << setw(3) << nickelUsed << endl;

		//This put values in outputReport to keep track
		outputReport.change.push_back(initialChange);
		outputReport.dollarC.push_back(dollarUsed);
		outputReport.quarterC.push_back(quarterUsed);
		outputReport.dimeC.push_back(dimeUsed);
		outputReport.nickelsC.push_back(nickelUsed);
		return true;
	}
}

/*
	@Param of int coin of Quarter
	@Param of int coin of Dimes
	@Param of int coin of Nickels
*/
void M100A::inCoin(int coinQ, int coinD, int coinN)
{
	quarter = coinQ;
	dimes = coinD;
	nickels = coinN;
}

/*
	Prints inventory item
*/
void M100A::printMachine()
{
	inventoryItem.printInventory();
}

/*
	documents Report at the end of the system.
*/
void M100A::reportDoc()
{
	outputReport.currentBalance = (dollarBill * 100) + (quarter * 25) + (dimes * 10) + (nickels * 5);
	outputReport.currentAmount[0] = dollarBill;
	outputReport.currentAmount[1] = quarter;
	outputReport.currentAmount[2] = dimes;
	outputReport.currentAmount[3] = nickels;
}

M100A::~M100A()
{
}
