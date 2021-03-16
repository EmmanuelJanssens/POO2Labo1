/**
 * @authors Chhen Rosalie, Janssens Emmanuel
 * File written in the scope of practical work
 * for the POO2 Cursus at HEIG-VD
 * */
#ifndef ADD_H
#define ADD_H

#include "Operation.h"

/**
 * Addition operation
 * */
class Add : public Operation
{
    public:
        Add()
        {}
        ~Add() 
        {}

        int execute(int op1, int op2) const override
        {
            return op1 + op2;
        }
};
#endif
