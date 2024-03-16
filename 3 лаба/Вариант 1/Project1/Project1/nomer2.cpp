#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    setlocale(0, "");
    // Ввод строки с клавиатуры
    string inputString;
    cout << "Введите строку символов, состоящую из цифр и слов, разделенных пробелами: ";
    getline(cin, inputString);

    // Запись строки в файл
    ofstream outputFile("data.txt");
    if (!outputFile) {
        cerr << "Ошибка открытия файла для записи." << endl;
        return 1;
    }
    outputFile << inputString;
    outputFile.close();

    // Чтение из файла и вывод нечетных чисел
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cerr << "Ошибка открытия файла для чтения." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            int num;
            if (stringstream(word) >> num) {
                if (num % 2 != 0) {
                    cout << num << " ";
                }
            }
        }
    }
    cout << endl;

    inputFile.close();#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

int main() {
    setlocale(0, "");
    // Ввод строки с клавиатуры
    std::string inputString;
    std::cout << "Введите строку символов, состоящую из цифр и слов, разделенных пробелами: ";
    std::getline(std::cin, inputString);

    // Запись строки в файл
    std::ofstream outputFile("data.txt");
    if (!outputFile) {
        std::cerr << "Ошибка открытия файла для записи." << std::endl;
        return 1;
    }
    outputFile << inputString;
    outputFile.close();

    // Чтение из файла и вывод нечетных чисел
    std::ifstream inputFile("data.txt");
    if (!inputFile) {
        std::cerr << "Ошибка открытия файла для чтения." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            bool isNumber = true;
            for (char c : word) {
                if (!std::isdigit(c) && c != '+' && c != '-') {
                    isNumber = false;
                    break;
                }
            }
            if (isNumber) {
                std::cout << word << " ";
            }
        }
    }
    std::cout << std::endl;

    inputFile.close();

    return 0;
}


    return 0;
}
