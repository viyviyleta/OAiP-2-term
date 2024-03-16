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
//    // �������� ������ ��� ������
//    if (fopen_s(&fileA, filenameA, "r") != 0 || fopen_s(&fileB, filenameB, "r") != 0) {
//        perror("������ ��� �������� ������");
//        exit(EXIT_FAILURE);
//    }
//
//    // ������ ���������� �������� �� ������
//    int columnsA, columnsB;
//    fscanf_s(fileA, "%d", &columnsA);
//    fscanf_s(fileB, "%d", &columnsB);
//
//    // �������� ���������� ���������� ��������
//    if (columnsA != columnsB) {
//        printf("���������� �������� � �������� �� ���������\n");
//        exit(EXIT_FAILURE);
//    }
//
//    // �������� ����� ��� ������
//    if (fopen_s(&fileC, filenameC, "w") != 0) {
//        perror("������ ��� �������� ����� fC.txt");
//        exit(EXIT_FAILURE);
//    }
//
//    // ������ ���������� �������� � ���� fC.txt
//    fprintf(fileC, "%d\n", columnsA);
//
//    // ������ � ������������ ������
//    double numA, numB;
//    int colCount = 0;
//    while (fscanf_s(fileA, "%lf", &numA) == 1 && fscanf_s(fileB, "%lf", &numB) == 1) {
//        fprintf(fileC, "%.2lf ", numA + numB);
//        colCount++;
//        if (colCount == columnsA) {
//            fprintf(fileC, "\n"); // ��������� ������ ����� ������ ����� ������ ������ �������
//            colCount = 0;
//        }
//    }
//
//    // �������� ������
//    fclose(fileA);
//    fclose(fileB);
//    fclose(fileC);
//
//    printf("����� ������ �������� � ���� fC.txt\n");
//
//    return 0;
//}
