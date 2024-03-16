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
//    int size;  // Размер файлов
//
//    // Открытие файлов
//    if (fopen_s(&fileA, "NameA.txt", "r") != 0 ||
//        fopen_s(&fileB, "NameB.txt", "r") != 0 ||
//        fopen_s(&fileC, "NameC.txt", "r") != 0 ||
//        fopen_s(&fileD, "NameD.txt", "w") != 0) {
//        perror("Ошибка открытия файлов");
//        return 1;
//    }
//
//    // Проверка на успешное открытие файлов
//    if (fileA == NULL || fileB == NULL || fileC == NULL || fileD == NULL) {
//        perror("Ошибка открытия файлов");
//        return 1;
//    }
//
//    // Чтение и запись содержимого файлов
//    char buffer[100]; // Буфер для хранения строки из файла
//
//    // Чтение содержимого из файла A и запись в файл D
//    while (fgets(buffer, sizeof(buffer), fileA) != NULL) {
//        fputs(buffer, fileD);
//        fputc(' ', fileD); // Добавляем пробел после каждой строки
//    }
//
//    // Чтение содержимого из файла B и запись в файл D
//    rewind(fileB); // Возвращаем указатель в начало файла
//    while (fgets(buffer, sizeof(buffer), fileB) != NULL) {
//        fputs(buffer, fileD);
//        fputc(' ', fileD); // Добавляем пробел после каждой строки
//    }
//
//    // Чтение содержимого из файла C и запись в файл D
//    rewind(fileC); // Возвращаем указатель в начало файла
//    while (fgets(buffer, sizeof(buffer), fileC) != NULL) {
//        fputs(buffer, fileD);
//        fputc(' ', fileD); // Добавляем пробел после каждой строки
//    }
//
//    cout << "Содержимое файлов NameA.txt, NameB.txt и NameC.txt успешно скопировано в файл NameD.txt" << endl;
//
//    // Закрытие файлов
//    fclose(fileA);
//    fclose(fileB);
//    fclose(fileC);
//    fclose(fileD);
//
//    return 0;
//}
//
