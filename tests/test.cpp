#include "FuncA.h"
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <cassert>

int main() {
    FuncA func;
    std::vector<double> results;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 100000; ++i) {
        results.push_back(func.taylor_sine(i * 0.001, 10));
    }

    std::sort(results.begin(), results.end());

    auto end = std::chrono::high_resolution_clock::now();
    double elapsed = std::chrono::duration<double>(end - start).count();

    std::cout << "Elapsed: " << elapsed << " seconds" << std::endl;

    assert(elapsed >= 5.0 && elapsed <= 20.0);
    std::cout << "Test passed.\n";

    return 0;
}
