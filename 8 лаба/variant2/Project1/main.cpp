#include <iostream>
#include <limits>
#include "MyQueue.h"
#include <string>

int main() {
    setlocale(LC_ALL, "ru");
    Queue* begin = nullptr, * end = nullptr;
    bool queueCreated = false; // ���������� ��� ������������ �������� �������
    std::string choose;

    do {
        std::cout << "�������� ��������:\n"
            << "1. ���� �������\n"
            << "2. ����� �������\n"
            << "3. ������� �������\n"
            << "4. ������� ������� �� �������\n"
            << "5. ����� ���������� ��������� ����� ������������ � �����������\n"
            << "6. �����\n\n";
        std::cin >> choose;

        if (choose == "1") {
            if (queueCreated) {
                char confirm;
                std::cout << "������� ��� �������. ������ �������� ������� ������� � ������� �����? (y/n): ";
                std::cin >> confirm;

                // �������� �� ������������ ������ ������������
                while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
                    std::cout << "������: ������� ���������� ����� (y/n): ";
                    std::cin >> confirm;
                }

                if (confirm == 'y' || confirm == 'Y') {
                    clear(&begin);
                }
                else {
                    continue;
                }
            }

            std::string sizeStr;
            std::cout << "������� ������ �������: ";
            std::cin >> sizeStr;

            // �������� �� ���� �����
            if (sizeStr.find_first_not_of("0123456789") != std::string::npos) {
                std::cout << "������: ������� �� �����. ������� ����� �������.\n";
                clear(&begin);
                queueCreated = false;
                continue;
            }

            int size = std::stoi(sizeStr);

            for (int i = 0; i < size; ++i) {
                std::string valueStr;
                std::cout << "������� �����: ";
                std::cin >> valueStr;

                // �������� �� ���� ����� ��� ������� ������ ��� ������������� �����
                if (valueStr.find_first_not_of("0123456789-") != std::string::npos) {
                    std::cout << "������: ������� �� �����. ������� ����� �������.\n";
                    clear(&begin);
                    queueCreated = false;
                    break; // ��������� ����
                }

                create(&begin, &end, valueStr);
            }

            queueCreated = true; // ������� �������
        }
        else if (choose == "2") {
            view(begin);
        }
        else if (choose == "3") {
            clear(&begin);
            std::cout << "������� �������.\n";
            queueCreated = false; // ������� �������
        }
        else if (choose == "4") {
            if (!queueCreated) {
                std::cout << "������� �� �������.\n";
                continue;
            }

            std::string valueStr;
            std::cout << "������� ����� ��� ��������: ";
            std::cin >> valueStr;

            // �������� �� ���� ����� ��� ������� ������ ��� ������������� �����
            if (valueStr.find_first_not_of("0123456789-") != std::string::npos) {
                std::cout << "������: ������� �� �����.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            int value = std::stoi(valueStr);
            removeElement(&begin, value);
        }

        else if (choose == "5") {
            if (!queueCreated) {
                std::cout << "������� �� �������.\n";
                continue;
            }

            int diff = findMinMaxDiff(begin);
            int count = countElementsBetweenMinMax(begin);
            std::cout << "���������� ��������� ����� ������������ � �����������: " << count << std::endl;
        }
        else if (choose == "6") {
            std::cout << "����� �� ���������.\n";
        }
        else {
            std::cout << "������������ ����. ����������, �������� ������������ ����� ����.\n";
        }
    } while (choose != "6");

    return 0;
}
