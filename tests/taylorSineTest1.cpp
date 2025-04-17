#include <iostream>
#include <cmath>
#include <cassert>
#include "../FuncA.h"

int main() {
    FuncA func;

    double x = M_PI / 2;
    int terms = 10;
    double result = func.taylor_sine(x, terms);
    double expected = std::sin(x);

    std::cout << "Result: " << result << "\nExpected: " << expected << std::endl;
    assert(std::abs(result - expected) < 0.01);  // точність 0.01
    return 0;
}
