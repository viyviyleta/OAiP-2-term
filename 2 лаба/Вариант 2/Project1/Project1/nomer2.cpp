#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    FILE* fileF, * fileG;
    int numbers[20];  // ������ ��� �������� ����� �� ����� f.txt

    // �������� ������
    if (fopen_s(&fileF, "f.txt", "r") != 0 || fopen_s(&fileG, "g.txt", "w") != 0) {
        cout << "������ �������� ������" << endl;
        return 1;
    }

    // ������ ����� �� ����� f.txt
    for (int i = 0; i < 20; i++) {
        fscanf_s(fileF, "%d", &numbers[i]);
    }

    // ������ ����� � ���� g.txt
    for (int i = 0; i < 2; ++i) { // ��������� ��� ����
        for (int j = 0; j < 5; ++j) {
            fprintf(fileG, "%d\n", numbers[j + i * 5]); // ���������� 5 ������������� �����
        }
        for (int j = 0; j < 5; ++j) {
            fprintf(fileG, "%d\n", numbers[j + 10 + i * 5]); // ���������� 5 ������������� �����
        }
    }

    cout << "���� g.txt ������" << endl;

    // �������� ������
    fclose(fileF);
    fclose(fileG);

    return 0;
}
