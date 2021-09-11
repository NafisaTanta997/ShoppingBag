/****************************************************************************************************************************
Title          :   Vegetable.cpp
Auhor          :   Nafisa Tanta
Dependencies   :   Vegetable.hpp
****************************************************************************************************************************/

#include <iostream>

#include "Vegetable.hpp"


using namespace std;
/* Parameterized Constructor */
Vegetable::Vegetable(string name, double price, double weight):Grocery(name, price, weight)
{
	updateCost();
}


void Vegetable :: updateCost()
{
	total_price_ = quantity_ * unit_weight_ * unit_price_;
}
