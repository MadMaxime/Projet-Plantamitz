#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define L 25
#define C 45



char LettreAleatoire()
{
    int r = rand()%5; //on génère une valeur entre 0 et 4
    if (r==0)
    {
        return 'S'; //on associe la valeur 0 à un soleil puis on faitde même pour tous les symboles
    }
    if (r==1)
    {
        return 'F';
    }
    if (r==2)
    {
        return 'O';
    }
    if (r==3)
    {
        return 'P';
    }
    else
    {
        return 'M';
    }
}



void InitialisationTableau(char tab[25][45])
{
    int i,j;   //déclaration des variables
    for (i=0; i<L; i++)
    {
        for (j=0;j<C; j++) //On parcourt le tableau
        {
            tab[i][j] = LettreAleatoire(); // On assigne un item à une case du tableau
        }
    }
}

