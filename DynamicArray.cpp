/****************************************************************************************************************************
Title          :   DynamicArray.cpp
Auhor          :   Team FBK
Modified By    :   ** ENTER YOUR NAME **
Description    :   implementation file of a dynamically resizeable array class
Dependencies   :   DynamicArray.hpp
****************************************************************************************************************************/

#include <iostream>

/****************************************************** Public Methods *****************************************************/

/* Default Constructor */
template <class T>
DynamicArray<T>::DynamicArray() : current_capacity_{1}, item_count_{0} // initializer list
{
    items_ = new T[current_capacity_]; /* initializes items_ to a dynamically 
                                           allocated array of size 
                                           current_capacity_ */
}

/* Destructor */
template <class T>
DynamicArray<T>::~DynamicArray()
{
    clear(); /* clear() releases dynamically allocated
                   memory - we want to repeat this behavior
                   in other methods, which is why the code 
                   in clear() is in its own function as 
                   opposed to simply being in the destructor */
}

/** 
    implements addition of an item of type T to the end of the caller
    @param new_entry to be added to the caller
    @post if successful, the caller contains the new_entry
    @return true if the addition was successful; false otherwise
*/
template <class T>
bool DynamicArray<T>::add(const T &new_entry)
{
    try
    {
        /*************************************
        *                                    *
        *                                    *
        *                                    *
        *        INSERT YOUR CODE HERE       *
        *                                    *
        *                                    *
        *                                    *
        *************************************/
    }
    catch (...)
    {
        return false;
    }
}

/**
    returns whether the caller contains parameter 
        T an_entry by checking whether its index 
        is above sentinel value -1
*/
template <class T>
bool DynamicArray<T>::contains(const T &an_entry) const
{
    return getIndexOf(an_entry) > -1;
}

/**
    returns whether the caller contains no items
 */
template <class T>
bool DynamicArray<T>::isEmpty() const
{
    return item_count_ == 0;
}

/**
    reassigns the caller's items_ array to parameter new_items_arr
    @param new_items_arr is a pointer to the first element of the
        array to which items_ will be assigned
    @param size is the number of entries in new_items_arr
    @post if successful, the items_ array has been assigned to new_items_arr
    @return true if the reassignment was successful; false otherwise
*/
template <class T>
bool DynamicArray<T>::setItems(T *new_items_arr, const size_t &size)
{
    try
    {
        clear();
        item_count_ = size;
        items_ = new_items_arr;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

/** 
    implements the removal of the first instance of parameter 
        an_item from the caller
    @param an_item to be removed from the caller
    @post if successful, the first instance of an_item has been 
        has been removed from the dynamic array 
    @return true if the removal was successful; false otherwise
*/
template <class T>
bool DynamicArray<T>::remove(const T &an_item)
{
    try
    {
        /*************************************
        *                                    *
        *                                    *
        *                                    *
        *        INSERT YOUR CODE HERE       *
        *                                    *
        *                                    *
        *                                    *
        *************************************/
    }
    catch (...)
    {
        return false;
    }

    return true;
}

/* Accessor: current_capacity_ */
template <class T>
size_t DynamicArray<T>::getCapacity() const
{
    return current_capacity_;
}

/* Accessor: item_count_ */
template <class T>
size_t DynamicArray<T>::getOccupiedSpaces() const
{
    return item_count_;
}

/* Accessor: items_ */
template <class T>
T *DynamicArray<T>::getItems() const
{
    return items_;
}

/**
    Releases dynamically allocated data and 
        handles the potential dangling pointer 
        that could be items_
*/
template <class T>
void DynamicArray<T>::clear()
{
    delete[] items_;
    item_count_ = 0;
    items_ = nullptr;
    current_capacity_ = 1;
}

/***************************************************** Private Methods *****************************************************/

/**
    returns whether the caller is full
    @pre item_count_ > -1
    @return true if the caller is at capacity; false otherwise
*/
template <class T>
bool DynamicArray<T>::atCapacity() const
{
    return item_count_ == current_capacity_;
}

/**
    @param target an object of type T that will be 
        parsed sought after in the caller
    @return the index of target if it is in the caller;
        -1 otherwise 
*/
template <class T>
int DynamicArray<T>::getIndexOf(const T &target) const
{
    bool found = false;
    int result = -1;
    int search_index = 0;

    // If the bag is empty, item_count_ is zero, so loop is skipped
    while (!found && (search_index < item_count_))
    {
        if (items_[search_index] == target)
        {
            found = true;
            result = search_index;
        }
        else
        {
            search_index++;
        } // end if
    }     // end while
    return result;
} // end getIndexOf

/* 
    copies the elements of items_ into a new dynamically allocated
        array which is either twice or half the size of current_capacity_
        depending on whether the resize was called because of an addition
        or a removal. If an item was added and items_ is now at capacity,
        double the size of the array. If an item was removed and 
        item_count_ < ( current_capacity / 4 ), reduce the size of the array
        by half.
*/
template <class T>
void DynamicArray<T>::resize()
{
    /*************************************
    *                                    *
    *                                    *
    *                                    *
    *        INSERT YOUR CODE HERE       *
    *                                    *
    *                                    *
    *                                    *
    *************************************/
    return;
}