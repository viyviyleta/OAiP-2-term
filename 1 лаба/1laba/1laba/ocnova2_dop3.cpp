//#include <iostream>
//#include <cstdarg>
//#include <limits> // для использования numeric_limits
//using namespace std;
//
//// функция fmax с переменным числом параметров
//template<typename t>
//t fmax(int type, int num, ...) {
//    // инициализируем переменную min значением максимального числа типа t
//    t min = numeric_limits<t>::max();
//
//    
//    if (type == 0) { // int
//        va_list args;
//        va_start(args, num);
//        for (int i = 0; i < num; ++i) {
//            t val = va_arg(args, int);
//            if (val < min) {
//                min = val;
//            }
//        }
//        va_end(args);
//    }
//    else if (type == 1) { // double
//        va_list args;
//        va_start(args, num);
//        for (int i = 0; i < num; ++i) {
//            t val = va_arg(args, double);
//            if (val < min) {
//                min = val;
//            }
//        }
//        va_end(args);
//    }
//
//    return min;
//}
//
//int main() {
//   
//    int result1 = fmax<int>(0, 5, 10, 20, 5, 15, 25); 
//    double result2 = fmax<double>(1, 4, 3.14, 2.71, 1.618, 0.123);
//
//    cout << "min int: " << result1 << endl;
//    cout << "min double: " << result2 << endl;
//
//    return 0;
//}
