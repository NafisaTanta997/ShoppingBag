/****************************************************************************************************************************
Title         :   Vegetable.hpp
Auhor         :   Nafisa Tanta
****************************************************************************************************************************/

#ifndef VEGETABLE_
#define VEGETABLE_

#include "Grocery.hpp"
#include <string>

using namespace std;

class Vegetable : public Grocery
{
public:
	
	Vegetable(string name, double price, double weight);

	void updateCost();
	
protected:
	
	std::string price = "dollars";
	std::string unit = "pounds (lb)";
};

#endif
