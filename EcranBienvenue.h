#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

typedef struct {
    char nom[50];
    int niveau;
    int vies;
} Joueur;

void ecranBienvenue(Joueur *joueur);
