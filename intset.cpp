#include "intset.h"
#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;


//----------------------------------------------------------------------------
// IntSet Constructor
// Default constructor allows for up to 5 parameters. 0-5 parameters
// If no values are entered, then a bool array of size 1 is created
IntSet::IntSet(int num1, int num2, int num3, int num4, int num5){
    largestVal_ = -1;
    largestVal_ = max({num1, num2, num3, num4, num5});
    size_ = largestVal_+1;
    int parameter[5] = {num1, num2, num3, num4, num5};
    if(size_ = 0){
        size_ = 1;
    }
    BoolArr_=new bool[size_]();
    for(int i = 0; i < size_; i++){
        BoolArr_[i] = false;
    }
    if(largestVal_ > 0){
        for(int i = 0; i < 5; i++){
            insert(parameter[i]);
        }
    }
}


//----------------------------------------------------------------------------
// IntSet Copy Constructor
// Takes in a IntSet object as a parameter
// Returns *this with all of the values in BoolArr_ copied over and size_
IntSet::IntSet(const IntSet & a){
    if(a.size_ > 0){
        size_ = a.size_;
        BoolArr_ = new bool[size_]();
        for(int i = 0; i < size_; i++){
            BoolArr_[i] = a.BoolArr_[i];
		}
    }
    else{
        BoolArr_ = new bool[1]();
        BoolArr_[0] = false;
        size_ = 1;
    }
}


//----------------------------------------------------------------------------
// IntSet Destructor
// Deletes the bool array values and then sets it to a null pointer
IntSet::~IntSet(){
    delete [] BoolArr_;
    BoolArr_ = nullptr;
}


//----------------------------------------------------------------------------
// operator+  
// overloaded +: addition of 2 IntSets, current object and parameter "set"
// Returns a combined new IntSet with both sets combined
// Terms appearing in both sets show up in the sum once
IntSet IntSet::operator+(const IntSet & set) const {
    IntSet combined;
    for(int i = 0; i < size_; i++){
        if(isInSet(i)){
            combined.insert(i);
        }
    }
    for(int j = 0; j < set.size_; j++){
        if(set.isInSet(j)){
            combined.insert(j);
        }
    }
    return combined;
}


//----------------------------------------------------------------------------
// operator+=  
// overloaded +=: addition of 2 IntSets, *this and parameter "set"
// Current IntSet=current IntSet+set
// Returns *this
IntSet& IntSet::operator+=(const IntSet& set){
    for(int i = 0; i < set.size_; i++){
        if(set.isInSet(i)){
            this->insert(i);
        }
    }
    return *this;
}


//----------------------------------------------------------------------------
// operator-
// overloaded -: Difference of two IntSets and returns a IntSet
// IntSet returned has terms in *this IntSet without common vals in both
IntSet IntSet::operator-(const IntSet & set) const {
    IntSet combined;
    for(int i = 0; i < max(size_, set.size_); i++){
        if(isInSet(i) && !set.isInSet(i)){
            combined.insert(i);
        }
    }
    return combined;
}


//----------------------------------------------------------------------------
// operator-=  
// overloaded -=: subtraction of 2 IntSets, *this and parameter "set"
// Current IntSet=current IntSet-set
// Returns *this
IntSet& IntSet::operator-=(const IntSet& set){
    for(int i = 0; i < size_; i++){
        if(set.isInSet(i) && isInSet(i)){
            remove(i);
        }
    }
    return *this;
}


//----------------------------------------------------------------------------
// operator*
// overloaded *: Intersection of two IntSets and returns a IntSet
// IntSet returned has terms in *this IntSet and in "set"
IntSet IntSet::operator*(const IntSet & set) const{
    IntSet combined;
    for(int i = 0; i < min(size_, set.size_); i++){
        if(isInSet(i) && set.isInSet(i)){
            combined.insert(i);
        }
    }
    return combined;
}


