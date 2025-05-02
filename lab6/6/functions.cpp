#include "headerlab6.h"

using namespace std;

// Функций для работы с маршрутами
void createMarshArray(vector<MARSH>& trafic, int n) {
    trafic.resize(n);
}

void fillMarsh(vector<MARSH>& trafic) {
    for (auto& marsh : trafic) {
        cout << "Введите название начала маршрута: \n";
        cin.ignore();
        getline(cin, marsh.BEGST);

        cout << "Введите название конца маршрута: \n";
        getline(cin, marsh.TERM);

        while (true) {
            cout << "Введите номер маршрута(целое число): \n";
            cin >> marsh.NUMER;
            if (cin.fail() or cin.peek() != '\n') {
                cin.clear();
                cin.ignore(100000000, '\n');
                cout << "Это не целое число. Введите снова \n";
            }
            else {
                break;
            }
        }
        cin.ignore();
    }
}

void sortByNumber(vector<MARSH>& trafic) {
    int n = trafic.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (trafic[j].NUMER > trafic[j + 1].NUMER) {
                MARSH vrem = trafic[j];
                trafic[j] = trafic[j + 1];
                trafic[j + 1] = vrem;
            }
        }
    }
}

void printMarsh(const MARSH& marsh) {
    cout << "Номер маршрута: " << marsh.NUMER << "\nНачало: " << marsh.BEGST << "\nКонец: " << marsh.TERM << endl;
}

void findMarshByNumber(const vector<MARSH>& trafic, int number) {
    bool found = false;
    for (auto& marsh : trafic) {
        if (marsh.NUMER == number) {
            printMarsh(marsh);
            found = true;
            break;
        }
    }
    if (found == false) {
        cout << "Не найден маршрут " << number << endl;
    }
}

// Реализация функций для работы с файлами
bool isFileExistsAndNotEmpty(const string& filename) {
    ifstream file(filename);
    if (!file) {
        return false; //Если файл не открылся
    }
    file.seekg(0, ios::end); // Перемещаем указатель чтения в конец файла
    bool isNotEmpty = (file.tellg() > 0); // Если позиция указателя > 0 файл не пуст
    file.close();
    return isNotEmpty;
}

void split(const string& s, vector<string>& words) {
    string currentWord;
    for (char c : s) {
        if (c != ' ') {
            currentWord += c;
        }
        else {
            if (currentWord.empty() == false) { // Если слово не пустое
                words.push_back(currentWord);
            }
            currentWord = "";
        }
    }
}

string processLine(const string& line) {
    vector<string> words;
    split(line, words);
    vector<int> toRemove;

    for (int i = 0; i < words.size(); ++i) {
        if (words[i].length() >= 3 && words[i].length() <= 5) {
            toRemove.push_back(i);
        }
    }

    if ((toRemove.size()) % 2 != 0) {
        toRemove.pop_back();
    }
    string result = "";
    for (int i = 0; i < words.size(); ++i) {
        bool shouldRemove = false;
        // Проверяем, есть ли текущий индекс в toRemove
        for (int index : toRemove) {
            if (i == index) {
                shouldRemove = true;
                break;
            }
        }
        // Добавляем слово, если его не нужно удалять
        if (shouldRemove == false) {
            result += words[i] + " ";
        }
    }
    words.clear();
    toRemove.clear();
    return result;
}

void processFile(const string& filename) {
    ifstream inFile(filename);
    vector<string> linesr;
    string line = "";
    while (getline(inFile, line)) {
        line = line + " ";
        linesr.push_back(processLine(line));
    }
    inFile.close();

    //ofstream outFile(filename); // Файл очищается при открытии
    for (const auto& curLine : linesr) {
        cout <<  curLine << '\n';
        //outFile << curLine << "\n"; // Записываем обработанные строки
    }
    //outFile.close();
}