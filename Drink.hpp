/****************************************************************************************************************************
Title         :   Drink.hpp
Auhor         :   Nafisa Tanta
****************************************************************************************************************************/
#ifndef DRINK_
#define DRINK_

#include "Grocery.hpp"
#include <string>


using namespace std;

class Drink : public Grocery
{

public:
	Drink(string name, double price, double weight);

	void updateCost();

protected:

	std::string price = "dollars";
	std::string unit = "pounds (lb)";

};


#endif