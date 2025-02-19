#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    setlocale(0, "rus");
    srand(time(0));
    int mas[10];
    int* p = &mas[0];
    for (int i = 0; i < 10; i++) {
        *(p + i) = 1 + rand() % 10;
    }
    cout << "Массив:\n";
    for (int i = 0; i < 10; i++) {
        cout << *(p + i) << " ";
    }
    cout << "\n";
    int locm;
    int n;
    if (*p > *(p + 1)) {
        locm = *p;
        n = 1;
    }
    for (int i = 1; i < 9; i++) {
        if (*(p + i) > *(p + i + 1) && *(p + i) > *(p + i - 1)) {
            locm = *(p + i);
            n = i + 1;
        }
    }
    if (*(p+9) > *(p + 8)) {
        locm = *(p + 9);
        n = 10;
    }
    
    cout << "Локальный максимум: " << locm << " номер: " << n << "\n";
    system("PAUSE");
}
