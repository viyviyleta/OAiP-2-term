//#include <iostream>
//#include <vector>
//#include <algorithm> // Для сортировки
//#include <chrono>    // Для измерения времени
//
//using namespace std;
//using namespace std::chrono;
//
//// Функция для перемещения элементов массива A в массив B
//void moveElements(const vector<int>& A, vector<int>& B) {
//    for (int i = 1; i < A.size(); i += 2) { // Начинаем со второго элемента и переходим через один
//        if (i + 1 < A.size()) { // Проверяем, есть ли следующий элемент
//            B.push_back(A[i]);
//        }
//    }
//}
//
//// Сортировка слиянием
//void merge(vector<int>& arr, int l, int m, int r) {
//    int n1 = m - l + 1;
//    int n2 = r - m;
//
//    vector<int> L(n1), R(n2);
//
//    for (int i = 0; i < n1; i++)
//        L[i] = arr[l + i];
//    for (int j = 0; j < n2; j++)
//        R[j] = arr[m + 1 + j];
//
//    int i = 0;
//    int j = 0;
//    int k = l;
//
//    while (i < n1 && j < n2) {
//        if (L[i] >= R[j]) {
//            arr[k] = L[i];
//            i++;
//        }
//        else {
//            arr[k] = R[j];
//            j++;
//        }
//        k++;
//    }
//
//    while (i < n1) {
//        arr[k] = L[i];
//        i++;
//        k++;
//    }
//
//    while (j < n2) {
//        arr[k] = R[j];
//        j++;
//        k++;
//    }
//}
//
//void mergeSort(vector<int>& arr, int l, int r) {
//    if (l < r) {
//        int m = l + (r - l) / 2;
//        mergeSort(arr, l, m);
//        mergeSort(arr, m + 1, r);
//        merge(arr, l, m, r);
//    }
//}
//
//// Сортировка Хоара (быстрая сортировка)
//int partition(vector<int>& arr, int low, int high) {
//    int pivot = arr[high];
//    int i = (low - 1);
//
//    for (int j = low; j <= high - 1; j++) {
//        if (arr[j] >= pivot) { // Здесь заменяем <= на >= для сортировки по убыванию
//            i++;
//            swap(arr[i], arr[j]);
//        }
//    }
//    swap(arr[i + 1], arr[high]);
//    return (i + 1);
//}
//
//void quickSort(vector<int>& arr, int low, int high) {
//    if (low < high) {
//        int pi = partition(arr, low, high);
//
//        quickSort(arr, low, pi - 1);
//        quickSort(arr, pi + 1, high);
//    }
//}
//
//int main() {
//    setlocale(0, "");
//    vector<int> A;
//    int size;
//    cout << "Введите размер массива: ";
//    cin >> size;
//    cout << "Введите элементы массива: ";
//    for (int i = 0; i < size; ++i) {
//        int num;
//        cin >> num;
//        A.push_back(num);
//    }
//
//    // Выводим массив A
//    cout << "Массив A: ";
//    for (int num : A) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    // Создаем массив B и переносим элементы из A
//    vector<int> B;
//    moveElements(A, B);
//
//    // Создаем копии массива B для сортировок
//    vector<int> B_merge = B;
//    vector<int> B_quick = B;
//
//    mergeSort(B_merge, 0, B_merge.size() - 1); // Сортировка слиянием
//    quickSort(B_quick, 0, B_quick.size() - 1); // Быстрая сортировка (Хоара)
//
//    // Выводим массив B, отсортированный слиянием
//    cout << "Отсортированный массив B (сортировкой слиянием): ";
//    for (int num : B_merge) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    // Выводим массив B, отсортированный быстрой сортировкой
//    cout << "Отсортированный массив B (сортировкой Хоара): ";
//    for (int num : B_quick) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
