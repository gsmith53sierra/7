#include <stdio.h>
#include <string.h>

// asks for color, snack, and animal and makes silly band names
int main() {
    char color[101], snack[101], animal[101];
    char band1[256], band2[256], band3[256];

    // get user input
    printf("Enter your favorite color: ");
    fgets(color, sizeof(color), stdin);
    color[strcspn(color, "\n")] = '\0'; // remove newline

    printf("Enter your favorite snack: ");
    fgets(snack, sizeof(snack), stdin);
    snack[strcspn(snack, "\n")] = '\0';

    printf("Enter your favorite animal: ");
    fgets(animal, sizeof(animal), stdin);
    animal[strcspn(animal, "\n")] = '\0';

    // build "The Color Snack"
    strcpy(band1, "The ");
    strcat(band1, color);
    strcat(band1, " ");
    strcat(band1, snack);

    // build "The Color Animal"
    strcpy(band2, "The ");
    strcat(band2, color);
    strcat(band2, " ");
    strcat(band2, animal);

    // build snack+animal combo
    char combo[10] = "";
    strncat(combo, snack, 3);  // first 3 letters of snack
    strncat(combo, animal, 2); // first 2 letters of animal
    strcat(combo, "s");        // add 's'

    strcpy(band3, "The ");
    strcat(band3, combo);

    // print results with flair
    printf("\nPresenting ... %s!\n", band1);
    printf("Tonight only ... %s!\n", band2);
    printf("Get ready for ... %s!\n", band3);

    return 0;
}
