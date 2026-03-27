#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <random>
#include <ctime>
#include <iomanip>
#include "Header.h"

// Вывод вектора
void printVector(const std::vector<int>& v, const std::string& title) {
    using namespace std;
    cout << title << ": ";
    for (int i = 0; i < v.size(); i++)
        cout << setw(3) << v[i] << " ";
    cout << endl;
}

void printVector(const std::vector<double>& v, const std::string& title) {
    using namespace std;
    cout << title << ": ";
    for (int i = 0; i < v.size(); i++)
        cout << fixed << setprecision(1) << v[i] << " ";
    cout << endl;
}

// Вывод списка
void printList(const std::list<int>& l, const std::string& title) {
    using namespace std;
    cout << title << ": ";
    for (auto it = l.begin(); it != l.end(); it++)
        cout << fixed << setprecision(1) << *it << " ";
    cout << endl;
}

// Выбор способа заполнения
int chooseMethod() {
    using namespace std;
    int m;
    cout << "\nСпособ заполнения:\n";
    cout << "1. C консоли\n";
    cout << "2. Случайные числа\n";
    cout << "3. Из файла\n";
    cout << "Выбор: ";
    cin >> m;
    return m;
}

// Заполнение вектора с консоли
void VectorFromConsole(std::vector<int>& v, int count) {
    using namespace std;
    vector<int> temp;
    cout << "Введите " << count << " целых чисел: ";
    for (int i = 0; i < count; i++) {
        int x;
        cin >> x;
        temp.push_back(x);
    }
    v = vector<int>(temp.begin(), temp.end());
}

// Заполнение вектора рандомом
void VectorRandom(std::vector<int>& v, int count) {
    using namespace std;
    vector<int> temp;
    for (int i = 0; i < count; i++)
        temp.push_back(rand() % 200 - 100);
    v = vector<int>(temp.begin(), temp.end());
}

// Заполнение вектора из файла 
bool VectorFromFile(std::vector<int>& v, const std::string& filename) {
    using namespace std;
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла\n";
        return false;
    }
    vector<int> temp;
    int x;
    while (file >> x)
        temp.push_back(x);
    v = vector<int>(temp.begin(), temp.end());
    return true;
}

// Заполнение списка с консоли
void ListFromConsole(std::list<int>& l, int count) {
    using namespace std;
    vector<int> temp;
    cout << "Введите " << count << " чисел: ";
    for (int i = 0; i < count; i++) {
        int x;
        cin >> x;
        temp.push_back(x);
    }
    l = list<int>(temp.begin(), temp.end());
}

// Заполнение списка рандомом 
void ListRandom(std::list<int>& l, int count) {
    using namespace std;
    vector<int> temp;
    for (int i = 0; i < count; i++)
        temp.push_back(rand() % 200 - 100);
    l = list<int>(temp.begin(), temp.end());
}

// Заполнение списка из файла 
bool ListFromFile(std::list<int>& l, const std::string& filename) {
    using namespace std;
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла\n";
        return false;
    }
    vector<int> temp;
    int x;
    while (file >> x)
        temp.push_back(x);
    l = list<int>(temp.begin(), temp.end());
    return true;
}

void STL3Alg1() {
    using namespace std;
    vector<int> V;
    int n, method;

    cout << "\n STL3Alg1 " << endl;
    cout << "Удалить второй нулевой элемент.\n";
    method = chooseMethod();

    if (method == 1) {
        cout << "Введите количество элементов: ";
        cin >> n;
        VectorFromConsole(V, n);
    }
    else if (method == 2) {
        cout << "Введите количество элементов: ";
        cin >> n;
        VectorRandom(V, n);
    }
    else {
        string fname;
        cout << "Имя файла: ";
        cin >> fname;
        if (!VectorFromFile(V, fname)) {
            return;
        }
    }

    printVector(V, "Исходный вектор");

    // Находим первый ноль
    auto it = find(V.begin(), V.end(), 0);
    if (it != V.end()) {
        // Находим второй ноль, начиная поиск со следующего элемента
        auto it2 = find(it + 1, V.end(), 0);
        if (it2 != V.end()) {
            // Удаляем второй ноль
            V.erase(it2);
            cout << "Второй ноль найден и удален" << endl;
        }
        else {
            cout << "Нулевых элементов меньше двух. Вектор не изменен" << endl;
        }
    }
    else {
        cout << "Нулевых элементов нет. Вектор не изменен" << endl;
    }

    printVector(V, "Результат");
}

