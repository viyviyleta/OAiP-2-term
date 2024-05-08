//#include <iostream>
//#include <fstream>
//using namespace std;
//// функция для определения максимального элемента
//unsigned int maxFunc(unsigned int n, unsigned int m) {
//	int max;
//	if (m > n)
//		max = m;
//	else
//		max = n;
//	return max;
//}
//// функция второго варианта
//unsigned int taskFunction(unsigned int m, unsigned int n) {
//	if ((m + n) % 2 == 0) {
//		return maxFunc(n, m);
//	}
//	else {
//		// Если сумма m и n нечетная, меняем их местами
//		if (m < n) {
//			unsigned int temp = m;
//			m = n;
//			n = temp;
//			cout << "m и n поменяли местами" << endl;
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
//        cout << "Введите m: ";
//        if (cin >> m1) {
//            if (m1 < 0) {
//                cout << "Ошибка ввода. Пожалуйста, введите неотрицательное целое число для m." << endl;
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            }
//            else {
//                cout << "Введите n: ";
//                if (cin >> n1) {
//                    if (n1 < 0) {
//                        cout << "Ошибка ввода. Пожалуйста, введите неотрицательное целое число для n." << endl;
//                        cin.clear();
//                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                    }
//                    else if (ceil(m1) != m1) {
//                        cout << "Ошибка ввода. Пожалуйста, введите целое число для m." << endl;
//                        cin.clear();
//                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                    }
//                    else if (ceil(n1) != n1) {
//                        cout << "Ошибка ввода. Пожалуйста, введите целое число для n." << endl;
//                        cin.clear();
//                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                    }
//                    else {
//                        valid_input = true; 
//                    }
//                }
//                else {
//                    cout << "Ошибка ввода. Пожалуйста, введите целое число для n." << endl;
//                    cin.clear();
//                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                }
//            }
//        }
//        else {
//            cout << "Ошибка ввода. Пожалуйста, введите целое число для m." << endl;
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        }
//    }
//
//    cout << "Результат = " << taskFunction(m1, n1) << "\n";
//
//    return 0;
//}
