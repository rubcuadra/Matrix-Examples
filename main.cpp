//
//  main.cpp
//  ExamenFInal
//
//  Created by Ruben Cuadra on 5/12/15.
//  Copyright (c) 2015 Ruben Cuadra. All rights reserved.
//

#include <iostream>
#include "Matrix.h"

int main(int argc, const char * argv[])
{
    Matrix<int> matrix(2);
    matrix.FillUser();
    
    //matrix.findAdyacent(&Matrix<int>::isPrime);
    //matrix.findIf(5,&Matrix<int>::MayorQue);
    //matrix.findSameAdyacent();
    matrix.findIf(&Matrix<int>::isCircularPrimo);
    
    
    std::cout<<matrix;
    return 0;
}
