#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){
    setlocale(0, "rus");
    int n;
    int s1 = 0;
    int s2 = 0;
    while (true) {
        std::cout << "Введите длину массива n \n";
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000000, '\n');
            std::cout << "Это не число. Введите снова \n";
        }
        else {
            break;
        }
    }
    srand(time(0));
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = -4 + rand() % 10;
    }
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    for (int i = 1; i < n; i = i + 2) {
        s1 = s1 + arr[i];
    }

    int neg1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            neg1 = i;
            break;
        }
    }
    int negl;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negl = i;
        }
    }
    for (int i = neg1 + 1; i < negl; i++) {
        s2 = s2 + arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (abs(arr[j]) <= 2) {
                arr[j] = arr[j + 1];
                arr[j + 1] = 0;
            }
        }
    }

    std::cout << "\n";
    std::cout << "Сумма нечетных элемемнтов массива: " << s1 << "\n";
    std::cout << "Сумма между отрицательными: " << s2 << "\n";
    std::cout << "Новый список: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}
