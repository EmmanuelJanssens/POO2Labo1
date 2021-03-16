/**
 * @authors Chhen Rosalie, Janssens Emmanuel
 * File written in the scope of practical work
 * for the POO2 Cursus at HEIG-VD
 * */
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "Add.h"
#include "Multiply.h"
#include "Substract.h"

/** 
 * This class represents a basic matrix and all
 * simple operation that can be done on it 
 * */
class Matrix
{
    public:

    /** 
     * constructor
     * @param size_i number of rows of the matrix
     * @param size_j number of collumns of the matrix
     * @param mod modulus of the matrix
     */
    Matrix(unsigned size_i, unsigned size_j, unsigned mod);
    /** 
     * Copy contructor 
     * @param mat matrix to be copied
     *  */
    Matrix( const Matrix& mat );

    /** 
     * Destructor 
     * */
    ~Matrix();

    /** 
     * Copy operator
     * @param mat matrix to be copied
     * **/
    Matrix& operator=(const Matrix& m2);

    /**
     * Initialises the values of the matrix
     * @param zero false = initialize a matrix with random value
     * @param zero true =  initialize a matrix with 0 as value
     * */
    void Init(bool zero = false);

    /**
     * Operation that is the root of every addition in our application
     * 
     * @param m1 first operand
     * @param m2 second operand
     * **/
    friend Matrix operator+(const Matrix& m1, const Matrix& m2) ;

    /**
     * Operation that is the root of every substraction in our application
     * 
     * @param m1 first operand
     * @param m2 second operand
     * **/
    friend Matrix operator-(const Matrix& m1, const Matrix& m2);

    /**
     * Operation that is the root of every Multiplication in our application
     * 
     * @param m1 first operand
     * @param m2 second operand
     * **/
    friend Matrix operator*(const Matrix& m1, const Matrix& m2);

    /** 
     * Input data for the current matrix
     * 
     * @param in input stream
     * @param mat matrix to be updated
     * */
    friend std::istream& operator>>(std::istream& in, Matrix& mat);

    /** 
     * Output data for a specified matrix 
     * 
     * @param out output stream
     * @param mat matrix to be written
     * @throws runtime_error if the values of the matrix are incoherent
     * */
    friend std::ostream& operator<<(std::ostream& out, const Matrix& mat);

    /**
     * Since the operation is done to one Self it is
     * usefull to return a reference to the current matrix
     * 
     * @param toAdd matrix to be added
     * */
    Matrix& operator +=(const Matrix& toAdd);

    /**
     * Since the operation is done to one Self it is
     * usefull to return a reference to the current matrix
     * 
     * @param toSubb matrix to be added 
     * */
    Matrix& operator -=(const Matrix& toSub);

    /**
     * Since the operation is done to one Self it is
     * usefull to return a reference to the current matrix
     * 
     * @param toMult matrix to be added
     * */
    Matrix& operator *=(const Matrix& toMult);

    /** 
     * Similar to operator override + 
     * Execute adition and returns a value
     * 
     */
    static Matrix AddRetByVal(const Matrix& m1, const Matrix& m2);

    /** 
     * Similar to operator override * 
     * Execute adition and returns a value
     * 
     * @param m1 first operand
     * @param m2 second operand
     */
    static Matrix MultRetByVal(const Matrix& m1, const Matrix& m2);

    /** 
     * Similar to operator override - 
     * Execute adition and returns a value
     * 
     * @param m1 first operand
     * @param m2 second operand
     */
    static Matrix SubRetByVal(const Matrix& m1, const Matrix& m2);  

    /**
     * Returns a new Matrix pointer 
     * @param m1 first operand
     * @param m2 second operand
     * **/
    static Matrix* AddRetByPoint(const Matrix& m1, const Matrix& m2);

    /**
     * Returns a new Matrix pointer 
     * @param m1 first operand
     * @param m2 second operand
     * **/
    static Matrix* MultRetByPoint(const Matrix& m1, const Matrix& m2);

    /**
     * Returns a new Matrix pointer 
     * @param m1 first operand
     * @param m2 second operand
     * **/
    static Matrix* SubRetByPoint(const Matrix& m1, const Matrix& m2);  


    private:

    /**
     * Returns a random value
     * */
    int CreateRandomValue();

    /** 
     * Executes the desired operation on two matrices
     * @param m1 first operand
     * @param m2 second operand
     * @param op Operation to be executed
     * @throws runtime_error if values of matrices or operation are not initialized
     * @throws invalid_arguement if modulos of two matrices are not compatible/equal
     * 
     * */
    static Matrix Calculate(const Matrix& m1, const Matrix& m2,Operation* op);

    /**
     * Content of the matrix
     * */
    int **_values;

    /**
     * Dimension of the matrix
     * _size_i = rows
     * _size_j = columns
     * */    
    unsigned _size_i,_size_j;

    /**
     * Modulus of the matrix
     * */
    int _mod;
};


inline std::ostream& operator<<(std::ostream& out, const Matrix& mat)
{
    if(mat._values != nullptr)
    {
        for( int i = 0; i < mat._size_i; i++)
        {
            for(int j = 0; j < mat._size_j; j++)
            {
                if(mat._values[i] != nullptr)
                    out<<mat._values[i][j]<<" ";
                else 
                    throw new std::runtime_error("Values of the matrix are badly initialized");
            }
            out<<std::endl;
        }
    }
    return out;
}
inline std::istream& operator>>(std::istream& in, Matrix& mat)
{
    in>>mat._size_j>>mat._size_i;
    mat.Init();
    return in;
}
inline Matrix operator+(const Matrix& m1, const Matrix& m2)
{
    return Matrix::Calculate(m1,m2,new Add());
}
inline Matrix operator*(const Matrix& m1, const Matrix& m2)
{
    return Matrix::Calculate(m1,m2,new Multiply());
}

// Correct negativ values
inline Matrix operator-(const Matrix& m1, const Matrix& m2)
{
    Matrix result = Matrix::Calculate(m1,m2,new Substract());

    // -1 mod 5 = 4
    for(int i = 0; i < result. _size_i; ++i)
    {
        for(int j = 0; j < result._size_j; ++j)
        {
            if(result._values[i][j] < 0)
            {
                result._values[i][j] += result._mod;
            }
        }
    }

    return result;
}
#endif