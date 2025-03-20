#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main(){
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string pr;
    string ans1pr;
    string ans1end = "";
    cout << "Введите предложение: " << '\n';
    getline(cin, pr);
    cout << "Предложение: " << pr << '\n';
    pr = pr + ' ';
    for (int i = 0; i < pr.length(); i++) {
        if (pr[i] != ' ') {
            ans1pr = ans1pr + pr[i];
        }
        else{
            if (ans1end.length() < ans1pr.length()) {
                ans1end = ans1pr;
                ans1pr = "";
            }
            else {
                ans1pr = "";
            }
        }
    }
    cout << "Самое длинное слово: " << ans1end << '\n';

    string s;
    string s0;
    cout << "Введите предложение s1: " << '\n';
    getline(cin, s);
    cout << "Введите предложение s2: " << '\n';
    getline(cin, s0);
    cout << "Предложение s: " << s << '\n';
    cout << "Предложение s0: " << s0 << '\n';
    if (s.find(s0) != string::npos) { //string::npos - число 18446744073709551615
        cout << "True";
    }
    else {
        cout << "False";
    }
}
