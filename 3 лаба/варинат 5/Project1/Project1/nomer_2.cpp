#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unordered_map>

// ������� ��� �������� ���������� ���� � ������
int countDigits(const std::string& word) {
    int count = 0;
    for (char c : word) {
        if (std::isdigit(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    std::ifstream inFile("FILE1.txt"); // �������� ����� FILE1 ��� ������
    std::ofstream outFile("FILE2.txt"); // �������� ����� FILE2 ��� ������

    if (!inFile || !outFile) {
        std::cerr << "Unable to open file\n";
        return 1;
    }

    std::string line;
    int lineNumber = 0;
    int maxDigitCount = 0;
    int maxDigitWordIndex = -1;
    int lineNumberWithMaxDigits = -1;

    while (std::getline(inFile, line)) { // ���������� ����� �� ����� FILE1
        lineNumber++;

        std::istringstream iss(line);
        std::vector<std::string> words(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

        std::unordered_map<std::string, int> wordCount;

        for (size_t i = 0; i < words.size(); ++i) {
            wordCount[words[i]]++;

            int digitCount = countDigits(words[i]);
            if (digitCount > maxDigitCount) {
                maxDigitCount = digitCount;
                maxDigitWordIndex = i;
                lineNumberWithMaxDigits = lineNumber;
            }
        }

        bool hasDuplicateWords = false;

        for (const auto& pair : wordCount) {
            if (pair.second >= 2) {
                hasDuplicateWords = true;
                break;
            }
        }

        if (hasDuplicateWords) { // ���� � ������ ���� �� ����� ���� ���������� ����
            outFile << line << "\n"; // ���������� ������ � ���� FILE2
        }
    }

    inFile.close(); // �������� ����� FILE1
    outFile.close(); // �������� ����� FILE2

    std::cout << "Index of word with the most digits: " << maxDigitWordIndex + 1 << std::endl;
    std::cout << "Line number with the word with the most digits: " << lineNumberWithMaxDigits << std::endl;

    return 0;
}
