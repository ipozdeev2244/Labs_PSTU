#pragma once
#include <iostream>
#include <iostream>
#include <iomanip>

using namespace std;
// ����������� ����������������� �����
char digit(int num);
// ��������� ����� ����� �����
int dectox_int(int a, int p, char* s);
// ��������� ������� ����� �����
void dectox_double(double a, int p, char* s);
// ������� � 10 ��
double toSS10(double  value, int ss);
// ������� � 10 ��
double Man(double &value, int ss);
// ��� ����� � 10 ��
int Cel(double value, int ss);
// �� 16 � 10 ��
double from16to10(char* value);
