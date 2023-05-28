#include <iostream>
#include <algorithm>
#include "MagicalContainer.h"



using namespace std;


// constructor
AscendingIterator::AscendingIterator(MagicalContainer &container) : mContainer_(container) {}

// // default constructor
// AscendingIterator::AscendingIterator() : mContainer_(MagicalContainer()) {}

// copy constructor
AscendingIterator::AscendingIterator(const AscendingIterator &other) : mContainer_(other.mContainer_) {}

// destructor
AscendingIterator::~AscendingIterator() {}

// getters
MagicalContainer AscendingIterator::getMagicalContainer() const
{
    return this->mContainer_;
}

// operator= (Assignment operator)
AscendingIterator& AscendingIterator::operator=(const AscendingIterator &other)
{
    return *this;
}

// operator == 
bool AscendingIterator::operator==(const AscendingIterator &other) const
{
    return false;
}

// operator !=
bool AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return false;
}

// operator >
bool AscendingIterator::operator>(const AscendingIterator &other) const
{
    return false;
}

// operator <
bool AscendingIterator::operator<(const AscendingIterator &other) const
{
    return false;
}

// operator* (Dereference operator)
int AscendingIterator::operator*() const
{
    return 0;
}

// operator++ (prefix --> ++i)
AscendingIterator& AscendingIterator::operator++()
{
    return *this;
}


AscendingIterator AscendingIterator::begin()
{
    return *this;
}


AscendingIterator AscendingIterator::end()
{
    return *this;
}