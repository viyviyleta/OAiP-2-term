//#include <iostream>
//#include <fstream>
//using namespace std;
//// ������� ��� ����������� ������������� ��������
//unsigned int maxFunc(unsigned int n, unsigned int m) {
//	int max;
//	if (m > n)
//		max = m;
//	else
//		max = n;
//	return max;
//}
//// ������� ������� ��������
//unsigned int taskFunction(unsigned int m, unsigned int n) {
//	if ((m + n) % 2 == 0) {
//		return maxFunc(n, m);
//	}
//	else {
//		// ���� ����� m � n ��������, ������ �� �������
//		if (m < n) {
//			unsigned int temp = m;
//			m = n;
//			n = temp;
//			cout << "m � n �������� �������" << endl;
//		}
//		return (taskFunction((n + m + 1) / 2, n + 1) + taskFunction(m, (m + n + 1) / 2));
//	}
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    int m1, n1;
//    bool valid_input = false;
//
//    while (!valid_input) {
//        cout << "������� m: ";
//        if (cin >> m1) {
//            if (m1 < 0) {
//                cout << "������ �����. ����������, ������� ��������������� ����� ����� ��� m." << endl;
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            }
//            else {
//                cout << "������� n: ";
//                if (cin >> n1) {
//                    if (n1 < 0) {
//                        cout << "������ �����. ����������, ������� ��������������� ����� ����� ��� n." << endl;
//                        cin.clear();
//                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                    }
//                    else if (ceil(m1) != m1) {
//                        cout << "������ �����. ����������, ������� ����� ����� ��� m." << endl;
//                        cin.clear();
//                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                    }
//                    else if (ceil(n1) != n1) {
//                        cout << "������ �����. ����������, ������� ����� ����� ��� n." << endl;
//                        cin.clear();
//                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                    }
//                    else {
//                        valid_input = true; 
//                    }
//                }
//                else {
//                    cout << "������ �����. ����������, ������� ����� ����� ��� n." << endl;
//                    cin.clear();
//                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                }
//            }
//        }
//        else {
//            cout << "������ �����. ����������, ������� ����� ����� ��� m." << endl;
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        }
//    }
//
//    cout << "��������� = " << taskFunction(m1, n1) << "\n";
//
//    return 0;
//}
