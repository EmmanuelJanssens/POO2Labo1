#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "Operation.h"


class Multiply : public Operation
{
    public:
        Multiply()
        {}
        ~Multiply() 
        {}

        int execute(int op1, int op2) override
        {
            return op1 * op2;
        }
};
#endif
