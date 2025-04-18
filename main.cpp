
#include "./FuncA.h"

int main(int argc, char const *argv[]) {

    // Check if exactly 2 parameters were provided
    // (argc should be 3: program name + 2 parameters)
    if (argc != 3)
    {
        cerr << "Invalid usage: 2 parameter are required" << endl;
        return 0;
    }


#include "./FuncA.h"  //Підключаємо заголовок із класом FuncA

int main(int argc, char const *argv[]) {

    //Перевіряємо, чи передано рівно два параметри
    //argc має бути 3: 1 — назва програми, 2 — значення x, 3 — кількість термів
    if (argc != 3)
    {
        std::cerr << "Invalid usage: 2 parameter are required" << std::endl;
        std::cerr << "Example: ./sinapp 0.5 10" << std::endl;
        return 0;
    }

    //Оголошення змінних для введених значень

    double x;
    int terms;

    try
    {

       x = stod(argv[1]);
        terms = stoi(argv[2]);
    }
    catch (const invalid_argument& e)
    {
        cerr << "Invalid argument: " << e.what() << endl;
        exit(1);
    }
    catch (const out_of_range& e)
   {
        cerr << "Out of range: " << e.what() << endl;
        exit(1);
    }

    FuncA funcA;

    double result = funcA.taylor_sine(x, terms);
    cout << "sin(" << x << ") ≈ " << result << endl;

    return 0;
}

        /*Перетворюємо аргументи з рядків у числа
        argv[1] — перший параметр: x (радіани)
        argv[2] — другий параметр: кількість членів ряду Тейлора
        x = std::stod(argv[1]);   // string → double*/
        terms = std::stoi(argv[2]); // string → int
    }
    catch (const std::invalid_argument& e)
    {
        //Якщо введено не число
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        exit(1);
    }
    catch (const std::out_of_range& e)
    {
        //Якщо число надто велике або мале
        std::cerr << "Out of range: " << e.what() << std::endl;
        exit(1);
    }

    //Створюємо об'єкт класу FuncA
    FuncA funcA;

    //Викликаємо метод для обчислення sin(x)
    double result = funcA.taylor_sine(x, terms);

    //Виводимо результат на екран
    std::cout << "sin(" << x << ") ≈ " << result << std::endl;

    return 0;
}

