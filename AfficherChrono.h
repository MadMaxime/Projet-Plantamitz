#include <stdio.h>
#include <time.h>
#include <windows.h>

typedef struct {
    int tempsMax;
    time_t debut;
    int tempsRestant;
}Chrono;

void afficherChrono(Chrono *chrono);
