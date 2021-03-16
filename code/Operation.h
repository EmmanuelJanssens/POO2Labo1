/**
 * @authors Chhen Rosalie, Janssens Emmanuel
 * File written in the scope of practical work
 * for the POO2 Cursus at HEIG-VD
 * */
#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

/**
 * Base operation
 * Abstract class
 * */
class Operation{
public:
    virtual int execute(int op1, int op2) const = 0;
};
#endif