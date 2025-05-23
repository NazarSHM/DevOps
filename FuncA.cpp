
#include "./FuncA.h"


double FuncA::taylor_sine(double x, int terms) {
    double sine_value = 0.0;

    for (int n = 0; n < terms; ++n) {
        // Taylor series term: ((-1)^n * x^(2n+1)) / (2n+1)!
        double term = pow(-1, n) * pow(x, 2 * n + 1) / factorial(2 * n + 1);
        sine_value += term;

        // Stop early if the term is very small (for better precision)

//Підключення заголовочного файлу класу FuncA, де оголошено методи
#include "./FuncA.h"

//Метод класу FuncA, який обчислює значення синуса x за допомогою ряду Тейлора
double FuncA::taylor_sine(double x, int terms) {
    //Ініціалізація змінної для зберігання кінцевого результату синуса
    double sine_value = 0.0;

    // Основний цикл по кількості членів ряду Тейлора
    for (int n = 0; n < terms; ++n) {
        /*ОЛбчислення одного члена ряду Тейлора для sin(x):
        Формула: ((-1)^n * x^(2n+1)) / (2n+1)!
        pow(-1, n) створює чергування знаків (+ / -)
        pow(x, 2n+1) — підносить x до непарного степеня
        factorial(2n+1) — знаменник: факторіал від (2n+1)*/
        double term = pow(-1, n) * pow(x, 2 * n + 1) / factorial(2 * n + 1);

        //Додаємо обчислений член до загального результату
        sine_value += term;

        /*Перевірка: якщо абсолютне значення члена дуже мале, припиняємо цикл раніше
        Це оптимізація: якщо приріст настільки малий, що він не вплине на результат
        numeric_limits<double>::epsilon() — найменше значення, яке double може додати без втрати точності*/

        if (abs(term) < numeric_limits<double>::epsilon()) {
            break;
        }
    }


    return sine_value;
}

unsigned long long FuncA::factorial(int n) {
    unsigned long long result = 1;


    //Повертаємо результат — приблизне значення sin(x)
   return sine_value;
}

// Метод класу FuncA, який обчислює факторіал числа n
unsigned long long FuncA::factorial(int n) {
    //Ініціалізація змінної результату (початкове значення 1)
    unsigned long long result = 1;

    //Послідовне множення всіх чисел від 1 до n включно
    //Наприклад: 5! = 1 × 2 × 3 × 4 × 5 = 120

    for (int i = 1; i <= n; ++i) {
        result *= i;
    }


    return result;
}

//Повертаємо факторіал
    return result;




