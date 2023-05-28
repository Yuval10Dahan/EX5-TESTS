#include <iostream>
#include <algorithm>
#include "MagicalContainer.h"


using namespace std;



// this method adds a specific element to the container
void MagicalContainer::addElement(int element)
{
    // adds the element to the vector
    this->mysticalElements_.push_back(element);
}

// this method erase a specific element in the container - if there is such element
void MagicalContainer::removeElement(int element)
{
    // the vector has at least 1 element
    if(mysticalElements_.size() > 0)
    {
        // loop through the vector with the iterator
        for(auto loc = mysticalElements_.begin(); loc != mysticalElements_.end(); ++loc)
        {
            // if the contents of the current index is equal
            // to the given element - erase it from the vector
            if(*loc == element)
            {
                mysticalElements_.erase(loc);
            }
        }
    }

    else
    {
        throw runtime_error("There isn't such an element in the container\n");
    }
}

// this method return the container's size
int MagicalContainer::size() const
{
    return mysticalElements_.size();
}

