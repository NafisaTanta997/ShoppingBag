/****************************************************************************************************************************
Title          :   Drink.cpp
Auhor          :   Nafisa Tanta
Dependencies   :   Drink.hpp
****************************************************************************************************************************/

#include <iostream>
#include "Drink.hpp"

using namespace std;

/****************************************************** Public Methods *****************************************************/

/* Parameterized Constructor */
Drink::Drink(string name, double price, double weight):Grocery(name, price, weight)
{
	updateCost();
}


void Drink :: updateCost()
{
	total_price_ = quantity_* (unit_weight_ * 16 / 33.814)* unit_price_;
}