#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    FILE* fileF, * fileG;
    int numbers[20];  // Массив для хранения чисел из файла f.txt

    // Открытие файлов
    if (fopen_s(&fileF, "f.txt", "r") != 0 || fopen_s(&fileG, "g.txt", "w") != 0) {
        cout << "Ошибка открытия файлов" << endl;
        return 1;
    }

    // Чтение чисел из файла f.txt
    for (int i = 0; i < 20; i++) {
        fscanf_s(fileF, "%d", &numbers[i]);
    }

    // Запись чисел в файл g.txt
    for (int i = 0; i < 2; ++i) { // Повторяем два раза
        for (int j = 0; j < 5; ++j) {
            fprintf(fileG, "%d\n", numbers[j + i * 5]); // Записываем 5 положительных чисел
        }
        for (int j = 0; j < 5; ++j) {
            fprintf(fileG, "%d\n", numbers[j + 10 + i * 5]); // Записываем 5 отрицательных чисел
        }
    }

    cout << "Файл g.txt создан" << endl;

    // Закрытие файлов
    fclose(fileF);
    fclose(fileG);

    return 0;
}
