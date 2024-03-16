#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <Windows.h>
#include <limits>
#include <sstream>
using namespace std;

// ������������ ��� ����� ����������
enum class AccommodationType {
    LUXURY,
    SINGLE,
    DOUBLE,
    TRIPLE,
    APARTMENT
};

// ��������� ��� �������� ���������� � �������� ���������
struct HotelClient {
    string passportNumber;
    string arrivalDate;
    string departureDate;
    int roomNumber;
    AccommodationType accommodationType; // ��������� ���� ������
    string lastName;
};

// ������� ��� �������� ��������� ���� �� ������������ � ������������ ����
bool isValidDate(const string& date) {
    // ��������� ����� ������ ����
    if (date.length() != 10) {
        return false;
    }

    // ���������, ��� ������� �� ������ 4 � 7 �������� ��������� '-'
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }

    // ��������� ���, ����� � ���� �� ������ ����
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    // ��������� ������������ ���������� ����, ������ � ���
    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    // ��������� ���������� ���� � ������
    bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int maxDays = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDays = 30;
    }
    else if (month == 2) {
        maxDays = leapYear ? 29 : 28;
    }

    if (day > maxDays) {
        return false;
    }

    return true;
}

// ������� ��� ����� ������ ������� � ��������� �� ������������ �����
int inputRoomNumber() {
    string input;
    int roomNumber;
    while (true) {
        cout << "������� ����� �������: ";
        cin >> input;
        // �������� �� ����������� �������������� ������ � �����
        stringstream ss(input);
        if (ss >> roomNumber && roomNumber > 0) {
            // �������� �� ������������ ���������� ������ ������� (���������� �������� ��������)
            break;
        }
        else {
            cout << "������������ ����. ����� ������� ������ ���� ������������� ������." << endl;
        }
    }
    return roomNumber;
}

// ������� ��� ����� ���� ���������� � ��������� �� ������������ �����
AccommodationType inputAccommodationType() {
    string input;
    int typeChoice;
    while (true) {
        cout << "������� ��� ���������� (1-����, 2-�����������, 3-�����������, 4-�����������, 5-�����������): ";
        cin >> input;
        // �������� �� ����������� �������������� ������ � �����
        stringstream ss(input);
        if (ss >> typeChoice && typeChoice >= 1 && typeChoice <= 5) {
            break;
        }
        else {
            cout << "������������ ����. ����������, �������� ����� �� 1 �� 5." << endl;
        }
    }
    switch (typeChoice) {
    case 1:
        return AccommodationType::LUXURY;
    case 2:
        return AccommodationType::SINGLE;
    case 3:
        return AccommodationType::DOUBLE;
    case 4:
        return AccommodationType::TRIPLE;
    case 5:
        return AccommodationType::APARTMENT;
    }
}
// ������� ��� ����� ���������� � �������� � ����������
HotelClient inputClient() {
    HotelClient client;

    // ���� ���������� ������
    cout << "������� ���������� ������ (2 ������� ��������� ����� � 7 ����): ";
    cin >> client.passportNumber;

    // �������� �� ������������ ����� ���������� ������
    if (client.passportNumber.length() != 9 ||
        !isupper(client.passportNumber[0]) ||
        !isupper(client.passportNumber[1])) {
        cout << "������������ ����. ���������� ������ ������ �������� �� 2 ������� ��������� ���� � 7 ����." << endl;
        return inputClient(); // ��������� ����� ������� ��� ����� ���������� ������
    }

    // �������� ���������� �������� �� �����
    bool isValidDigits = true;
    for (int i = 2; i < 9; ++i) {
        if (!isdigit(client.passportNumber[i])) {
            isValidDigits = false;
            break;
        }
    }
    if (!isValidDigits) {
        cout << "������������ ����. ���������� ������ ������ �������� �� 2 ������� ��������� ���� � 7 ����." << endl;
        return inputClient(); // ��������� ����� ������� ��� ����� ���������� ������
    }

    // ���� ��� ������� � �������
    cout << "������� ���� ������� (����-��-��): ";
    cin >> client.arrivalDate;
    if (!isValidDate(client.arrivalDate)) {
        cout << "������������ ����. ��������� ������ ���� � �� ������������." << endl;
        return inputClient(); // ��������� ����� ������� ��� ����� ������
    }

    cout << "������� ���� ������� (����-��-��): ";
    cin >> client.departureDate;
    if (!isValidDate(client.departureDate)) {
        cout << "������������ ����. ��������� ������ ���� � �� ������������." << endl;
        return inputClient(); // ��������� ����� ������� ��� ����� ������
    }

    // �������� �� ������������ ����� ���
    // ���������, ��� ���� ������� ����� ���� �������
    if (client.departureDate <= client.arrivalDate) {
        cout << "������������ ����. ���� ������� ������ ���� ����� ���� �������." << endl;
        return inputClient(); // ��������� ����� ������� ��� ����� ������
    }

    // ���� ������ �������
    client.roomNumber = inputRoomNumber();

    // ���� ���� ����������
    client.accommodationType = inputAccommodationType();

    // ���� ������� ����������
    cout << "������� ������� ����������: ";
    cin >> client.lastName;

    return client;
}

