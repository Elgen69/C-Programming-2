#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


// Function to check if a recipe can be made with the available ingredients
int canMakeRecipe(Recipe recipe, IngredientNode* ingredients) {
    /* 6.) Write code to check if Recipe can be made using the available ingredients*/
    for (int i = 0; i < recipe.numIngredients; i++) {
        IngredientNode* current = ingredients;
        int found = 0;
        while (current != NULL) {
            if (strcmp(current->ingredient.name, recipe.ingredients[i].name) == 0) {
                if (current->ingredient.quantity >= recipe.ingredients[i].quantity) {
                    found = 1;
                    break;
                }
            }
            current = current->next;
        }
        if (!found) {
            return 0; // Missing an ingredient or not enough quantity
        }
    }
    return 1; // All ingredients available in sufficient quantity
}

int findRecipe(Recipe* recipeList,char* recipeName){
    /* 3.) Write the code to find the selected recipe */
    for (int i = 0; i < MAX_RECIPES; i++) {
        if (strcmp(recipeList[i].name, recipeName) == 0) {
            return i; // Return the index of the found recipe
        }
    }
    return -1; // Recipe not found
}

int main() {
    IngredientNode* ingredients = NULL;
    ingredients = populate();

    Recipe* recipes = populateRecipe();
    printf("\nRecipes:\n");
    printRecipes(recipes, MAX_RECIPES);

    // Ask user for recipe choice
    char recipeName[50];
    printf("\nEnter the name of the recipe you want to check: ");
    scanf(" %[^\n]s", recipeName);

    int recipeIndex = findRecipe(recipes, recipeName);

    // Display the Recipe and its Individual ingredients
    if (recipeIndex != -1) {
        Recipe foundRecipe = recipes[recipeIndex];
        printf("\nRecipe: %s\n", foundRecipe.name);
        for (int i = 0; i < foundRecipe.numIngredients; i++) {
            printf("  Ingredient: %s, Quantity: %d\n", foundRecipe.ingredients[i].name, foundRecipe.ingredients[i].quantity);
        }

        // Check if the recipe can be made with the available ingredients
        if (canMakeRecipe(foundRecipe, ingredients)) {
            printf("You have all the necessary ingredients to make this recipe.\n");
        } else {
            printf("You do not have enough ingredients to make this recipe.\n");
        }
    } else {
        printf("Recipe not found.\n");
    }

    return 0;
}
