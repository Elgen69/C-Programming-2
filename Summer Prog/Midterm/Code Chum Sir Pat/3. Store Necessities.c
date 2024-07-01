#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definitions

typedef struct {
    int month;
    int year;
} date;

typedef struct {
    char productName[50];
    float price;
    date expiryDate;
    int quantity;
} productInfo;

typedef struct {
    productInfo *product;
    float inventoryCost;
    int inventoryCount;
} inventory;

typedef struct {
    inventory currentInventory;
    inventory expiredInventory;
} storeInventory;

// Function prototypes

void addInitialInventory(inventory *inv);
productInfo addProductInfo(char name[], float price, date expiry, int quantity);
date addDate(int month, int year);
void display(storeInventory store, int mode);
void expiredProductRemoval(storeInventory *store, date currentDate);

// Function implementations

void addInitialInventory(inventory *inv) {
    // Example initial inventory setup
    inv->product = malloc(10 * sizeof(productInfo)); // Allocating memory for 10 products
    inv->inventoryCost = 0.0;
    inv->inventoryCount = 0;

    // Adding some initial products (example)
    inv->product[inv->inventoryCount++] = addProductInfo("Milk", 100.00, addDate(3, 2024), 8);
    inv->product[inv->inventoryCount++] = addProductInfo("Chicken", 250.00, addDate(7, 2024), 4);
    inv->product[inv->inventoryCount++] = addProductInfo("Oil", 80.50, addDate(10, 2024), 4);
    inv->product[inv->inventoryCount++] = addProductInfo("Beef", 230.75, addDate(3, 2024), 3);
    inv->product[inv->inventoryCount++] = addProductInfo("Pork", 200.50, addDate(2, 2024), 5);
    inv->product[inv->inventoryCount++] = addProductInfo("Ketchup", 110.85, addDate(6, 2024), 8);
    inv->product[inv->inventoryCount++] = addProductInfo("Soda", 89.50, addDate(9, 2024), 10);
    inv->product[inv->inventoryCount++] = addProductInfo("Beer", 120.00, addDate(1, 2025), 10);
    inv->product[inv->inventoryCount++] = addProductInfo("Bottled Water", 50.00, addDate(2, 2025), 30);
    inv->product[inv->inventoryCount++] = addProductInfo("Salad Dressing", 125.50, addDate(3, 2024), 9);

    // Calculate initial inventory cost
    for (int i = 0; i < inv->inventoryCount; ++i) {
        inv->inventoryCost += inv->product[i].price * inv->product[i].quantity;
    }
}

productInfo addProductInfo(char name[], float price, date expiry, int quantity) {
    productInfo info;
    strcpy(info.productName, name);
    info.price = price;
    info.expiryDate = expiry;
    info.quantity = quantity;
    return info;
}

date addDate(int month, int year) {
    date d;
    d.month = month;
    d.year = year;
    return d;
}

void display(storeInventory store, int mode) {
    switch (mode) {
        case 1:
            printf("\n=====ITEMS LIST======\n");
            printf("PRODUCT NAME               UNIT PRICE            QUANTITY         EXPIRY DATE\n");
            printf("------------               ----------            --------         -----------\n");

            for (int i = 0; i < store.currentInventory.inventoryCount; i++) {
                printf("%-30s%-22.2f%-17d%d/%d\n", store.currentInventory.product[i].productName, store.currentInventory.product[i].price, store.currentInventory.product[i].quantity, store.currentInventory.product[i].expiryDate.month, store.currentInventory.product[i].expiryDate.year);
            }

            printf("\nInventory Value: %.2f\n", store.currentInventory.inventoryCost);
            break;

        case 2:
            printf("\n=====ITEM LIST AFTER EXPIRED REMOVAL======\n");
            printf("PRODUCT NAME               UNIT PRICE            QUANTITY         EXPIRY DATE\n");
            printf("------------               ----------            --------         -----------\n");

            for (int i = 0; i < store.currentInventory.inventoryCount; i++) {
                printf("%-30s%-22.2f%-17d%d/%d\n", store.currentInventory.product[i].productName, store.currentInventory.product[i].price, store.currentInventory.product[i].quantity, store.currentInventory.product[i].expiryDate.month, store.currentInventory.product[i].expiryDate.year);
            }

            printf("\nInventory Value: %.2f\n", store.currentInventory.inventoryCost);
            break;

        default:
            printf("Invalid mode. Please provide 1 or 2.\n");
            break;
    }
}

void expiredProductRemoval(storeInventory *store, date currentDate) {
    int i, j;
    float lossValue = 0.0;

    // Display original inventory before removal
    display(*store, 1);

    // Move expired items from currentInventory to expiredInventory
    for (i = 0; i < store->currentInventory.inventoryCount; i++) {
        if (store->currentInventory.product[i].expiryDate.year < currentDate.year ||
            (store->currentInventory.product[i].expiryDate.year == currentDate.year &&
             store->currentInventory.product[i].expiryDate.month <= currentDate.month)) {
            
            // Move to expiredInventory
            store->expiredInventory.product[store->expiredInventory.inventoryCount] = store->currentInventory.product[i];
            store->expiredInventory.inventoryCount++;
            lossValue += store->currentInventory.product[i].price * store->currentInventory.product[i].quantity;

            // Remove from currentInventory by shifting remaining items
            for (j = i; j < store->currentInventory.inventoryCount - 1; j++) {
                store->currentInventory.product[j] = store->currentInventory.product[j + 1];
            }
            store->currentInventory.inventoryCount--;
            i--; // Adjust index since we removed an item
        }
    }

    // Update inventory cost
    store->currentInventory.inventoryCost -= lossValue;

    // Display updated inventory after removal
    display(*store, 2);

    // Display final list of expired items if any were moved
    if (lossValue > 0.0) {
        printf("\n=====ITEMS IN EXPIRED LIST AFTER REMOVAL======\n");
        printf("PRODUCT NAME               UNIT PRICE            QUANTITY         EXPIRY DATE\n");
        printf("------------               ----------            --------         -----------\n");

        for (int k = 0; k < store->expiredInventory.inventoryCount; k++) {
            printf("%-30s%-22.2f%-17d%d/%d\n", store->expiredInventory.product[k].productName, store->expiredInventory.product[k].price, store->expiredInventory.product[k].quantity, store->expiredInventory.product[k].expiryDate.month, store->expiredInventory.product[k].expiryDate.year);
        }
    }

    printf("\nLoss Value: %.2f\n", lossValue);
}


int main() {
    storeInventory store;
    date currentDate;

    store.expiredInventory.product = malloc(10 * sizeof(productInfo)); // Allocating memory for expiredInventory
    store.expiredInventory.inventoryCount = 0;
    store.expiredInventory.inventoryCost = 0;

    printf("Input Current Month: ");
    scanf("%d", &currentDate.month);
    printf("Input Current Year: ");
    scanf("%d", &currentDate.year);

    addInitialInventory(&store.currentInventory);

    expiredProductRemoval(&store, currentDate);

    return 0;
}
