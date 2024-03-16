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

// Перечисление для типов размещения
enum class AccommodationType {
    LUXURY,
    SINGLE,
    DOUBLE,
    TRIPLE,
    APARTMENT
};

// Структура для хранения информации о клиентах гостиницы
struct HotelClient {
    string passportNumber;
    string arrivalDate;
    string departureDate;
    int roomNumber;
    AccommodationType accommodationType; // Изменение типа данных
    string lastName;
};

// Функция для проверки введенной даты на корректность и високосность года
bool isValidDate(const string& date) {
    // Проверяем длину строки даты
    if (date.length() != 10) {
        return false;
    }

    // Проверяем, что символы на местах 4 и 7 являются символами '-'
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }

    // Извлекаем год, месяц и день из строки даты
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    // Проверяем корректность введенного года, месяца и дня
    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    // Проверяем количество дней в месяце
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

// Функция для ввода номера комнаты с проверкой на корректность ввода
int inputRoomNumber() {
    string input;
    int roomNumber;
    while (true) {
        cout << "Введите номер комнаты: ";
        cin >> input;
        // Проверка на возможность преобразования строки в число
        stringstream ss(input);
        if (ss >> roomNumber && roomNumber > 0) {
            // Проверка на корректность введенного номера комнаты (допустимое диапазон значений)
            break;
        }
        else {
            cout << "Некорректный ввод. Номер комнаты должен быть положительным числом." << endl;
        }
    }
    return roomNumber;
}

