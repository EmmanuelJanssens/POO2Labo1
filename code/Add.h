/**
 * @file Add.h
 * @authors Chhen Rosalie, Janssens Emmanuel
 * @brief Addition operation
 * */
#ifndef ADD_H
#define ADD_H

#include "Operation.h"

class Add : public Operation
{
    public:

        int execute(int op1, int op2) const override
        {
            return op1 + op2;
        }
};
#endif
