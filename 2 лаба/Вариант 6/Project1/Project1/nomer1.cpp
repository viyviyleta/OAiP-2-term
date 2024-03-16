//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    FILE* fileA;
//    double targetNumber;
//    int lineNumber = 0, closestLineNumber = 0;
//    double closestDistance = -1;  // Используем отрицательное значение для инициализации
//    double closestNumber;
//
//    // Получение значения от пользователя
//    std::cout << "Enter an integer: ";
//    std::cin >> targetNumber;
//
//    // Открытие файла с исходными данными
//    fopen_s(&fileA, "fA.txt", "r");
//    if (fileA == NULL) {
//        perror("File opening error fA.txt");
//        return 1;
//    }
//
//    // Чтение и анализ вещественных чисел из файла
//    double currentNumber;
//    while (fscanf_s(fileA, "%lf", &currentNumber) != EOF) {
//        lineNumber++;
//
//        // Определение близости текущего числа к введенному
//        double distance = abs(targetNumber - currentNumber);
//
//        // Если это ближайшее число, обновляем переменные
//        if (closestDistance == -1 || distance < closestDistance) {
//            closestDistance = distance;
//            closestLineNumber = lineNumber;
//            closestNumber = currentNumber;
//        }
//    }
//
//    // Выводим результат на экран
//    std::cout << "The closest number to " << targetNumber << " is " << closestNumber
//        << " its position " << closestLineNumber << " in the file" << std::endl;
//
//    // Закрытие файла
//    fclose(fileA);
//
//    return 0;
//}
