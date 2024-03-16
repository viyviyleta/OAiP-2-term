//#include <iostream>
//#include <cmath>
//using namespace std;
//const double epsilon = 0.001;
//
//// ������� ��� ��������� 1: x^3 + x - 3
//double equation1(double x) {
//    return pow(x, 3) + x - 3;
//}
//
//// ������� ��� ��������� 2: cos^3(x)
//double equation2(double x) {
//    return pow(cos(x), 3);
//}
//
//// ������� ������ ���������
//double bisectionMethod(double (*equation)(double), double a, double b) {
//    double c;
//    while ((b - a) >= epsilon) {
//        c = (a + b) / 2.0;
//
//        // ���������, ��������� �� ������ ����� ������� a � c
//        if (equation(c) == 0.0)
//            break;
//        else if (equation(c) * equation(a) < 0)
//            b = c;
//        else
//            a = c;
//    }
//    return c;
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    // ���� �������� ������: �������� [a, b] ��� ��������� 1
//    double a1, b1;
//    cout << "������� �������� [a, b] ��� ��������� 1:";
//    cin >> a1 >> b1;
//
//    // ���������� ����� ��������� 1 ������� ���������
//    double root1 = bisectionMethod(equation1, a1, b1);
//    cout << "����� ��������� 1: " << root1 << endl;
//
//    // ���� �������� ������: �������� [a, b] ��� ��������� 2
//    double a2, b2;
//    cout << "������� �������� [a, b] ��� ��������� 2: ";
//    cin >> a2 >> b2;
//
//    // ���������� ����� ��������� 2 ������� ���������
//    double root2 = bisectionMethod(equation2, a2, b2);
//    cout << "����� ��������� 2: " << root2 << endl;
//
//    return 0;
//}
