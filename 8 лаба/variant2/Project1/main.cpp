#include <iostream>
#include <limits>
#include "MyQueue.h"
#include <string>

int main() {
    setlocale(LC_ALL, "ru");
    Queue* begin = nullptr, * end = nullptr;
    bool queueCreated = false; // Переменная для отслеживания создания очереди
    std::string choose;

    do {
        std::cout << "Выберите действие:\n"
            << "1. Ввод очереди\n"
            << "2. Вывод очереди\n"
            << "3. Очистка очереди\n"
            << "4. Удалить элемент из очереди\n"
            << "5. Найти количество элементов между максимальным и минимальным\n"
            << "6. Выйти\n\n";
        std::cin >> choose;

        if (choose == "1") {
            if (queueCreated) {
                char confirm;
                std::cout << "Очередь уже создана. Хотите очистить текущую очередь и создать новую? (y/n): ";
                std::cin >> confirm;

                // Проверка на корректность ответа пользователя
                while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
                    std::cout << "Ошибка: введите корректный ответ (y/n): ";
                    std::cin >> confirm;
                }

                if (confirm == 'y' || confirm == 'Y') {
                    clear(&begin);
                }
                else {
                    continue;
                }
            }

            std::string sizeStr;
            std::cout << "Введите размер очереди: ";
            std::cin >> sizeStr;

            // Проверка на ввод числа
            if (sizeStr.find_first_not_of("0123456789") != std::string::npos) {
                std::cout << "Ошибка: введено не число. Очередь будет очищена.\n";
                clear(&begin);
                queueCreated = false;
                continue;
            }

            int size = std::stoi(sizeStr);

            for (int i = 0; i < size; ++i) {
                std::string valueStr;
                std::cout << "Введите число: ";
                std::cin >> valueStr;

                // Проверка на ввод числа или символа минуса для отрицательных чисел
                if (valueStr.find_first_not_of("0123456789-") != std::string::npos) {
                    std::cout << "Ошибка: введено не число. Очередь будет очищена.\n";
                    clear(&begin);
                    queueCreated = false;
                    break; // Прерываем цикл
                }

                create(&begin, &end, valueStr);
            }

            queueCreated = true; // Очередь создана
        }
        else if (choose == "2") {
            view(begin);
        }
        else if (choose == "3") {
            clear(&begin);
            std::cout << "Очередь очищена.\n";
            queueCreated = false; // Очередь удалена
        }
        else if (choose == "4") {
            if (!queueCreated) {
                std::cout << "Очередь не создана.\n";
                continue;
            }

            std::string valueStr;
            std::cout << "Введите число для удаления: ";
            std::cin >> valueStr;

            // Проверка на ввод числа или символа минуса для отрицательных чисел
            if (valueStr.find_first_not_of("0123456789-") != std::string::npos) {
                std::cout << "Ошибка: введено не число.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            int value = std::stoi(valueStr);
            removeElement(&begin, value);
        }

        else if (choose == "5") {
            if (!queueCreated) {
                std::cout << "Очередь не создана.\n";
                continue;
            }

            int diff = findMinMaxDiff(begin);
            int count = countElementsBetweenMinMax(begin);
            std::cout << "Количество элементов между максимальным и минимальным: " << count << std::endl;
        }
        else if (choose == "6") {
            std::cout << "Выход из программы.\n";
        }
        else {
            std::cout << "Некорректный ввод. Пожалуйста, выберите существующий пункт меню.\n";
        }
    } while (choose != "6");

    return 0;
}
