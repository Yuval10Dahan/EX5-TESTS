#include <stdexcept>
#include <cmath>
#include <iostream>
#include "doctest.h"
#include "sources/MagicalContainer.h"

using namespace std;




TEST_CASE("MagicalContainer") 
{
    SUBCASE("AddElement") 
    {
        MagicalContainer testContainer;

        testContainer.addElement(130);
        testContainer.addElement(69);
        testContainer.addElement(12);

        CHECK(testContainer.size() == 3);
    }

    SUBCASE("RemoveElement") 
    {
        MagicalContainer testContainer;

        testContainer.addElement(45);
        testContainer.addElement(6);
        testContainer.addElement(-14);
        testContainer.removeElement(6);

        CHECK(testContainer.size() == 2);
    }

    SUBCASE("Remove an element that doesn't exists")
    {
        MagicalContainer testContainer;

        testContainer.addElement(2);
        testContainer.addElement(5);

        CHECK_THROWS_AS(testContainer.removeElement(3), std::runtime_error);
    }

    SUBCASE("Remove while the container is empty")
    {
        MagicalContainer testContainer;

        CHECK_THROWS_AS(testContainer.removeElement(6), std::runtime_error);
    }
}

TEST_CASE("AscendingIterator") 
{
    SUBCASE("Assignment Operator, Operator == and Operator !=")
    {
        MagicalContainer testContainer;
        MagicalContainer defaultContainer;

        testContainer.addElement(1);
        testContainer.addElement(2);
        testContainer.addElement(3);

        AscendingIterator Aiterator(testContainer);

        // Create another iterator and assign the first iterator to it
        AscendingIterator Aiterator2(defaultContainer);
        Aiterator2 = Aiterator;

        // Check if the container references are the same
        CHECK(Aiterator2 == Aiterator);

        
        CHECK_FALSE(Aiterator2 != Aiterator);
    }

    SUBCASE("Dereference Operator (*)")
    {
        MagicalContainer testContainer;

        for (size_t i = 10; i > 0; --i)
        {
            testContainer.addElement(i); // 10 9 8 7 6 5 4 3 2 1
        }

        AscendingIterator Aiterator(testContainer);

        for (auto it = Aiterator.begin(); it != Aiterator.end(); ++it) 
        {
            int index = 1;
            CHECK(*Aiterator == index); // 1 2 3 4 5 6 7 8 9 10
            index++;
        }
    }

    SUBCASE("Prefix Increment Operator(++)")
    {
        MagicalContainer testContainer;
        testContainer.addElement(1);
        testContainer.addElement(2);

        AscendingIterator Aiterator(testContainer);

        // Increment the iterator and check the value
        ++Aiterator;

        CHECK(*Aiterator == 2);

        CHECK_THROWS_AS(++Aiterator, std::out_of_range);
    }

    SUBCASE("Begin Iterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        AscendingIterator Aiterator(testContainer);

        auto begin = Aiterator.begin(); // begin iterator

        CHECK(*begin == 2); // 2 15 33
    }

    SUBCASE("End Iterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        AscendingIterator Aiterator(testContainer);

        auto end = Aiterator.end(); // end iterator

        CHECK(end != Aiterator.begin()); 
    }
}

TEST_CASE("SideCrossIterator") 
{
    SUBCASE("Assignment Operator, Operator == and Operator !=")
    {
        MagicalContainer testContainer;
        MagicalContainer defaultContainer;

        testContainer.addElement(1);
        testContainer.addElement(2);
        testContainer.addElement(3);

        SideCrossIterator SideIter(testContainer);

        // Create another iterator and assign the first iterator to it
        SideCrossIterator SideIter2(defaultContainer);
        SideIter2 = SideIter;

        // Check if the container references are the same
        CHECK(SideIter2 == SideIter);

        
        CHECK_FALSE(SideIter2 != SideIter);
    }

    SUBCASE("Dereference Operator (*)")
    {
        MagicalContainer testContainer;

        for (size_t i = 5; i > 0; --i)
        {
            testContainer.addElement(i); // 5 4 3 2 1
        }

        SideCrossIterator SideIter(testContainer);

        vector<int> compare{ 5, 1, 4, 2, 3 };

        for (auto it = SideIter.begin(); it != SideIter.end(); ++it) 
        {
            size_t indexOfVector = 0;

            CHECK(*SideIter == compare.at(indexOfVector)); // 5 1 4 2 3

            indexOfVector++;
        }
    }

    SUBCASE("Prefix Increment Operator(++)")
    {
        MagicalContainer testContainer;
        testContainer.addElement(1);
        testContainer.addElement(2);
        testContainer.addElement(3);

        SideCrossIterator SideIter(testContainer);

        // Increment the iterator and check the value
        ++SideIter;

        CHECK(*SideIter == 3);

        ++SideIter;

        CHECK(*SideIter == 2);

        CHECK_THROWS_AS(++SideIter, std::out_of_range);
    }

    SUBCASE("Begin Iterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        SideCrossIterator SideIter(testContainer);

        auto begin = SideIter.begin(); // begin iterator

        CHECK(*begin == 15); // 15 33 2
    }

    SUBCASE("End Iterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        SideCrossIterator SideIter(testContainer);

        auto end = SideIter.end(); // end iterator

        CHECK(end != SideIter.begin()); 
    }
}

TEST_CASE("PrimeIterator") 
{
    SUBCASE("Assignment Operator, Operator == and Operator !=")
    {
        MagicalContainer testContainer;
        MagicalContainer defaultContainer;

        testContainer.addElement(10);
        testContainer.addElement(29);
        testContainer.addElement(3);

        PrimeIterator primeIter(testContainer);

        // Create another iterator and assign the first iterator to it
        PrimeIterator primeIter2(defaultContainer);
        primeIter2 = primeIter;

        // Check if the container references are the same
        CHECK(primeIter2 == primeIter);

        
        CHECK_FALSE(primeIter2 != primeIter);
    }

    SUBCASE("Dereference Operator (*)")
    {
        MagicalContainer testContainer;

        for (size_t i = 10; i > 0; --i)
        {
            testContainer.addElement(i); // 10 9 8 7 6 5 4 3 2 1
        }

        PrimeIterator primeIter(testContainer);

        vector<int> compare{ 7, 5, 3, 2 };

        for (auto it = primeIter.begin(); it != primeIter.end(); ++it) 
        {
            size_t indexOfVector = 0;

            CHECK(*primeIter == compare.at(indexOfVector)); // 7 5 3 2

            indexOfVector++;
        }
    }

    SUBCASE("Prefix Increment Operator(++)")
    {
        MagicalContainer testContainer;
        testContainer.addElement(19);
        testContainer.addElement(22);

        PrimeIterator primeIter(testContainer);

        // Increment the iterator and check the value
        ++primeIter;

        CHECK_THROWS_AS(++primeIter, std::out_of_range);
    }

    SUBCASE("Begin Iterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        PrimeIterator primeIter(testContainer);

        auto begin = primeIter.begin(); // begin iterator

        CHECK(*begin == 2); // 2 
    }

    SUBCASE("End Iterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        PrimeIterator primeIter(testContainer);

        auto end = primeIter.end(); // end iterator

        CHECK(end == primeIter.begin()); // 2
    }
}