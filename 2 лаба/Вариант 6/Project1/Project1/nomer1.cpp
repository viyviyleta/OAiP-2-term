//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    FILE* fileA;
//    double targetNumber;
//    int lineNumber = 0, closestLineNumber = 0;
//    double closestDistance = -1;  // ���������� ������������� �������� ��� �������������
//    double closestNumber;
//
//    // ��������� �������� �� ������������
//    std::cout << "Enter an integer: ";
//    std::cin >> targetNumber;
//
//    // �������� ����� � ��������� �������
//    fopen_s(&fileA, "fA.txt", "r");
//    if (fileA == NULL) {
//        perror("File opening error fA.txt");
//        return 1;
//    }
//
//    // ������ � ������ ������������ ����� �� �����
//    double currentNumber;
//    while (fscanf_s(fileA, "%lf", &currentNumber) != EOF) {
//        lineNumber++;
//
//        // ����������� �������� �������� ����� � ����������
//        double distance = abs(targetNumber - currentNumber);
//
//        // ���� ��� ��������� �����, ��������� ����������
//        if (closestDistance == -1 || distance < closestDistance) {
//            closestDistance = distance;
//            closestLineNumber = lineNumber;
//            closestNumber = currentNumber;
//        }
//    }
//
//    // ������� ��������� �� �����
//    std::cout << "The closest number to " << targetNumber << " is " << closestNumber
//        << " its position " << closestLineNumber << " in the file" << std::endl;
//
//    // �������� �����
//    fclose(fileA);
//
//    return 0;
//}
