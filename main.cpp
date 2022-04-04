#include "intset.h"
#include <iostream>
using namespace std;

int main() {

   IntSet A(9), B(15,3), C(10,5,8), D(12,5,10,12,-500), E, X(D), Y;

   // sets A and B acquire desired values
   //A = { 3 7 9};
   //B = { 3 5 9 12 15};
   cout << "Enter ints for set A:  " << endl;
   cin >> A;
   cout << "Enter ints for set B:  " << endl;
   cin >> B;

   //As a shortcut when testing, you can use insert to avoid typing each time
   A.insert(3);
   A.insert(7);
   B.insert(5);
   B.insert(9);
   B.insert(12);

   cout << "A = " << A << endl;               // outputs: A = { 3 7 9}
   cout << "B = " << B << endl << endl;       // outputs: B = { 3 5 9 12 15}

   cout << "Compute  C = A + B" << endl;
   C = A + B;                                 // C is replaced by A+B
   cout << "C = " << C << endl << endl;       // outputs: C = { 3 5 7 9 12 15}

   cout << "Ask if  A == C" << endl;
   cout <<  ( (A == C)? "A == C" : "A is not == C" ) << endl << endl;

   cout << "Ask if  A != C" << endl;
   cout <<  ( (A != C)? "A is not == C" : "A == C" ) << endl << endl;

   cout << "Compute B - A = " << B - A << endl;            // B - A = { 5 12 15}
   cout << "Compute A - B = " << A - B << endl;            // A - B = { 7}
   cout << "Compute  D = (A * B) + D" << endl;
   cout << "Before: D = " << D;                            // D = { 5 10 12}
   D = (A * B) + D;
   cout << "    After: " << "D = " << D << endl << endl;   // D = { 3 5 9 10 12}

   /*
   IntSet A(9);
   IntSet B(15,3);
   IntSet C(10,5,8);
   IntSet D(12,5,10,12,-500);
   IntSet E;
   IntSet X(D);
   IntSet Y;
   
   cout<<A<<endl;
   cout<<B<<endl;
   cout<<C<<endl;
   cout<<D<<endl;
   cout<<E<<endl;
   cout<<"Copy: " << X<<endl;
   C.insert(4);
   C.remove(5);
   cout<<"C"<<C<<endl;
   B+=A;
   cout<<"B:"<<B<<endl;
   cout<<"A:"<<A<<endl;
   B-=A;
   cout<<"B1"<<B<<endl;
   cout<<"test "<<C+D<<endl;
   Y=C+D;   
   cout<<"Y"<<Y<<endl;
   Y=Y-C;
   cout<<"Y1"<<Y<<endl;
   Y=Y+C;
   Y-=C;
   cout<<"Y2"<<Y<<endl;
   */
   
   

/*
   IntSet A(9), B(15,3), C(10,5,8), D(12,5,10,12,-500), E, X(D), Y;

   // sets A and B acquire desired values
   // A = { 3 7 9}
   // B = { 3 5 9 12 15}
   cout << "Enter ints for set A:  " << endl;
   cin >> A;
   cout << "Enter ints for set B:  " << endl;
   cin >> B;
   // As a shortcut when testing, you can use insert to avoid typing each time
   // A.insert(3);
   // A.insert(7);
   // B.insert(5);
   // B.insert(9);
   // B.insert(12);

   cout << "A = " << A << endl;               // outputs: A = { 3 7 9}
   cout << "B = " << B << endl << endl;       // outputs: B = { 3 5 9 12 15}

   cout << "Compute  C = A + B" << endl;
   C = A + B;                                 // C is replaced by A+B
   cout << "C = " << C << endl << endl;       // outputs: C = { 3 5 7 9 12 15}

   cout << "Ask if  A == C" << endl;
   cout <<  ( (A == C)? "A == C" : "A is not == C" ) << endl << endl;

   cout << "Ask if  A != C" << endl;
   cout <<  ( (A != C)? "A is not == C" : "A == C" ) << endl << endl;

   cout << "Compute B - A = " << B - A << endl;            // B - A = { 5 12 15}
   cout << "Compute A - B = " << A - B << endl;            // A - B = { 7}
   cout << "Compute  D = (A * B) + D" << endl;
   cout << "Before: D = " << D;                            // D = { 5 10 12}
   D = (A * B) + D;
   cout << "    After: " << "D = " << D << endl << endl;   // D = { 3 5 9 10 12}

   cout << "Test assignment operators" << endl;
   X = C = D = D;
   Y += A *= B;
   cout << "X = " << X << "    Y = " << Y << endl << endl;

   // miscellaneous stuff
   cout << (D.isInSet(0) ? "0 in set" : "0 not in set" ) << endl;
   cout << (D.isInSet(-1000) ? "-1000 in set" : "-1000 not in set" ) << endl;
   cout << (A.isEmpty() ? "A empty" : "A not empty" ) << endl;
   bool success;
   success = D.insert(-20000);           // handle value out of range
   success = D.remove(20000);            // handle value out of range
   success = D.remove(-5000);            // handle value out of range
   success = D.insert(0);                // put 0 in the set
   success = D.insert(20000);            

   return 0;
   */
}