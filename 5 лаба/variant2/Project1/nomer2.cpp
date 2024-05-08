#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <windows.h>

using namespace std;

// ����������� ��������� Time
struct Time {
    int hours;
    int minutes;
};

// ����������� ��� �������� �������
union TimeUnion {
    Time separated;
    int combined;
};

bool isValidDaySequence(const string& input) {
    if (input.empty()) {
        return false;
    }

    stringstream ss(input);
    int day;
    vector<int> days;
    while (ss >> day) {
        if (day < 1 || day > 7) {
            return false;
        }
        days.push_back(day);
    }

    // ���� ������ ������� ��������� 7 � ������������������
    auto it = find(days.begin(), days.end(), 7);
    if (it != days.end()) {
        // ����� 7, ���������, ��� ����� ���� ���� 1 � ��� ��������� ��� � �������
        auto nextDay = it + 1;
        if (nextDay == days.end()) {
            return true; // � ������������������ ������ 7 ��� ����������� ����
        }
        if (*nextDay != 1) {
            return false; // ����� 7 �� ���� 1
        }
        // ���������, ��� ��� ��������� ��� � ������� �����������
        for (auto currentDay = nextDay + 1; currentDay != days.end(); ++currentDay) {
            if (*currentDay != *(currentDay - 1) + 1) {
                return false; // ������� ������� �����������
            }
        }
        // ���������, ��� ��� �������������� ��� ���� � ������� �����������
        for (auto prevDay = days.begin(); prevDay != it; ++prevDay) {
            if (*prevDay != *(prevDay + 1) - 1) {
                return false; // ������� ������� �����������
            }
        }
    }
    else {
        // ���������, ��� ��� ��� � ������� �����������
        for (size_t i = 1; i < days.size(); ++i) {
            if (days[i] != days[i - 1] + 1) {
                return false;
            }
        }
    }

    return true;
}
string inputdaysfromkeyboard() {
    string inputDays;
    while (true) {
        cout << "������� ��� ���������� ����� ������ (��������, 1 2 3): ";
        getline(cin, inputDays);
        // �������� �� ��, ��� ���� �� ������ � �������� ������ ����� � �������
        if (inputDays.empty() || inputDays.find_first_not_of("1234567890 ") != string::npos) {
            cout << "������: ��� ���������� ������ �������� ������ �� ����." << endl;
            continue;
        }
        // �������� �� ���������� ������� ����
        if (!isValidDaySequence(inputDays)) {
            cout << "������: ��� ���������� ������ ���� ������� � ������� ����������� ����� ������." << endl;
            continue;
        }
        return inputDays;
    }
}
// ������� ��� �������� ������������ ������� ������� (��:��)
bool isvalidtimeformat(const string& time) {
    if (time.length() != 5) {
        return false;
    }
    if (time[2] != ':') {
        return false;
    }
    for (int i = 0; i < 5; ++i) {
        if (i == 2) {
            continue;
        }
        if (!isdigit(time[i])) {
            return false;
        }
    }
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
        return false;
    }
    return true;
}

// ��������� ��� �������� ���������� � ������
struct train {
    int trainnumber;
    string destination;
    string daysofoperation;
    TimeUnion arrivaltime; // ���������� ����������� ��� �������� �������
    TimeUnion departuretime; // ���������� ����������� ��� �������� �������
};

// �������������� ������� � ������
string timetostring(const TimeUnion& time) {
    stringstream ss;
    ss << setw(2) << setfill('0') << time.separated.hours << ":" << setw(2) << setfill('0') << time.separated.minutes;
    return ss.str();
}

// ������� ��� ����� ���������� � ������ � ����������
train inputtrainfromkeyboard() {
    train newtrain;
    string temptrainnumber;
    while (true) {
        cout << "������� ����� ������: ";
        getline(cin, temptrainnumber);
        if (!temptrainnumber.empty()) {
            stringstream ss(temptrainnumber);
            if (ss >> newtrain.trainnumber && ss.eof()) {
                break;
            }
            else {
                cout << "������: ������� ������������ ��������. ����� ������ ������ ���� ������." << endl;
                continue;
            }
        }
        else cout << "������� ����� ������: ";
    }

    cout << "������� ����� ����������: ";
    getline(cin, newtrain.destination);
    while (newtrain.destination.empty()) {
        cout << "����� ���������� �� ����� ���� ������. ����������, ������� ����� ����������: ";
        getline(cin, newtrain.destination);
    }

    newtrain.daysofoperation = inputdaysfromkeyboard();

    cout << "������� ����� �������� (� ������� ��:��): ";
    string arrivalTimeStr;
    getline(cin, arrivalTimeStr);
    while (!isvalidtimeformat(arrivalTimeStr)) {
        cout << "������������ ������ �������. ����������, ������� ����� �������� � ������� ��:��: ";
        getline(cin, arrivalTimeStr);
    }
    sscanf_s(arrivalTimeStr.c_str(), "%d:%d", &newtrain.arrivaltime.separated.hours, &newtrain.arrivaltime.separated.minutes);

    cout << "������� ����� ����������� (� ������� ��:��): ";
    string departureTimeStr;
    getline(cin, departureTimeStr);
    while (!isvalidtimeformat(departureTimeStr)) {
        cout << "������������ ������ �������. ����������, ������� ����� ����������� � ������� ��:��: ";
        getline(cin, departureTimeStr);
    }
    sscanf_s(departureTimeStr.c_str(), "%d:%d", &newtrain.departuretime.separated.hours, &newtrain.departuretime.separated.minutes);

    return newtrain;
}

