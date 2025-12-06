#include <stdio.h>
#include <time.h>
#include <windows.h>

typedef struct {
    int tempsMax;
    time_t debut;
    int tempsRestant;
}Chrono;

void afficherChrono(Chrono *chrono) {
    time_t maintenant = time(NULL);
    int ecoule = (int)difftime(maintenant, chrono->debut);
    chrono->tempsRestant = chrono->tempsMax - ecoule;

    if (chrono->tempsRestant < 0) {
        chrono->tempsRestant = 0;
    }

    int minutes = chrono->tempsRestant / 60;
    int secondes = chrono->tempsRestant % 60;

    gotoligcol(9, 50);
    Color(15, 0);
    printf("%c%c%c TEMPS %c%c%c", 0xC9, 0xCD, 0xCD, 0xCD, 0xCD, 0xBB);

    gotoligcol(10, 50);
    if (chrono->tempsRestant < 30) {
        Color(12, 0); // Rouge si moins de 30 secondes
    } else {
        Color(10, 0); // Vert sinon
    }
    printf("  %02d:%02d  ", minutes, secondes);
    Color(15, 0);
}
