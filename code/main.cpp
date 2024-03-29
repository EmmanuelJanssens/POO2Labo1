/**
 * @file main.h
 * @authors Chhen Rosalie, Janssens Emmanuel
 * @brief Contains main program that tests our matrix implementation
 * */
#include <iostream>
#include <string.h>
#include <time.h>

#include "Matrix.h"
#include "Test.h"
using namespace std;

bool IsNumber(char c[]);

int main(int argc, char *argv[])
{

    srand(time(0));

    if(argc != 6)
    {
        throw runtime_error("Invalid numbers of arguments (should enter : N1 M1 N2 M2 MOD)");
    }

    for(int i= 1; i < argc; i++)
    {
        if(!IsNumber(argv[i]))
        {
            throw runtime_error("All entries must be numbers");
        }
    }

    Matrix *first = new Matrix(atoi(argv[1]), atoi(argv[2]), atoi(argv[5]));
    Matrix *second = new Matrix(atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
    Matrix *ptr_result = nullptr;


    cout<<"The Modulus is " << argv[4] <<endl<<endl;
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


    // --- TESTS

    cout << "--- TESTS ---" << endl;

    Test test;

    test.AddTest();
    test.SubTest();
    test.MultiplyTest();
    test.CopyConstructorTest();

    try
    {
        test.DifferentModTest(); 
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    

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