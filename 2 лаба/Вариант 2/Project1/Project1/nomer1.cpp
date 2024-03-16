//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//int main() {
//    setlocale(0, "");
//    FILE* fileA, * fileB, * fileC;
//    char filenameA[] = "fA.txt";
//    char filenameB[] = "fB.txt";
//    char filenameC[] = "fC.txt";
//
//    // Открытие файлов для чтения
//    if (fopen_s(&fileA, filenameA, "r") != 0 || fopen_s(&fileB, filenameB, "r") != 0) {
//        perror("Ошибка при открытии файлов");
//        exit(EXIT_FAILURE);
//    }
//
//    // Чтение количества столбцов из файлов
//    int columnsA, columnsB;
//    fscanf_s(fileA, "%d", &columnsA);
//    fscanf_s(fileB, "%d", &columnsB);
//
//    // Проверка совпадения количества столбцов
//    if (columnsA != columnsB) {
//        printf("Количество столбцов в матрицах не совпадает\n");
//        exit(EXIT_FAILURE);
//    }
//
//    // Открытие файла для записи
//    if (fopen_s(&fileC, filenameC, "w") != 0) {
//        perror("Ошибка при создании файла fC.txt");
//        exit(EXIT_FAILURE);
//    }
//
//    // Запись количества столбцов в файл fC.txt
//    fprintf(fileC, "%d\n", columnsA);
//
//    // Чтение и суммирование матриц
//    double numA, numB;
//    int colCount = 0;
//    while (fscanf_s(fileA, "%lf", &numA) == 1 && fscanf_s(fileB, "%lf", &numB) == 1) {
//        fprintf(fileC, "%.2lf ", numA + numB);
//        colCount++;
//        if (colCount == columnsA) {
//            fprintf(fileC, "\n"); // добавляем символ новой строки после каждой строки матрицы
//            colCount = 0;
//        }
//    }
//
//    // Закрытие файлов
//    fclose(fileA);
//    fclose(fileB);
//    fclose(fileC);
//
//    printf("Сумма матриц записана в файл fC.txt\n");
//
//    return 0;
//}
