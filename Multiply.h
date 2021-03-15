//
// Created by Rosalie Chhen on 13.03.2021.
//

#ifndef LABO01_CLION_MULTIPLY_H
#define LABO01_CLION_MULTIPLY_H

#include "Operation.h"

class Multiply : public Operation{
public:
    virtual int perform(int a, int b) const{
        return a * b;
    }
};

#endif //LABO01_CLION_MULTIPLY_H
