#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack(); // конструктор
    ~Stack(); // деструктор
    void push(int value); // добавление элемента в стек
    int pop(); // извлечение элемента из стека
    int peek(); // просмотр верхнего элемента стека
    bool isEmpty(); // проверка на пустоту стека
    void clear(); // очистка стека
    void saveToFile(const std::string& filename); // сохранение стека в файл
    void readFromFile(const std::string& filename); // считывание стека из файла
    void removeFirstNegative(); // удаление первого отрицательного элемента из стека
};

#endif
#pragma once
