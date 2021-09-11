/****************************************************************************************************************************
Title          :   ShoppingCart.cpp
Auhor          :   Nafisa Tanta
Dependencies   :   ShoppingCart.hpp
****************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "ShoppingCart.hpp"


using namespace std;

/****************************************************** Public Methods *****************************************************/



/* Default Constructor */

ShoppingCart::ShoppingCart() :DynamicArray<Grocery*>()
{
}

/* Destructor */

ShoppingCart::~ShoppingCart()
{
    clear(); /* clear() releases dynamically allocated
                   memory - we want to repeat this behavior
                   in other methods, which is why the code
                   in clear() is in its own function as
                   opposed to simply being in the destructor */
}

/*
      adds new_entry to the caller; if the entry
      already exists in the caller, increment
      quantity_ in the object, and increment
      the curr_contents_weight_ of the caller
      by the unit_weight_ of the added item.

      @pre    :   the addition of the weight of
                  new_entry does not bring the
                  curr_contents_weight_ over the
                  carrying capacity

      @return :   true if the addition is successful
*/

bool ShoppingCart::add(Grocery* new_entry)
{
    double weight = new_entry->getUnitWeight();
    double new_w = 0;
    double temp_weight = getMaxWeight() - getCurrentWeight();
    int k = DynamicArray::getIndexOf(new_entry);
    try
    {
        if (DynamicArray::contains(new_entry))
        {
            items_[k]->incrementQuantity();
        }
        else
        {
            DynamicArray::add(new_entry);
        }
        new_w = getCurrentWeight() + weight;
        setWeight(new_w);
        return true;

    }
    catch (...)
    {
        return false;
    }
}

/*
      removes the first instance of an_item from the caller;
      if the entry already exists in the caller, decrement
      quantity_ in the object, and decrement the
      curr_contents_weight_ of the caller by the
      unit_weight_ of the added item.
      --> !!!THIS FUNCTION MUST CALL garbageClear()!!! <--
      @return :   true if the addition is successful
*/

bool ShoppingCart::remove(Grocery* an_item)
{
    try
    {
        double weight1 = an_item->getUnitWeight();
        double new_weight1 = 0;
        int k = DynamicArray::getIndexOf(an_item);
        if (DynamicArray::contains(an_item))
        {
            items_[k]->decrementQuantity();
        }
        else
        {
            DynamicArray::remove(an_item);
        }

        new_weight1 = getCurrentWeight() - weight1;
        setWeight(new_weight1);

        garbageClear();
        return true;
    }
    catch (...)
    {
        return false;
    }
}

/* displays shopping cart contents in required format */

double ShoppingCart::checkout()
{
    if (item_count_ == 0)
    {
        std::cout << "Your cart is empty!" << std::endl;
        return 0;
    }

    double total = 0;
    for (size_t i = 0; i < item_count_; i++)
    {
        std::cout << "\n" << std::setw(10) << std::left <<
            items_[i]->getName() << "\t" << items_[i]->getQuantity()
            << "\t" << std::fixed << std::setprecision(2)
            << items_[i]->getTotalPrice();
        total += items_[i]->getTotalPrice();
    }
    std::cout << std::setfill('-') << std::setw(40) << "\n"
        << std::endl << "Total:                  "
        << total << std::endl << std::endl;
    clear();
    return total;
}

/*
      iterates through caller and removes items whose quantity_ == 0
      --> !!!THIS FUNCTION MUST CALL DynamicArray::remove()!!! <--
      @post   :   every item in the caller has quantity_ >= 1
*/
void ShoppingCart::garbageClear()
{
    for (int i = 0; i < item_count_; i++)
    {
        if (items_[i]->getQuantity() == 0)
        {
            DynamicArray::remove(items_[i]);
        }
    }
}

/* Getter: curr_contents_weight_ */
double ShoppingCart::getCurrentWeight()
{
    return curr_contents_weight_;
}

double ShoppingCart::getMaxWeight()
{
    return max_weight_;
}

void ShoppingCart::setWeight(double num)
{
    curr_contents_weight_ = num;
}


