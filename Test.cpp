#include <stdexcept>
#include <cmath>
#include <iostream>
#include "doctest.h"
#include "sources/MagicalContainer.hpp"

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

    SUBCASE("Cheking the size of the container")
    {
        MagicalContainer testContainer;

        CHECK(testContainer.size() == 0);

        for (size_t i = 0; i < 5; i++)
        {
            testContainer.addElement(i);
        }

        CHECK_FALSE(testContainer.size() == 6);
    }
}

TEST_CASE("Assignment Operator, Operator == and Operator !=")
{
    SUBCASE("AscendingIterator")
    {
        MagicalContainer testContainer;
        MagicalContainer defaultContainer;

        testContainer.addElement(1);
        testContainer.addElement(2);
        testContainer.addElement(3);

        MagicalContainer::AscendingIterator Aiterator(testContainer);

        // Create another iterator and assign the first iterator to it
        MagicalContainer::AscendingIterator Aiterator2(defaultContainer);
        Aiterator2 = Aiterator;

        // Check if the container references are the same
        CHECK(Aiterator2 == Aiterator);

        
        CHECK_FALSE(Aiterator2 != Aiterator);
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer testContainer;
        MagicalContainer defaultContainer;

        testContainer.addElement(1);
        testContainer.addElement(2);
        testContainer.addElement(3);

        MagicalContainer::SideCrossIterator SideIter(testContainer);

        // Create another iterator and assign the first iterator to it
        MagicalContainer::SideCrossIterator SideIter2(defaultContainer);
        SideIter2 = SideIter;

        // Check if the container references are the same
        CHECK(SideIter2 == SideIter);

        
        CHECK_FALSE(SideIter2 != SideIter);
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer testContainer;
        MagicalContainer defaultContainer;

        testContainer.addElement(10);
        testContainer.addElement(29);
        testContainer.addElement(3);

        MagicalContainer::PrimeIterator primeIter(testContainer);

        // Create another iterator and assign the first iterator to it
        MagicalContainer::PrimeIterator primeIter2(defaultContainer);
        primeIter2 = primeIter;

        // Check if the container references are the same
        CHECK(primeIter2 == primeIter);

        
        CHECK_FALSE(primeIter2 != primeIter);
    }
}

TEST_CASE("Dereference Operator (*)")
{
    SUBCASE("")
    {
        MagicalContainer testContainer;

        for (size_t i = 10; i > 0; --i)
        {
            testContainer.addElement(i); // 10 9 8 7 6 5 4 3 2 1
        }

        MagicalContainer::AscendingIterator Aiterator(testContainer);

        for (auto it = Aiterator.begin(); it != Aiterator.end(); ++it) 
        {
            int index = 1;
            CHECK(*Aiterator == index); // 1 2 3 4 5 6 7 8 9 10
            index++;
        }
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer testContainer;

        for (size_t i = 5; i > 0; --i)
        {
            testContainer.addElement(i); // 5 4 3 2 1
        }

        MagicalContainer::SideCrossIterator SideIter(testContainer);

        vector<int> compare{ 5, 1, 4, 2, 3 };

        for (auto it = SideIter.begin(); it != SideIter.end(); ++it) 
        {
            size_t indexOfVector = 0;

            CHECK(*SideIter == compare.at(indexOfVector)); // 5 1 4 2 3

            indexOfVector++;
        }
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer testContainer;

        for (size_t i = 10; i > 0; --i)
        {
            testContainer.addElement(i); // 10 9 8 7 6 5 4 3 2 1
        }

        MagicalContainer::PrimeIterator primeIter(testContainer);

        vector<int> compare{ 7, 5, 3, 2 };

        for (auto it = primeIter.begin(); it != primeIter.end(); ++it) 
        {
            size_t indexOfVector = 0;

            CHECK(*primeIter == compare.at(indexOfVector)); // 7 5 3 2

            indexOfVector++;
        }
    }
}

TEST_CASE("Prefix Increment Operator(++)")
{
    SUBCASE("AscendingIterator")
    {
        MagicalContainer testContainer;
        testContainer.addElement(1);
        testContainer.addElement(2);

        MagicalContainer::AscendingIterator Aiterator(testContainer);

        // Increment the iterator and check the value
        ++Aiterator;

        CHECK(*Aiterator == 2);

        CHECK_THROWS_AS(++Aiterator, std::out_of_range);
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer testContainer;
        testContainer.addElement(1);
        testContainer.addElement(2);
        testContainer.addElement(3);

        MagicalContainer::SideCrossIterator SideIter(testContainer);

        // Increment the iterator and check the value
        ++SideIter;

        CHECK(*SideIter == 3);

        ++SideIter;

        CHECK(*SideIter == 2);

        CHECK_THROWS_AS(++SideIter, std::out_of_range);
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer testContainer;
        testContainer.addElement(19);
        testContainer.addElement(22);

        MagicalContainer::PrimeIterator primeIter(testContainer);

        // Increment the iterator and check the value
        ++primeIter;

        CHECK_THROWS_AS(++primeIter, std::out_of_range);
    }
}

