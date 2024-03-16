#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    setlocale(0, "");
    // ���� ������ � ����������
    string inputString;
    cout << "������� ������ ��������, ��������� �� ���� � ����, ����������� ���������: ";
    getline(cin, inputString);

    // ������ ������ � ����
    ofstream outputFile("data.txt");
    if (!outputFile) {
        cerr << "������ �������� ����� ��� ������." << endl;
        return 1;
    }
    outputFile << inputString;
    outputFile.close();

    // ������ �� ����� � ����� �������� �����
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cerr << "������ �������� ����� ��� ������." << endl;
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
    // ���� ������ � ����������
    std::string inputString;
    std::cout << "������� ������ ��������, ��������� �� ���� � ����, ����������� ���������: ";
    std::getline(std::cin, inputString);

    // ������ ������ � ����
    std::ofstream outputFile("data.txt");
    if (!outputFile) {
        std::cerr << "������ �������� ����� ��� ������." << std::endl;
        return 1;
    }
    outputFile << inputString;
    outputFile.close();

    // ������ �� ����� � ����� �������� �����
    std::ifstream inputFile("data.txt");
    if (!inputFile) {
        std::cerr << "������ �������� ����� ��� ������." << std::endl;
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
