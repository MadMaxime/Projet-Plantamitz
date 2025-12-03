#include <stdio.h>
#include <stdlib.h>

#define N 25
#define M 45


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
    if (L<2)        // pas de rectangle sinon
    {
        return 0;
    }

    // trouver la hauteur h
    while (i+h < N && tab[i][j] == tab[i+h][j])
    {
        h++;
    }
    if (h < 2)      // pas de rectangle sinon
    {
        return 0;
    }

    // vérification
    for (x=0; x<h; x++)
    {
        // si une ligne n'a pas toutes les cases identiques → pas rectangle
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




// Détection Combos
int DetectionCombo(char tab[N][M])
{
    int i;
    int j;

}