//----------------------------------------------------------------------------
// operator-=  
// overloaded -=: intersection of 2 IntSets, *this and parameter "set"
// Returns *this
IntSet& IntSet::operator*=(const IntSet& set){
    for(int i = 0; i < min(size_, set.size_); i++){
        if(!(isInSet(i) && set.isInSet(i))){
            this->remove(i);
        }
    }
    return *this;
}


//----------------------------------------------------------------------------
// operator==  
// overloaded ==: returns if the two sets are equal or not
// returns true if the sets are equal
bool IntSet::operator==(const IntSet &set) const{
    if(size_ != set.size_){
        return false;
    }
    for(int i = 0; i < size_; i++){
        if(BoolArr_[i] != set.BoolArr_[i]){
            return false;
        } 
    }
    return true;
}


//----------------------------------------------------------------------------
// operator!=  
// overloaded !=: returns if the two sets are equal or not
// returns false if the sets are equal
bool IntSet::operator!=(const IntSet &set) const{
    return(!(*this==set));
}

//----------------------------------------------------------------------------
// assignment operator=  
// overloaded =: deletes the old BoolArr_ and creates a new one
// to match that of set
// Returns *this
IntSet& IntSet::operator=(const IntSet& set){
    if(&set != this){
        delete [] BoolArr_;
		size_ = set.size_;
        BoolArr_ = new bool[size_];
        for(int i = 0; i < size_; i++){
            BoolArr_[i] = false;
        }
        for(int i = 0; i < size_; i++){
            if(set.isInSet(i)){
                //cout<<"testing: "<<i<<endl;
                BoolArr_[i] = true;
            }
        }
    }
    return *this;
}


//----------------------------------------------------------------------------
// operator<< 
// Overloaded <<: prints the whole IntSet in brackets
// If any numbers are in the intset they are inside the brackets
// The numbers in the brackets are each separated by a space
ostream& operator<<(ostream &out, const IntSet &a) {
	out << "{";
	for(int i = 0; i < a.size_; i++) {
		if(a.BoolArr_[i] == true) {
			out << " " << i;
		}
	}
	out << "}";
	return out;
}

//----------------------------------------------------------------------------
// operator>> 
// Overloaded >>: allows for integers to be inputted by users
// As many integers as possible can be inserted
// Entering -1 at the end will end the input and all negatives are ignored
istream& operator>>(istream &inp, IntSet &a) {
    int temp;
    bool insertSuccess;
    inp >> temp;
    while (temp != -1) {
        insertSuccess = a.insert(temp);
        inp >> temp;
    }
    return inp;
}


//----------------------------------------------------------------------------
// insert
// insert method checks the value and adds it to the set if its valid
// Checks if it's a positive number and resizes if val is too big
// Returns true if the value can be inserted and false if val<0
bool IntSet::insert(int val){
    if(val<0){
        return false;
    }
    else if(val>=size_){
        IntSet prev = *this;
        delete [] BoolArr_;
        BoolArr_ = new bool[val+1];
        size_ = val+1;
        for(int i=0; i < prev.size_; i++){
            BoolArr_[i] = prev.BoolArr_[i];
        }
        for(int j=prev.size_; j < size_; j++){
            BoolArr_[j] = false;
        }
    }
    BoolArr_[val]=true;
    return true;
}


//----------------------------------------------------------------------------
// remove
// remove method removes a value if its in the IntSet
// Returns true if the val was successfully removed
bool IntSet::remove(int val){
    if(val<0 || val>size_ || BoolArr_[val]==false){
        return false;
    }
    BoolArr_[val]=false;
    return true;
}


//----------------------------------------------------------------------------
// isEmpty
// isEmpty method checks if the IntSet is empty and has no values in the set
bool IntSet::isEmpty(){
    for(int i = 0; i < size_; i++){
        if(BoolArr_[i]){
            return false;
        }
    }
    return true;
}


//----------------------------------------------------------------------------
// isInSet
// isInSet method checks if a int is in the IntSet returns true if it is
bool IntSet::isInSet(int val) const{
    if(val>=size_ || val<0){
        return false;
    }
    if(BoolArr_[val]==false){
        return false;
    }
    return true;
}