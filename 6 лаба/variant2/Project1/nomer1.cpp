#include <iostream>
#include <fstream>
#include <iomanip> 
#include <sstream> 
#include <limits> 
using namespace std;

// Структура для односвязного списка
struct Node {
    double data;
    Node* next;
};

// Функция для добавления элемента в начало списка
void insert(Node*& head, double value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Функция для удаления элемента из списка
void remove(Node*& head, double value) {
    Node* current = head;
    Node* prev = nullptr;

    // Поиск элемента
    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }

    // Если элемент найден, удаляем его
    if (current != nullptr) {
        if (prev != nullptr) {
            prev->next = current->next;
        }
        else {
            head = current->next;
        }
        delete current;
    }
    else {
        cout << "Элемент " << value << " не найден в списке" << endl;
    }
}


// Функция для вывода списка на консоль
void printList(Node* head) {
    if (head == NULL) {
        cout << "Список пуст" << endl;
    }
    else {
        cout << "Список:" << endl;
        while (head != NULL) {
            cout << "-->" << head->data;
            head = head->next;
        }
        cout << "-->NULL" << endl;
    }
}

// Функция для записи списка в файл
void toFile(Node* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла" << endl;
        return;
    }
    while (head != nullptr) {
        file << fixed << setprecision(2) << head->data << endl;
        head = head->next;
    }
    cout << "Список записан в файл " << filename << endl;
    file.close();
}

// Функция для чтения списка из файла
void fromFile(Node*& head, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла" << endl;
        return;
    }
    double value;
    while (file >> value) {
        insert(head, value);
    }
    cout << "Список считан из файла " << filename << endl;
    file.close();
}

// Функция для поиска элемента в списке и вывода его номера
void search(Node* head, double value) {
    int index = 1;
    while (head != nullptr) {
        if (head->data == value) {
            cout << "Элемент " << value << " найден на позиции " << index << endl;
            return;
        }
        head = head->next;
        index++;
    }
    cout << "Элемент " << value << " не найден в списке" << endl;
}

// Функция для вычисления среднего значения положительных элементов списка
double averageOfPositive(Node* head) {
    int count = 0;
    double sum = 0.0;
    while (head != nullptr) {
        if (head->data > 0) {
            sum += head->data;
            count++;
        }
        head = head->next;
    }
    return count > 0 ? sum / count : 0.0;
}

// Функция для вывода меню
void menu() {
    cout << "Сделайте выбор:" << endl;
    cout << "1 - Добавить элемент" << endl;
    cout << "2 - Удалить элемент" << endl;
    cout << "3 - Вывести список" << endl;
    cout << "4 - Записать список в файл" << endl;
    cout << "5 - Считать список из файла" << endl;
    cout << "6 - Поиск элемента" << endl;
    cout << "7 - Найти среднее значение положительных элементов" << endl;
    cout << "8 - Выход" << endl;
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    Node* head = nullptr;
    int choice;
    double value;

    menu();
    cout << "? ";
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Введите число от 1 до 8: ";
    }

    while (choice != 8) {
        switch (choice) {
        case 1:
            cout << "Введите элемент: ";
            while (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода. Введите вещественное число: ";
            }
            insert(head, value);
            printList(head);
            break;
        case 2:
            cout << "Введите элемент, который хотите удалить: ";
            while (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода. Введите вещественное число: ";
            }
            remove(head, value);
            printList(head);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            toFile(head, "list.txt");
            break;
        case 5:
            fromFile(head, "list.txt");
            printList(head);
            break;
        case 6:
            cout << "Введите элемент, который хотите найти: ";
            while (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода. Введите вещественное число: ";
            }
            search(head, value);
            break;
        case 7:
            cout << "Среднее значение положительных элементов списка: " << averageOfPositive(head) << endl;
            break;
        default:
            cout << "Неправильный выбор" << endl;
            break;
        }
        menu();
        cout << "? ";
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Введите число от 1 до 8: ";
        }
    }

    // Освобождаем память, выделенную под список
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
