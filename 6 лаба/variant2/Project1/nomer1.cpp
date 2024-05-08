#include <iostream>
#include <fstream>
#include <iomanip> 
#include <sstream> 
#include <limits> 
using namespace std;

// ��������� ��� ������������ ������
struct Node {
    double data;
    Node* next;
};

// ������� ��� ���������� �������� � ������ ������
void insert(Node*& head, double value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// ������� ��� �������� �������� �� ������
void remove(Node*& head, double value) {
    Node* current = head;
    Node* prev = nullptr;

    // ����� ��������
    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }

    // ���� ������� ������, ������� ���
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
        cout << "������� " << value << " �� ������ � ������" << endl;
    }
}


// ������� ��� ������ ������ �� �������
void printList(Node* head) {
    if (head == NULL) {
        cout << "������ ����" << endl;
    }
    else {
        cout << "������:" << endl;
        while (head != NULL) {
            cout << "-->" << head->data;
            head = head->next;
        }
        cout << "-->NULL" << endl;
    }
}

// ������� ��� ������ ������ � ����
void toFile(Node* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "������ �������� �����" << endl;
        return;
    }
    while (head != nullptr) {
        file << fixed << setprecision(2) << head->data << endl;
        head = head->next;
    }
    cout << "������ ������� � ���� " << filename << endl;
    file.close();
}

// ������� ��� ������ ������ �� �����
void fromFile(Node*& head, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "������ �������� �����" << endl;
        return;
    }
    double value;
    while (file >> value) {
        insert(head, value);
    }
    cout << "������ ������ �� ����� " << filename << endl;
    file.close();
}

// ������� ��� ������ �������� � ������ � ������ ��� ������
void search(Node* head, double value) {
    int index = 1;
    while (head != nullptr) {
        if (head->data == value) {
            cout << "������� " << value << " ������ �� ������� " << index << endl;
            return;
        }
        head = head->next;
        index++;
    }
    cout << "������� " << value << " �� ������ � ������" << endl;
}

// ������� ��� ���������� �������� �������� ������������� ��������� ������
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

// ������� ��� ������ ����
void menu() {
    cout << "�������� �����:" << endl;
    cout << "1 - �������� �������" << endl;
    cout << "2 - ������� �������" << endl;
    cout << "3 - ������� ������" << endl;
    cout << "4 - �������� ������ � ����" << endl;
    cout << "5 - ������� ������ �� �����" << endl;
    cout << "6 - ����� ��������" << endl;
    cout << "7 - ����� ������� �������� ������������� ���������" << endl;
    cout << "8 - �����" << endl;
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
        cout << "������ �����. ������� ����� �� 1 �� 8: ";
    }

    while (choice != 8) {
        switch (choice) {
        case 1:
            cout << "������� �������: ";
            while (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������ �����. ������� ������������ �����: ";
            }
            insert(head, value);
            printList(head);
            break;
        case 2:
            cout << "������� �������, ������� ������ �������: ";
            while (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������ �����. ������� ������������ �����: ";
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
            cout << "������� �������, ������� ������ �����: ";
            while (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������ �����. ������� ������������ �����: ";
            }
            search(head, value);
            break;
        case 7:
            cout << "������� �������� ������������� ��������� ������: " << averageOfPositive(head) << endl;
            break;
        default:
            cout << "������������ �����" << endl;
            break;
        }
        menu();
        cout << "? ";
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������ �����. ������� ����� �� 1 �� 8: ";
        }
    }

    // ����������� ������, ���������� ��� ������
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
