#include <iostream>
#include "stack.h"

int main() {
    setlocale(0, "");
    Stack stack;
    int choice;
    std::string filename = "stack_data.txt";

    do {
        std::cout << "\nМеню:" << std::endl;
        std::cout << "1. Добавить элемент в стек" << std::endl;
        std::cout << "2. Извлечь элемент из стека" << std::endl;
        std::cout << "3. Просмотреть верхний элемент стека" << std::endl;
        std::cout << "4. Удалить первый отрицательный элемент из стека" << std::endl;
        std::cout << "5. Очистить стек" << std::endl;
        std::cout << "6. Сохранить стек в файл" << std::endl;
        std::cout << "7. Загрузить стек из файла" << std::endl;
        std::cout << "8. Выход" << std::endl;
        std::cout << "Выберите действие: ";

        // Проверка на ввод буквы
        if (!(std::cin >> choice)) {
            std::cerr << "Ошибка: Введено некорректное значение." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            int value;
            std::cout << "Введите значение элемента: ";

            // Проверка на ввод буквы
            if (!(std::cin >> value)) {
                std::cerr << "Ошибка: Введено некорректное значение." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            stack.push(value);
            break;
        case 2:
            std::cout << "Извлеченный элемент: " << stack.pop() << std::endl;
            break;
        case 3:
            std::cout << "Верхний элемент: " << stack.peek() << std::endl;
            break;
        case 4:
            stack.removeFirstNegative();
            break;
        case 5:
            stack.clear();
            std::cout << "Стек очищен." << std::endl;
            break;
        case 6:
            stack.saveToFile(filename);
            break;
        case 7:
            stack.readFromFile(filename);
            break;
        case 8:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Некорректный ввод. Попробуйте еще раз." << std::endl;
        }
    } while (choice != 8);

    return 0;
}