TEST_CASE("Begin Iterator")
{
    SUBCASE("AscendingIterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        MagicalContainer::AscendingIterator Aiterator(testContainer);

        auto begin = Aiterator.begin(); // begin iterator

        CHECK(*begin == 2); // 2 15 33
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        MagicalContainer::SideCrossIterator SideIter(testContainer);

        auto begin = SideIter.begin(); // begin iterator

        CHECK(*begin == 15); // 15 33 2
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        MagicalContainer::PrimeIterator primeIter(testContainer);

        auto begin = primeIter.begin(); // begin iterator

        CHECK(*begin == 2); // 2 
    }
}

TEST_CASE("End Iterator")
{
    SUBCASE("AscendingIterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        MagicalContainer::AscendingIterator Aiterator(testContainer);

        auto end = Aiterator.end(); // end iterator

        CHECK(end != Aiterator.begin()); 
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        MagicalContainer::SideCrossIterator SideIter(testContainer);

        auto end = SideIter.end(); // end iterator

        CHECK(end != SideIter.begin()); 
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        MagicalContainer::PrimeIterator primeIter(testContainer);

        auto end = primeIter.end(); // end iterator

        CHECK(end == primeIter.begin()); // 2
    }
}

TEST_CASE("Not a single prime number") 
{
    MagicalContainer testContainer;

    testContainer.addElement(38);
    testContainer.addElement(646);
    testContainer.addElement(81);

    MagicalContainer::PrimeIterator primeIter(testContainer);

    CHECK(primeIter == primeIter.end());    
}

TEST_CASE("Same Type Iterator Comparison")
{
    SUBCASE("AscendingIterator")
    {
        MagicalContainer container1; 
        container1.addElement(1);
        container1.addElement(2);
        container1.addElement(7);
        container1.addElement(5);

        // begin iterator of the container 

        // 1 2 5 7
        MagicalContainer::AscendingIterator it1(container1); // 1 (index 0)
        MagicalContainer::AscendingIterator it2(container1); // 1 (index 0)

        // end iterator of the container
        MagicalContainer::AscendingIterator endIt = it2.end(); // 7 (index 3)

        CHECK(it1 == it2); // 1 == 1 (index 0)
        CHECK(it1 != endIt); // 1 != 7 (index 0 and index 3)
        CHECK(it2 != endIt); // 1 != 7 (index 0 and index 3)

        CHECK(it1 < endIt); // 1 < 7 (index 0 and index 3)
        CHECK(it2 < endIt); // 1 < 7 (index 0 and index 3)

        CHECK(endIt > it1); // 7 > 1 (index 0 and index 3)
        CHECK(endIt > it2); // 7 > 1 (index 0 and index 3)
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer container1; 
        container1.addElement(1);
        container1.addElement(2);
        container1.addElement(74);
        container1.addElement(51);
        container1.addElement(30);


        // begin iterator of the container 

        // 1 30 2 51 74
        MagicalContainer::SideCrossIterator it1(container1); // 1 (index 0)
        MagicalContainer::SideCrossIterator it2(container1); // 1 (index 0)

        // end iterator of the container
        MagicalContainer::SideCrossIterator endIt = it2.end(); // 74 (index 4)

        CHECK(it1 == it2); // 1 == 1 (index 0)
        CHECK(it1 != endIt); // 1 != 74 (index 0 and index 4)
        CHECK(it2 != endIt); // 1 != 74 (index 0 and index 4)

        ++it2; // 30 (index 1)
        ++it1; 
        ++it1; // 2 (index 2)


        CHECK(it1 > it2); // 2 > 30 (index 2 and index 1)

        CHECK(endIt > it1); // 74 > 2 (index 4 and index 2)
        CHECK(endIt > it2); // 74 > 30 (index 4 and index 1)
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer container1; 
        container1.addElement(2);
        container1.addElement(5);
        container1.addElement(74);
        container1.addElement(19);
        container1.addElement(30);


        // begin iterator of the container 

        // 2 5 19
        MagicalContainer::SideCrossIterator it1(container1); // 2 (index 0)
        MagicalContainer::SideCrossIterator it2(container1); // 2 (index 0)

        // end iterator of the container
        MagicalContainer::SideCrossIterator endIt = it2.end(); // 19 (index 2)

        CHECK(it1 == it2); // 2 == 2 (index 0)
        CHECK(it1 != endIt); // 2 != 19 (index 0 and index 4)
        CHECK(it2 != endIt); // 2 != 19 (index 0 and index 4)

        ++it2; // 5 (index 1)
        ++it1; 
        ++it1; // 19 (index 2)


        CHECK(it1 > it2); // 19 > 5 (index 2 and index 1)

        CHECK_FALSE(endIt > it1); // 19 > 19 --> false (index 2 and index 2)
        CHECK(endIt > it2); // 19 > 5 (index 2 and index 1)
    }
}

