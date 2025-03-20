#include <stdio.h>
#include <stdlib.h>

#include "Vettore.h"
#include "Matrice.h"

int main(void){

    vettore vet1;
    vettore vet2;

    costruire_vettore_random(&vet1, 3);
    costruire_vettore_random(&vet2, 3);

    stampare_vettore(&vet1);
    stampare_vettore(&vet2);

    prodotto_incrociato_algebrico(&vet1, &vet2);

    dealocare_vettore(&vet1);
    dealocare_vettore(&vet2);


return 0;
}