#include <stdio.h>
#include <string.h>
#include <ctype.h>

// make string uppercase
void toUpperStr(char *str) {
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

// make string lowercase
void toLowerStr(char *str) {
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    // check args
    if (argc != 4) {
        printf("Usage: %s inputfile shortfile longfile\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        printf("could not open input file.\n");
        return 1;
    }

    FILE *shortFile = fopen(argv[2], "w");
    FILE *longFile = fopen(argv[3], "w");

    if (!shortFile || !longFile) {
        printf("error opening output files.\n");
        fclose(input);
        return 1;
    }

    char line[256];
    int shortCount = 0, longCount = 0;

    while (fgets(line, sizeof(line), input)) {
        line[strcspn(line, "\n")] = '\0';

        if (strlen(line) < 20) {
            toUpperStr(line);
            fprintf(shortFile, "%s\n", line);
            shortCount++;
        } else {
            toLowerStr(line);
            fprintf(longFile, "%s\n", line);
            longCount++;
        }
    }

    fclose(input);
    fclose(shortFile);
    fclose(longFile);

    printf("%d lines written to %s\n", shortCount, argv[2]);
    printf("%d lines written to %s\n", longCount, argv[3]);

    return 0;
}
