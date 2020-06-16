#pragma once
#include <iostream>
#include <iostream>
#include <iomanip>

using namespace std;
// Отображение шестнадцатеричной цифры
char digit(int num);
// Получение целой части числа
int dectox_int(int a, int p, char* s);
// Получение дробной части числа
void dectox_double(double a, int p, char* s);
// Перевод в 10 СС
double toSS10(double  value, int ss);
// Мантиса в 10 СС
double Man(double &value, int ss);
// Цел часть в 10 СС
int Cel(double value, int ss);
// Из 16 в 10 СС
double from16to10(char* value);
