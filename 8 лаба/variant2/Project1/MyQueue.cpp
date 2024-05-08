#include "MyQueue.h"
#include <cstdlib> 
#include <limits> 
#include <iostream>
#include <string>

void create(Queue** begin, Queue** end, const std::string& valueStr) {
    try {
        int value = std::stoi(valueStr);
        Queue* newNode = new Queue;
        newNode->info = value;
        newNode->next = nullptr;

        if (*begin == nullptr) {
            *begin = *end = newNode;
        }
        else {
            (*end)->next = newNode;
            *end = newNode;
        }
    }
    catch (const std::invalid_argument&) {
        std::cerr << "Ошибка: Неверный формат числа. Введите число заново.\n";
    }
    catch (const std::out_of_range&) {
        std::cerr << "Ошибка: Число вне допустимого диапазона. Введите число заново.\n";
    }
}

void view(const Queue* begin) {
    const Queue* current = begin;
    if (current == nullptr) {
        std::cout << "Очередь пуста.\n";
        return;
    }

    std::cout << "Очередь:\n";
    while (current != nullptr) {
        std::cout << current->info << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void clear(Queue** begin) {
    while (*begin != nullptr) {
        Queue* temp = *begin;
        *begin = (*begin)->next;
        if (temp->info < 0) { // Проверяем, является ли значение отрицательным
            delete temp; // Удаляем элемент, если его значение отрицательное
        }
    }
}
void removeElement(Queue** begin, int value) {
    Queue* current = *begin;
    Queue* prev = nullptr;

    while (current != nullptr) {
        if (current->info == value) {
            if (prev == nullptr) {
                // Удаляем первый элемент
                *begin = current->next;
                if (current->info < 0) { // Проверяем, является ли значение отрицательным
                    delete current; // Удаляем элемент, если его значение отрицательное
                }
                return;
            }
            else {
                prev->next = current->next;
                if (current->info < 0) { // Проверяем, является ли значение отрицательным
                    delete current; // Удаляем элемент, если его значение отрицательное
                }
                return;
            }
        }
        prev = current;
        current = current->next;
    }

    std::cout << "Элемент " << value << " не найден в очереди.\n";
}


int findMinMaxDiff(const Queue* begin) {
    if (begin == nullptr) {
        std::cerr << "Очередь пуста.\n";
        return 0;
    }

    const Queue* current = begin;
    int min = current->info, max = current->info;

    while (current != nullptr) {
        if (current->info < min) {
            min = current->info;
        }
        if (current->info > max) {
            max = current->info;
        }
        current = current->next;
    }

    if (min == max) {
        std::cerr << "Минимальный и максимальный элементы равны. Разница равна 0.\n";
        return 0;
    }
    else {
        return max - min;
    }
}


int countElementsBetweenMinMax(const Queue* begin) {
    if (begin == nullptr) {
        std::cout << "Очередь пуста.\n";
        return 0;
    }

    const Queue* current = begin;
    int min = current->info, max = current->info;
    int minIndex = 0, maxIndex = 0, currentIndex = 0;

    // Находим минимальный и максимальный элементы в очереди и их индексы
    while (current != nullptr) {
        if (current->info < min) {
            min = current->info;
            minIndex = currentIndex;
        }
        if (current->info > max) {
            max = current->info;
            maxIndex = currentIndex;
        }
        current = current->next;
        currentIndex++;
    }

    // Если минимальный и максимальный элементы равны, возвращаем 0
    if (min == max) {
        return 0;
    }

    // Находим количество элементов между минимальным и максимальным элементами
    int count = 0;
    if (minIndex < maxIndex) {
        count = maxIndex - minIndex - 1;
    }
    else {
        count = minIndex - maxIndex - 1;
    }

    return count;
}
