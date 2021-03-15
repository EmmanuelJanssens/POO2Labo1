//
// Created by Rosalie Chhen on 10.03.2021.
//

#ifndef LABO01_CLION_ADDITION_H
#define LABO01_CLION_ADDITION_H

#include "Operation.h"

class Addition : public Operation{
public:
    virtual int perform(int a, int b) const{
        return a + b;
    }
};


#endif //LABO01_CLION_ADDITION_H
