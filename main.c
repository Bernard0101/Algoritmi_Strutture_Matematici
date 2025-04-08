#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Vettore.h"
#include "Matrice.h"

int main(void){
    srand(time(NULL));

    vettore vetv;
    vettore vetw;
    vettore *normale;

    costruire_vettore(&vetv, 3);
    costruire_vettore(&vetw, 3);

    stampare_vettore(&vetv);
    stampare_vettore(&vetw);

    normale=prodotto_incrociato_algebrico(&vetv, &vetw);
    proiezione_ortogonale(&vetv, &vetw);

    angolo_tra_vettori(normale, &vetw, 1);
   

    dealocare_vettore(&vetv);
    dealocare_vettore(normale);
    dealocare_vettore(&vetw);


return 0;
}