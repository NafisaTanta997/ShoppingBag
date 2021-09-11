/****************************************************************************************************************************
Title         :   ShoppingCart.hpp
Auhor         :   Nafisa Tanta
****************************************************************************************************************************/

#ifndef SHOPPING_CART_
#define SHOPPING_CART_

#include "DynamicArray.hpp"
#include "Grocery.hpp"

#include <string>
#include <vector>

using namespace std;


class ShoppingCart : public DynamicArray<Grocery*>
{
public:
	ShoppingCart();
	~ShoppingCart();

	bool add(Grocery* new_entry);
	bool remove(Grocery* an_item);
	double checkout();
	void garbageClear();
	double getCurrentWeight();
	double getMaxWeight();
	void setWeight(double num);
	
private:
	DynamicArray<Grocery*> shopping_list_;
	double curr_contents_weight_;
	const int max_weight_ = 350;
	
};


#endif