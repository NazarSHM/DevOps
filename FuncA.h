#ifndef FUNCA_H
#define FUNCA_H
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

class FuncA {
 

public:

    /**
     * 
     * @brief Calculate sin(x) using the Taylor series.
     * 
     * This function takes two numbers as input, perform the computing of
     * sin(x) using the Taylor series, and returns the result.
     * 
     * @param x The function x value.
     * @param terms The function terms.
     * @return The sin(x) value.
     * 
     */
    double taylor_sine(double x, int terms = 0);

private:

    unsigned long long factorial(int n);


};

#endif