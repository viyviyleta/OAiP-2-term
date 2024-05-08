#include "list.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
using namespace std;

void insert(Address* e, Address** phead, Address** plast) {
    Address* p = *plast;
    if (*plast == NULL) {
        e->next = NULL;
        e->prev = NULL;
        *plast = e;
        *phead = e;
    }
    else {
        p->next = e;
        e->next = NULL;
        e->prev = p;
        *plast = e;
    }
}

Address* setElement() {
    string cho1, cho2;
    Address* temp = new  Address();
    if (!temp) {
        cerr << "������ ��������� ������.\n";
        return NULL;
    }

    do {
        cout << "������� ���: ";
        getline(cin, cho1);
        cin.ignore(cin.rdbuf()->in_avail());
        cin.clear();
    } while (cho1.find_first_not_of(FOUND2) != string::npos);
    temp->name = cho1;

    do {
        cout << "������� �����: ";
        getline(cin, cho2);
        cin.ignore(cin.rdbuf()->in_avail());
        cin.clear();
        if (cho2.find_first_not_of(FOUND1) != string::npos) {

        }
    } while (cho2.find_first_not_of(FOUND1) != string::npos);
    temp->city = cho2;

    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void outputList(Address** phead, Address** plast) {
    if (*phead == nullptr) {
        cout << "������ ����.\n";
        return;
    }

    Address* t = *phead;
    while (t) {
        cout << "���: " << t->name << ' ' << "�����: " << t->city << '\n';
        t = t->next;
    }
    cout << endl;
}


void delet(string name, Address** phead, Address** plast) {
    struct Address* t = *phead;
    while (t) {
        if (name == t->name)  break;
        t = t->next;
    }
    if (!t)
        cerr << "��� �� �������.\n" << endl;
    else {
        if (*phead == t) {
            *phead = t->next;
            if (*phead)
                (*phead)->prev = NULL;
            else
                *plast = NULL;
        }
        else {
            t->prev->next = t->next;
            if (t != *plast)
                t->next->prev = t->prev;
            else
                *plast = t->prev;
        }
        delete t;
        cout << "������� ������.\n" << endl;
    }
}

void find(string name, Address** phead) {
    Address* t = *phead;
    while (t) {
        if (name == t->name) break;
        t = t->next;
    }
    if (!t)
        cerr << "��� �� �������.\n" << endl;
    else
        cout << t->name << ' ' << t->city << endl;
}

void writeToFile(Address** phead) {
    Address* t = *phead;
    ofstream file1("Lip.txt");
    if (file1.fail()) {
        cerr << "���� �� �����������" << endl;
        exit(1);
    }
    cout << "���������� � ����" << endl;
    while (t) {
        file1 << t->name << " " << t->city << endl; // �������� �� ������ ������ ���������
        t = t->next;
    }
    file1.close();
}

void readFromFile(Address** phead, Address** plast) {
    // ������� ������ ����� ������� �� �����
    while (*phead) {
        *plast = (*phead)->next;
        delete* phead;
        *phead = *plast;
    }
    *phead = *plast = nullptr;

    string name, city; // ������� �������� ���������� ��� �������
    ifstream file1("Lip.txt");
    if (!file1.is_open()) {
        cerr << "������ �������� �����" << endl;
        exit(1);
    }

    while (file1 >> name >> city) { // �������� �� ������ ����� ���� �����
        Address* t = new Address;
        t->name = name;
        t->city = city;
        t->prev = *plast;
        t->next = nullptr;

        if (*plast == nullptr) {
            *phead = t;
        }
        else {
            (*plast)->next = t;
        }

        *plast = t;
    }

    file1.close();
}

void deleteKFirst(Address*& head, Address*& tail) {
    int k;
    cout << "������� ���������� ��������� ��� ��������: ";
    while (!(cin >> k) || k <= 0) {
        if (cin.fail()) {
            cout << "������: ������� ����� �����.\n";
            cin.clear();
            cin.ignore();
        }
        else {
            cout << "������: ������� ������������� �����.\n";
        }
    }

    Address* temp = head;
    for (int i = 0; i < k && temp != nullptr; ++i) {
        Address* wasDeleted = temp;
        temp = temp->next;
        if (wasDeleted == head) {
            head = temp;
            if (temp != nullptr) {
                temp->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
        }
        else {
            temp->prev = wasDeleted->prev;
            wasDeleted->prev->next = temp;
        }
        delete wasDeleted;
    }
}
