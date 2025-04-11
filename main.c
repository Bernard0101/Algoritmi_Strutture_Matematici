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
    vettore *copia;

    costruire_vettore(&vetv, 3);
    costruire_vettore(&vetw, 3);

    stampare_vettore(&vetv);
    stampare_vettore(&vetw);

    normale=prodotto_incrociato_algebrico(&vetv, &vetw);
    copia=copiare_vettore(&vetw);

    angolo_tra_vettori(normale, copia, 1);
   

    dealocare_vettore(&vetv);
    dealocare_vettore(normale);
    dealocare_vettore(&vetw);



return 0;
}