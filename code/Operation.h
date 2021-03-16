#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

class Operation{
public:
    virtual int execute(int op1, int op2) const = 0;
};
#endif