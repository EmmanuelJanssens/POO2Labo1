//
// Created by Rosalie Chhen on 10.03.2021.
//

#ifndef LABO01_CLION_SUBTRACTION_H
#define LABO01_CLION_SUBTRACTION_H


#include "Operation.h"

class Subtraction : public Operation{
public:
    virtual int perform(int a, int b) const{
        return a - b;
    }
};


#endif //LABO01_CLION_SUBTRACTION_H
