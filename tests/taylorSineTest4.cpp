#include <cassert>
#include <cmath>
#include <iostream>
#include "../FuncA.h"

bool isEqual(double a, double b, double eps = 1e-6) {
    return std::abs(a - b) < eps;
}

int main() {
    FuncA f;
    double input = M_PI / 2; // 90 градусів
    double result = f.taylor_sine(input, 10);
    double expected = 1.0;

    std::cout << "Result: " << result << std::endl;
    std::cout << "Expected: " << expected << std::endl;

    assert(isEqual(result, expected));
    std::cout << " Test passed!" << std::endl;

    return 0;
}
