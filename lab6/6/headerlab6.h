//#pragma once рекомендуется
#ifndef HEADERLAB6_H
#define HEADERLAB6_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct MARSH {
    std::string BEGST;
    std::string TERM;
    int NUMER;
};

// Прототипы функций для работы с маршрутами
void createMarshArray(std::vector<MARSH>& trafic, int n);
void fillMarsh(std::vector<MARSH>& trafic);
void sortByNumber(std::vector<MARSH>& trafic);
void printMarsh(const MARSH& marsh);
void findMarshByNumber(const std::vector<MARSH>& trafic, int number);

// Прототипы функций для работы с файлами
bool isFileExistsAndNotEmpty(const std::string& filename);
void processFile(const std::string& filename);
std::string processLine(const std::string& line);
void split(const std::string& s, std::vector<std::string>& words);

#endif
