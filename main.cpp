// simple_http_server.cpp — HTTP сервер із обчисленням sin(x) через FuncA

#include "httplib.h"  // Бібліотека HTTP-сервера
#include "FuncA.h"     // Клас із методом taylor_sine
#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    httplib::Server svr;

    svr.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        if (!req.has_param("x") || !req.has_param("terms")) {
            res.status = 400;
            res.set_content("Missing parameters 'x' and/or 'terms'", "text/plain");
            return;
        }

        try {
            double x = std::stod(req.get_param_value("x"));
            int terms = std::stoi(req.get_param_value("terms"));

            FuncA func;
            double result = func.taylor_sine(x, terms);

            std::string response = "sin(" + std::to_string(x) + ") ≈ " + std::to_string(result);
            res.set_content(response, "text/plain");
        } catch (const std::exception& e) {
            res.status = 400;
            res.set_content(std::string("Error: ") + e.what(), "text/plain");
        }
    });

    std::cout << "HTTP сервер запущено на порті 80" << std::endl;
    svr.listen("0.0.0.0", 80);
    return 0;
}
