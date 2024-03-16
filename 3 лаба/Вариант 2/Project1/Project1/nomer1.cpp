//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cctype>
//#include <sstream>
//
//int main() {
//    setlocale(LC_ALL, "Russian"); 
//
//    std::ifstream inputFile("FILE1.txt"); 
//    std::ofstream outputFile("FILE2.txt"); 
//
//    if (!inputFile || !outputFile) {
//        std::cerr << "������ �������� ������." << std::endl;
//        return 1;
//    }
//
//    std::string line;
//    int wordCount = 0;
//    int totalWords = 0; // ����� ���������� ���� �� ������ �����
//
//    while (std::getline(inputFile, line)) { // ������ ����� �� FILE1
//        if (!line.empty() && std::isupper(line[0]) && line[0] == 'A') {
//            outputFile << line << std::endl; // ������ ������ � FILE2
//            // ������� ���������� ���� � ������
//            ++wordCount;
//            std::istringstream iss(line);
//            std::string word;
//            while (iss >> word) {
//                ++totalWords; // ����������� ����� ���������� ����
//            }
//        }
//    }
//
//    std::cout << "���������� �����, ������������ � ������� ����� A � FILE2: " << wordCount << std::endl;
//    std::cout << "����� ���������� ���� � FILE2: " << totalWords << std::endl;
//
//   
//    inputFile.close();
//    outputFile.close();
//
//    return 0;
//}
