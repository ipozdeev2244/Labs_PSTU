#include "Func.h"

char digit(int num)
{
    switch (num) {
    case 0: return '0';
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
    case 10: return 'A';
    case 11: return 'B';
    case 12: return 'C';
    case 13: return 'D';
    case 14: return 'E';
    case 15: return 'F';
    }
}
// Получение целой части числа
int dectox_int(int a, int p, char* s)
{
    int num = (int)a;
    int rest = num % p;
    num /= p;
    if (num == 0)
    {
        s[0] = digit(rest); return 1;
    }
    int k = dectox_int(num, p, s);
    s[k++] = digit(rest);
    return k;
}
// Получение дробной части числа
void dectox_double(double a, int p, char* s)
{
    int iter = 0;
    int k = 0;
    double a1 = a;
    do {
        a1 = a1 * p;
        int num = (int)(a1);
        s[k++] = digit(num);
        a1 -= (int)a1;
        iter++;
    } while (a1 > 0.00000001 && iter < 10);
    s[k] = '\0';
}
//Перевод в 10ч СС
double toSS10(double  value, int ss)
{
    int cel = Cel(value, ss);
    double man = Man(value, ss);
    double res = cel + man;
    return res;
}
double Man(double &value, int ss)
{
   // int cel = int(value);
   // double val = 0 + double(value); 
   // val = val - cel;
    value = value - int(value);
    double resm = 0, val = value;
    int i = -1;
    while (val>0)
    {
        resm += double(int(val * 10))*pow(ss,i);
        i--;
        val = val*10 - int(val * 10);
        if (val < 0.000000001) val = 0;
    }
    return resm;
}
int Cel(double value, int ss)
{ 
    int i = 0;//счётчик
    int cel = int(value);//целая часть 
    int resc = 0;//результат перевода
    while (cel>0)
        {
            resc += cel % 10 * pow(ss, i);
            i++;
            cel /= 10;
        }
    return resc;
}  
double from16to10(char* value)
{
    
    return 0;
}