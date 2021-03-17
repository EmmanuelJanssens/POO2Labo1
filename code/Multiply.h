/**
 * @file Multiply.h
 * @authors Chhen Rosalie, Janssens Emmanuel
 * @brief Multiplication operation
 * */
 
#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "Operation.h"


class Multiply : public Operation
{
    public:

        int execute(int op1, int op2) const override
        {
            return op1 * op2;
        }
};
#endif