// ������� ��� ������ ���������� � ������ � ����
void writetraintofile(const train& train, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << train.trainnumber << ',' << train.destination << ',' << train.daysofoperation << ',' << timetostring(train.arrivaltime) << ',' << timetostring(train.departuretime) << '\n';
        file.close();
        cout << "���������� � ������ ������� �������� � ����." << endl;
    }
    else {
        cout << "������ �������� ����� ��� ������." << endl;
    }
}

string getDayOfWeek(int dayNumber) {
    switch (dayNumber) {
    case 1:
        return "�����������";
    case 2:
        return "�������";
    case 3:
        return "�����";
    case 4:
        return "�������";
    case 5:
        return "�������";
    case 6:
        return "�������";
    case 7:
        return "�����������";
    default:
        return "�������� ����� ���";
    }
}

void printtrain(const train& train) {
    cout << "����� ������: " << train.trainnumber << endl;
    cout << "����� ����������: " << train.destination << endl;
    cout << "��� ����������: ";
    stringstream ss(train.daysofoperation);
    int dayNumber;
    while (ss >> dayNumber) {
        cout << getDayOfWeek(dayNumber) << " ";
    }
    cout << endl;
    cout << "����� ��������: " << setw(2) << setfill('0') << train.arrivaltime.separated.hours << ":" << setw(2) << setfill('0') << train.arrivaltime.separated.minutes << endl;
    cout << "����� �����������: " << setw(2) << setfill('0') << train.departuretime.separated.hours << ":" << setw(2) << setfill('0') << train.departuretime.separated.minutes << endl;
}

vector<train> readtrainsfromfile(const string& filename) {
    vector<train> trains;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            train train;
            stringstream ss(line);
            string field;
            if (getline(ss, field, ',')) {
                train.trainnumber = stoi(field);
            }
            else {
                cout << "������ ������ ������ ������." << endl;
                continue;
            }
            if (getline(ss, train.destination, ',')) {
                if (getline(ss, train.daysofoperation, ',')) {
                    string arrivalTimeStr, departureTimeStr;
                    if (getline(ss, arrivalTimeStr, ',')) {
                        if (getline(ss, departureTimeStr, ',')) {
                            // �������������� ������� � ��������� Time
                            sscanf_s(arrivalTimeStr.c_str(), "%d:%d", &train.arrivaltime.separated.hours, &train.arrivaltime.separated.minutes);
                            sscanf_s(departureTimeStr.c_str(), "%d:%d", &train.departuretime.separated.hours, &train.departuretime.separated.minutes);
                            trains.push_back(train);
                        }
                        else {
                            cout << "������ ������ ������� �����������." << endl;
                            continue;
                        }
                    }
                    else {
                        cout << "������ ������ ������� ��������." << endl;
                        continue;
                    }
                }
                else {
                    cout << "������ ������ ���� ����������." << endl;
                    continue;
                }
            }
            else {
                cout << "������ ������ ������ ����������." << endl;
                continue;
            }
        }
        file.close();
    }
    else {
        cout << "������ �������� ����� ��� ������." << endl;
    }
    return trains;
}

vector<train> searchtrainbydestination(const vector<train>& trains, const string& destination) {
    vector<train> foundtrains;
    for (const auto& train : trains) {
        if (train.destination == destination) {
            foundtrains.push_back(train);
        }
    }
    return foundtrains;
}

void displaytrains(const vector<train>& trains) {
    cout << "������ �������:" << endl;
    for (const auto& train : trains) {
        printtrain(train);
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string filename = "trains.txt";
    vector<train> trains;

    while (true) {
        cout << "\n����:" << endl;
        cout << "1. �������� ���������� � ������" << endl;
        cout << "2. ������� ���������� � ���� �������" << endl;
        cout << "3. ����� ������ �� ������ ����������" << endl;
        cout << "4. �������� ���������� � ������� � ����" << endl;
        cout << "5. ��������� ���������� � ������� �� �����" << endl;
        cout << "6. �����" << endl;
        cout << "�������� ��������: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            train newtrain = inputtrainfromkeyboard();
            trains.push_back(newtrain);
            break;
        }
        case 2: {
            displaytrains(trains);
            break;
        }
        case 3: {
            string destination;
            cout << "������� ����� ���������� ��� ������: ";
            getline(cin, destination);
            vector<train> foundtrains = searchtrainbydestination(trains, destination);
            displaytrains(foundtrains);
            break;
        }
        case 4: {
            ofstream clearfile(filename, ios::trunc);
            clearfile.close();
            for (const auto& train : trains) {
                writetraintofile(train, filename);
            }
            cout << "���������� � ������� ������� �������� � ����." << endl;
            break;
        }
        case 5: {
            trains = readtrainsfromfile(filename);
            displaytrains(trains);
            break;
        }
        case 6: {
            cout << "����� �� ���������." << endl;
            return 0;
        }
        default: {
            cout << "������������ ����. ��������� �������." << endl;
            break;
        }
        }
    }

    return 0;
}