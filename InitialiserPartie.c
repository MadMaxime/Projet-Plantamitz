#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Initialisation.h"


int difficulte()
{
    int a;
    printf("Choisissez une difficulté : \n1.Facile\2.Moyen\n3.Difficile");
    scanf("%d",&a);
    if (a != 1 || a!=2 || a!=3)
    {
        printf("Choix non valide");
        return 4;
    }
    return a;
}


void GenererContrat(Contrat *p, int d)
{
    if (difficulte == 1)
    {
        p->fraise = rand()%12;
        p->oignon = rand()%12;
        p->soleil = rand()%12;
        p->coupmax = 30;
    }
    if (difficulte == 2)
    {
        p->fraise = rand()%12;
        p->oignon = rand()%12;
        p->soleil = rand()%12;
        p->pomme = rand()%12;
        p->mandarine= rand()%12;
        p->coupmax = 40;
    }
    if (difficulte == 3)
    {
        p->fraise = rand()%12;
        p->oignon = rand()%25;
        p->soleil = rand()%23;
        p->pomme = rand()%28;
        p->mandarine= rand()%30;
        p->coupmax = 40;
    }
}

void verificationInit()
{
    if (DetectionCombo())
    {
        InitialisationTableau(tab[25][45]);
    }
}


void InitialisationPartie()
{
    int d;
    Contrat p;
    d = difficulte();
    GenererContrat(&p, d);
    InitialisationTableau(tab[25][45]);
    verificationInit;
}
