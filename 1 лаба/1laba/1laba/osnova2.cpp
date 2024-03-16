#include <iostream>
#include <cstdarg>

// функция fsum с переменным числом параметров
int fsum(int num, ...) {
    int sum = 0;
    va_list args;
    va_start(args, num);
    for (int i = 0; i < num - 1; ++i) {
        int a = va_arg(args, int);
        sum += a;
    }
    va_end(args);
    return sum;
}

int main() {
    // вызов функции fsum с разным количеством параметров
    int result1 = fsum(4, 1, 2, 3, 4);
    int result2 = fsum(6, 1, 2, 3, 4, 5, 6);
    int result3 = fsum(8, 1, 2, 3, 4, 5, 6, 7, 8);

    // вывод результатов
    std::cout << "result 1: " << result1 << std::endl;
    std::cout << "result 2: " << result2 << std::endl;
    std::cout << "result 3: " << result3 << std::endl;

    return 0;
}
