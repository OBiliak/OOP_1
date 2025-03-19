
#include <iostream>

struct Money {
    int grn;
    short int kop;
};

void addMoney(const Money& a, const Money& b, Money& result);
void multiplyMoney(const Money& a, int multiplier, Money& result);
void roundMoney(Money& money);
void printMoney(const Money& money);
int parseLine(const char* line, int& quantity, int& grn, short int& kop);
