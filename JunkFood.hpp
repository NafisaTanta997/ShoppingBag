/****************************************************************************************************************************
Title         :   JunkFood.hpp
Auhor         :   Nafisa Tanta
****************************************************************************************************************************/

#ifndef JUNKFOOD_
#define JUNKFOOD_

#include "Grocery.hpp"
#include <string>

using namespace std;

class JunkFood : public Grocery
{
public:

	JunkFood(std::string name, double price, double weight);
	void updateCost();

protected:
	std::string price = "dollars";
	std::string unit = "pounds (lb)";
	
};


#endif