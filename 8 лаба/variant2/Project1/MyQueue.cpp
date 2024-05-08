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
        std::cerr << "������: �������� ������ �����. ������� ����� ������.\n";
    }
    catch (const std::out_of_range&) {
        std::cerr << "������: ����� ��� ����������� ���������. ������� ����� ������.\n";
    }
}

void view(const Queue* begin) {
    const Queue* current = begin;
    if (current == nullptr) {
        std::cout << "������� �����.\n";
        return;
    }

    std::cout << "�������:\n";
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
        if (temp->info < 0) { // ���������, �������� �� �������� �������������
            delete temp; // ������� �������, ���� ��� �������� �������������
        }
    }
}
void removeElement(Queue** begin, int value) {
    Queue* current = *begin;
    Queue* prev = nullptr;

    while (current != nullptr) {
        if (current->info == value) {
            if (prev == nullptr) {
                // ������� ������ �������
                *begin = current->next;
                if (current->info < 0) { // ���������, �������� �� �������� �������������
                    delete current; // ������� �������, ���� ��� �������� �������������
                }
                return;
            }
            else {
                prev->next = current->next;
                if (current->info < 0) { // ���������, �������� �� �������� �������������
                    delete current; // ������� �������, ���� ��� �������� �������������
                }
                return;
            }
        }
        prev = current;
        current = current->next;
    }

    std::cout << "������� " << value << " �� ������ � �������.\n";
}


int findMinMaxDiff(const Queue* begin) {
    if (begin == nullptr) {
        std::cerr << "������� �����.\n";
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
        std::cerr << "����������� � ������������ �������� �����. ������� ����� 0.\n";
        return 0;
    }
    else {
        return max - min;
    }
}


int countElementsBetweenMinMax(const Queue* begin) {
    if (begin == nullptr) {
        std::cout << "������� �����.\n";
        return 0;
    }

    const Queue* current = begin;
    int min = current->info, max = current->info;
    int minIndex = 0, maxIndex = 0, currentIndex = 0;

    // ������� ����������� � ������������ �������� � ������� � �� �������
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

    // ���� ����������� � ������������ �������� �����, ���������� 0
    if (min == max) {
        return 0;
    }

    // ������� ���������� ��������� ����� ����������� � ������������ ����������
    int count = 0;
    if (minIndex < maxIndex) {
        count = maxIndex - minIndex - 1;
    }
    else {
        count = minIndex - maxIndex - 1;
    }

    return count;
}
