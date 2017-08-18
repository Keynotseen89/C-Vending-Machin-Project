#include "Machine.h"
#ifndef  M100A_H
#define  M100A_H

class M100A : public Machine
{
protected:
	//dollarBills put into the Machine
	int dollarBill;
public:
	M100A();
	void trans();
	bool calChange(int, int);
	void M100A::inCoin(int, int, int);
	void printMachine();
	void reportDoc();
	~M100A();
};

#endif