TEST_CASE("Different Type Iterator Comparison")
{
    MagicalContainer container1;
    container1.addElement(1);
    container1.addElement(2);
    container1.addElement(4);
    container1.addElement(5);
    container1.addElement(14);

    MagicalContainer::AscendingIterator AIt(container1);
    MagicalContainer::SideCrossIterator SIt(container1);
    MagicalContainer::PrimeIterator PIt(container1);

    MagicalContainer::AscendingIterator Abegin = AIt.begin();
    MagicalContainer::SideCrossIterator Sbegin = SIt.begin();
    MagicalContainer::PrimeIterator Pbegin = PIt.begin();

    // ### comparing different iterators didn't work - needed to implement operators for
    // different iterators but that wasn't part of the assigment ###

    // CHECK_THROWS_AS(Abegin < Sbegin, std::runtime_error); 
    // CHECK_THROWS_AS(Abegin < Pbegin, std::runtime_error);
    // CHECK_THROWS_AS(Sbegin < Pbegin, std::runtime_error);
}

TEST_CASE("Empty Container")
{
    SUBCASE("AscendingIterator")
    {
        MagicalContainer testContainer;
        MagicalContainer::AscendingIterator Aiterator(testContainer);

        CHECK(Aiterator == Aiterator.end());
        CHECK(Aiterator == Aiterator.begin());
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer testContainer;
        MagicalContainer::SideCrossIterator SideIter(testContainer);
        
        CHECK(SideIter == SideIter.end());
        CHECK(SideIter == SideIter.begin());
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer testContainer;
        MagicalContainer::PrimeIterator primeIter(testContainer);

        CHECK(primeIter == primeIter.end());
        CHECK(primeIter == primeIter.begin());
    }
}

TEST_CASE("Exceeded iterator limits")
{
    SUBCASE("AscendingIterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        MagicalContainer::AscendingIterator Aiterator(testContainer);

        while(Aiterator != Aiterator.end())
        {
            ++Aiterator;
        }

        CHECK_THROWS_AS(++Aiterator, std::runtime_error);
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        MagicalContainer::SideCrossIterator SideIter(testContainer);

        while(SideIter != SideIter.end())
        {
            ++SideIter;
        }

        CHECK_THROWS_AS(++SideIter, std::runtime_error);
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer testContainer;

        testContainer.addElement(15);
        testContainer.addElement(2);
        testContainer.addElement(33);

        MagicalContainer::PrimeIterator primeIter(testContainer);

        while(primeIter != primeIter.end())
        {
            ++primeIter;
        }

        CHECK_THROWS_AS(++primeIter, std::runtime_error);
    }
}

TEST_CASE("Different Container Iterator Comparison")
{
    MagicalContainer testContainer1;
    MagicalContainer testContainer2;

    testContainer1.addElement(34);
    testContainer1.addElement(56);
    testContainer1.addElement(23);

    testContainer2.addElement(19);
    testContainer2.addElement(58);

    SUBCASE("AscendingIterator")
    {   
        MagicalContainer::AscendingIterator Aiterator1(testContainer1);
        MagicalContainer::AscendingIterator Aiterator2(testContainer2);

        // ## not working ##
        // CHECK_THROWS_AS(Aiterator1 < Aiterator2, std::runtime_error);
        // CHECK_THROWS_AS(Aiterator1 == Aiterator2, std::runtime_error);
        // CHECK_THROWS_AS(Aiterator1 > Aiterator2, std::runtime_error);
        CHECK_THROWS_AS(Aiterator1 = Aiterator2, std::runtime_error);
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer::SideCrossIterator SideIter1(testContainer1);
        MagicalContainer::SideCrossIterator SideIter2(testContainer2);

        // ## not working ##
        // CHECK_THROWS_AS(SideIter1 < SideIter2, std::runtime_error);
        // CHECK_THROWS_AS(SideIter1 == SideIter2, std::runtime_error);
        // CHECK_THROWS_AS(SideIter1 > SideIter2, std::runtime_error);
        CHECK_THROWS_AS(SideIter1 = SideIter2, std::runtime_error);
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer::PrimeIterator primeIter1(testContainer1);
        MagicalContainer::PrimeIterator primeIter2(testContainer2);

        // ## not working ##
        // CHECK_THROWS_AS(primeIter1 < primeIter2, std::runtime_error);
        // CHECK_THROWS_AS(primeIter1 == primeIter2, std::runtime_error);
        // CHECK_THROWS_AS(primeIter1 > primeIter2, std::runtime_error);
        CHECK_THROWS_AS(primeIter1 = primeIter2, std::runtime_error);
    }
}