#include <iostream>
#include "list.h"

using namespace std;

int main() {
    string s;
    int c;
    string dname;
    string fname;
    setlocale(LC_CTYPE, "Rus");
    system("chcp 1251");
    Address* head = NULL;
    Address* last = NULL;
    short choose = 0;
    while (choose != 5) {
        cout << "�������� ��������:\n1 � ���� ��������;\n2 � ����� ������;\n3 � �������� ��������;\n4 � ����� ��������;"
            "\n5 � ������ � ����;\n6 � ����� �� �����;\n7 � �������� K ������ ���������;\n8 � ����� �� ���������.\n";

        do {
            getline(cin >> ws, s);
        } while (s.find_first_not_of(FOUND) != string::npos);

        c = stoi(s);

        switch (c) {
        case 1:
            insert(setElement(), &head, &last);
            break;
        case 2:
            outputList(&head, &last);
            break;
        case 3:
            do {
                cout << "������� ���: ";
                getline(cin, dname);
                cin.ignore(cin.rdbuf()->in_avail());
                cin.clear();
            } while (dname.find_first_not_of(FOUND2) != string::npos);
            delet(dname, &head, &last);
            break;
        case 4:
            do {
                cout << "������� ���: ";
                getline(cin, fname);
                cin.ignore(cin.rdbuf()->in_avail());
                cin.clear();
            } while (fname.find_first_not_of(FOUND2) != string::npos);
            find(fname, &head);
            break;
        case 5:
            writeToFile(&head);
            break;
        case 6:
            readFromFile(&head, &last);
            break;
        case 7:
            deleteKFirst(head, last);
            break;
        case 8:
            cout << "�� ��������!\n";
            exit(0);
        }
    }
}
