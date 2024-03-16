//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//// Функция для подсчета количества гласных букв в строке
//int countVowels(const string& str) {
//    int count = 0;
//    for (char ch : str) {
//        if (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u') {
//            count++;
//        }
//    }
//    return count;
//}
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
//    int k;
//    cout << "Введите значение k: ";
//    cin >> k;
//
//    string line;
//    int lineNumber = 1;
//    while (getline(inputFile, line)) {
//        if (lineNumber >= k && lineNumber <= k + 3) {
//            outputFile << line << endl;
//        }
//        lineNumber++;
//    }
//
//    inputFile.close();
//    outputFile.close();
//
//    // Подсчет количества гласных букв в FILE2
//    ifstream file2("FILE2.txt");
//    if (!file2) {
//        cerr << "Ошибка открытия файла FILE2.txt." << endl;
//        return 1;
//    }
//
//    int vowelCount = 0;
//    while (getline(file2, line)) {
//        vowelCount += countVowels(line);
//    }
//
//    cout << "Количество гласных букв в FILE2.txt: " << vowelCount << endl;
//
//    file2.close();
//
//    return 0;
//}
