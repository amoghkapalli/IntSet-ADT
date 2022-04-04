// file intset.h
// IntSet ADT
#ifndef INTSET_H
#define INTSET_H

#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
// IntSet class:  Abstract Data Type which holds a set of positive integers
// with the following features:
//   -- allows for terms to be inserted and removed from the list
//   -- allows for comparison of two IntSets to see if they are equal
//   -- allows for adding, subtracting, and multiplying IntSets
//   -- 
//   -- includes range checking, program terminates for out-of-bound subscripts
//
// Implementation and assumptions:
//   -- implemented using a bool array
//   -- the size of the array is originally created in the constructors
//   -- array elements are all first initialized to false
//   -- values in the bool array are true if the index is in IntSet
//   -- user must enter valid integers when using >>
//   -- Entries are stopped when -1 is entered
//   -- in <<, the set is printed as a whole with all the values separated by ‘ ‘
//---------------------------------------------------------------------------

class IntSet {
    // Overloaded >> allows for inputted integers
    // as many integers as possible can be inserted
    // entering -1 at the end will end the input and all negatives are ignored
    friend istream& operator>>(istream &inp, IntSet &a);
    // Overloaded << prints the whole IntSet with “{}”
    // If any numbers in intset they are inside the brackets
    // the numbers in the brackets are each separated by a space
    friend ostream& operator<<(ostream & out, const IntSet &a);
    public:
        // Default constructor which takes up to 5 paramters
        // Paramters are values of the set
        IntSet(int = -1, int = -1, int = -1, int = -1, int = -1);

        // Copy constructor
        // IntSet object which is declared is taken as a parameter
        // IntSet object with the same values as the input is returned
        IntSet(const IntSet &a);

        // destructor
        ~IntSet();

        // Additon operator overload
        IntSet operator+(const IntSet & set) const;

        // Additon assignment operator overload
        // Same function as the + operator but returns the current object
        IntSet& operator+=(const IntSet& set);

        // Subtraction operator overload
        IntSet operator-(const IntSet & set) const;

        // Subtraction assignment operator overload
        // Same function as the - operator but returns the current object
        IntSet& operator-=(const IntSet& set);

        // Multiplication operator overload
        IntSet operator*(const IntSet & set) const;

        // Multiplication assignment operator overload
        // Same function as the * operator but returns current object
        IntSet& operator*=(const IntSet& set);

        // Boolean comparison operators
        bool operator==(const IntSet &set) const;
        bool operator!=(const IntSet &set) const;

        // Assignment equal operator
        IntSet& operator=(const IntSet& set);

        // Insert method inserts a value into the array
        bool insert(int val);

        // Remove method removes a value if its in the IntSet
        bool remove(int val);

        //isEmpty method checking if the IntSet is empty
        bool isEmpty();

        //Checks if a int is in the IntSet returns true if it is
        bool isInSet(int val) const;

        
    private:
        // The Boolean array which keeps track of the terms in the IntSet
        // True at the index means that the index val is in the array
        // False at a index means the index isnt in the IntSet
        bool *BoolArr_;
        // Keeps track of the size of the whole bolean array
        // Used to check if the Bool arr needs to be resized
        int size_;
        // Helper variable to find the max value in the IntSet when initialized
        int largestVal_;
};
#endif