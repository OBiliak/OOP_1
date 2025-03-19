#include "header.h"
#include <cstdio>
#include <regex>
#include <cstring>
#include <string>

void addMoney(const Money& a, const Money& b, Money& result) {
    result.grn = a.grn + b.grn;
    result.kop = a.kop + b.kop;
    if (result.kop >= 100) {
        result.grn += result.kop / 100;
        result.kop %= 100;
    }
}

void multiplyMoney(const Money& a, int multiplier, Money& result) {
    int totalKop = a.grn * 100 + a.kop;
    totalKop *= multiplier;
    result.grn = totalKop / 100;
    result.kop = totalKop % 100;
}

void roundMoney(Money& money) {
    if (money.kop >= 95) {
        money.grn++;
        money.kop = 0;
    } else {
        money.kop = ((money.kop + 5) / 10) * 10;
    }
}

void printMoney(const Money& money) {
    std::cout << "Загальна вартість товарів: " << money.grn << " грн " << money.kop << " коп" << std::endl;
}

int parseLine(const char* line, int& quantity, int& grn, short& kop) {
    std::regex pattern(R"((.+?),\s*(\d+)\s*грн,\s*(\d+)\s*коп,\s*(\d+)\s*одн;)");
    std::cmatch match;
    quantity = 1;

    if (std::regex_match(line, match, pattern)) {
        grn = std::stoi(match[2]);
        kop = std::stoi(match[3]);
        quantity = std::stoi(match[4]);
        return 0;
    }
    return -1;
}