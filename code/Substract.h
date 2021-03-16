/**
 * @authors Chhen Rosalie, Janssens Emmanuel
 * File written in the scope of practical work
 * for the POO2 Cursus at HEIG-VD
 * */
#ifndef SUBSTRACT_H
#define SUBSTRACT_H

#include "Operation.h"

/**
 * Substract operation
 * */
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
