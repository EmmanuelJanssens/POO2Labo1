#include "Matrix.hpp"

#include <iostream>
#include "time.h"
#include <limits.h>

using namespace std;

int main(int argc, char *argv[]){

    srand(time(0));

    // Arguments should be exactly : n1 m1 n2 m2 modulus
    // Otherwise, behaviour is not defined
    if(argc != 6){
        throw std::runtime_error("Numbers of input invalid");
    }

    // Transform String arguments to int arguments
    int argvInt[argc - 1];
    for(int i_argv = 1; i_argv < argc; ++i_argv){
        int arg = atoi(argv[i_argv]);
        if( arg < 1 || arg > INT_MAX){
            throw std::runtime_error("Each argument should be a number between 1 and INT_MAX");
        }
        argvInt[i_argv - 1] = arg;
    }

    Matrix one(argvInt[0],argvInt[1],argvInt[4]);
    Matrix two(argvInt[2],argvInt[3],argvInt[4]);

    cout << "--- Addition : " << endl;

    cout << "Matrix one : " << endl;
    cout << one;

    cout << "\nMatrix two : " << endl;
    cout << two;

    Matrix copyOne(one);
    cout << "\nCopy constructor : "<< endl;
    cout << copyOne;

    Matrix staticResultAdd = one + two;
    cout << "\none + two, new statically allocated Matrix :" << endl;
    cout << staticResultAdd;

    Matrix* dynamicResultAdd = one.add(two);
    cout << "\none add two, new dynamically allocated Matrix :" << endl;
    cout << *dynamicResultAdd;

    cout << "\noriginal has not be modified, one and two : " << endl;
    cout << one;
    cout << endl << two;

    cout << "\none += two, self add : " << endl;
    one += two;
    cout << one;

    // -----------------

    cout << "\n\n--- Subtraction : " << endl;

    Matrix first(argvInt[0],argvInt[1],argvInt[4]);
    Matrix second(argvInt[2],argvInt[3],argvInt[4]);

    cout << "Matrix first : " << endl;
    cout << first;

    cout << "\nMatrix second : " << endl;
    cout << second;

    Matrix staticResultSub = first - second;
    cout << "\nfirst - second, new statically allocated Matrix :" << endl;
    cout << staticResultSub;

    Matrix* dynamicResultSub = first.sub(second);
    cout << "\nfirst sub second, new dynamically allocated Matrix :" << endl;
    cout << *dynamicResultSub;

    cout << "\noriginal has not be modified, first and second : " << endl;
    cout << first;
    cout << endl << second;

    cout << "\nfirst += second, self add : " << endl;
    first -= second;
    cout << first;

    cout << "\n\n--- Multiplication : " << endl;

    Matrix un(argvInt[0],argvInt[1],argvInt[4]);
    Matrix deux(argvInt[2],argvInt[3],argvInt[4]);

    cout << "Matrix un : " << endl;
    cout << un;

    cout << "\nMatrix deux : " << endl;
    cout << deux;

    Matrix staticResultMult = un * deux;
    cout << "\nun * deux, new statically allocated Matrix :" << endl;
    cout << staticResultMult;

    Matrix* dynamicResultMult = un.multiply(deux);
    cout << "\nun multiply deux, new dynamically allocated Matrix :" << endl;
    cout << *dynamicResultMult;

    cout << "\noriginal has not be modified, un and deux : " << endl;
    cout << un;
    cout << endl << deux;

    cout << "\nun *= deux, self add : " << endl;
    un *= deux;
    cout << un;

}