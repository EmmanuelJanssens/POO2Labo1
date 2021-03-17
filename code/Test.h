/**
 * @file Test.h
 * @authors Chhen Rosalie, Janssens Emmanuel
 * @brief Tests our implementation of the matrix
 * */
#ifndef POO2LABO1_TEST_H
#define POO2LABO1_TEST_H

#include <vector>

#include "Matrix.h"
#include "Add.h"
#include "Substract.h"
#include "Multiply.h"

using namespace std;

class Test {

private:

    vector<vector<unsigned>> validArgs = {
            {2, 3, 2, 3, 5}, // Matrix 1 and Matrix 2 have same size
            {2, 3, 3, 3, 5}, // Matrix 1 rows number is smaller than Matrix 2
            {2, 3, 2, 4, 5}, // Matrix 1 columns number is smaller than Matrix 2
            {2, 3, 4, 5, 5}, // Matrix 1 rows and columns numbers are smaller than Matrix 2
            {4, 5, 2, 3, 5}, // Matrix 2 rows and columns numbers are smaller than Matrix 1
    };

public:

    /**
     * For each serie of 5 valid arguments, create Matrix 1 (m1) and Matrix 2 (m2)
     * Test Additions :
     * - result by pointer
     * - result by value with operator +
     * - result by value
     * - result on self with operator +=
     * */
    void AddTest() {

        cout << "--- Addition tests :" << endl;

        for (int i = 0; i < validArgs.size(); ++i) {

            Matrix m1(validArgs[i][0], validArgs[i][1], validArgs[i][4]);
            Matrix m2(validArgs[i][2], validArgs[i][3], validArgs[i][4]);


            cout << "The Modulus is " << validArgs[i][4] << endl << endl;
            cout << "m1 :\n";
            cout << m1 << endl;
            cout << "m2 :\n";
            cout << m2 << endl;

            cout << "m1 + m2 (by pointer)\n";
            Matrix* ptr_result = Matrix::AddRetByPoint(m1, m2);
            cout << *(ptr_result) << endl;
            
            delete ptr_result;
            ptr_result = nullptr;

            cout << "m1 + m2 (by value) operator+\n";
            cout << m1+m2 << endl;

            cout << "m1 + m2 (by value)\n";
            cout << Matrix::AddRetByVal(m1, m2)<<endl;

            cout << "m1 += m2 (self)\n";
            m1 += m2;
            cout << "new m1 : \n"<< m1 <<endl;
        }
    }

    /**
     * For each serie of 5 valid arguments, create Matrix 1 (m1) and Matrix 2 (m2)
     * Test Subtraction :
     * - result by pointer
     * - result by value with operator -
     * - result by value
     * - result on self with operator -=
     * */
    void SubTest() {

        cout << "--- Subtraction tests :" << endl;

        for (int i = 0; i < validArgs.size(); ++i) {

            Matrix m1(validArgs[i][0], validArgs[i][1], validArgs[i][4]);
            Matrix m2(validArgs[i][2], validArgs[i][3], validArgs[i][4]);


            cout << "The Modulus is " << validArgs[i][4] << endl << endl;
            cout << "m1 :\n";
            cout << m1 << endl;
            cout << "m2 :\n";
            cout << m2 << endl;

            cout << "m1 - m2 (by pointer)\n";
            Matrix* ptr_result = Matrix::SubRetByPoint(m1, m2);
            cout << *(ptr_result) << endl;
            delete ptr_result;
            ptr_result = nullptr;

            cout << "m1 - m2 (by value) operator-\n";
            cout << m1-m2 << endl;

            cout << "m1 - m2 (by value)\n";
            cout << Matrix::SubRetByVal(m1, m2)<<endl;

            cout << "m1 -= m2 (self)\n";
            m1 -= m2;
            cout << "new m1 : \n"<< m1 <<endl;
        }
    }

    /**
     * For each serie of 5 valid arguments, create Matrix 1 (m1) and Matrix 2 (m2)
     * Test Multiplication :
     * - result by pointer
     * - result by value with operator *
     * - result by value
     * - result on self with operator *=
     * */
    void MultiplyTest() {

        cout << "--- Multiplication tests :" << endl;

        for (int i = 0; i < validArgs.size(); ++i) {

            Matrix m1(validArgs[i][0], validArgs[i][1], validArgs[i][4]);
            Matrix m2(validArgs[i][2], validArgs[i][3], validArgs[i][4]);


            cout << "The Modulus is " << validArgs[i][4] << endl << endl;
            cout << "m1 :\n";
            cout << m1 << endl;
            cout << "m2 :\n";
            cout << m2 << endl;

            cout << "m1 * m2 (by pointer)\n";
            Matrix* ptr_result = Matrix::MultRetByPoint(m1, m2);
            cout << *(ptr_result) << endl;
            delete ptr_result;
            ptr_result = nullptr;

            cout << "m1 * m2 (by value) operator*\n";
            cout << m1*m2 << endl;

            cout << "m1 * m2 (by value)\n";
            cout << Matrix::MultRetByVal(m1, m2)<<endl;

            cout << "m1 *= m2 (self)\n";
            m1 *= m2;
            cout << "new m1 : \n"<< m1 <<endl;
        }
    }

    /**
     * Create 3 Matrices and then copy them to test the copy constructor
     * */
    void CopyConstructorTest(){

        Matrix m1(2, 3, 4);

        Matrix m2(4,5,6);

        Matrix m3(3,4,3);

        Matrix copy1(m1);
        Matrix copy2(m2);
        Matrix copy3(m3);

        cout << "Test copy contructor : \n"
                "m1 mod 4 : " << endl;
        cout << m1;
        cout << "\nm2 mod 6 : " << endl;
        cout << m2;
        cout << "\nm3 mod 3 : " << endl;
        cout << m3;

        cout << "\ncopy1 of m1: " << endl;
        cout << copy1;
        cout << "\ncopy2 of m2: " << endl;
        cout << copy2;
        cout << "\ncopy3 of m3: " << endl;
        cout << copy3;
    }

    /**
     * Create 2 Matrices with different modulus and perform an operation between them
     * This test should throw an exception
     * */
    void DifferentModTest(){

        Matrix m1(2, 3, 4);
        Matrix m2(2, 3, 5);


        // throw an exception
        Matrix* ptr_result = Matrix::MultRetByPoint(m1, m2);
    }



};


#endif //POO2LABO1_TEST_H
