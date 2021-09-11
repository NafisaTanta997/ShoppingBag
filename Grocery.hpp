/****************************************************************************************************************************
Title         :   Grocery.hpp
Auhor         :   Team FBK
Description   :   header/interface file of a dynamically resizeable array class
****************************************************************************************************************************/

#ifndef GROCERY_
#define GROCERY_

#include <iostream>
#include <string>

class Grocery
{
    public:

        /** 
            Set the quantity_ to 1 and total_price_ to 0. Set name_, unit_price_, and unit_weight_ to what was given by the user.
        */
        Grocery(std::string name, double price, double weight);

        /**
            Increase quantity_ by one and call updateCost().

            If the function works, return true.
        */
        bool incrementQuantity();

        /**
            Decrease the quantity by one if there is at least a quantity of 1,
                and call updateCost().

            If the function works, return true
        */
        bool decrementQuantity();

        double getTotalPrice() const;                   // returns total_price_
        double getUnitPrice() const;                    // returns unit_cost_
        double getUnitWeight() const;                   // returns unit_weight_
        int getQuantity() const;                        // returns quantity_
        std::string getName() const;                    // returns name_

        bool operator==(const Grocery &rhs) const;      // Comparison operator overload


    protected:
        
        /*
            Calculates the total cost of the items in the class.
        */
        virtual void updateCost() = 0;

        std::string name_;
        int quantity_;
        double unit_price_;
        double unit_weight_;
        double total_price_;
}; // end Grocery

#endif