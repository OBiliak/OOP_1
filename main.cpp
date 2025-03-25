#include <iostream>
#include "methods.cpp"

int main() {
    FILE *file = fopen("C:\\Users\\ASUS\\Desktop\\GROSHA\\price.txt", "r");
    if (file == NULL){
        perror("Error opening file");
        return -1;
    }

    Money total = {0, 0};
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int quantity, grn=0;
        short kop=0;
        
        if (parseLine(line, quantity, grn, kop) == 0) {
            Money price = {grn, kop};
            Money multipliedPrice;
            multiplyMoney(price, quantity, multipliedPrice);
            
            Money newTotal;
            addMoney(total, multipliedPrice, newTotal);
            total = newTotal;
        }
    }

    std::cout << "До заокруглення: ";
    printMoney(total);

    roundMoney(total);
    std::cout << "Після заокруглення: ";
    printMoney(total);

    fclose(file);
    return 0;
}