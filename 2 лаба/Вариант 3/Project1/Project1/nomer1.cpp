#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main() {
    setlocale(0, "");
    FILE* inputFile, * outputFile;
    int cols, rows, i, j;

    // Открываем файл для чтения
    if (fopen_s(&inputFile, "input.txt", "r") != 0) {
        printf("Ошибка открытия файла для чтения.\n");
        return 1;
    }

    // Читаем количество столбцов матрицы
    if (fscanf_s(inputFile, "%d", &cols) != 1) {
        printf("Ошибка чтения количества столбцов матрицы.\n");
        fclose(inputFile);
        return 1;
    }

    // Определяем количество строк матрицы
    rows = cols;

    // Выделяем память под матрицу
    double** matrix = (double**)malloc(rows * sizeof(double*));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти для матрицы.\n");
        fclose(inputFile);
        return 1;
    }
    for (i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
        if (matrix[i] == NULL) {
            printf("Ошибка выделения памяти для матрицы.\n");
            fclose(inputFile);
            return 1;
        }
    }

    // Читаем матрицу из файла
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (fscanf_s(inputFile, "%lf", &matrix[i][j]) != 1) {
                printf("Ошибка чтения элементов матрицы.\n");
                fclose(inputFile);
                return 1;
            }
        }
    }

    // Закрываем файл для чтения
    fclose(inputFile);

    // Создаем новый файл для записи
    if (fopen_s(&outputFile, "output.txt", "w") != 0) {
        printf("Ошибка открытия файла для записи.\n");
        return 1;
    }

    // Записываем количество столбцов в новый файл (стало количество строк)
    fprintf(outputFile, "%d\n", rows);

    // Транспонируем матрицу и записываем в новый файл
    for (j = 0; j < cols; j++) {
        for (i = 0; i < rows; i++) {
            fprintf(outputFile, "%.2lf ", matrix[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    // Закрываем файл для записи
    fclose(outputFile);

    // Освобождаем память, выделенную для матрицы
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    printf("Транспонированная матрица успешно записана в файл 'output.txt'\n");

    return 0;
}
