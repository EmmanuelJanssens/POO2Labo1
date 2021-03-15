#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Operation.h"

#include <iostream>

class Matrix{


private:

    int** content;
    int rowNb;
    int columnNb;
    int modulus;



public:

    Matrix(int rowNb, int columnNb, int modulus);
    Matrix(const Matrix& other);

    ~Matrix();

    Matrix& fillMatrix(int rowNb,  int columnNb);

    Matrix& compute(const Matrix& other, const Operation& operation);

    Matrix& operator+=(const Matrix& other);
    Matrix operator+(const Matrix& other) const;
    Matrix* add(const Matrix& other) const;

    Matrix& operator-=(const Matrix& other);
    Matrix operator-(const Matrix& other) const;
    Matrix* sub(const Matrix& other) const;

    Matrix& operator*=(const Matrix& other);
    Matrix operator*(const Matrix& other) const;
    Matrix* multiply(const Matrix& other) const;


    friend std::ostream& operator<<(std::ostream& lhs, const Matrix& rhs);


};

#endif /*MATRIX_HPP*/