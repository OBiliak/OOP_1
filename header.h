#include <iostream>
#include <cstdio>
#include <regex>
#include <cstring>
#include <string>

struct Money {
    int grn;
    short int kop;
};

void addMoney(Money& a, Money& b);
void multiplyMoney(Money& a, int multiplier);
void roundMoney(Money& money);
void printMoney(const Money& money);
void parseLine(const char* line, int& quantity, Money& money);
