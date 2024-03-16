//#include <iostream>
//#include <cmath>
//using namespace std;
//
//// ��������� 1: x^2 + 4x - 2
//double equation1(double x) {
//    return x * x + 4 * x - 2;
//}
//
//// ��������� 2: sin(x) + 0.1
//double equation2(double x) {
//    return sin(x) + 0.1;
//}
//
//// ����� ��������� ��� ���������� ������ ���������
//double bisectionMethod(double (*equation)(double), double a, double b, double epsilon) {
//    double fa = equation(a);
//    double fb = equation(b);
//    double c;
//
//    while ((b - a) >= epsilon) {
//        // ������� �������� �������
//        c = (a + b) / 2;
//        double fc = equation(c);
//
//        // ��������� ���� ������� � ����� c
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
//    cout << "����� ���������: " << root << endl;
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    double a, b, epsilon;
//
//    // ���� �������� ������ ��� ��������� 1
//    cout << "������� �������� [a, b] ��� ��������� 1: ";
//    cin >> a >> b;
//    epsilon=0.001;
//
//    cout << "����� ��������� 1: " << endl;
//    findRoots(equation1, a, b, epsilon);
//
//    // ���� �������� ������ ��� ��������� 2
//    cout << "\n������� �������� [a, b] ��� ��������� 2: ";
//    cin >> a >> b;
//    epsilon=0.001;
//
//    cout << "����� ��������� 2: " << endl;
//    findRoots(equation2, a, b, epsilon);
//
//    return 0;
//}
