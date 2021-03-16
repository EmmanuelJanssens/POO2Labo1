#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "Add.h"
#include "Multiply.h"
#include "Substract.h"


class Matrix
{
    public:

    /** constructor */
    Matrix(unsigned size_i, unsigned size_j, unsigned mod);
    /** Copy contructor  */
    Matrix( const Matrix& mat );
    /** Destructor */
    ~Matrix();

    void operator=(const Matrix& m2);

    /** Return result by value */
    static Matrix AddRetByVal(const Matrix& m1, const Matrix& m2);
    static Matrix MultRetByVal(const Matrix& m1, const Matrix& m2);
    static Matrix SubRetByVal(const Matrix& m1, const Matrix& m2);  

    /** Return a result as a pointer */
    static Matrix* AddRetByPoint(const Matrix& m1, const Matrix& m2);
    static Matrix* MultRetByPoint(const Matrix& m1, const Matrix& m2);
    static Matrix* SubRetByPoint(const Matrix& m1, const Matrix& m2);  

    /** Overload operators */
    friend Matrix operator+(const Matrix& m1, const Matrix& m2);
    friend Matrix operator-(const Matrix& m1, const Matrix& m2);
    friend Matrix operator*(const Matrix& m1, const Matrix& m2);

    //Operations On Self
    void AddSelf(const Matrix& toAdd);
    void MultSelf(const Matrix& toMult);
    void SubSelf(const Matrix& toSub);

    //operator(to self) overload
    void operator +=(const Matrix& toAdd);
    void operator -=(const Matrix& toSub);
    void operator *=(const Matrix& toMult);

    void Init(bool zero = false);

    /** Input data for the current matrix*/
    friend std::istream& operator>>(std::istream& in, Matrix& mat);
    /** Output data for a specified matrix */
    friend std::ostream& operator<<(std::ostream& out, const Matrix& mat);

    private:
    
    /** Wich operation should be executed */
    static Matrix Calculate(const Matrix& m1, const Matrix& m2,Operation* op);

    int CreateRandomValue();

    // Content of matrix
    int **_values;

    // Matrix i x j, i rows and j columns
    unsigned _size_i;
    unsigned _size_j;

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
                if(mat._values[j] != nullptr)
                    out<<mat._values[i][j]<<" ";
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