#include "stack.h"

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    clear();
}

void Stack::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}



int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "���� ����!" << std::endl;
        return INT_MIN;
    }
    else {
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
}


int Stack::peek() {
    if (isEmpty()) {
        std::cerr << "���� ����!" << std::endl;
        return INT_MIN;
    }
    else {
        return top->data;
    }
}


bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        Node* current = top;
        while (current != nullptr) {
            file << current->data << " ";
            current = current->next;
        }
        file.close();
        std::cout << "���� ������� �������� � ����." << std::endl;
    }
    else {
        std::cerr << "������ ��� �������� �����." << std::endl;
    }
}

void Stack::readFromFile(const std::string& filename) {
    clear(); // ������� ���� ����� ������� �� �����
    std::ifstream file(filename);
    if (file.is_open()) {
        int value;
        while (file >> value) {
            push(value);
        }
        if (file.eof()) {
            std::cout << "���� ������� �������� �� �����." << std::endl;
        }
        else {
            std::cerr << "������: ������������ ������ � �����." << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "������ ��� �������� �����." << std::endl;
    }
}


void Stack::removeFirstNegative() {
    if (isEmpty()) {
        std::cerr << "���� ����!" << std::endl;
        return;
    }
    Node* current = top;
    if (current->data < 0) {
        top = top->next;
        delete current;
        std::cout << "������ ������������� ������� ������ �� �����." << std::endl;
        return;
    }
    while (current->next != nullptr && current->next->data >= 0) {
        current = current->next;
    }
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        std::cout << "������ ������������� ������� ������ �� �����." << std::endl;
    }
    else {
        std::cout << "� ����� ��� ������������� ���������." << std::endl;
    }
}
