//#include <stdio.h>
//#include <iostream>
//int main() {
//    setlocale(LC_ALL, "rus");
//    FILE* fileF, * fileG;
//    int threshold, number;
//
//    // ��������� �������� ������ � ����������
//    printf("������� ��������� ��������: ");
//    scanf_s("%d", &threshold);
//
//    // �������� ����� � ��������� �������
//    fopen_s(&fileF, "f.txt", "r");
//    if (fileF == NULL) {
//        perror("������ �������� ����� f.txt");
//        return 1;
//    }
//
//    // �������� ����� ��� ������ �����, ������� ������
//    fopen_s(&fileG, "g.txt", "w");
//    if (fileG == NULL) {
//        perror("������ �������� ����� g.txt");
//        fclose(fileF);
//        return 1;
//    }
//
//    // ������ � ������ �����, ������� ������
//    while (fscanf_s(fileF, "%d", &number) != EOF) {
//        if (number > threshold) {
//            fprintf(fileG, "%d\n", number);
//        }
//    }
//
//    std::cout << "����" << " fileG ������� ������" << std::endl;
//
//    // �������� ������
//    fclose(fileF);
//    fclose(fileG);
//
//    return 0;
//}
