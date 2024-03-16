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
//        cerr << "������ �������� ������." << endl;
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
//    // ������� �������� ������
//    ifstream file1("FILE1.txt", ios::binary | ios::ate);
//    ifstream file2("FILE2.txt", ios::binary | ios::ate);
//
//    if (!file1 || !file2) {
//        cerr << "������ �������� ������ ��� �������� ��������." << endl;
//        return 1;
//    }
//
//    int fileSize1 = file1.tellg();
//    int fileSize2 = file2.tellg();
//
//    cout << "������ FILE1.txt: " << fileSize1 << " ����." << endl;
//    cout << "������ FILE2.txt: " << fileSize2 << " ����." << endl;
//
//    file1.close();
//    file2.close();
//
//    return 0;
//}
