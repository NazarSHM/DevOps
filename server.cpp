#include "httplib.h"
#include "FuncA.h"
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main() {
    httplib::Server svr;

    svr.Get("/calculate", [](const httplib::Request&, httplib::Response& res) {
        FuncA func;
        std::vector<double> values;
        int terms = 10;
        int N = 10000000; // підібрати під свою машину (10s +/-)

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < N; ++i) {
            values.push_back(func.taylor_sine(i * 0.001, terms));
        }

        std::sort(values.begin(), values.end());

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        res.set_content("Elapsed time: " + std::to_string(elapsed.count()) + "s", "text/plain");
    });

    std::cout << "✅ HTTP сервер запущено: http://localhost:8080/calculate" << std::endl;
    svr.listen("0.0.0.0", 8080);
}
