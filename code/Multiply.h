/**
 * @authors Chhen Rosalie, Janssens Emmanuel
 * File written in the scope of practical work
 * for the POO2 Cursus at HEIG-VD
 * */
#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "Operation.h"

/**
 * Multiplication operation
 * */
class Multiply : public Operation
{
    public:
        Multiply()
        {}
        ~Multiply() 
        {}

        int execute(int op1, int op2) const override
        {
            return op1 * op2;
        }
};
#endif
