//#include <stdio.h>
//#include <iostream>
//int main() {
//    setlocale(LC_ALL, "rus");
//    FILE* fileF, * fileG;
//    int threshold, number;
//
//    // Получение значения порога с клавиатуры
//    printf("Введите пороговое значение: ");
//    scanf_s("%d", &threshold);
//
//    // Открытие файла с исходными данными
//    fopen_s(&fileF, "f.txt", "r");
//    if (fileF == NULL) {
//        perror("Ошибка открытия файла f.txt");
//        return 1;
//    }
//
//    // Открытие файла для записи чисел, больших порога
//    fopen_s(&fileG, "g.txt", "w");
//    if (fileG == NULL) {
//        perror("Ошибка открытия файла g.txt");
//        fclose(fileF);
//        return 1;
//    }
//
//    // Чтение и запись чисел, больших порога
//    while (fscanf_s(fileF, "%d", &number) != EOF) {
//        if (number > threshold) {
//            fprintf(fileG, "%d\n", number);
//        }
//    }
//
//    std::cout << "Файл" << " fileG успешно создан" << std::endl;
//
//    // Закрытие файлов
//    fclose(fileF);
//    fclose(fileG);
//
//    return 0;
//}
