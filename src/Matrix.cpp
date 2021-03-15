#include "Matrix.hpp"
#include "Operation.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiply.h"

#include <stdlib.h>
#include <iostream>

using namespace std;


// Constructor initializing Matrix with random values
Matrix::Matrix(int rowNb, int columnNb, int modulus) : rowNb(rowNb), columnNb(columnNb), modulus(modulus) {
    content = new int*[rowNb];
    for(int i_row = 0; i_row < rowNb; ++i_row){
        content[i_row] = new int[columnNb];
        for(int i_col = 0; i_col < columnNb; ++i_col){
            content[i_row][i_col] = std::rand() % modulus;
        }
    }
}

// Copy Constructor
Matrix::Matrix(const Matrix& other) : rowNb(other.rowNb), columnNb(other.columnNb), modulus(other.modulus){
    content = new int*[rowNb];
    for(int i_row = 0; i_row < rowNb; ++i_row){
        content[i_row] = new int[columnNb];
        for(int i_col = 0; i_col < columnNb; ++i_col){
            content[i_row][i_col] = other.content[i_row][i_col];
        }
    }
}

// Destructor
Matrix::~Matrix(){

    // Delete each row
    for(int i_row = 0;  i_row < rowNb; ++i_row){
        if(content[i_row] != nullptr){
            delete[] content[i_row];
            content[i_row] = nullptr;
        }
    }

    // Delete the array
    if(content != nullptr){
        delete[] content;
        content = nullptr;
    }
}

// Overloaded operator
ostream& operator<<(ostream& lhs, const Matrix& rhs) {
    // TODO exception
    for(int i_row = 0; i_row < rhs.rowNb; ++i_row){
        for(int i_col = 0; i_col < rhs.columnNb; ++i_col){
            lhs << rhs.content[i_row][i_col] << " ";
        }
        lhs << endl;
    }
}

// Return current Matrix filled with 0, until Matrix has rowNb and columnNb
Matrix& Matrix::fillMatrix(int rowNb,  int columnNb){

    // TODO Allocation statique ou dynamique?
    //Matrix newMatrix(rowNb, columnNb, this->modulus);

    int** newContent = new int*[rowNb];

    for(int i_row = 0; i_row < rowNb; ++i_row){
        newContent[i_row] = new int[columnNb];

        for(int i_col = 0; i_col < columnNb; ++i_col){

            if(i_row < this->rowNb && i_col < this->columnNb){
                // Copy existing values
                newContent[i_row][i_col] = this->content[i_row][i_col];
            } else {
                // Add 0 to the Matrix
                newContent[i_row][i_col] = 0;
            }
        }
    }

    this->rowNb = rowNb;
    this->columnNb = columnNb;
    this->content = newContent;
    //newMatrix.content = newContent;

    return *this;

}

// Iterate on the current Matrix and an other one for each value to perform an operation on the current Matrix
Matrix& Matrix::compute(const Matrix& other, const Operation& operation){

    if(this->modulus != other.modulus){
        throw std::runtime_error("Modulus are not similar.");
    }

    int maxRowNb = max(this->rowNb, other.rowNb);
    int maxColNb = max(this->columnNb, other.columnNb);

    this->fillMatrix(maxRowNb, maxColNb);

    Matrix copyOther(other);
    copyOther.fillMatrix(maxRowNb, maxColNb);

    for(int i_row = 0; i_row < maxRowNb; ++i_row){
        for(int i_col = 0; i_col < columnNb; ++i_col){
            int resultValue = operation.perform(this->content[i_row][i_col], copyOther.content[i_row][i_col]) % this->modulus;
            this->content[i_row][i_col] = resultValue;
        }
    }


    return *this;
}


// Compute result on current Matrix
Matrix& Matrix::operator+=(const Matrix& other){
    Addition add;
    return this->compute(other, add);
}

// Return a new result Matrix statically allocated
// Use of operator+=
Matrix Matrix::operator+(const Matrix& other) const{

    // Create a copy of this
    Matrix newMatrix(*this);

    // Perform on the copy of this
    return newMatrix += other;
}

// Return a new result Matrix dynamically allocated
// Use of operator+
Matrix* Matrix::add(const Matrix& other) const{

    Matrix* ptrNewMatrix = new Matrix(*this + other);

    return ptrNewMatrix;
}

// Compute result on current Matrix
Matrix& Matrix::operator-=(const Matrix& other){
    Subtraction sub;

    this->compute(other, sub);

    // For negativ result values, add the modulus
    for(int i_row = 0; i_row < this->rowNb; ++i_row){
        for(int i_col = 0; i_col < this->columnNb; ++i_col){
            if(this->content[i_row][i_col] < 0){
                this->content[i_row][i_col] += this->modulus;
            }
        }
    }

    return *this;
}

// Return a new result Matrix statically allocated
// Use of operator-=
Matrix Matrix::operator-(const Matrix& other) const{

    Matrix newMatrix(*this);

    return newMatrix -= other;
}

// Return a new result Matrix dynamically allocated
// Use of operator-
Matrix* Matrix::sub(const Matrix& other) const{

    Matrix* ptrNewMatrix = new Matrix(*this - other);

    return ptrNewMatrix;
}

// Compute result on current Matrix
Matrix& Matrix::operator*=(const Matrix& other){
    Multiply mult;
    return this->compute(other, mult);
}

// Return a new result Matrix statically allocated
// Use of operator*=
Matrix Matrix::operator*(const Matrix& other) const{

    // utilisation d'une copie de this pour ne pas modifier l'orignale
    Matrix newMatrix(*this);

    return newMatrix *= other;
}

// Return a new result Matrix dynamically allocated
// Use of operator*
Matrix* Matrix::multiply(const Matrix &other) const {

    Matrix* ptrNewMatrix = new Matrix(*this * other);

    return ptrNewMatrix;
}
