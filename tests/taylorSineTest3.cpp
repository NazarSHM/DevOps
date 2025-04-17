#include <cmath>
#include <cassert>
#include "../FuncA.h"

int main() {
    FuncA func;
    double x = -M_PI / 2;
    double expected = std::sin(x);
    double result = func.taylor_sine(x, 10);
    assert(std::abs(result - expected) < 0.01);
    return 0;
}
