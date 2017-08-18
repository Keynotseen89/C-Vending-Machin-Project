#ifndef ITEMVEN_H
#define ITEMVEN_H


#include <string>
class ItemVen
{
private:
	int numCode[23];			//array to keep track of code of machine
	int numCount[23];			//number of count of product
	int numPrice[23];			//price of product
	std::string prodName[23];	//names of product
public:
	ItemVen();
	void printInventory();
	void restInventory();
	void adjustInventory(int,int);
	void pullInventory(int);
	int getLocation(int);
	bool checkValid(int);
	int getID(int);
	int getProduct(int );
	double getPrice(int );
	std::string getProductName(int);
	~ItemVen();
};

#endif