void STL3Alg30() {
    using namespace std;
    vector<int> V;
    int n, method;

    cout << "\n STL3Alg30 " << endl;
    cout << "Удалить все нули во второй половине вектора\n";
    method = chooseMethod();

    if (method == 1) {
        cout << "Введите четное количество элементов: ";
        cin >> n;
        while (n % 2 != 0) {
            cout << "Ошибка! Введите четное число: ";
            cin >> n;
        }
        VectorFromConsole(V, n);
    }
    else if (method == 2) {
        cout << "Введите четное количество элементов: ";
        cin >> n;
        while (n % 2 != 0) {
            cout << "Ошибка! Введите четное число: ";
            cin >> n;
        }
        VectorRandom(V, n);
    }
    else {
        string fname;
        cout << "Имя файла: ";
        cin >> fname;
        if (!VectorFromFile(V, fname)) {
            return;
        }
        if (V.size() % 2 != 0) {
            cout << "Ошибка: в файле должно быть четное количество чисел\n";
            return;
        }
    }

    printVector(V, "Исходный вектор");

    int half = V.size() / 2;
    auto Rhalf = V.begin() + half;

    // Перемещаем нули из второй половины в конец вектора
    auto new_end = remove(Rhalf, V.end(), 0);

    // Удаляем их
    V.erase(new_end, V.end());

    printVector(V, "После удаления нулей из второй половины: ");
}

void STL3Alg36() {
    using namespace std;
    vector<int> V;
    int n, method;

    cout << "\n STL3Alg36 " << endl;
    cout << "Найти три средних элемента по возрастанию\n";
    method = chooseMethod();

    if (method == 1) {
        cout << "Введите нечетное количество элементов (>=3): ";
        cin >> n;
        while (n < 3 || n % 2 == 0) {
            cout << "Ошибка! Введите нечетное число >=3: ";
            cin >> n;
        }
        VectorFromConsole(V, n);
    }
    else if (method == 2) {
        cout << "Введите нечетное количество элементов (>=3): ";
        cin >> n;
        while (n < 3 || n % 2 == 0) {
            cout << "Ошибка! Введите нечетное число >=3: ";
            cin >> n;
        }
        VectorRandom(V, n);
    }
    else {
        string fname;
        cout << "Имя файла: ";
        cin >> fname;
        if (!VectorFromFile(V, fname)) {
            return;
        }
        if (V.size() < 3 || V.size() % 2 == 0) {
            cout << "Ошибка: в файле должно быть нечетное количество чисел >=3\n";
            return;
        }
    }

    printVector(V, "Исходный вектор");

    int n_size = V.size();
    int mid_index = n_size / 2;

    // Находим центральный элемент
    auto mid = V.begin() + mid_index;
    nth_element(V.begin(), mid, V.end());
    int middle = *mid;

    // Для находим элемент предшествующий центральному,
    auto left_max = max_element(V.begin(), mid);
    int left = *left_max;
    // Для находим элемент следующий за центральным,
    auto right_min = min_element(mid + 1, V.end());
    int right = *right_min;

    vector<int> result = { left, middle, right };
    sort(result.begin(), result.end());

    cout << "\nТри средних элемента в порядке возрастания: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}
//функциональный объект
class Avg {
public:
    double operator()(double a, double b) const {
        return (a + b) / 2.0;
    }
};

void STL3Alg60() {
    using namespace std;
    list<int> L;
    int n, method;

    cout << "\n STL3Alg60 " << endl;
    cout << "Получить вектор средних арифметических соседних элементов списка\n";
    method = chooseMethod();

    if (method == 1) {
        cout << "Введите количество элементов (>=2): ";
        cin >> n;
        while (n < 2) {
            cout << "Ошибка! Введите число >=2: ";
            cin >> n;
        }
        ListFromConsole(L, n);
    }
    else if (method == 2) {
        cout << "Введите количество элементов (>=2): ";
        cin >> n;
        while (n < 2) {
            cout << "Ошибка! Введите число >=2: ";
            cin >> n;
        }
        ListRandom(L, n);
    }
    else {
        string fname;
        cout << "Имя файла: ";
        cin >> fname;
        if (!ListFromFile(L, fname)) {
            return;
        }
        if (L.size() < 2) {
            cout << "Ошибка: в файле должно быть не менее 2 чисел\n";
            return;
        }
    }
    printList(L, "Исходный список");

    vector<double> V(L.begin(), L.end());
    //вычисляет сред. арефметических соседних элементов 
    Avg avg;
    adjacent_difference(L.begin(), L.end(), V.begin(), avg);
    V.erase(V.begin());

    printVector(V, "Вектор средних арифметических");
}