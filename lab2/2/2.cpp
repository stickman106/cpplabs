#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "rus");
    float mas[10];
    float* p = &mas[0];
    for (int i = 0; i < 10; i++) {
        while (true) {
            cout << "Введите число " << i + 1 << " можно вещественное: \n";
            cin >> *(p + i);
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100000000, '\n');
                cout << "Это не число. Введите снова \n";
            }
            else {
                break;
            }
        }
    }
    cout << "Массив: ";
    for (int i = 0; i < 10; i++) {
        cout << *(p + i) << " ";
    }
    cout << "\n";
    int n = 0;
    for (int i = 0; i < 10; i++) {
        if (*(p + i) < 0) {
            n = n + 1;
        }
    }
    cout << "Число отрицательных элементов " << n << "\n";
    system("PAUSE");
}