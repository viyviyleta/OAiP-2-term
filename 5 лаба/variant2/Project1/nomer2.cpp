#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <windows.h>

using namespace std;

// Определение структуры Time
struct Time {
    int hours;
    int minutes;
};

// Объединение для хранения времени
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

    // Ищем индекс первого вхождения 7 в последовательности
    auto it = find(days.begin(), days.end(), 7);
    if (it != days.end()) {
        // Нашли 7, проверяем, что после него идет 1 и все остальные дни в порядке
        auto nextDay = it + 1;
        if (nextDay == days.end()) {
            return true; // В последовательности только 7 без последующих дней
        }
        if (*nextDay != 1) {
            return false; // После 7 не идет 1
        }
        // Проверяем, что все остальные дни в порядке возрастания
        for (auto currentDay = nextDay + 1; currentDay != days.end(); ++currentDay) {
            if (*currentDay != *(currentDay - 1) + 1) {
                return false; // Нарушен порядок возрастания
            }
        }
        // Проверяем, что все предшествующие дни тоже в порядке возрастания
        for (auto prevDay = days.begin(); prevDay != it; ++prevDay) {
            if (*prevDay != *(prevDay + 1) - 1) {
                return false; // Нарушен порядок возрастания
            }
        }
    }
    else {
        // Проверяем, что все дни в порядке возрастания
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
        cout << "Введите дни следования через пробел (например, 1 2 3): ";
        getline(cin, inputDays);
        // Проверка на то, что ввод не пустой и содержит только цифры и пробелы
        if (inputDays.empty() || inputDays.find_first_not_of("1234567890 ") != string::npos) {
            cout << "Ошибка: дни следования должны состоять только из цифр." << endl;
            continue;
        }
        // Проверка на корректный порядок дней
        if (!isValidDaySequence(inputDays)) {
            cout << "Ошибка: дни следования должны быть введены в порядке возрастания через пробел." << endl;
            continue;
        }
        return inputDays;
    }
}
// Функция для проверки корректности формата времени (чч:мм)
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

// Структура для хранения информации о поезде
struct train {
    int trainnumber;
    string destination;
    string daysofoperation;
    TimeUnion arrivaltime; // Используем объединение для хранения времени
    TimeUnion departuretime; // Используем объединение для хранения времени
};

// Преобразование времени в строку
string timetostring(const TimeUnion& time) {
    stringstream ss;
    ss << setw(2) << setfill('0') << time.separated.hours << ":" << setw(2) << setfill('0') << time.separated.minutes;
    return ss.str();
}

// Функция для ввода информации о поезде с клавиатуры
train inputtrainfromkeyboard() {
    train newtrain;
    string temptrainnumber;
    while (true) {
        cout << "Введите номер поезда: ";
        getline(cin, temptrainnumber);
        if (!temptrainnumber.empty()) {
            stringstream ss(temptrainnumber);
            if (ss >> newtrain.trainnumber && ss.eof()) {
                break;
            }
            else {
                cout << "Ошибка: введено некорректное значение. Номер поезда должен быть числом." << endl;
                continue;
            }
        }
        else cout << "Введите номер поезда: ";
    }

    cout << "Введите пункт назначения: ";
    getline(cin, newtrain.destination);
    while (newtrain.destination.empty()) {
        cout << "Пункт назначения не может быть пустым. Пожалуйста, введите пункт назначения: ";
        getline(cin, newtrain.destination);
    }

    newtrain.daysofoperation = inputdaysfromkeyboard();

    cout << "Введите время прибытия (в формате чч:мм): ";
    string arrivalTimeStr;
    getline(cin, arrivalTimeStr);
    while (!isvalidtimeformat(arrivalTimeStr)) {
        cout << "Некорректный формат времени. Пожалуйста, введите время прибытия в формате чч:мм: ";
        getline(cin, arrivalTimeStr);
    }
    sscanf_s(arrivalTimeStr.c_str(), "%d:%d", &newtrain.arrivaltime.separated.hours, &newtrain.arrivaltime.separated.minutes);

    cout << "Введите время отправления (в формате чч:мм): ";
    string departureTimeStr;
    getline(cin, departureTimeStr);
    while (!isvalidtimeformat(departureTimeStr)) {
        cout << "Некорректный формат времени. Пожалуйста, введите время отправления в формате чч:мм: ";
        getline(cin, departureTimeStr);
    }
    sscanf_s(departureTimeStr.c_str(), "%d:%d", &newtrain.departuretime.separated.hours, &newtrain.departuretime.separated.minutes);

    return newtrain;
}

