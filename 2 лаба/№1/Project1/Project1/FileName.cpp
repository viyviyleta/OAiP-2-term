#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fileF1, * fileF2;
    char line[256]; // Предполагаем, что строка не будет длиннее 255 символов
    int lineNumber = 0;

    // Создание и запись в файл F1.txt
    fopen_s(&fileF1, "F1.txt", "w");
    if (fileF1 == NULL) {
        perror("Ошибка открытия файла F1.txt");
        return 1;
    }

    // Запись не менее 6 строк в F1.txt
    fprintf(fileF1, "Первая строка\n");
    fprintf(fileF1, "Вторая строка\n");
    fprintf(fileF1, "Третья строка\n");
    fprintf(fileF1, "Четвертая строка\n");
    fprintf(fileF1, "Пятая строка\n");
    fprintf(fileF1, "Шестая строка\n");

    // Закрытие файла F1.txt
    fclose(fileF1);

    // Копирование четных строк в F2.txt
    fopen_s(&fileF1, "F1.txt", "r");
    fopen_s(&fileF2, "F2.txt", "w");
    if (fileF1 == NULL || fileF2 == NULL) {
        perror("Ошибка открытия файлов F1.txt или F2.txt");
        return 1;
    }

    // Чтение и копирование четных строк
    while (fgets(line, sizeof(line), fileF1) != NULL) {
        lineNumber++;
        if (lineNumber % 2 == 0) {
            fprintf(fileF2, "%s", line);
        }
    }

    // Закрытие файлов
    fclose(fileF1);
    fclose(fileF2);

    return 0;
}
