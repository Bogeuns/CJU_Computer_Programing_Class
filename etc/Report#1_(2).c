#include <stdio.h>

int main() {
    int insertedMoney, itemPrice, change;
    int thousands, fiveHundreds, hundreds;

    // Step 1: Read the inserted money and the price of the item
    printf("Enter the amount of money inserted: ");
    scanf("%d", &insertedMoney);
    printf("Enter the price of the item: ");
    scanf("%d", &itemPrice);

    // Step 2: Calculate the change
    change = insertedMoney - itemPrice;

    if (change < 0) {
        printf("Insufficient funds. You are short by %d KRW.\n", -change);
        return 0;
    }

    // Step 3: Calculate the number of 1000, 500, and 100 KRW units
    thousands = change / 1000;
    change = change % 1000;
    
    fiveHundreds = change / 500;
    change = change % 500;
    
    hundreds = change / 100;
    change = change % 100;

    // Step 4: Output the result
    printf("Change to be returned: \n");
    printf("1000 KRW bills: %d\n", thousands);
    printf("500 KRW coins: %d\n", fiveHundreds);
    printf("100 KRW coins: %d\n", hundreds);
    
    return 0;
}
