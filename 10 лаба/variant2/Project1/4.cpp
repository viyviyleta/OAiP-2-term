#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

// �������������� ������� ��� ���������� ��������
double mod(double a, double b) {
    return (a - floor(a / b) * b);
}

// ������� ���������� ��������
double taskTwo(double a, double b) {
    if (b == 0) return 0;
    if (b != 0) {
        return (floor(a / b) + taskTwo(b, mod(a, b)));
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    double a, b;
    char input[100]; // ����� ��� ���������� ������

    // ���� ������������ �� ��� ���, ���� �� ����� ������� ���������� ��������
    while (true) {
        cout << "a = ";
        cin >> input; // ��������� ������ � �����
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����

        // ��������� ������� ����� � ������
        if (strchr(input, '.') != nullptr) {
            cout << "������ �����. ����������, ������� ����� ����� ��� a." << endl;
            continue; // ���� ����� ����������, ��������� �� ��������� �������� �����
        }

        // �������� ������������� ������ � �����
        if (sscanf_s(input, "%lf", &a) == 1 && a >= 0 && ceil(a) == a) {
            break; // ���� �������������� ������ ������� � ����� ��������������� � �����, ������� �� �����
        }
        else {
            cout << "������ �����. ����������, ������� ��������������� ����� ����� ��� a." << endl;
        }
    }

    // �� �� ����� ��� ���������� b
    while (true) {
        cout << "b = ";
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (strchr(input, '.') != nullptr) {
            cout << "������ �����. ����������, ������� ����� ����� ��� b." << endl;
            continue;
        }

        if (sscanf_s(input, "%lf", &b) == 1 && b >= 0 && ceil(b) == b) {
            break;
        }
        else {
            cout << "������ �����. ����������, ������� ��������������� ����� ����� ��� b." << endl;
        }
    }

    cout << "��������� = " << taskTwo(a, b) << " �����������" << "\n";

    return 0;
}
