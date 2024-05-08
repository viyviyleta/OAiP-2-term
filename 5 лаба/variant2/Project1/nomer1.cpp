//#include <iostream>
//#include <vector>
//#include <string>
//#include <locale>
//#include <windows.h>
//#include <limits> 
//#include <sstream>
//
//using namespace std;
//
//// ������������ 
//enum Gender { Male, Female };
//
//struct Citizen {
//    string fullName;
//    struct {
//        unsigned int day : 5;
//        unsigned int month : 4;
//        unsigned int year : 12;
//    } birthDate; // ������e ����
//    string address;
//    Gender gender;
//};
//
//vector<Citizen> citizens;
//
//bool isLeapYear(int year) {
//    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
//}
//
//// ������� ��� �������� ������������ ��������� ����
//bool isValidDate(int day, int month, int year) {
//    // �������� ���� �� ������������
//    if (day < 1 || month < 1 || year < 1) {
//        return false; // ������������ �������� ���, ������ ��� ����
//    }
//    if (month > 12) {
//        return false; // ������������ ����� ������
//    }
//    if (day > 31) {
//        return false; // ������������ ����� ���
//    }
//    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
//        return false; // � ������, ����, �������� � ������ �������� 30 ����
//    }
//    if (month == 2) {
//        if (isLeapYear(year)) {
//            if (day > 29) {
//                return false; // � ���������� ��� � ������� �������� 29 ����
//            }
//        }
//        else {
//            if (day > 28) {
//                return false; // � ������� ��� � ������� �������� 28 ����
//            }
//        }
//    }
//    // �������� ���� �� ������� ��������
//    if (year > 2024 || (year == 2024 && (month > 3 || (month == 3 && day > 14)))) {
//        return false; // ��������� ���� ����� 14 ����� 2024 ����
//    }
//    // ��� �������� ��������, ���� ���������
//    return true;
//}
//
//// ������� ��� ���������� ����������
//void addCitizen() {
//    Citizen newCitizen;
//    cout << "������� �.�.�. ����������: ";
//    getline(cin >> ws, newCitizen.fullName);
//    int day, month, year;
//    // �������� ������������ ����� ����
//    while (true) {
//        cout << "������� ���� �������� ���������� (� ������� �� �� ����): ";
//        cin >> day >> month >> year;
//        if (isValidDate(day, month, year)) {
//            break; // ���� ���� ���������, ������� �� �����
//        }
//        else {
//            cout << "������������ ����. ���������� �����." << endl;
//            cin.clear();
//        }
//    }
//    // ���������� ���� �������� � ������� ����
//    newCitizen.birthDate.day = day;
//    newCitizen.birthDate.month = month;
//    newCitizen.birthDate.year = year;
//    cout << "������� ����� ����������: ";
//    getline(cin >> ws, newCitizen.address);
//    char genderInput;
//    // �������� ������������ ����� ����
//    while (true) {
//        cout << "������� ��� ���������� (0 - �������, 1 - �������): ";
//        cin >> genderInput;
//        if (genderInput == '0' || genderInput == '1') {
//            break;
//        }
//        else {
//            cout << "������������ ����. ������� 0 ��� 1." << endl;
//            cin.clear();
//        }
//    }
//    int gender = genderInput - '0'; // �������������� ������� � ����� �����
//    newCitizen.gender = static_cast<Gender>(gender);
//    citizens.push_back(newCitizen);
//}
//
//// ������� ��� �������� ���������� �� �������
//void deleteCitizen(size_t index) {
//    if (index < citizens.size()) {
//        citizens.erase(citizens.begin() + index);
//        cout << "��������� ������� ������." << endl;
//    }
//    else {
//        cout << "������������ ������." << endl;
//    }
//}
//
//// ������� ��� ������ ������� �� ���� ��������
//void searchByBirthYear(int year) {
//    bool found = false;
//    cout << "��������, ���������� � " << year << " ����:" << endl;
//    for (const auto& citizen : citizens) {
//        if (citizen.birthDate.year == year) { // �������� ���� ��������
//            cout << citizen.fullName << endl;
//            found = true;
//        }
//    }
//    if (!found) {
//        cout << "��������, ���������� � " << year << " ����, �� �������." << endl;
//    }
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    setlocale(LC_ALL, "Russian");
//
//    int choice;
//    while (true) {
//        cout << "\n����:" << endl;
//        cout << "1. �������� ����������" << endl;
//        cout << "2. ������� ������ �������" << endl;
//        cout << "3. ������� ����������" << endl;
//        cout << "4. ����� ������� �� ���� ��������" << endl;
//        cout << "5. �����" << endl;
//        cout << "�������� ��������: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            addCitizen();
//            break;
//        case 2:
//            // ����� ������ �������
//            cout << "������ �������:" << endl;
//            for (const auto& citizen : citizens) {
//                cout << "�.�.�.: " << citizen.fullName << endl;
//                cout << "���� ��������: " << citizen.birthDate.day << "." << citizen.birthDate.month << "." << citizen.birthDate.year << endl;
//                cout << "�����: " << citizen.address << endl;
//                cout << "���: " << (citizen.gender == Male ? "�������" : "�������") << endl;
//                cout << endl;
//            }
//            break;
//        case 3:
//            size_t index;
//            cout << "������� ������ ���������� ��� ��������: ";
//            cin >> index;
//            deleteCitizen(index - 1);
//            break;
//        case 4:
//            int year;
//            cout << "������� ��� �������� ��� ������: ";
//            cin >> year;
//            searchByBirthYear(year);
//            break;
//        case 5:
//            cout << "����� �� ���������." << endl;
//            return 0;
//        default:
//            cout << "������������ �����. ���������� ��� ���." << endl;
//        }
//    }
//
//    return 0;
//}