// Функция для записи информации о поезде в файл
void writetraintofile(const train& train, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << train.trainnumber << ',' << train.destination << ',' << train.daysofoperation << ',' << timetostring(train.arrivaltime) << ',' << timetostring(train.departuretime) << '\n';
        file.close();
        cout << "Информация о поезде успешно записана в файл." << endl;
    }
    else {
        cout << "Ошибка открытия файла для записи." << endl;
    }
}

string getDayOfWeek(int dayNumber) {
    switch (dayNumber) {
    case 1:
        return "Понедельник";
    case 2:
        return "Вторник";
    case 3:
        return "Среда";
    case 4:
        return "Четверг";
    case 5:
        return "Пятница";
    case 6:
        return "Суббота";
    case 7:
        return "Воскресенье";
    default:
        return "Неверный номер дня";
    }
}

void printtrain(const train& train) {
    cout << "Номер поезда: " << train.trainnumber << endl;
    cout << "Пункт назначения: " << train.destination << endl;
    cout << "Дни следования: ";
    stringstream ss(train.daysofoperation);
    int dayNumber;
    while (ss >> dayNumber) {
        cout << getDayOfWeek(dayNumber) << " ";
    }
    cout << endl;
    cout << "Время прибытия: " << setw(2) << setfill('0') << train.arrivaltime.separated.hours << ":" << setw(2) << setfill('0') << train.arrivaltime.separated.minutes << endl;
    cout << "Время отправления: " << setw(2) << setfill('0') << train.departuretime.separated.hours << ":" << setw(2) << setfill('0') << train.departuretime.separated.minutes << endl;
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
                cout << "Ошибка чтения номера поезда." << endl;
                continue;
            }
            if (getline(ss, train.destination, ',')) {
                if (getline(ss, train.daysofoperation, ',')) {
                    string arrivalTimeStr, departureTimeStr;
                    if (getline(ss, arrivalTimeStr, ',')) {
                        if (getline(ss, departureTimeStr, ',')) {
                            // Преобразование времени в структуру Time
                            sscanf_s(arrivalTimeStr.c_str(), "%d:%d", &train.arrivaltime.separated.hours, &train.arrivaltime.separated.minutes);
                            sscanf_s(departureTimeStr.c_str(), "%d:%d", &train.departuretime.separated.hours, &train.departuretime.separated.minutes);
                            trains.push_back(train);
                        }
                        else {
                            cout << "Ошибка чтения времени отправления." << endl;
                            continue;
                        }
                    }
                    else {
                        cout << "Ошибка чтения времени прибытия." << endl;
                        continue;
                    }
                }
                else {
                    cout << "Ошибка чтения дней следования." << endl;
                    continue;
                }
            }
            else {
                cout << "Ошибка чтения пункта назначения." << endl;
                continue;
            }
        }
        file.close();
    }
    else {
        cout << "Ошибка открытия файла для чтения." << endl;
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
    cout << "Список поездов:" << endl;
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
        cout << "\nМеню:" << endl;
        cout << "1. Добавить информацию о поезде" << endl;
        cout << "2. Вывести информацию о всех поездах" << endl;
        cout << "3. Поиск поезда по пункту назначения" << endl;
        cout << "4. Записать информацию о поездах в файл" << endl;
        cout << "5. Прочитать информацию о поездах из файла" << endl;
        cout << "6. Выход" << endl;
        cout << "Выберите действие: ";

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
            cout << "Введите пункт назначения для поиска: ";
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
            cout << "Информация о поездах успешно записана в файл." << endl;
            break;
        }
        case 5: {
            trains = readtrainsfromfile(filename);
            displaytrains(trains);
            break;
        }
        case 6: {
            cout << "Выход из программы." << endl;
            return 0;
        }
        default: {
            cout << "Некорректный ввод. Повторите попытку." << endl;
            break;
        }
        }
    }

    return 0;
}