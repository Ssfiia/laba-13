#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <Windows.h>
#include "Header.h"

int main() {
    using namespace std;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(0));
    int choice;
    do {
        cout << "\n    ВЫБОР ЗАДАНИЯ \n";
        cout << "1. STL3Alg1: Удалить второй из элементов вектора, равных нулю\n";
        cout << "2. STL3Alg30: Удалить все нулевые элементы во второй половине вектора\n";
        cout << "3. STL3Alg36: Найти три средних элемента после сортировки\n";
        cout << "4. STL3Alg60: Получить вектор средних арифметических соседних элементов\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Ошибка ввода! \n";
            continue;
        }

        switch (choice) {
        case 1:
            STL3Alg1();
            break;
        case 2:
            STL3Alg30();
            break;
        case 3:
            STL3Alg36();
            break;
        case 4:
            STL3Alg60();
            break;
        case 0:
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);

    return 0;
}