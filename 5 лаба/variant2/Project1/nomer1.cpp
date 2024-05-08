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
//// Перечисление 
//enum Gender { Male, Female };
//
//struct Citizen {
//    string fullName;
//    struct {
//        unsigned int day : 5;
//        unsigned int month : 4;
//        unsigned int year : 12;
//    } birthDate; // битовоe поле
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
//// Функция для проверки корректности введенной даты
//bool isValidDate(int day, int month, int year) {
//    // Проверка даты на корректность
//    if (day < 1 || month < 1 || year < 1) {
//        return false; // Некорректные значения дня, месяца или года
//    }
//    if (month > 12) {
//        return false; // Некорректный номер месяца
//    }
//    if (day > 31) {
//        return false; // Некорректный номер дня
//    }
//    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
//        return false; // В апреле, июне, сентябре и ноябре максимум 30 дней
//    }
//    if (month == 2) {
//        if (isLeapYear(year)) {
//            if (day > 29) {
//                return false; // В високосный год в феврале максимум 29 дней
//            }
//        }
//        else {
//            if (day > 28) {
//                return false; // В обычный год в феврале максимум 28 дней
//            }
//        }
//    }
//    // Проверка даты на позднее значение
//    if (year > 2024 || (year == 2024 && (month > 3 || (month == 3 && day > 14)))) {
//        return false; // Введенная дата позже 14 марта 2024 года
//    }
//    // Все проверки пройдены, дата корректна
//    return true;
//}
//
//// Функция для добавления горожанина
//void addCitizen() {
//    Citizen newCitizen;
//    cout << "Введите Ф.И.О. горожанина: ";
//    getline(cin >> ws, newCitizen.fullName);
//    int day, month, year;
//    // Проверка корректности ввода даты
//    while (true) {
//        cout << "Введите дату рождения горожанина (в формате ДД ММ ГГГГ): ";
//        cin >> day >> month >> year;
//        if (isValidDate(day, month, year)) {
//            break; // Если дата корректна, выходим из цикла
//        }
//        else {
//            cout << "Некорректная дата. Попробуйте снова." << endl;
//            cin.clear();
//        }
//    }
//    // Сохранение даты рождения в битовом поле
//    newCitizen.birthDate.day = day;
//    newCitizen.birthDate.month = month;
//    newCitizen.birthDate.year = year;
//    cout << "Введите адрес горожанина: ";
//    getline(cin >> ws, newCitizen.address);
//    char genderInput;
//    // Проверка корректности ввода пола
//    while (true) {
//        cout << "Введите пол горожанина (0 - мужской, 1 - женский): ";
//        cin >> genderInput;
//        if (genderInput == '0' || genderInput == '1') {
//            break;
//        }
//        else {
//            cout << "Некорректный ввод. Введите 0 или 1." << endl;
//            cin.clear();
//        }
//    }
//    int gender = genderInput - '0'; // Преобразование символа в целое число
//    newCitizen.gender = static_cast<Gender>(gender);
//    citizens.push_back(newCitizen);
//}
//
//// Функция для удаления горожанина по индексу
//void deleteCitizen(size_t index) {
//    if (index < citizens.size()) {
//        citizens.erase(citizens.begin() + index);
//        cout << "Горожанин успешно удален." << endl;
//    }
//    else {
//        cout << "Некорректный индекс." << endl;
//    }
//}
//
//// Функция для поиска горожан по году рождения
//void searchByBirthYear(int year) {
//    bool found = false;
//    cout << "Горожане, родившиеся в " << year << " году:" << endl;
//    for (const auto& citizen : citizens) {
//        if (citizen.birthDate.year == year) { // Проверка года рождения
//            cout << citizen.fullName << endl;
//            found = true;
//        }
//    }
//    if (!found) {
//        cout << "Горожане, родившиеся в " << year << " году, не найдены." << endl;
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
//        cout << "\nМеню:" << endl;
//        cout << "1. Добавить горожанина" << endl;
//        cout << "2. Вывести список горожан" << endl;
//        cout << "3. Удалить горожанина" << endl;
//        cout << "4. Поиск горожан по году рождения" << endl;
//        cout << "5. Выход" << endl;
//        cout << "Выберите действие: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            addCitizen();
//            break;
//        case 2:
//            // Вывод списка горожан
//            cout << "Список горожан:" << endl;
//            for (const auto& citizen : citizens) {
//                cout << "Ф.И.О.: " << citizen.fullName << endl;
//                cout << "Дата рождения: " << citizen.birthDate.day << "." << citizen.birthDate.month << "." << citizen.birthDate.year << endl;
//                cout << "Адрес: " << citizen.address << endl;
//                cout << "Пол: " << (citizen.gender == Male ? "Мужской" : "Женский") << endl;
//                cout << endl;
//            }
//            break;
//        case 3:
//            size_t index;
//            cout << "Введите индекс горожанина для удаления: ";
//            cin >> index;
//            deleteCitizen(index - 1);
//            break;
//        case 4:
//            int year;
//            cout << "Введите год рождения для поиска: ";
//            cin >> year;
//            searchByBirthYear(year);
//            break;
//        case 5:
//            cout << "Выход из программы." << endl;
//            return 0;
//        default:
//            cout << "Некорректный выбор. Попробуйте еще раз." << endl;
//        }
//    }
//
//    return 0;
//}

