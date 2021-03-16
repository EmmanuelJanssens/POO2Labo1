#ifndef SUBSTRACT_H
#define SUBSTRACT_H

#include "Operation.h"


class Substract :public Operation
{
    public:
        Substract()
        {}
        ~Substract() 
        { }

        int execute(int op1, int op2) const override
        {
            return op1 - op2;
        }
};
#endif
