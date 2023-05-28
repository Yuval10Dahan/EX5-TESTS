#include <iostream>
#include <algorithm>
#include "MagicalContainer.h"



using namespace std;



// Constructor
PrimeIterator::PrimeIterator(MagicalContainer &container) : mContainer_(container) {}

// default constructor


// copy constructor
PrimeIterator::PrimeIterator(const PrimeIterator &other) : mContainer_(other.getMagicalContainer()) {}

// destructor
PrimeIterator::~PrimeIterator() {}

// getters
MagicalContainer PrimeIterator::getMagicalContainer() const
{
    return this->mContainer_;
}

// operator= (Assignment operator)
PrimeIterator& PrimeIterator::operator=(const PrimeIterator &other)
{
    return *this;
}

// operator == 
bool PrimeIterator::operator==(const PrimeIterator &other) const
{
    return false;
}

// operator !=
bool PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return false;
}

// operator >
bool PrimeIterator::operator>(const PrimeIterator &other) const
{
    return false;
}

// operator <
bool PrimeIterator::operator<(const PrimeIterator &other) const
{
    return false;
}

// operator* (Dereference operator)
int PrimeIterator::operator*() const
{
    return 0;
}

// operator++ (prefix --> ++i)
PrimeIterator& PrimeIterator::operator++()
{
    return *this;
}


PrimeIterator PrimeIterator::begin()
{
    return *this;
}


PrimeIterator PrimeIterator::end()
{
    return *this;
}