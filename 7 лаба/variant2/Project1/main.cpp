#include <iostream>
#include "stack.h"

int main() {
    setlocale(0, "");
    Stack stack;
    int choice;
    std::string filename = "stack_data.txt";

    do {
        std::cout << "\n����:" << std::endl;
        std::cout << "1. �������� ������� � ����" << std::endl;
        std::cout << "2. ������� ������� �� �����" << std::endl;
        std::cout << "3. ����������� ������� ������� �����" << std::endl;
        std::cout << "4. ������� ������ ������������� ������� �� �����" << std::endl;
        std::cout << "5. �������� ����" << std::endl;
        std::cout << "6. ��������� ���� � ����" << std::endl;
        std::cout << "7. ��������� ���� �� �����" << std::endl;
        std::cout << "8. �����" << std::endl;
        std::cout << "�������� ��������: ";

        // �������� �� ���� �����
        if (!(std::cin >> choice)) {
            std::cerr << "������: ������� ������������ ��������." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            int value;
            std::cout << "������� �������� ��������: ";

            // �������� �� ���� �����
            if (!(std::cin >> value)) {
                std::cerr << "������: ������� ������������ ��������." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            stack.push(value);
            break;
        case 2:
            std::cout << "����������� �������: " << stack.pop() << std::endl;
            break;
        case 3:
            std::cout << "������� �������: " << stack.peek() << std::endl;
            break;
        case 4:
            stack.removeFirstNegative();
            break;
        case 5:
            stack.clear();
            std::cout << "���� ������." << std::endl;
            break;
        case 6:
            stack.saveToFile(filename);
            break;
        case 7:
            stack.readFromFile(filename);
            break;
        case 8:
            std::cout << "����� �� ���������." << std::endl;
            break;
        default:
            std::cout << "������������ ����. ���������� ��� ���." << std::endl;
        }
    } while (choice != 8);

    return 0;
}
