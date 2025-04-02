#ifndef FUNCA_H
#define FUNCA_H

#include <iostream>
#include <cmath>
#include <limits>
using namespace std;


class FuncA {
public:
 
    double taylor_sine(double x);


private:

    /**
     * 
     * @brief Compute factorial of a number.
     * 
     * This function takes one integer as input, calculates its factorial, and
     * returns the result.
     * 
     * @param n The number whose factorial will be calculated.
     * 
     */
    unsigned long long factorial(int n);
};


#endif