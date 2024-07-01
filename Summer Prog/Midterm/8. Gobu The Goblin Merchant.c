#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 12

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} GobuShop;

void initializeShop(GobuShop *shop);
void populateShop(GobuShop *shop);
void displayProducts(GobuShop *shop);
void sortByPrice(GobuShop *shop);
void sortByName(GobuShop *shop);
void sortByID(GobuShop *shop);

int main() {
    GobuShop shop;

    initializeShop(&shop);
    populateShop(&shop);

    printf("Products sorted by price (ascending):\n");
    sortByPrice(&shop);
    displayProducts(&shop);

    printf("\nProducts sorted by name (alphabetical):\n");
    sortByName(&shop);
    displayProducts(&shop);

    printf("\nProducts sorted by ID (descending):\n");
    sortByID(&shop);
    displayProducts(&shop);

    return 0;
}
+
// Initialize the GobuShop product count to zero
void initializeShop(GobuShop *shop) {
    shop->count = 0;
}

// Populate GobuShop with at least eight products
void populateShop(GobuShop *shop) {
    Product initialProducts[] = {
        {1, "Sword", 12.00},
        {2, "HealthPotion", 50.00},
        {3, "PlateMail", 120.50},
        {4, "MagicAmulet", 75.00},
        {5, "Arrows", 3.70},
        {7, "ScaleMail", 120.00},
        {8, "LongBow", 10.00}
    };

    for (int i = 0; i < 7; i++) {
        shop->products[i] = initialProducts[i];
        shop->count++;
    }
}

// Display the details of all products in Gobu’s Shop
void displayProducts(GobuShop *shop) {
    for (int i = 0; i < shop->count; i++) {
        printf("ID: %03d - Name: %s - Price: %.2f\n", shop->products[i].id, shop->products[i].name, shop->products[i].price);
    }
}

// Sort the products in Gobu’s Shop by price in ascending order using Bubble Sort
void sortByPrice(GobuShop *shop) {
    for (int i = 0; i < shop->count - 1; i++) {
        for (int j = 0; j < shop->count - i - 1; j++) {
            if (shop->products[j].price > shop->products[j + 1].price) {
                Product temp = shop->products[j];
                shop->products[j] = shop->products[j + 1];
                shop->products[j + 1] = temp;
            }
        }
    }
}

// Sort the products in Gobu’s Shop by name in alphabetical order using Bubble Sort
void sortByName(GobuShop *shop) {
    for (int i = 0; i < shop->count - 1; i++) {
        for (int j = 0; j < shop->count - i - 1; j++) {
            if (strcmp(shop->products[j].name, shop->products[j + 1].name) > 0) {
                Product temp = shop->products[j];
                shop->products[j] = shop->products[j + 1];
                shop->products[j + 1] = temp;
            }
        }
    }
}

// Sort the products in Gobu’s Shop by ID in descending order using Bubble Sort
void sortByID(GobuShop *shop) {
    for (int i = 0; i < shop->count - 1; i++) {
        for (int j = 0; j < shop->count - i - 1; j++) {
            if (shop->products[j].id < shop->products[j + 1].id) {
                Product temp = shop->products[j];
                shop->products[j] = shop->products[j + 1];
                shop->products[j + 1] = temp;
            }
        }
    }
}
