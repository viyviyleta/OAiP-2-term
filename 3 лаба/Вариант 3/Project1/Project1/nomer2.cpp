#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <locale>
#include <Windows.h>

using namespace std;

// ������� ��� ��������� ������ �� �����
vector<string> splitString(const string& input) {
    vector<string> words;
    istringstream iss(input);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

// ������� ��� ��������, �������� �� ������ ������
bool isWord(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    // ��������� ��������� ��� ������� Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ���� ������ � ����������
    string inputString;
    cout << "������� ������ ��������, ��������� �� ���� � ����(���������� �����), ����������� ���������: ";
    getline(cin, inputString);

    // ������ ������ � ����
    ofstream outputFile("data.txt");
    if (!outputFile) {
        cerr << "������ �������� ����� ��� ������." << endl;
        return 1;
    }
    outputFile << inputString;
    outputFile.close();

    // ������ �� �����, ����� ���� � ������ ���� � ������ ����
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cerr << "������ �������� ����� ��� ������." << endl;
        return 1;
    }

    string line;
    ofstream outputFile2("words.txt");
    if (!outputFile2) {
        cerr << "������ �������� ����� ��� ������ ����." << endl;
        return 1;
    }

    while (getline(inputFile, line)) {
        // ��������� ������ �� �����
        vector<string> words = splitString(line);

        // ����� ���� �� ����� � ������ � ����
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
