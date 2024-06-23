#include <stdio.h>
#include <stdlib.h>

void disp(int*, int*, float*, char**);
void update_stock(int*, int*, int, int);
void change_price(int*, float*, float, int);
void add_cart(int*, int*, int, float*, int, int*, float*, char**);
void remove_cart(int*, int*, int, float*, int, int*, float*, char**);
void view_cart(int*, float*, char**);
void check_out(float*);

int main(void) {
    char* product[5] = {"Milk Chocolate", "Dark Chocolate", "Mint Chocolate", "White Chocolate", "Pean Chocolate"};
    int opt = 0, temp_id = 0, temp_quant = 0;
    int* name_id = malloc(5 * sizeof(int));
    int* quantity = malloc(5 * sizeof(int));
    float* price = malloc(5 * sizeof(float));
    float temp_price;

    // Cart arrays
    int* cart_quantity = malloc(100 * sizeof(int));
    float* cart_price = malloc(100 * sizeof(float));

    for (int i = 0; i < 5; i++) {
        *(name_id + i) = i + 1;
        switch (i) {
            case 0:
                *(quantity + i) = 60;
                *(price + i) = 12.00;
                break;
            case 1:
                *(quantity + i) = 42;
                *(price + i) = 25.00;
                break;
            case 2:
                *(quantity + i) = 29;
                *(price + i) = 20.00;
                break;
            case 3:
                *(quantity + i) = 60;
                *(price + i) = 15.00;
                break;
            case 4:
                *(quantity + i) = 38;
                *(price + i) = 8.00;
                break;
        }
    }

    printf("Type in number of option, 0 to end: \n");
    printf("1. Display Stock: \n");
    printf("2. Update Stock: \n");
    printf("3. Change Price: \n");
    printf("4. Add to Cart \n");
    printf("5. Remove from Cart \n");
    printf("6. View Cart \n");
    printf("7. Check Out \n\n");

    do {
        scanf("%i", &opt);
        switch (opt) {
            case 1:
                disp(name_id, quantity, price, product);
                break;
            case 2:
                printf("\nEnter ID and quantity to change: ");
                scanf("%d %d", &temp_id, &temp_quant);
                if (temp_quant <= 0 || temp_id > 5 || temp_id < 1) {
                    printf("Invalid input.\n");
                } else {
                    update_stock(name_id, quantity, temp_quant, temp_id);
                }
                break;
            case 3:
                printf("\nEnter ID and price to change: ");
                scanf("%d %f", &temp_id, &temp_price);
                if (temp_price <= 0 || temp_id > 5 || temp_id < 1) {
                    printf("Invalid input.\n");
                } else {
                    change_price(name_id, price, temp_price, temp_id);
                }
                break;
            case 4:
                printf("\nEnter ID to add to cart and how many: ");
                scanf("%d %d", &temp_id, &temp_quant);
                add_cart(name_id, quantity, temp_id, price, temp_quant, cart_quantity, cart_price, product);
                break;
            case 5:
                printf("\nEnter ID to remove from cart and how many: ");
                scanf("%d %d", &temp_id, &temp_quant);
                remove_cart(name_id, quantity, temp_id, price, temp_quant, cart_quantity, cart_price, product);
                break;
            case 6:
                view_cart(cart_quantity, cart_price, product);
                break;
            case 7:
                check_out(cart_price);
                break;
            default:
                if (opt != 0) {
                    printf("Invalid option.\n");
                }
                break;
        }
    } while (opt != 0);

    free(name_id);
    free(quantity);
    free(price);
    free(cart_quantity);
    free(cart_price);
    return 0;
}
void disp(int* name_id, int* quantity, float* price, char** product) {
    printf("Name\t\t\tQuantity\tPrice\n");
    for (int i = 0; i < 5; i++) {
        printf("%-15s\t\t%d\t\t%.2f\n", *(product+i), *(quantity+i), *(price+i));
    }
}
void update_stock(int* id, int* quantity, int new_quantity, int temp) {
    for (int i = 0; i < 5; i++) {
        if (*(id + i) == temp) {
            *(quantity + i) = new_quantity;
        }
    }
}

void change_price(int* id, float* price, float new_price, int temp) {
    for (int i = 0; i < 5; i++) {
        if (*(id + i) == temp) {
            *(price + i) = new_price;
        }
    }
}

void add_cart(int* name_id, int* quantity, int temp, float* price, int temp_quant, int* cart_quantity, float* cart_price, char** product) {
    for (int i = 0; i < 5; i++) {
        if (*(name_id + i) == temp) {  // Check if the current product ID matches the input ID
            if (*(quantity + i) >= temp_quant) {  // Check if there is enough stock
                *(quantity + i) -= temp_quant;  // Deduct the requested quantity from stock
                *(cart_quantity + temp - 1) += temp_quant;  // Add the requested quantity to the cart
                *(cart_price + temp - 1) += *(price + i) * temp_quant;  // Update the total price for this product in the cart
                printf("%d %s added to cart.\n", temp_quant,*(product+i));  
            } else {
                printf("Not enough stock available.\n"); 
            }
        }
    }
}

void remove_cart(int* name_id, int* quantity, int temp, float* price, int temp_quant, int* cart_quantity, float* cart_price, char** product) {
    for (int i = 0; i < 5; i++) {
        if (*(name_id + i) == temp) {
            if (*(cart_quantity + temp - 1) >= temp_quant) {
                *(quantity + i) += temp_quant;
                *(cart_quantity + temp - 1) -= temp_quant; 
                *(cart_price + temp - 1) -= (*(price + i) * temp_quant);  
                printf("%d %s removed from cart.\n", temp_quant, *(product+i));
            } else {
                printf("Not enough items in cart to remove.\n");
            }
        }
    }
}

void view_cart(int* cart_quantity, float* cart_price, char** product) {
    printf("Cart:\n");
    printf("Name\t\t\tQuantity\tTotal Price\n");
    for (int i = 0; i < 5; i++) {
        if (*(cart_quantity + i) > 0) {
            printf("%-15s\t\t%d\t\t%.2f\n", *(product+i), *(cart_quantity + i), *(cart_price + i));
        }
    }
}

void check_out(float* cart_price) {
    float total = 0;
    for (int i = 0; i < 5; i++) {
        total += *(cart_price + i);
    }
    printf("Total price: %.2f\n", total);
}
