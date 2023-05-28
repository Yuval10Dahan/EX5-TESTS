#include <iostream>
#include <algorithm>
#include "MagicalContainer.h"



using namespace std;



// Constructor
SideCrossIterator::SideCrossIterator(MagicalContainer &container) : mContainer_(container) {}

// // default constructor
// SideCrossIterator::SideCrossIterator() : mContainer_(MagicalContainer()) {}

// copy constructor
SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : mContainer_(other.mContainer_) {}

// destructor
SideCrossIterator::~SideCrossIterator() {}

// getters
MagicalContainer SideCrossIterator::getMagicalContainer() const
{
    return this->mContainer_;
}

// operator= (Assignment operator)
SideCrossIterator& SideCrossIterator::operator=(const SideCrossIterator &other)
{
    return *this;
}

// operator == 
bool SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return false;
}

// operator !=
bool SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return false;
}

// operator >
bool SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return false;
}

// operator <
bool SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return false;
}

// operator* (Dereference operator)
int SideCrossIterator::operator*() const
{
    return 0;
}

// operator++ (prefix --> ++i)
SideCrossIterator& SideCrossIterator::operator++()
{
    return *this;
}

SideCrossIterator SideCrossIterator::begin()
{
    return *this;
}

SideCrossIterator SideCrossIterator::end()
{
    return *this;
}