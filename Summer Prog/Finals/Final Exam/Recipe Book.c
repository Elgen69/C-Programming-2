// USE HAMBURGER CODE!
// Function to check if a recipe can be made with the available ingredients
int canMakeRecipe(Recipe recipe, IngredientNode* ingredients) {
    /* 6.) Write code to check if Recipe can be made using the available ingredients*/
    for (int i = 0; i < recipe.numIngredients; i++) 
    {
        IngredientNode* current = ingredients;
        int found = 0;
        while (current != NULL) 
        {
            if (strcmp(current->ingredient.name, recipe.ingredients[i].name) == 0) 
            {
                if (current->ingredient.quantity >= recipe.ingredients[i].quantity) 
                {
                    found = 1;
                    break;
                }
            }
            current = current->next;
        }
        if (!found) 
        {
            return 0; // Missing an ingredient or not enough quantity
        }
    }
    return 1; // All ingredients available in sufficient quantity
}

int findRecipe(Recipe* recipeList,char* recipeName)
{
    /* 3.) Write the code to find the selected recipe */
    for (int i = 0; i < MAX_RECIPES; i++) 
    {
        if (strcmp(recipeList[i].name, recipeName) == 0) 
        {
            return i; // Return the index of the found recipe
        }
    }
    return -1; // Recipe not found
}
