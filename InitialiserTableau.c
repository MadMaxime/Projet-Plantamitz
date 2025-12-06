#include <stdio.h>
#include <stdlib.h>
#define LIGNES 25
#define COLONNES 45
#define SOLEIL 'S'
#define FRAISE 'F'
#define POMME 'P'
#define OIGNON 'O'
#define MANDARINE 'M'

void initialiserTableau(char tableau[LIGNES][COLONNES]) {
    int valide = 0;

    // Générer jusqu'à obtenir un tableau sans groupe de 3+
    while (!valide) {
        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLONNES; j++) {
                tableau[i][j] = genererItemAleatoire();
            }
        }
        valide = verifierAucunGroupeInitial(tableau);
    }
}
