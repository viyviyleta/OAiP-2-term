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
    Stack(); // �����������
    ~Stack(); // ����������
    void push(int value); // ���������� �������� � ����
    int pop(); // ���������� �������� �� �����
    int peek(); // �������� �������� �������� �����
    bool isEmpty(); // �������� �� ������� �����
    void clear(); // ������� �����
    void saveToFile(const std::string& filename); // ���������� ����� � ����
    void readFromFile(const std::string& filename); // ���������� ����� �� �����
    void removeFirstNegative(); // �������� ������� �������������� �������� �� �����
};

#endif
#pragma once
