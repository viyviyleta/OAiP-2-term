//#include <iostream>
//#include <cstdarg>
//#include <climits>
//using namespace std;
//
//// Функция fmin с переменным числом параметров для определения минимального числа типа int
//int fmin(int num, ...) {
//    int min = INT_MAX; // Инициализируем минимальное значение максимальным возможным значением для int
//    va_list args;
//    va_start(args, num);
//    for (int i = 0; i < num; ++i) {
//        int current = va_arg(args, int);
//        if (current < min) {
//            min = current;
//        }
//    }
//    va_end(args);
//    return min;
//}
//
//int main() {
//    // Вызов функции fmin с различным количеством параметров
//    int min1 = fmin(3, 23, 3, 6);
//    int min2 = fmin(5, 50, 4, 5, 30, 5);
//    int min3 = fmin(4, 100, 50, 75, 25);
//
//    // Вывод результатов
//    cout << "Min 1: " << min1 << endl;
//    cout << "Min 2: " << min2 << endl;
//    cout << "Min 3: " << min3 << endl;
//
//    return 0;
//}