// ������� ��� ������ ���������� � ������� � �������
void outputClient(const HotelClient& client) {
    string accommodation;
    switch (client.accommodationType) {
    case AccommodationType::LUXURY:
        accommodation = "����";
        break;
    case AccommodationType::SINGLE:
        accommodation = "�����������";
        break;
    case AccommodationType::DOUBLE:
        accommodation = "�����������";
        break;
    case AccommodationType::TRIPLE:
        accommodation = "�����������";
        break;
    case AccommodationType::APARTMENT:
        accommodation = "�����������";
        break;
    default:
        accommodation = "����������� ���";
    }

    cout << left << setw(20) << client.passportNumber
        << setw(15) << client.arrivalDate
        << setw(15) << client.departureDate
        << setw(15) << client.roomNumber
        << setw(20) << accommodation
        << setw(15) << client.lastName << endl;
}

// ������� ��� ������ ������� �� �������
void findClient(const vector<HotelClient>& clients, const string& lastName) {
    bool found = false;

    cout << left << setw(20) << "���������� ������"
        << setw(15) << "���� �������"
        << setw(15) << "���� �������"
        << setw(15) << "����� �������"
        << setw(20) << "��� ����������"
        << setw(15) << "�������" << endl;

    cout << "���������� ������ ��� ������� \"" << lastName << "\":" << endl;

    // �������� �� ���� �������� � ���� ���������� �� �������
    for (const auto& client : clients) {
        if (client.lastName == lastName) {
            outputClient(client);
            found = true;
        }
    }

    // ���� �� ������� ����������, ������� ��������� �� ����
    if (!found) {
        cout << "������ � �������� \"" << lastName << "\" �� ������." << endl;
    }
}

// ������� ��� �������� ������� �� ���������� ������
void deleteClient(vector<HotelClient>& clients, const string& passportNumber) {
    auto it = remove_if(clients.begin(), clients.end(), [&](const HotelClient& client) {
        return client.passportNumber == passportNumber;
        });

    if (it != clients.end()) {
        clients.erase(it, clients.end());
        cout << "������ � ����������� ������� \"" << passportNumber << "\" ������." << endl;
    }
    else {
        cout << "������ � ����������� ������� \"" << passportNumber << "\" �� ������." << endl;
    }
}

