#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

// дополнительная функция для четвертого варианта
double mod(double a, double b) {
    return (a - floor(a / b) * b);
}

// функция четвертого варианта
double taskTwo(double a, double b) {
    if (b == 0) return 0;
    if (b != 0) {
        return (floor(a / b) + taskTwo(b, mod(a, b)));
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    double a, b;
    char input[100]; // Буфер для считывания строки

    // Цикл продолжается до тех пор, пока не будет введено корректное значение
    while (true) {
        cout << "a = ";
        cin >> input; // Считываем строку в буфер
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода

        // Проверяем наличие точки в строке
        if (strchr(input, '.') != nullptr) {
            cout << "Ошибка ввода. Пожалуйста, введите целое число для a." << endl;
            continue; // Если точка обнаружена, переходим на следующую итерацию цикла
        }

        // Пытаемся преобразовать строку в число
        if (sscanf_s(input, "%lf", &a) == 1 && a >= 0 && ceil(a) == a) {
            break; // Если преобразование прошло успешно и число неотрицательное и целое, выходим из цикла
        }
        else {
            cout << "Ошибка ввода. Пожалуйста, введите неотрицательное целое число для a." << endl;
        }
    }

    // То же самое для переменной b
    while (true) {
        cout << "b = ";
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (strchr(input, '.') != nullptr) {
            cout << "Ошибка ввода. Пожалуйста, введите целое число для b." << endl;
            continue;
        }

        if (sscanf_s(input, "%lf", &b) == 1 && b >= 0 && ceil(b) == b) {
            break;
        }
        else {
            cout << "Ошибка ввода. Пожалуйста, введите неотрицательное целое число для b." << endl;
        }
    }

    cout << "Результат = " << taskTwo(a, b) << " квадратиков" << "\n";

    return 0;
}
