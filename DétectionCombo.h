#include <stdio.h>
#include <stdlib.h>

#define N 25
#define M 45


// détection H vertical
int testHVertical(char tab[N][M], int i, int j)
{
    int extremiteG = j;                         // extrémité gauche de la barre horizontale
    int extremiteD = j;                         // extrémité droite de la barre horizontale
    int l = 0;                                  // longueur de la barre horizontale
    int hautG = i;                              // extrémité haut de la barre verticale gauche
    int basG = i;                               // extrémité bas de la barre verticale gauche
    int hautD = i;                              // extrémité haut de la barre verticale droite
    int basD = i;                               // extrémité bas de la barre verticale droite
    int hauteurG;                               // hauteur de la barre verticale gauche
    int hauteurD;                               // hauteur de la barre verticale droite

    // vérifier que la case n'est pas vide
    if (tab[i][j] == ' ')
    {
        return 0;
    }

    // barre horizontale
        // recherche des items identique à gauche
    while (extremiteG>0 && tab[i][extremiteG-1] == tab[i][j])
    {
        extremiteG--;
    }

        // recherche des items identique à droite
    while (extremiteD < M-1 && tab[i][extremiteD+1] == tab[i][j])
    {
        extremiteD++;
    }

    // longueur de la barre horizontale
    l = extremiteD - extremiteG + 1;
    if (l < 3)                              // sinon pas de H
    {
        return 0;
    }

    // colonnes verticales
        // Colonne gauche
            // recherche des items identique au dessus de l'extrémité gauche
    while (hautG>0 && tab[hautG-1][extremiteG] == tab[i][j])
    {
        hautG--;
    }

            // recherche des items identique en dessous de l'extrémité gauche
    while (basG < N-1 && tab[basG+1][extremiteG] == tab[i][j])
    {
        basG++;
    }

        // Colonne droite
            // recherche des items identique au dessus de l'extrémité droite
    while (hautD > 0 && tab[hautD-1][extremiteD] == tab[i][j])
    {
        hautD--;
    }

            // recherche des items identique en dessous de l'extrémité droite
    while (basD < N-1 && tab[basD+1][extremiteD] == tab[i][j])
    {
        basD++;
    }

    // longueur des hauteurs
    hauteurG = basG - hautG + 1;
    hauteurD = basD - hautD + 1;
    if (hauteurG < 3 || hauteurD < 3)           // sinon pas de H
    {
        return 0;
    }

    // Vérifier que la barre horizontale est au milieu
        // côté gauche
    if (i <= hautG || i >= basG)
    {
        return 0;
    }
        // côté droit
    if (i <= hautD || i >= basD)
    {
        return 0;
    }

    return 1;       // H détecté
}

// détection rectangle
int testRectangle(char tab[N][M], int i, int j)
{
    int L = 1;      // largeur
    int h = 1;      // hauteur
    int x;
    int y;

    // vérifier que la case n'est pas vide
    if (tab[i][j] == ' ')
    {
        return 0;
    }
    // trouver la largeur L
    while (j+L < M && tab[i][j] == tab[i][j+L])
    {
        L++;
    }
    if (L<2)        // pour avoir 2 colonnes
    {
        return 0;
    }

    // trouver la hauteur h
    while (i+h < N && tab[i][j] == tab[i+h][j])
    {
        h++;
    }
    if (h<2)      // pour avoir 2 lignes
    {
        return 0;
    }

    // vérification
    for (x=0; x<h; x++)
    {
        // si une ligne n'a pas les mêmes items → pas rectangle
        for (y=0; y<L; y++)
        {
            if (tab[i+x][j+y] != tab[i][j])
            {
                return 0;
            }
        }
    }
    return 1;       // rectangle détecté
}

// détection combo6
int testcombo6(char tab[N][M])
{
    int i;
    int j;

    // sur les lignes
    for (i=0; i<N; i++)
    {
        for (j=0; j<M-5; j++)
        {
            if (tab[i][j] != ' ' && tab[i][j] == tab[i][j+1] && tab[i][j] == tab[i][j+2] && tab[i][j] == tab[i][j+3] && tab[i][j] == tab[i][j+4] && tab[i][j] == tab[i][j+5])
            {
                return 1;
            }
        }
    }

    // sur les colonnes
    for (j=0; j<M; j++)
    {
        for (i=0; i<N-5; i++)
        {
            if (tab[i][j] != ' ' && tab[i][j] == tab[i+1][j] && tab[i][j] == tab[i+2][j] && tab[i][j] == tab[i+3][j] && tab[i][j] == tab[i+4][j] && tab[i][j] == tab[i+5][j])
            {
                return 1;
            }
        }
    }

    return 0;
}

// détection combo5
int testcombo5(char tab[N][M])
{
    int i;
    int j;

    // sur les lignes
    for (i=0; i<N; i++)
    {
        for (j=0; j<M-4; j++)
        {
            if (tab[i][j] != ' ' && tab[i][j] == tab[i][j+1] && tab[i][j] == tab[i][j+2] && tab[i][j] == tab[i][j+3] && tab[i][j] == tab[i][j+4])
            {
                return 1;
            }
        }
    }

    // sur les colonnes
    for (j=0; j<M; j++)
    {
        for (i=0; i<N-4; i++)
        {
            if (tab[i][j] != ' ' && tab[i][j] == tab[i+1][j] && tab[i][j] == tab[i+2][j] && tab[i][j] == tab[i+3][j] && tab[i][j] == tab[i+4][j])
            {
                return 1;
            }
        }
    }

    return 0;
}

// détection combo4
int testcombo4(char tab[N][M])
{
    int i;
    int j;

    // sur les lignes
    for (i=0; i<N; i++)
    {
        for (j=0; j<M-3; j++)
        {
            if (tab[i][j] != ' ' && tab[i][j] == tab[i][j+1] && tab[i][j] == tab[i][j+2] && tab[i][j] == tab[i][j+3])
            {
                return 1;
            }
        }
    }

    // sur les colonnes
    for (j=0; j<M; j++)
    {
        for (i=0; i<N-3; i++)
        {
            if (tab[i][j] != ' ' && tab[i][j] == tab[i+1][j] && tab[i][j] == tab[i+2][j] && tab[i][j] == tab[i+3][j])
            {
                return 1;
            }
        }
    }

    return 0;
}

// détection combo3
int testcombo3(char tab[N][M])
{
    int i;
    int j;

    // sur les lignes
    for (i=0; i<N; i++)
    {
        for (j=0; j<M-2; j++)
        {
            if (tab[i][j] != ' ' && tab[i][j] == tab[i][j+1] && tab[i][j] == tab[i][j+2])
            {
                return 1;
            }
        }
    }

    // sur les colonnes
    for (j=0; j<M; j++)
    {
        for (i=0; i<N-2; i++)
        {
            if (tab[i][j] != ' ' && tab[i][j] == tab[i+1][j] && tab[i][j] == tab[i+2][j])
            {
                return 1;
            }
        }
    }

    return 0;
}
