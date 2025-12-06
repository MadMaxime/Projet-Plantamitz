#include <stdio.h>
#include <windows.h

typedef struct {
    int soleils;
    int fraises;
    int pommes;
    int oignons;
    int mandarines;
    int coupsMax;
} Contrat;

void afficherContrat(Contrat contrat, Contrat progression) {
    gotoligcol(0, 50);
    Color(15, 0);
    printf("%c%c%c CONTRAT %c%c%c", 0xC9, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);

    gotoligcol(1, 50);
    if (contrat.soleils > 0) {
        Color(14, 0);
        printf("S:");
        Color(15, 0);
        printf(" %d/%d  ", progression.soleils, contrat.soleils);
    }

    gotoligcol(2, 50);
    if (contrat.fraises > 0) {
        Color(12, 0);
        printf("F:");
        Color(15, 0);
        printf(" %d/%d  ", progression.fraises, contrat.fraises);
    }

    gotoligcol(3, 50);
    if (contrat.pommes > 0) {
        Color(10, 0);
        printf("P:");
        Color(15, 0);
        printf(" %d/%d  ", progression.pommes, contrat.pommes);
    }

    gotoligcol(4, 50);
    if (contrat.oignons > 0) {
        Color(13, 0);
        printf("O:");
        Color(15, 0);
        printf(" %d/%d  ", progression.oignons, contrat.oignons);
    }

    gotoligcol(5, 50);
    if (contrat.mandarines > 0) {
        Color(6, 0);
        printf("M:");
        Color(15, 0);
        printf(" %d/%d  ", progression.mandarines, contrat.mandarines);
    }

    gotoligcol(7, 50);
    Color(11, 0);
    printf("Coups: %d/%d", contrat.coupsMax - progression.coupsMax, contrat.coupsMax);

    Color(15, 0);
}
