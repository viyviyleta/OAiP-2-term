#include "Heap.h"
#include <iostream>
#include <limits>
using namespace std;
using namespace heap;

heap::CMP cmpAAA(void* a1, void* a2) {
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    heap::CMP
        rc = heap::EQUAL;
    if (A1->x > A2->x)
        rc = heap::GREAT;
    else
        if (A2->x > A1->x)
            rc = heap::LESS;
    return rc;
#undef A2
#undef A1 
}

int main() {
    setlocale(LC_ALL, "rus");
    int k = 1, choice;
    heap::Heap h1 = heap::create(30, cmpAAA);
    heap::Heap h2 = heap::create(30, cmpAAA);
    Heap* ph2 = &h2;
    for (;;) {
        cout << "1 - Вывод кучи на экран" << endl;
        cout << "2 - Добавить элемент" << endl;
        cout << "3 - Удалить максимальный элемент" << endl;
        cout << "4 - Удалить минимальный элемент" << endl;
        cout << "5 - Удалить i-ый элемент" << endl;
        cout << "6 - Объединение двух бинарных куч" << endl;
        cout << "0 - Выход" << endl;
        cout << "Сделайте выбор:" << endl;
        cin >> choice;

        if (cin.fail()) { // Проверка на некорректный ввод
            cout << "Ошибка: некорректный ввод. Пожалуйста, введите число от 0 до 6." << endl;
            cin.clear(); // Сброс флага ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
            continue; // Возвращаемся к началу цикла
        }
        int j = 1;
        switch (choice) {
        case 0:
            exit(0);
        case 1:
            h1.scan(0);
            break;
        case 2:
            do {
                cout << "Введите ключ (отрицательное число для завершения ввода):" << endl;
                cin >> k;
                if (cin.fail() || k < 0) {
                    cout << "Ошибка: некорректный ввод. Пожалуйста, введите положительное число." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    AAA* a = new AAA;
                    a->x = k;
                    h1.insert(a);
                }
            } while (k >= 0);
            break;
        case 3:
            h1.extractMax();
            break;
        case 4:
            h1.extractMin();
            break;
        case 5:
            int i;
            cout << "Введите i:\n";
            cin >> i;
            if (cin.fail() || i < 0) {
                cout << "Ошибка: некорректный ввод. Пожалуйста, введите положительное число." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                h1.extractI(i);
            }
            break;
        case 6:
            cout << "Введите вторую кучу:\n";
            while (j > 0) {
                AAA* b = new AAA;
                cout << "Введите ключ:" << endl;
                cin >> j;
                if (cin.fail()) {
                    cout << "Ошибка: некорректный ввод. Пожалуйста, введите число." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else if (j > 0) {
                    b->x = j;
                    h2.insert(b);
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Дополнительное очищение буфера
            }
            h1.unionHeap(ph2);
            break;
        default:
            cout << "Ошибка: некорректный выбор. Пожалуйста, выберите одну из предложенных опций." << endl;
            break;
        }
    }
    return 0;
}