// Функция для ввода типа размещения с проверкой на корректность ввода
AccommodationType inputAccommodationType() {
    string input;
    int typeChoice;
    while (true) {
        cout << "Введите тип размещения (1-люкс, 2-одноместный, 3-двухместный, 4-трехместный, 5-апартаменты): ";
        cin >> input;
        // Проверка на возможность преобразования строки в число
        stringstream ss(input);
        if (ss >> typeChoice && typeChoice >= 1 && typeChoice <= 5) {
            break;
        }
        else {
            cout << "Некорректный ввод. Пожалуйста, выберите число от 1 до 5." << endl;
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
// Функция для ввода информации о клиентах с клавиатуры
HotelClient inputClient() {
    HotelClient client;

    // Ввод паспортных данных
    cout << "Введите паспортные данные (2 большие латинские буквы и 7 цифр): ";
    cin >> client.passportNumber;

    // Проверка на корректность ввода паспортных данных
    if (client.passportNumber.length() != 9 ||
        !isupper(client.passportNumber[0]) ||
        !isupper(client.passportNumber[1])) {
        cout << "Некорректный ввод. Паспортные данные должны состоять из 2 больших латинских букв и 7 цифр." << endl;
        return inputClient(); // Повторный вызов функции для ввода паспортных данных
    }

    // Проверка оставшихся символов на цифры
    bool isValidDigits = true;
    for (int i = 2; i < 9; ++i) {
        if (!isdigit(client.passportNumber[i])) {
            isValidDigits = false;
            break;
        }
    }
    if (!isValidDigits) {
        cout << "Некорректный ввод. Паспортные данные должны состоять из 2 больших латинских букв и 7 цифр." << endl;
        return inputClient(); // Повторный вызов функции для ввода паспортных данных
    }

    // Ввод дат приезда и отъезда
    cout << "Введите дату приезда (гггг-мм-дд): ";
    cin >> client.arrivalDate;
    if (!isValidDate(client.arrivalDate)) {
        cout << "Некорректный ввод. Проверьте формат даты и ее корректность." << endl;
        return inputClient(); // Повторный вызов функции для ввода данных
    }

    cout << "Введите дату отъезда (гггг-мм-дд): ";
    cin >> client.departureDate;
    if (!isValidDate(client.departureDate)) {
        cout << "Некорректный ввод. Проверьте формат даты и ее корректность." << endl;
        return inputClient(); // Повторный вызов функции для ввода данных
    }

    // Проверка на корректность ввода дат
    // Проверяем, что дата отъезда позже даты приезда
    if (client.departureDate <= client.arrivalDate) {
        cout << "Некорректный ввод. Дата отъезда должна быть позже даты приезда." << endl;
        return inputClient(); // Повторный вызов функции для ввода данных
    }

    // Ввод номера комнаты
    client.roomNumber = inputRoomNumber();

    // Ввод типа размещения
    client.accommodationType = inputAccommodationType();

    // Ввод фамилии посетителя
    cout << "Введите фамилию посетителя: ";
    cin >> client.lastName;

    return client;
}

// Функция для вывода информации о клиенте в консоль
void outputClient(const HotelClient& client) {
    string accommodation;
    switch (client.accommodationType) {
    case AccommodationType::LUXURY:
        accommodation = "люкс";
        break;
    case AccommodationType::SINGLE:
        accommodation = "одноместный";
        break;
    case AccommodationType::DOUBLE:
        accommodation = "двухместный";
        break;
    case AccommodationType::TRIPLE:
        accommodation = "трехместный";
        break;
    case AccommodationType::APARTMENT:
        accommodation = "апартаменты";
        break;
    default:
        accommodation = "неизвестный тип";
    }

    cout << left << setw(20) << client.passportNumber
        << setw(15) << client.arrivalDate
        << setw(15) << client.departureDate
        << setw(15) << client.roomNumber
        << setw(20) << accommodation
        << setw(15) << client.lastName << endl;
}

// Функция для поиска клиента по фамилии
void findClient(const vector<HotelClient>& clients, const string& lastName) {
    bool found = false;

    cout << left << setw(20) << "Паспортные данные"
        << setw(15) << "Дата приезда"
        << setw(15) << "Дата отъезда"
        << setw(15) << "Номер комнаты"
        << setw(20) << "Тип размещения"
        << setw(15) << "Фамилия" << endl;

    cout << "Результаты поиска для фамилии \"" << lastName << "\":" << endl;

    // Проходим по всем клиентам и ищем совпадения по фамилии
    for (const auto& client : clients) {
        if (client.lastName == lastName) {
            outputClient(client);
            found = true;
        }
    }

    // Если не найдено совпадений, выводим сообщение об этом
    if (!found) {
        cout << "Клиент с фамилией \"" << lastName << "\" не найден." << endl;
    }
}

// Функция для удаления клиента по паспортным данным
void deleteClient(vector<HotelClient>& clients, const string& passportNumber) {
    auto it = remove_if(clients.begin(), clients.end(), [&](const HotelClient& client) {
        return client.passportNumber == passportNumber;
        });

    if (it != clients.end()) {
        clients.erase(it, clients.end());
        cout << "Клиент с паспортными данными \"" << passportNumber << "\" удален." << endl;
    }
    else {
        cout << "Клиент с паспортными данными \"" << passportNumber << "\" не найден." << endl;
    }
}

// Функция для записи данных в файл
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
        cout << "Данные успешно записаны в файл \"" << filename << "\"." << endl;
        file.close();
    }
    else {
        cout << "Ошибка открытия файла для записи." << endl;
    }
}

// Функция для чтения данных из файла
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
        cout << "Данные успешно считаны из файла \"" << filename << "\"." << endl;
        file.close();
    }
    else {
        cout << "Ошибка открытия файла для чтения." << endl;
    }
    return clients;
}
// Функция для обработки выбранного пользователем пункта меню
void processMenuChoice(vector<HotelClient>& clients, int choice) {
    switch (choice) {
    case 1: {
        clients.push_back(inputClient());
        break;
    }
    case 2: {
        cout << left << setw(20) << "Паспортные данные"
            << setw(15) << "Дата приезда"
            << setw(15) << "Дата отъезда"
            << setw(15) << "Номер комнаты"
            << setw(20) << "Тип размещения"
            << setw(15) << "Фамилия" << endl;
        for (const auto& client : clients) {
            outputClient(client);
        }
        break;
    }
    case 3: {
        string lastName;
        cout << "Введите фамилию посетителя: ";
        cin >> lastName;
        findClient(clients, lastName);
        break;
    }
    case 4: {
        string passportNumber;
        cout << "Введите паспортные данные клиента для удаления: ";
        cin >> passportNumber;
        deleteClient(clients, passportNumber);
        break;
    }
    case 5: {
        string filename;
        cout << "Введите имя файла для записи: ";
        cin >> filename;
        writeToFile(clients, filename);
        break;
    }
    case 6: {
        string filename;
        cout << "Введите имя файла для чтения: ";
        cin >> filename;
        clients = readFromFile(filename);
        break;
    }
    case 0: {
        cout << "Выход из программы." << endl;
        break;
    }
    default: {
        cout << "Некорректный ввод. Повторите попытку." << endl;
        // Повторный ввод текущего пункта меню
        int newChoice;
        cout << "Выберите действие: ";
        cin >> newChoice;
        processMenuChoice(clients, newChoice);
        // Выход из функции, чтобы избежать повторного вызова меню
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
        cout << "\nМеню:" << endl;
        cout << "1. Ввод данных о клиенте" << endl;
        cout << "2. Вывод всех клиентов" << endl;
        cout << "3. Поиск клиента по фамилии" << endl;
        cout << "4. Удаление клиента по паспортным данным" << endl;
        cout << "5. Запись данных в файл" << endl;
        cout << "6. Чтение данных из файла" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        // Обработка выбранного пункта меню
        processMenuChoice(clients, choice);

    } while (choice != 0);

    return 0;
}