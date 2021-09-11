/****************************************************************************************************************************
Title          :   JunkFood.cpp
Auhor          :   Nafisa Tanta
Dependencies   :   JunkFood.hpp
****************************************************************************************************************************/

#include <iostream>
#include "JunkFood.hpp"


using namespace std;

/****************************************************** Public Methods *****************************************************/

/* Parameterized Constructor */
JunkFood::JunkFood(string name, double price, double weight) :Grocery(name, price, weight)
{
	updateCost();
}


void JunkFood :: updateCost()
{
	total_price_ = quantity_ * unit_price_;
}