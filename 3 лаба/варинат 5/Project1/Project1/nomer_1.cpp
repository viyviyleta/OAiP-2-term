//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//
//int main() {
//    setlocale(0, "");
//    std::ifstream inputFile("FILE1.txt");
//    std::ofstream outputFile("FILE2.txt");
//
//    if (!inputFile.is_open() || !outputFile.is_open()) {
//        std::cerr << "Unable to open file!" << std::endl;
//        return 1;
//    }
//
//    // ���������� ������ ��� ������ �� FILE1.txt
//    std::string line;
//    for (int i = 0; i < 3; ++i) {
//        if (!std::getline(inputFile, line)) {
//            std::cerr << "Not enough lines in FILE1.txt!" << std::endl;
//            return 1;
//        }
//    }
//
//    // ����������� ���������� ������ � FILE2.txt
//    while (std::getline(inputFile, line)) {
//        outputFile << line << std::endl;
//    }
//
//    inputFile.close();
//    outputFile.close();
//
//    // ������� FILE2.txt ��� �������� �������� � ��������� �����
//    std::ifstream inputFile2("FILE2.txt");
//    if (!inputFile2.is_open()) {
//        std::cerr << "Unable to open FILE2.txt!" << std::endl;
//        return 1;
//    }
//
//    std::string lastWord;
//    while (inputFile2 >> lastWord) {
//        // ���������� ���������� � ����� ���������� �����
//        while (!lastWord.empty() && !std::isalnum(lastWord.back())) {
//            lastWord.pop_back();
//        }
//    }
//
//    inputFile2.close();
//
//    // ������� ���������� �������� � ��������� �����
//    std::cout << "���������� �������� � ��������� ����� FILE2.txt: " << lastWord.size() << std::endl;
//
//    return 0;
//}
