//#include <iostream>
//#include <cstdarg>
//#include <climits>
//using namespace std;
//
//// Функция fmin с переменным числом параметров для определения минимального числа типа int
//int fmin(int num, ...) {
//    int maxi = INT_MIN; // Инициализируем минимальное значение максимальным возможным значением для int
//    va_list args;
//    va_start(args, num);
//    for (int i = 0; i < num; ++i) {
//        int current = va_arg(args, int);
//        if (current > maxi) {
//            maxi = current;
//        }
//    }
//    va_end(args);
//    return maxi;
//}
//
//int main() {
//    // Вызов функции fmin с различным количеством параметров
//    int max1 = fmin(3, 23, 3, 6);
//    int max2 = fmin(5, 50, 4, 5, 30, 5);
//    int max3 = fmin(4, 100, 50, 75, 25);
//
//    // Вывод результатов
//    cout << "Max 1: " << max1 << endl;
//    cout << "Max 2: " << max2 << endl;
//    cout << "Max 3: " << max3 << endl;
//
//    return 0;
//}
