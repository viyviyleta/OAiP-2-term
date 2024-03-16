#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main() {
    setlocale(0, "");
    FILE* inputFile, * outputFile;
    int cols, rows, i, j;

    // ��������� ���� ��� ������
    if (fopen_s(&inputFile, "input.txt", "r") != 0) {
        printf("������ �������� ����� ��� ������.\n");
        return 1;
    }

    // ������ ���������� �������� �������
    if (fscanf_s(inputFile, "%d", &cols) != 1) {
        printf("������ ������ ���������� �������� �������.\n");
        fclose(inputFile);
        return 1;
    }

    // ���������� ���������� ����� �������
    rows = cols;

    // �������� ������ ��� �������
    double** matrix = (double**)malloc(rows * sizeof(double*));
    if (matrix == NULL) {
        printf("������ ��������� ������ ��� �������.\n");
        fclose(inputFile);
        return 1;
    }
    for (i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
        if (matrix[i] == NULL) {
            printf("������ ��������� ������ ��� �������.\n");
            fclose(inputFile);
            return 1;
        }
    }

    // ������ ������� �� �����
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (fscanf_s(inputFile, "%lf", &matrix[i][j]) != 1) {
                printf("������ ������ ��������� �������.\n");
                fclose(inputFile);
                return 1;
            }
        }
    }

    // ��������� ���� ��� ������
    fclose(inputFile);

    // ������� ����� ���� ��� ������
    if (fopen_s(&outputFile, "output.txt", "w") != 0) {
        printf("������ �������� ����� ��� ������.\n");
        return 1;
    }

    // ���������� ���������� �������� � ����� ���� (����� ���������� �����)
    fprintf(outputFile, "%d\n", rows);

    // ������������� ������� � ���������� � ����� ����
    for (j = 0; j < cols; j++) {
        for (i = 0; i < rows; i++) {
            fprintf(outputFile, "%.2lf ", matrix[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    // ��������� ���� ��� ������
    fclose(outputFile);

    // ����������� ������, ���������� ��� �������
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    printf("����������������� ������� ������� �������� � ���� 'output.txt'\n");

    return 0;
}
