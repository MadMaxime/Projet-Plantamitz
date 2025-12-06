#include <stdio.h>
#include <windows.h>
#define LIGNES 25
#define COLONNES 45

void afficherTableau(char tableau[LIGNES][COLONNES]) {
    gotoligcol(3, 0);

    // Bordure supérieure
    Color(15, 0);
    printf("%c", 0xC9); // Coin supérieur gauche
    for (int j = 0; j < COLONNES; j++) {
        printf("%c", 0xCD); // Ligne horizontale
    }
    printf("%c\n", 0xBB); // Coin supérieur droit

    // Affichage du tableau avec bordures
    for (int i = 0; i < LIGNES; i++) {
        Color(15, 0);
        printf("%c", 0xBA); // Bordure verticale gauche

        for (int j = 0; j < COLONNES; j++) {
            afficherItem(tableau[i][j]);
        }

        Color(15, 0);
        printf("%c\n", 0xBA); // Bordure verticale droite
    }

    // Bordure inférieure
    Color(15, 0);
    printf("%c", 0xC8); // Coin inférieur gauche
    for (int j = 0; j < COLONNES; j++) {
        printf("%c", 0xCD); // Ligne horizontale
    }
    printf("%c\n", 0xBC); // Coin inférieur droit
}
