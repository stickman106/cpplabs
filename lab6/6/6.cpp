#include "headerlab6.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "");
    // Задание 1: Работа с маршрутами
    int n;
    while (true) {
        std::cout << "Введите кол-во маршрутов(целое положительное число): \n";
        std::cin >> n;
        if (std::cin.fail() or std::cin.peek() != '\n' or n <=0) {
            std::cin.clear();
            std::cin.ignore(100000000, '\n');
            std::cout << "Это не целое положительное число. Введите снова \n";
        }
        else {
            break;
        }
    }

    vector<MARSH> trafic;
    createMarshArray(trafic, n);
    fillMarsh(trafic);
    sortByNumber(trafic);

    int searchNumber;
    cout << "Введите номер маршрута: ";
    while (true) {
        cout << "Введите номер маршрута:  \n";
        std::cin >> searchNumber;
        if (std::cin.fail() or std::cin.peek() != '\n' or n <= 0) {
            std::cin.clear();
            std::cin.ignore(100000000, '\n');
            std::cout << "Это не целое положительное число. Введите снова \n";
        }
        else {
            break;
        }
    }
    findMarshByNumber(trafic, searchNumber);

    // Задание 2: Обработка файла
    string filename;
    cout << "Введите название файла: ";
    cin.ignore();
    getline(cin, filename);
    if (isFileExistsAndNotEmpty(filename) == false) {
        cout << "Файл не существует или пустой \n";
    }
    else {
        processFile(filename);
        cout << "Файл прошел программу";
    }
    return 0;
}