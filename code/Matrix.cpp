#include "Matrix.h"

Matrix::Matrix()
    :_size_i(0),_size_j(0),_mod(0)
{
    _values = nullptr;
}
Matrix::Matrix(int i, int j, int mod)
    : _size_i(i),_size_j(j),_mod(mod)
{
    Init(false);
}


Matrix::Matrix(const Matrix& copy)
{
    this->_size_i = copy.GetSizeI();
    this->_size_j = copy.GetSizeJ();
    this->_mod = copy.GetMod();

    //initialize array pointer
    _values =  new int*[_size_i];
    for(int i = 0; i < _size_i; i++)
    {
        //initialize values arrays
        _values[i] =  new int[_size_j];
    }

    //copy values
    for(int i = 0; i < _size_i; i++)
    {
        for(int j = - 0; j < _size_j; j++)
        {
            _values[i][j] = copy.GetValues()[i][j];
        }
    }
}
void Matrix::operator=(const Matrix& copy)
{
    this->_size_i = copy.GetSizeI();
    this->_size_j = copy.GetSizeJ();
    this->_mod = copy.GetMod();

    //initialize array pointer
    _values =  new int*[_size_i];
    for(int i = 0; i < _size_i; i++)
    {
        //initialize values arrays
        _values[i] =  new int[_size_j];
    }

    //copy values
    for(int i = 0; i < _size_i; i++)
    {
        for(int j = - 0; j < _size_j; j++)
        {
            _values[i][j] = copy.GetValues()[i][j];
        }
    }
}
void Matrix::Generate()
{
    this->_size_i = 1 + std::rand() % 10;
    this->_size_j =  1 + std::rand() % 10;
    this->_mod =  1 + std::rand() % 10;

    Init(false);
}
void Matrix::Init(bool zero)
{
    //initialize array pointer
    /**
        {
            {1,2,3,4}, 
            {1,2,3,4},
            {1,2,3,4} 
        }
    **/

    _values =  new int*[_size_i];
    for(int i= 0; i < _size_i; i++)
    {
        //initialize values arrays
        _values[i] =  new int[_size_j];
        for(int j = - 0; j < _size_j; j++)
        {
            if(!zero)
                _values[i][j] = CreateRandeomValue();
            else
                _values[i][j] = 0;

        }    
    }
}
int **Matrix::GetValues() const
{ 
    if(this->_values != nullptr)
    {
        if( *(this->_values) != nullptr )
        {
            return this->_values;
        }
    }

    //if we get here values are either not initialized or not valid
    throw std::runtime_error("Values are not valid");
    return nullptr;
}

Matrix Matrix::Calculate(const Matrix& m1, const Matrix& m2, Operation * op)
{
    Matrix *temp = new Matrix();
    temp->SetSizeJ(std::max(m1.GetSizeJ(), m2.GetSizeJ()));
    temp->SetSizeI(std::max(m1.GetSizeI(), m2.GetSizeI()));
    temp->SetMod(std::max(m1.GetMod(), m2.GetMod()));
    temp->Init(true);

    int op1 = 0;
    int op2 = 0;


    for(int i =0; i < temp->GetSizeI(); i++)
    {
        for(int j = 0; j < temp->GetSizeJ(); j++)
        {
            if(i < m1.GetSizeI() && j < m1.GetSizeJ())
            {
                op1 = m1.GetValues()[i][j];
            }
            else
                op1 = 0;

            if(i < m2.GetSizeI() && j < m2.GetSizeJ())
                op2 = m2.GetValues()[i][j];
            else
                op2 = 0;

            //temp->GetValues()[i][j]  = op->execute(op1,op2) % temp->GetMod();
            temp->GetValues()[i][j] = op->execute(op1,op2) - temp->GetMod();

        }
    }
    // -1 % 5 = 4
    if(op != nullptr)
        delete op;
    else
        throw std::runtime_error("Operation is not declared");

    op = nullptr;
    
    Matrix result(*temp);
    if(temp!=nullptr)
        delete temp;
    else
        throw std::runtime_error("Error while getting results");

    temp = nullptr;

    return result;    
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

int Matrix::CreateRandeomValue()
{
    int random = 1+std::rand() % _mod;
    return random;
}



void Matrix::AddSelf(const Matrix& toAdd)
{
    *this = *this + toAdd;
}
void Matrix::operator+=(const Matrix& toAdd)
{   
    AddSelf(toAdd);
} 
Matrix Matrix::AddRetByVal(const Matrix& m1, const Matrix& m2)
{
    return Matrix::Calculate(m1,m2,new Add());
}
Matrix* Matrix::AddRetByPoint(const Matrix& m1, const Matrix& m2)
{
    return  new Matrix(m1+m2);
}

void Matrix::SubSelf(const Matrix& toAdd)
{
    *this = *this - toAdd; 
}
void Matrix::operator-=(const Matrix& toAdd)
{   
    SubSelf(toAdd);
} 
Matrix Matrix::SubRetByVal(const Matrix& m1, const Matrix& m2)
{
    return Matrix::Calculate(m1,m2,new Substract());
}
Matrix* Matrix::SubRetByPoint(const Matrix& m1, const Matrix& m2)
{
    return  new Matrix(m1-m2);
}

void Matrix::MultSelf(const Matrix& toAdd)
{
    *this = *this * toAdd;
}
void Matrix::operator*=(const Matrix& toAdd)
{   
    MultSelf(toAdd);
} 
Matrix Matrix::MultRetByVal(const Matrix& m1, const Matrix& m2)
{
    return Matrix::Calculate(m1,m2,new Multiply());
}
Matrix* Matrix::MultRetByPoint(const Matrix& m1, const Matrix& m2)
{
    return  new Matrix(m1*m2);
}
