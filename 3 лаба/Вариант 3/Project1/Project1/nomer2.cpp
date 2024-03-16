#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <locale>
#include <Windows.h>

using namespace std;

// Функция для разбиения строки на слова
vector<string> splitString(const string& input) {
    vector<string> words;
    istringstream iss(input);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

// Функция для проверки, является ли строка словом
bool isWord(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    // Установка кодировки для консоли Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Ввод строки с клавиатуры
    string inputString;
    cout << "Введите строку символов, состоящую из цифр и слов(латинского языка), разделенных пробелами: ";
    getline(cin, inputString);

    // Запись строки в файл
    ofstream outputFile("data.txt");
    if (!outputFile) {
        cerr << "Ошибка открытия файла для записи." << endl;
        return 1;
    }
    outputFile << inputString;
    outputFile.close();

    // Чтение из файла, вывод слов и запись слов в другой файл
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cerr << "Ошибка открытия файла для чтения." << endl;
        return 1;
    }

    string line;
    ofstream outputFile2("words.txt");
    if (!outputFile2) {
        cerr << "Ошибка открытия файла для записи слов." << endl;
        return 1;
    }

    while (getline(inputFile, line)) {
        // Разбиение строки на слова
        vector<string> words = splitString(line);

        // Вывод слов на экран и запись в файл
        for (const string& word : words) {
            if (isWord(word)) {
                cout << word << " ";
                outputFile2 << word << " ";
            }
        }
    }
    cout << endl;

    inputFile.close();
    outputFile2.close();

    return 0;
}
