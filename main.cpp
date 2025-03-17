#include <iostream>
#include "matrix.h"

int main(){
    // Matrix m1(2,3);
    // m1.setElement(1, 0, 0);
    // m1.setElement(2, 1, 0);
    // m1.setElement(3, 2, 0);
    // m1.setElement(4, 0, 1);
    // m1.setElement(5, 1, 1);
    // m1.setElement(6, 2, 1);
    // m1.print();

    Matrix m1(2,2);
    m1.setElement(1, 0, 0);
    m1.setElement(2, 1, 0);
    m1.setElement(3, 0, 1);
    m1.setElement(4, 1, 1);
    m1.print();

    Matrix m2(2,2);
    m2.setElement(-1, 0, 0);
    m2.setElement(-2, 1, 0);
    m2.setElement(-3, 0, 1);
    m2.setElement(-4, 1, 1);
    m2.print();

    Matrix <int>m3;
    m3 = sum(m1, m2);
    m3.print();
    m1.print();
    return 0;
}