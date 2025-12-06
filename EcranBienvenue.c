#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#define LIGNES 25
#define COLONNES 45
#define SOLEIL 'S'
#define FRAISE 'F'
#define POMME 'P'
#define OIGNON 'O'
#define MANDARINE 'M'

typedef struct {
    char nom[50];
    int niveau;
    int vies;
} Joueur;

void ecranBienvenue(Joueur *joueur) {
    system("cls");

    // Titre avec bordure
    Color(14, 0);
    printf("\n\n");
    printf("        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
           0xC9, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,
           0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,
           0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);

    Color(10, 0);
    printf("        %c                                              %c\n", 0xBA, 0xBA);
    printf("        %c          BIENVENUE DANS PLANTAMITZ           %c\n", 0xBA, 0xBA);
    printf("        %c                    2025                      %c\n", 0xBA, 0xBA);
    printf("        %c                                              %c\n", 0xBA, 0xBA);

    Color(14, 0);
    printf("        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
           0xC8, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,
           0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD,
           0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xBC);

    printf("\n\n");

    // Affichage des items du jeu avec leurs couleurs
    Color(15, 0);
    printf("                Items du jeu : ");
    Color(14, 0);
    printf("S");
    Color(15, 0);
    printf("(Soleil) ");
    Color(12, 0);
    printf("F");
    Color(15, 0);
    printf("(Fraise) ");
    Color(10, 0);
    printf("P");
    Color(15, 0);
    printf("(Pomme) ");
    Color(13, 0);
    printf("O");
    Color(15, 0);
    printf("(Oignon) ");
    Color(6, 0);
    printf("M");
    Color(15, 0);
    printf("(Mandarine)\n\n");

    // Objectif du jeu
    Color(11, 0);
    printf("                %c%c%c OBJECTIF %c%c%c\n", 0xC9, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);
    Color(15, 0);
    printf("        Alignez 3 items ou plus pour les faire disparaitre\n");
    printf("        Remplissez votre contrat avant la fin du temps imparti\n");
    printf("        Vous disposez de 5 vies pour progresser dans le jeu\n\n\n");

    // Demande du nom
    Color(10, 0);
    printf("        %c", 0xC9);
    for (int i = 0; i < 46; i++) printf("%c", 0xCD);
    printf("%c\n", 0xBB);

    Color(15, 0);
    printf("        %c                                              %c\n", 0xBA, 0xBA);
    printf("        %c  ", 0xBA);
    Color(14, 0);
    printf("Entrez votre nom de joueur : ");
    Color(15, 0);

    // Lecture du nom avec gestion du buffer
    if (fgets(joueur->nom, sizeof(joueur->nom), stdin) != NULL) {
        // Supprimer le '\n' à la fin si présent
        size_t len = strlen(joueur->nom);
        if (len > 0 && joueur->nom[len-1] == '\n') {
            joueur->nom[len-1] = '\0';
        }
    }

    // Si le nom est vide, mettre un nom par défaut
    if (strlen(joueur->nom) == 0) {
        strcpy(joueur->nom, "Joueur");
    }

    printf("            %c\n", 0xBA);
    printf("        %c                                              %c\n", 0xBA, 0xBA);
    Color(10, 0);
    printf("        %c", 0xC8);
    for (int i = 0; i < 46; i++) printf("%c", 0xCD);
    printf("%c\n", 0xBC);

    printf("\n\n");
    Color(11, 0);
    printf("                Bonjour ");
    Color(14, 0);
    printf("%s", joueur->nom);
    Color(11, 0);
    printf(" ! Bonne chance !");
    Color(15, 0);

    // Initialiser le niveau et les vies
    joueur->niveau = 1;
    joueur->vies = 5;

    printf("\n\n\n");
    Color(15, 0);
    printf("                Appuyez sur une touche pour commencer...");
    _getch();
}
