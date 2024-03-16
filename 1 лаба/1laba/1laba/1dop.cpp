//#include <iostream>
//#include <cmath>
//using namespace std;
//
//// Уравнение 1: x^2 + 4x - 2
//double equation1(double x) {
//    return x * x + 4 * x - 2;
//}
//
//// Уравнение 2: sin(x) + 0.1
//double equation2(double x) {
//    return sin(x) + 0.1;
//}
//
//// Метод дихотомии для вычисления корней уравнения
//double bisectionMethod(double (*equation)(double), double a, double b, double epsilon) {
//    double fa = equation(a);
//    double fb = equation(b);
//    double c;
//
//    while ((b - a) >= epsilon) {
//        // Находим середину отрезка
//        c = (a + b) / 2;
//        double fc = equation(c);
//
//        // Проверяем знак функции в точке c
//        if (fc == 0.0)
//            return c;
//        else if (fc * fa < 0)
//            b = c;
//        else
//            a = c;
//    }
//    return (a + b) / 2;
//}
//
//void findRoots(double (*equation)(double), double a, double b, double epsilon) {
//    double root = bisectionMethod(equation, a, b, epsilon);
//    cout << "Корни уравнения: " << root << endl;
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    double a, b, epsilon;
//
//    // Ввод исходных данных для уравнения 1
//    cout << "Введите интервал [a, b] для уравнения 1: ";
//    cin >> a >> b;
//    epsilon=0.001;
//
//    cout << "Корни уравнения 1: " << endl;
//    findRoots(equation1, a, b, epsilon);
//
//    // Ввод исходных данных для уравнения 2
//    cout << "\nВведите интервал [a, b] для уравнения 2: ";
//    cin >> a >> b;
//    epsilon=0.001;
//
//    cout << "Корни уравнения 2: " << endl;
//    findRoots(equation2, a, b, epsilon);
//
//    return 0;
//}
