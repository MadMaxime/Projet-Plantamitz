#include <stdio.h>
#include <time.h>

typedef struct {
    int tempsMax;
    time_t debut;
    int tempsRestant;
} Chrono;

void initialiserChrono(Chrono *chrono, int tempsMax) {
    chrono->tempsMax = tempsMax;
    chrono->debut = time(NULL);
    chrono->tempsRestant = tempsMax;
}
