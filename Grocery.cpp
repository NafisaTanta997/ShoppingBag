/****************************************************************************************************************************
Title          :   Grocery.cpp
Auhor          :   Team FBK
Modified By    :   ** ENTER YOUR NAME **
Description    :   implementation file of a dynamically resizeable array class
Dependencies   :   Grocery.hpp
****************************************************************************************************************************/

#include "Grocery.hpp"

Grocery::Grocery(std::string name, double price, double weight) : name_{name}, unit_price_{price}, unit_weight_{weight}, quantity_{1}
{
}

bool Grocery::incrementQuantity()
{
    quantity_++;
    updateCost();
    return true;
}

bool Grocery::decrementQuantity()
{
    if (quantity_ > 0)
    {
        quantity_--;
        updateCost();
        return true;
    }
    return false;
}

double Grocery::getTotalPrice() const
{
    return total_price_;
}

double Grocery::getUnitPrice() const
{
    return unit_price_;
}

double Grocery::getUnitWeight() const
{
    return unit_weight_;
}

int Grocery::getQuantity() const
{
    return quantity_;
}

std::string Grocery::getName() const
{
    return name_;
}

//Assignment operator overload
bool Grocery::operator==(const Grocery &rhs) const
{
    return rhs.getName() == name_ && rhs.getUnitPrice() == unit_price_ && rhs.getQuantity() == quantity_ && rhs.getUnitWeight() == unit_weight_;
}
