#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fileF1, * fileF2;
    char line[256]; // ������������, ��� ������ �� ����� ������� 255 ��������
    int lineNumber = 0;

    // �������� � ������ � ���� F1.txt
    fopen_s(&fileF1, "F1.txt", "w");
    if (fileF1 == NULL) {
        perror("������ �������� ����� F1.txt");
        return 1;
    }

    fprintf(fileF1, "������ ������\n");
    fprintf(fileF1, "������ ������\n");
    fprintf(fileF1, "������ ������\n");
    fprintf(fileF1, "��������� ������\n");
    fprintf(fileF1, "����� ������\n");
    fprintf(fileF1, "������ ������\n");

    // �������� ����� F1.txt
    fclose(fileF1);

    // ����������� ������ ����� � F2.txt
    fopen_s(&fileF1, "F1.txt", "r");
    fopen_s(&fileF2, "F2.txt", "w");
    if (fileF1 == NULL || fileF2 == NULL) {
        perror("������ �������� ������ F1.txt ��� F2.txt");
        return 1;
    }

    // ������ � ����������� ������ �����
    while (fgets(line, sizeof(line), fileF1) != NULL) {
        lineNumber++;
        if (lineNumber % 2 == 0) {
            fprintf(fileF2, "%s", line);
        }
    }

    // �������� ������
    fclose(fileF1);
    fclose(fileF2);

    return 0;
}
