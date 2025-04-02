#include "methods.cpp"
#include <Windows.h>
#include <cstdio>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    FILE *file = fopen("C:\\Users\\ASUS\\Desktop\\GROSHA\\price.txt", "r");
    if (file == NULL){
        perror("Error opening file");
        return -1;
    }

    Money total = {0, 0};
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Money price = {0, 0};
        int quantity = 1;
        parseLine(line, quantity, price);
        multiplyMoney(price, quantity);
        addMoney(total, price);
    }

    std::cout << "До заокруглення: ";
    printMoney(total);

    roundMoney(total);
    std::cout << "Після заокруглення: ";
    printMoney(total);

    fclose(file);
    return 0;
}