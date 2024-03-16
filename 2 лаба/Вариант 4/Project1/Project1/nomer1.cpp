#include <iostream>
#include <stdio.h>

int main() {
    setlocale(LC_ALL, "rus");
    FILE* fileA, * fileB;
    int number;

    // �������� ����� � ��������� �������
    if (fopen_s(&fileA, "fileA.txt", "r") != 0) {
        perror("������ �������� ����� fileA.txt");
        return 1;
    }

    // �������� ����� ��� ������ ������������� �����
    if (fopen_s(&fileB, "fileB.txt", "w") != 0) {
        perror("������ �������� ����� fileB.txt");
        fclose(fileA);
        return 1;
    }

    // ������ � ������ ������������� �����
    while (fscanf_s(fileA, "%lf", &number) != EOF) {
        if (number > 0) {
            fprintf(fileB, "%.2lf\n", number); // %.2lf ��� ������ ����� � ��������� ������ � ����� ������� ����� �������
        }
    }

    std::cout << "���� fileB ������� ������" << std::endl;

    // �������� ������
    fclose(fileA);
    fclose(fileB);

    return 0;
}
