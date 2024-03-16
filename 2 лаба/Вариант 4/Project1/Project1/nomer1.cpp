#include <iostream>
#include <stdio.h>

int main() {
    setlocale(LC_ALL, "rus");
    FILE* fileA, * fileB;
    int number;

    // Открытие файла с исходными данными
    if (fopen_s(&fileA, "fileA.txt", "r") != 0) {
        perror("Ошибка открытия файла fileA.txt");
        return 1;
    }

    // Открытие файла для записи положительных чисел
    if (fopen_s(&fileB, "fileB.txt", "w") != 0) {
        perror("Ошибка открытия файла fileB.txt");
        fclose(fileA);
        return 1;
    }

    // Чтение и запись положительных чисел
    while (fscanf_s(fileA, "%lf", &number) != EOF) {
        if (number > 0) {
            fprintf(fileB, "%.2lf\n", number); // %.2lf для записи чисел с плавающей точкой с двумя знаками после запятой
        }
    }

    std::cout << "Файл fileB успешно создан" << std::endl;

    // Закрытие файлов
    fclose(fileA);
    fclose(fileB);

    return 0;
}
