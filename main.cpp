/*
Program:	CSCI-140-Project4
Author :	Quinatzin Sintora
Class  :	CSCI 140 MW
Date   :	6/01/2017
Description:	Vending Machine with classes.  This programe reads from two doc files.  One 
of the files is machineTest, the other file is product which holds the inventory.
This reads the files so that the customer/user and choice from the vending machine 
which candy they want but only allowed to enter a Dollar.
This returns in change of Quarter, Dimes, and Nickels only if Machine has propler amount in system.
*/


#include "Machine.h"
#include "Report.h"
#include "M100A.h"
#include "ItemVen.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>


using namespace std;

void fillMachine(vector<Machine*> &v, vector<string> &mCode);
bool bootupCode();
int selectedMachine(vector<string> mCode);
void createReport(vector<Machine*> &m, vector<string> mCode);
void displayReport(vector<Machine*> &m, vector<string> mCode);
int main()
{
	vector <Machine*> m;
	vector <string> mCode;

	cout << "Author : Quinatzin Sintora. " << endl;

	bool boot = bootupCode();
	if (!boot)
	{
		cout << "Invailed code. System powering off." << endl;
		return 0;
	}

	fillMachine(m, mCode);

	cout << "Available machines: ";
	for (int i = 0; i < mCode.size(); i++)
	{
		cout << mCode[i] << ", ";
	}
	cout << endl;

	while (true)
	{
		int mNum = selectedMachine(mCode);

		if (mNum == -1)
		{
			cout << "Invalid machine ID. Try again" << endl;
			//continue;
		}
		else if (mNum == -2)
		{
			
			createReport(m, mCode);
			displayReport(m, mCode);
			return 0;
		}
		cout << "Available items:" << endl;
		m[mNum]->printSelect();
		m[mNum]->trans();
		
	}

	system("Pause");
	return 0;
}//end of main

int selectedMachine(vector<string> mCode)
{
	string machineCode;
	cout << "\nSelect a machine--> ";
	cin >> machineCode;

	if (machineCode == "100A1" || machineCode == "100A2")
	{
		cout << "This machine accepts one-dollar bill only." << endl;
	}
	//Secret code to Machine
	//After propler entered  Report is generated and 
	//System shuts down 
	else if (machineCode == "20171989")
	{
		cout << "Report is generating..." << endl;
		cout << "System is shutting down." << endl;
		return -2;
	}

	//This gets the size of the mCode
	//id and compars digits
	for (int i = 0; i<mCode.size(); i++)
	{

		if (machineCode == mCode[i])
		{
			return i;
		}
	}
	return -1;
}

//This check if machine boots up properly 
bool bootupCode()
{
	int startCode = 2017;
	int inputVale;

	cout << "Please enter a startup code --> ";
	cin >> inputVale;
	
	//Checks if inputVale matches startCode
	//If so return true
	//else return false
	if (inputVale == startCode)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void fillMachine(vector<Machine*> &v, vector<string> &mCode)
{
	cout << "Initialize machines.  Please wait..." << endl;
	cout << "Machines are ready." << endl;

	string typeM;
	int machCount;
	int quarters, dimes, nickels, itemAmount, itemNumber, itemStock;
	string itemChoice;

	ifstream machineFile("machines.txt");
	while (true)
	{
		machineFile >> typeM >> machCount;
		if (machineFile.eof())
		{
			break;
		}
		for (int i = 0; i<machCount; i++)
		{
			//adds 100A
			if (typeM == "100A")
			{
				v.push_back(new M100A);
				//Add the change
				machineFile >> quarters >> dimes >> nickels;
				v[v.size() - 1]->outputReport.balance += (quarters * 25) + (dimes * 10) + (nickels * 5);
				v[v.size() - 1]->outputReport.amountOfCash[0] = 0;
				v[v.size() - 1]->outputReport.amountOfCash[1] = quarters;
				v[v.size() - 1]->outputReport.amountOfCash[2] = dimes;
				v[v.size() - 1]->outputReport.amountOfCash[3] = nickels;
				static_cast<M100A*> (v[v.size() - 1])->inCoin(quarters, dimes, nickels);
				//add items
				machineFile >> itemAmount;
				for (int i = 0; i<itemAmount; i++)
				{
					machineFile >> itemChoice >> itemNumber >> itemStock;
					v[v.size() - 1]->plusSelectItem(itemChoice, itemNumber, itemStock);
					v[v.size() - 1]->outputReport.initialStock.push_back(itemStock);
				}

				string machineString = "100A" + to_string(i + 1);
				mCode.push_back(machineString);
			}//end ofif statement
	
		}//end of for loop
	}//end of while loop
	machineFile.close();
}//end of fillMachine code

void createReport(vector<Machine*> &m, vector<string> mCode)
{
	for (int i = 0; i<m.size(); i++)
	{
		m[i]->printMachine();
	}
}
void displayReport(vector<Machine*> &m, vector<string> mID)
{
	for (int i = 0; i<m.size(); i++)
	{
		m[i]->printReport(mID, i);
	}
}