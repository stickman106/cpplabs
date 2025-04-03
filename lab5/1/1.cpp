#include <iostream>
#include <ctime>
#include <cstdlib>

double Vvod1() {
    double n;
    while (true) {
        std::cout << "Введите вещественное число \n";
        std::cin >> n;
        if (std::cin.fail() or std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(100000000, '\n');
            std::cout << "Это не вещественное число. Введите снова \n";
        }
        else {
            break;
        }
    }
    return n;
}
void Minmax(double& x, double& y) {
    if (x > y) {
        std::swap(x, y);
    }
}

int Vvod2() {
    int k;
    while (true) {
        std::cout << "Введите целое K > 0 \n";
        std::cin >> k;
        if (std::cin.fail() or std::cin.peek() != '\n' or k <= 0) {
            std::cin.clear();
            std::cin.ignore(100000000, '\n');
            std::cout << "Это не целое положительное число. Введите снова \n";
        }
        else {
            break;
        }
    }
    return k;
}
bool IsPowerN(int K, int N) {
    if (K == 1) {
        return true; // N^0 
    }
    while (K % N == 0) {
        K = K / N;
    }
    if (K == 1) {
        return true;
    }
    return false;
}

double PowerN(double x, int n) {
    if (n == 0) {
        return 1;
    }
    else if (n > 0 && n % 2 == 0) {
        return pow((pow(x, n / 2)), 2); // просто деление тк n и так целое число
    }
    else if (n > 0 && n % 2 != 0) {
        return x * pow(x, n - 1);
    }
    else {
        return 1 / pow(x, n * (-1));
    }
}
int Vvod3() {
    int n;
    while (true) {
        std::cout << "Введите целое N \n";
        std::cin >> n;
        if (std::cin.fail() or std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(100000000, '\n');
            std::cout << "Это не целое число. Введите снова \n";
        }
        else {
            break;
        }
    }
    return n;
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "");
    std::cout << "1" << '\n';
    double A = Vvod1();
    double B = Vvod1();
    double C = Vvod1();
    double D = Vvod1();
    Minmax(A, B);
    Minmax(C, D);
    Minmax(A, C); // A становится минимальным из A и C(минимум из минимув)
    Minmax(B, D); // D Уже наоборот
    std::cout << "Минимум: " << A << '\n';
    std::cout << "Максимум: " << D << '\n';

    std::cout << "2" << '\n';
    int arr[10];
    int count = 0;
    int n;
    while (true) {
        std::cout << "Введите целое N > 1 \n";
        std::cin >> n;
        if (std::cin.fail() or std::cin.peek() != '\n' or n <= 1) {
            std::cin.clear();
            std::cin.ignore(100000000, '\n');
            std::cout << "Это не целое число > 1. Введите снова \n";
        }
        else {
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        arr[i] = Vvod2();
    }
    for (int i = 0; i < 10; i++) {
        if (IsPowerN(arr[i], n)) {
            count++;
        }
    }
    std::cout << "Колличество: " << count << "\n";

    std::cout << "3" << '\n';
    double X = Vvod1();
    int arr2[5];
    for (int i = 0; i < 5; i++) {
        arr2[i] = Vvod3();
    }
    for (int i = 0; i < 5; i++) {
        std::cout << PowerN(X, arr2[i]) << '\n';
    }
}