#include <iostream>
#include <string.h>
#include "Matrix.h"
#include "Multiply.h"
using namespace std;

bool IsNumber(char c[]);

// this is a test
// omg another test!!!
int main(int argc, char *argv[])
{

    srand(time(0));
    Matrix *first = new Matrix();
    Matrix *second = new Matrix();
    Matrix *ptr_result = nullptr;

    

    if(argc == 1)
    {
        first->Generate();
        second->Generate();
    }
    else
    {
        if(argc > 6)
        {
            delete first;
            delete second;
            if(ptr_result != nullptr)
                delete ptr_result;
            
            throw runtime_error("You entered too many arguments (Maximum is 7)");
        }

        for(int i= 1; i < argc; i++)
        {
            if(!IsNumber(argv[i]))
            {
                delete first;
                delete second;
                if(ptr_result != nullptr)
                    delete ptr_result;
                throw runtime_error("All entries must be numbers");
            }
        }
        
        first->SetSizeI(atoi(argv[1]));
        first->SetSizeJ(atoi(argv[2]));
        first->SetMod(atoi(argv[5]));
        first->Init(false);

        second->SetSizeI(atoi(argv[3]));
        second->SetSizeJ(atoi(argv[4]));
        second->SetMod(atoi(argv[5]));
        second->Init();

    }
    cout<<"The Modulus is " <<second->GetMod()<<endl<<endl; 
    cout<<"one\n";
    cout<<*first<<endl;  
    cout<<"two\n";  
    cout<<*second<<endl;


    cout<<"one + two (self)\n";
    *first += *second;
    cout << "new one : \n"<< *first<<endl;
    
    ptr_result = Matrix::AddRetByPoint(*first,*second);
    cout<<"one + two (by pointer)\n";
    cout<<*(ptr_result)<<endl;
    cout<<"one + two (by value) operator+\n";
    cout<<*first+*second<<endl;
    cout<<"one + two (by value)\n";
    cout<<Matrix::AddRetByVal(*first,*second)<<endl;

    ptr_result = Matrix::SubRetByPoint(*first,*second);

    cout<<"one - two (by pointer)\n";
    cout<<*(ptr_result)<<endl;
    cout<<"one - two (by value) operator+\n";
    cout<<*first - *second<<endl;
    cout<<"one - two (by value)\n";
    cout<<Matrix::SubRetByVal(*first,*second)<<endl;

    ptr_result = Matrix::MultRetByPoint(*first,*second);

    cout<<"one * two (by pointer)\n";
    cout<<*(ptr_result)<<endl;
    cout<<"one * two (by value) operator+\n";
    cout<<*first * *second<<endl;
    cout<<"one * two (by value)\n";
    cout<<Matrix::MultRetByVal(*first,*second)<<endl;


    delete first;
    first = nullptr;
    delete second;
    second = nullptr;
    if(ptr_result != nullptr)
        delete ptr_result;
    return 0;
}



bool IsNumber(char c[])
{
    const int len = strlen(c);
    for(int i = 0; i < len;i++)
    {
        if(!isdigit(c[i]))
            return false;
    }
    return true;
}