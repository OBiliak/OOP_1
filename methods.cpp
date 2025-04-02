#include "header.h"

void addMoney(Money& a, Money& b) {
    a.grn += b.grn;
    a.kop += b.kop;

    a.grn += a.kop / 100;
    a.kop %= 100;
}

void multiplyMoney(Money& a, int multiplier) {
    a.grn *= multiplier;
    a.kop *= multiplier;

    a.grn += a.kop / 100;
    a.kop %= 100;
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

void parseLine(const char* line, int& quantity, Money& money) {
    std::regex pattern(R"(\s*(\d+)\s*грн,\s*(\d+)\s*коп,\s*(\d+)\s*одн;\n*)");
    std::cmatch match;

    if (std::regex_search(line, match, pattern)) {
        money.grn = std::stoi(match[1]);
        money.kop = std::stoi(match[2]);
        quantity = std::stoi(match[3]);
    }
}