// ������� ��� ������ ������ � ����
void writeToFile(const vector<HotelClient>& clients, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& client : clients) {
            string accommodation;
            switch (client.accommodationType) {
            case AccommodationType::LUXURY:
                accommodation = "1";
                break;
            case AccommodationType::SINGLE:
                accommodation = "2";
                break;
            case AccommodationType::DOUBLE:
                accommodation = "3";
                break;
            case AccommodationType::TRIPLE:
                accommodation = "4";
                break;
            case AccommodationType::APARTMENT:
                accommodation = "5";
                break;
            default:
                accommodation = "0";
            }

            file << client.passportNumber << " "
                << client.arrivalDate << " "
                << client.departureDate << " "
                << client.roomNumber << " "
                << accommodation << " "
                << client.lastName << endl;
        }
        cout << "������ ������� �������� � ���� \"" << filename << "\"." << endl;
        file.close();
    }
    else {
        cout << "������ �������� ����� ��� ������." << endl;
    }
}

// ������� ��� ������ ������ �� �����
vector<HotelClient> readFromFile(const string& filename) {
    vector<HotelClient> clients;
    ifstream file(filename);
    if (file.is_open()) {
        HotelClient client;
        while (file >> client.passportNumber >> client.arrivalDate >> client.departureDate
            >> client.roomNumber) {
            int typeChoice;
            file >> typeChoice;
            switch (typeChoice) {
            case 1:
                client.accommodationType = AccommodationType::LUXURY;
                break;
            case 2:
                client.accommodationType = AccommodationType::SINGLE;
                break;
            case 3:
                client.accommodationType = AccommodationType::DOUBLE;
                break;
            case 4:
                client.accommodationType = AccommodationType::TRIPLE;
                break;
            case 5:
                client.accommodationType = AccommodationType::APARTMENT;
                break;
            default:
                client.accommodationType = AccommodationType::LUXURY;
            }
            file >> client.lastName;
            clients.push_back(client);
        }
        cout << "������ ������� ������� �� ����� \"" << filename << "\"." << endl;
        file.close();
    }
    else {
        cout << "������ �������� ����� ��� ������." << endl;
    }
    return clients;
}
// ������� ��� ��������� ���������� ������������� ������ ����
void processMenuChoice(vector<HotelClient>& clients, int choice) {
    switch (choice) {
    case 1: {
        clients.push_back(inputClient());
        break;
    }
    case 2: {
        cout << left << setw(20) << "���������� ������"
            << setw(15) << "���� �������"
            << setw(15) << "���� �������"
            << setw(15) << "����� �������"
            << setw(20) << "��� ����������"
            << setw(15) << "�������" << endl;
        for (const auto& client : clients) {
            outputClient(client);
        }
        break;
    }
    case 3: {
        string lastName;
        cout << "������� ������� ����������: ";
        cin >> lastName;
        findClient(clients, lastName);
        break;
    }
    case 4: {
        string passportNumber;
        cout << "������� ���������� ������ ������� ��� ��������: ";
        cin >> passportNumber;
        deleteClient(clients, passportNumber);
        break;
    }
    case 5: {
        string filename;
        cout << "������� ��� ����� ��� ������: ";
        cin >> filename;
        writeToFile(clients, filename);
        break;
    }
    case 6: {
        string filename;
        cout << "������� ��� ����� ��� ������: ";
        cin >> filename;
        clients = readFromFile(filename);
        break;
    }
    case 0: {
        cout << "����� �� ���������." << endl;
        break;
    }
    default: {
        cout << "������������ ����. ��������� �������." << endl;
        // ��������� ���� �������� ������ ����
        int newChoice;
        cout << "�������� ��������: ";
        cin >> newChoice;
        processMenuChoice(clients, newChoice);
        // ����� �� �������, ����� �������� ���������� ������ ����
        return;
    }
    }
}

int main() {
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<HotelClient> clients;

    int choice;
    do {
        cout << "\n����:" << endl;
        cout << "1. ���� ������ � �������" << endl;
        cout << "2. ����� ���� ��������" << endl;
        cout << "3. ����� ������� �� �������" << endl;
        cout << "4. �������� ������� �� ���������� ������" << endl;
        cout << "5. ������ ������ � ����" << endl;
        cout << "6. ������ ������ �� �����" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;

        // ��������� ���������� ������ ����
        processMenuChoice(clients, choice);

    } while (choice != 0);

    return 0;
}