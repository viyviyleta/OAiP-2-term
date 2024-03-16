#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype> // ��� ������� isdigit

int main() {
    setlocale(0, "");
    std::string inputString;

    // ���� ������ � ����������
    std::cout << "������� ������ �� ����� ���� � �����: ";
    std::getline(std::cin, inputString);

    // �������� ������� ������ ���� � �����
    bool containsOnlyDigits = true;
    for (char c : inputString) {
        if (!std::isdigit(c) && c != ' ') {
            containsOnlyDigits = false;
            break;
        }
    }

    if (!containsOnlyDigits) {
        std::cerr << "������" << std::endl;
        return 1;
    }

    // �������� ����� ��� ������
    std::ofstream outputFile("data.txt");
    if (!outputFile) {
        std::cerr << "������ �������� ����� ��� ������." << std::endl;
        return 1;
    }

    // ������ ������ � ����
    outputFile << inputString;
    outputFile.close();

    // �������� ����� ��� ������
    std::ifstream inputFile("data.txt");
    if (!inputFile) {
        std::cerr << "������ �������� ����� ��� ������." << std::endl;
        return 1;
    }

    // ������ ������ �� �����
    std::string fileData;
    std::getline(inputFile, fileData);
    inputFile.close();

    // ����� ����� �������� ������
    std::vector<std::string> groups;
    std::istringstream iss(fileData);
    std::string group;
    while (iss >> group) {
        groups.push_back(group);
    }

    // ������� ����� ����� �������� ������
    size_t shortestLength = groups[0].length();
    for (const std::string& group : groups) {
        if (group.length() < shortestLength) {
            shortestLength = group.length();
        }
    }

    // ����� ���� ����� �������� �����
    std::cout << "����� �������� ������: ";
    for (const std::string& group : groups) {
        if (group.length() == shortestLength) {
            std::cout << group << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
