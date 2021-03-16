#include "Matrix.h"

Matrix::Matrix(unsigned i, unsigned j, unsigned mod)
    : _size_i(i),_size_j(j),_mod(mod)
{
    Init(false);
}

Matrix::Matrix(const Matrix& copy)
{
    this->_size_i = copy._size_i;
    this->_size_j = copy._size_j;
    this->_mod = copy._mod;

    //initialize array pointer
    _values =  new int*[_size_i];
    for(int i = 0; i < _size_i; i++)
    {
        //initialize values arrays and copy values
        _values[i] =  new int[_size_j];
        for(int j = - 0; j < _size_j; j++)
        {
            _values[i][j] = copy._values[i][j];
        }
    }
}

Matrix::~Matrix()
{
    //first delete  value arrays
    for(int i = 0; i < _size_i; i++)
    {
        if(_values[i] != nullptr)
        {
            delete _values[i];
            _values[i] = nullptr;
        }
    }

    //then delete pointer arrays
    if(_values != nullptr)
        delete _values;

    _values = nullptr;

}

Matrix& Matrix::operator=(const Matrix& copy)
{
    this->_size_i = copy._size_i;
    this->_size_j = copy._size_j;
    this->_mod = copy._mod;

    //initialize array pointer
    _values =  new int*[_size_i];
    for(int i = 0; i < _size_i; i++)
    {
        //initialize values arrays and copy values
        _values[i] =  new int[_size_j];
        for(int j = - 0; j < _size_j; j++)
        {
            _values[i][j] = copy._values[i][j];
        }
    }

    return *this;
}

void Matrix::Init(bool zero)
{
    _values =  new int*[_size_i];
    for(int i= 0; i < _size_i; i++)
    {
        //initialize values arrays
        _values[i] =  new int[_size_j];
        for(int j = 0; j < _size_j; j++)
        {
            if(!zero)
                _values[i][j] = CreateRandomValue();
            else
                _values[i][j] = 0;

        }    
    }
}

Matrix Matrix::Calculate(const Matrix& m1, const Matrix& m2, Operation * op)
{
    Matrix *temp = new Matrix(std::max(m1._size_i, m2._size_i), std::max(m1._size_j, m2._size_j), m1._mod);
    temp->Init(true);  // fill this matrix with 0

    int op1 = 0; // operand from m1
    int op2 = 0; // operand from m2

    for(int i =0; i < temp->_size_i; i++)
    {
        for(int j = 0; j < temp->_size_j; j++)
        {
            if(i < m1._size_i && j < m1._size_j)
                op1 = m1._values[i][j];
            else
                op1 = 0;

            if(i < m2._size_i && j < m2._size_j)
                op2 = m2._values[i][j];
            else
                op2 = 0;

            temp->_values[i][j] = op->execute(op1,op2) % temp->_mod;

        }
    }

    if(op != nullptr)
        delete op;
    else
        throw std::runtime_error("Operation is not declared");

    op = nullptr;
    
    Matrix result(*temp);
    delete temp;
    temp = nullptr;

    return result;

}

int Matrix::CreateRandomValue()
{
    int random = 1+std::rand() % _mod;
    return random;
}



void Matrix::AddSelf(const Matrix& toAdd)
{
    *this += toAdd;
}
Matrix& Matrix::operator+=(const Matrix& toAdd)
{   
    *this = *this + toAdd;
    return *this;
} 
Matrix Matrix::AddRetByVal(const Matrix& m1, const Matrix& m2)
{
    return m1 + m2;
}
Matrix* Matrix::AddRetByPoint(const Matrix& m1, const Matrix& m2)
{
    return  new Matrix(m1+m2);
}


void Matrix::SubSelf(const Matrix& toSubb)
{
    *this -= toSubb;
}
Matrix& Matrix::operator-=(const Matrix& toAdd)
{   
    *this = *this - toAdd;
    return *this;
} 
Matrix Matrix::SubRetByVal(const Matrix& m1, const Matrix& m2)
{
    return m1-m2;
}
Matrix* Matrix::SubRetByPoint(const Matrix& m1, const Matrix& m2)
{
    return  new Matrix(m1-m2);
}

void Matrix::MultSelf(const Matrix& toMult)
{
    *this *= toMult;
}
Matrix& Matrix::operator*=(const Matrix& toMult)
{   
    *this = *this * toMult;
    return *this;
} 
Matrix Matrix::MultRetByVal(const Matrix& m1, const Matrix& m2)
{
    return m1 * m2;
}
Matrix* Matrix::MultRetByPoint(const Matrix& m1, const Matrix& m2)
{
    return  new Matrix(m1*m2);
}
