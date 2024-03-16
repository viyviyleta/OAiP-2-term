//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//int main() {
//    setlocale(0, "");
//    ifstream inputFile("FILE1.txt");
//    ofstream outputFile("FILE2.txt");
//
//    if (!inputFile || !outputFile) {
//        cerr << "Ошибка открытия файлов." << endl;
//        return 1;
//    }
//
//    string line;
//    int lineNumber = 1;
//    while (getline(inputFile, line)) {
//        if (lineNumber % 2 == 0) {
//            outputFile << line << endl;
//        }
//        lineNumber++;
//    }
//
//    inputFile.close();
//    outputFile.close();
//
//    // Подсчет размеров файлов
//    ifstream file1("FILE1.txt", ios::binary | ios::ate);
//    ifstream file2("FILE2.txt", ios::binary | ios::ate);
//
//    if (!file1 || !file2) {
//        cerr << "Ошибка открытия файлов для подсчета размеров." << endl;
//        return 1;
//    }
//
//    int fileSize1 = file1.tellg();
//    int fileSize2 = file2.tellg();
//
//    cout << "Размер FILE1.txt: " << fileSize1 << " байт." << endl;
//    cout << "Размер FILE2.txt: " << fileSize2 << " байт." << endl;
//
//    file1.close();
//    file2.close();
//
//    return 0;
//}
