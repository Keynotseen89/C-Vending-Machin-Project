#include "ItemVen.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
	Default contrustor
*/
ItemVen::ItemVen()
{
	string inventory;
	ifstream inputFile("products.txt");

	//use to obtain inventory and add into arry for Code, Count,
	//Price and name of Product in text
	for (int i = 0; i < 23; i++)
	{
		inputFile >> this->numCode[i] >> this->numCount[i]
			>> this-> numPrice[i];
		
		//used to get full string of Inventory namej
		getline(inputFile, this->prodName[i]);
	}
	//close file that was opened
	inputFile.close();
}

/*
	Displays Inventory from product.txt
*/
void ItemVen::printInventory()
{
	//This prints Inventoray to the screen
	for (int i = 0; i < 23; i++)
	{
		if (numCount[i] > 0)
		{
			
			cout << this->numCode[i] << " " << this->numCount[i] << " " << numPrice[i]
				<< " " << this->prodName[i] << endl;
		}
	}
	
}

//Clear Inventory from array
void ItemVen::restInventory()
{
	//Change index from number of product into 
	//zero 
	for (int i = 0; i < 23; i++)
	{
		this->numCount[i] = 0;
	}
}

/*
	@Param using int numVale
	@param using int product stock
*/
void ItemVen::adjustInventory(int numVale, int inStock)
{
	//this adjust the prodcut 
	for (int i = 0; i < 23; i++)
	{
		//use Param numVale
		//check if matched with numCode
		//then change amount of instock
		if (numVale == numCode[i])
		{
			numCount[i] = inStock;
		}
	}
}
/*
	@Param of int inventory to subtract
*/
void ItemVen::pullInventory(int inventoryNum)
{
	if (numCount[inventoryNum] == 0)
	{
		cout << "OUT OF STOCK of (" << numCode[inventoryNum] << endl;
		return;
	}
	numCount[inventoryNum]--;
}

/*
	@Param int num of Product
	@return location/postion of codeNum
*/
int ItemVen::getLocation(int codeNum)
{
	//Position of codeNum
	int location;

	for (int c = 0; c < 23; c++)
	{
		if (numCode[c] == codeNum)
		{
			location = c;
		}
	}
	return location;
}

/*
 @Param int postion of product
 @Return true/false
*/
bool ItemVen::checkValid(int location)
{
	//set venStock to false
	bool venStock = false;
	if (numCount[location] > 0)
	{
		venStock = true;
	}
	return venStock;
}

/*
	@Param location of ID
	@return numCode
*/
int ItemVen::getID(int idLocation)
{
	return numCode[idLocation];
}

/*
	@Param location of count
	@return count
*/
int ItemVen::getProduct(int location)
{
	return numCount[location];
}

/*
	@Param int location
	@return price
*/
double ItemVen::getPrice(int location)
{
	//varable of priceValue
	double priceValue;

	//Cast value of numPrice to double
	priceValue = double(numPrice[location]) / 100;

	//return priceValue;
	return priceValue;
}

/*
	used to return product name;
*/
std::string ItemVen::getProductName(int location)
{
	return prodName[location];
}
ItemVen::~ItemVen()
{
}
