#include "utilitaire.h"

void ClearScreen() {
    printf("\033[2J\033[H");
}


void DisplayMenu(char *title, char *options[], int n) {

    ClearScreen();

    printf("========================================\n");
    printf("   %s\n", title);
    printf("========================================\n");

    for (int i = 0; i < n; i++) {
        printf("  %d. %s\n", i + 1, options[i]);
    }

    printf("========================================\n");
    printf("Your choice : ");
}

int GetIntInput(int min, int max) {

    int val;

    while (scanf("%d", &val) != 1 || val < min || val > max) {
        printf("Invalid value. Enter a number between %d and %d : ", min, max);

    
        while (getchar() != '\n');
    }

    while (getchar() != '\n');

    return val;
}

void GetStringInput(char *buf, int size) {


    fgets(buf, size, stdin);

    buf[strcspn(buf, "\n")] = '\0';
}