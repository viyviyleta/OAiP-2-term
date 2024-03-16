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
//        std::cerr << "Ошибка открытия файлов." << std::endl;
//        return 1;
//    }
//
//    std::string line;
//    int wordCount = 0;
//    int totalWords = 0; // Общее количество слов во втором файле
//
//    while (std::getline(inputFile, line)) { // Чтение строк из FILE1
//        if (!line.empty() && std::isupper(line[0]) && line[0] == 'A') {
//            outputFile << line << std::endl; // Запись строки в FILE2
//            // Подсчет количества слов в строке
//            ++wordCount;
//            std::istringstream iss(line);
//            std::string word;
//            while (iss >> word) {
//                ++totalWords; // Увеличиваем общее количество слов
//            }
//        }
//    }
//
//    std::cout << "Количество строк, начинающихся с большой буквы A в FILE2: " << wordCount << std::endl;
//    std::cout << "Общее количество слов в FILE2: " << totalWords << std::endl;
//
//   
//    inputFile.close();
//    outputFile.close();
//
//    return 0;
//}
