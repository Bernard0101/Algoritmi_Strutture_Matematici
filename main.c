#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Vettore.h"
#include "Matrice.h"

int main(void){
    srand(time(NULL));

    vettore vetv;
    vettore vetw;

    costruire_vettore_random(&vetv, 3);
    costruire_vettore_random(&vetw, 3);

    stampare_vettore(&vetv);
    stampare_vettore(&vetw);

    equazione_vettoriale(&vetv, &vetw);
    equazione_parametrica(&vetv, &vetw);

    dealocare_vettore(&vetv);
    dealocare_vettore(&vetw);


return 0;
}