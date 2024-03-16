#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype> // Для функции isdigit

int main() {
    setlocale(0, "");
    std::string inputString;

    // Ввод строки с клавиатуры
    std::cout << "Введите строку из групп цифр и нулей: ";
    std::getline(std::cin, inputString);

    // Проверка наличия только цифр и нулей
    bool containsOnlyDigits = true;
    for (char c : inputString) {
        if (!std::isdigit(c) && c != ' ') {
            containsOnlyDigits = false;
            break;
        }
    }

    if (!containsOnlyDigits) {
        std::cerr << "Ошибка" << std::endl;
        return 1;
    }

    // Открытие файла для записи
    std::ofstream outputFile("data.txt");
    if (!outputFile) {
        std::cerr << "Ошибка открытия файла для записи." << std::endl;
        return 1;
    }

    // Запись строки в файл
    outputFile << inputString;
    outputFile.close();

    // Открытие файла для чтения
    std::ifstream inputFile("data.txt");
    if (!inputFile) {
        std::cerr << "Ошибка открытия файла для чтения." << std::endl;
        return 1;
    }

    // Чтение данных из файла
    std::string fileData;
    std::getline(inputFile, fileData);
    inputFile.close();

    // Поиск самой короткой группы
    std::vector<std::string> groups;
    std::istringstream iss(fileData);
    std::string group;
    while (iss >> group) {
        groups.push_back(group);
    }

    // Находим длину самой короткой группы
    size_t shortestLength = groups[0].length();
    for (const std::string& group : groups) {
        if (group.length() < shortestLength) {
            shortestLength = group.length();
        }
    }

    // Вывод всех самых коротких групп
    std::cout << "Самые короткие группы: ";
    for (const std::string& group : groups) {
        if (group.length() == shortestLength) {
            std::cout << group << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
