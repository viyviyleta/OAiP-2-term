//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    FILE* fileA, * fileB, * fileC, * fileD;
//    int size;  // ������ ������
//
//    // �������� ������
//    if (fopen_s(&fileA, "NameA.txt", "r") != 0 ||
//        fopen_s(&fileB, "NameB.txt", "r") != 0 ||
//        fopen_s(&fileC, "NameC.txt", "r") != 0 ||
//        fopen_s(&fileD, "NameD.txt", "w") != 0) {
//        perror("������ �������� ������");
//        return 1;
//    }
//
//    // �������� �� �������� �������� ������
//    if (fileA == NULL || fileB == NULL || fileC == NULL || fileD == NULL) {
//        perror("������ �������� ������");
//        return 1;
//    }
//
//    // ������ � ������ ����������� ������
//    char buffer[100]; // ����� ��� �������� ������ �� �����
//
//    // ������ ����������� �� ����� A � ������ � ���� D
//    while (fgets(buffer, sizeof(buffer), fileA) != NULL) {
//        fputs(buffer, fileD);
//        fputc(' ', fileD); // ��������� ������ ����� ������ ������
//    }
//
//    // ������ ����������� �� ����� B � ������ � ���� D
//    rewind(fileB); // ���������� ��������� � ������ �����
//    while (fgets(buffer, sizeof(buffer), fileB) != NULL) {
//        fputs(buffer, fileD);
//        fputc(' ', fileD); // ��������� ������ ����� ������ ������
//    }
//
//    // ������ ����������� �� ����� C � ������ � ���� D
//    rewind(fileC); // ���������� ��������� � ������ �����
//    while (fgets(buffer, sizeof(buffer), fileC) != NULL) {
//        fputs(buffer, fileD);
//        fputc(' ', fileD); // ��������� ������ ����� ������ ������
//    }
//
//    cout << "���������� ������ NameA.txt, NameB.txt � NameC.txt ������� ����������� � ���� NameD.txt" << endl;
//
//    // �������� ������
//    fclose(fileA);
//    fclose(fileB);
//    fclose(fileC);
//    fclose(fileD);
//
//    return 0;
//}
//
