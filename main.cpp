#include "Matrix.cpp"

#include <iostream>
#include "time.h"

using namespace std;

int main(){

    srand(time(0));

    Matrix one(3,4,5);
    Matrix two(3,5,5);

    cout << "Matrix one : " << endl;
    cout << one;

    cout << "\nMatrix two : " << endl;
    cout << two;

    Matrix copyOne(one);c
    cout << "\nCopy constructor : "<< endl;
    cout << copyOne;

    Matrix staticResultAdd = one + two;
    cout << "\none + two, new statically allocated Matrix :" << endl;
    cout << staticResultAdd;

    Matrix* dynamicResultAdd = one.add(two);
    cout << "\none add two, new dynamically allocated Matrix :" << endl;
    cout << *dynamicResultAdd;

    cout << "\n original has not be modified, one and two : " << endl;
    cout << one;
    cout << endl << two;

    cout << "\none += two, self add : " << endl;
    one += two;
    cout << one;


}