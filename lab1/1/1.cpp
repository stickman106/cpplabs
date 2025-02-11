
#include <iostream>
#include <math.h>

int main(){
    setlocale(0, "rus");
    float x, y, r, z;
    while (true) {
        while (true) {
            std::cout << "Введите x не равное 0: \n";
            std::cin >> x;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(100000000, '\n');
                std::cout << "Это не число. Введите снова \n";
            }
            else if (x == 0) {
                std::cout << "Введите x снова\n";
            }
            else {
                break;
            }
        }
        if (x > 0) {
            while (true) {
                std::cout << "Введите y >= 0: \n";
                std::cin >> y;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(100000000, '\n');
                    std::cout << "Это не число. Введите снова \n";
                }
                else if (y < 0) {
                    std::cout << "Введите y снова\n";
                }
                else {
                    break;
                }
            }
        }
        else {
            while (true) {
                std::cout << "Введите y <= 0: \n";
                std::cin >> y;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(100000000, '\n');
                    std::cout << "Это не число. Введите снова \n";
                }
                else if (y > 0) {
                    std::cout << "Введите y снова\n";
                }
                else {
                    break;
                }
            }
        }
        r = x + (sqrt(x * y) / pow(x, 2));
        if (r > 0) {
            z = log2(r);
            break;
        }
        else {
            std::cout << "Выражение под логарифмом должно быть > 0. Введите снова\n";
        }
    }

    
    std::cout << z << '\n';
    system("PAUSE");
    
}

