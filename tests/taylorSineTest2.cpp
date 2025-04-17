#include <cassert>
#include "../FuncA.h"

int main() {
    FuncA func;
    double result = func.taylor_sine(0, 5);
    assert(result == 0);
    return 0;
}
