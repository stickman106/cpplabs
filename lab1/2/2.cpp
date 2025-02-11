
#include <iostream>
#include <math.h>

int main() {
    setlocale(0, "rus");
    float x, y, r;
    while (true) {
        std::cout << "Введите x: \n";
        std::cin >> x;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000000, '\n');
            std::cout << "Это не число. Введите снова \n";
        }
        else {
            break;
        }
    }
    if (x < 2) {
        y = (6 * sin(x) - pow(x, 2)) / 3;
    }
    else if (x >= 2 && x < 4) {
        y = (exp(3 * x - cos(2 * x))) / (3 + 4 * pow(x, 6));
    }
    else {
        r = 6 * pow(x, 3) - 4 * tan(x + 1);
        y = pow(6 * pow(x, 3) - 4 * tan(x + 1), (1.0 / 5.0));
    }
    std::cout << y << '\n';
    system("PAUSE");
}