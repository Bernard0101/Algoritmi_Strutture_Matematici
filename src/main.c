#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Vettore.h"
#include "Matrice.h"
#include "Sistema_lineare.h"

int main(void){
    srand(time(NULL));

    vettore vetAB;
    vettore vetAC;
    vettore *ProdottoAB_AC;
    float magnitudine;
    float risultato;
    

    costruire_vettore(&vetAB, 3);
    stampare_vettore(&vetAB);

    costruire_vettore(&vetAC, 3);
    stampare_vettore(&vetAC);
    
    ProdottoAB_AC=prodotto_incrociato_algebrico(&vetAB, &vetAC);
    stampare_vettore(ProdottoAB_AC);
    
    magnitude_vettore(ProdottoAB_AC, 1);

    dealocare_vettore(&ProdottoAB_AC);
    dealocare_vettore(&vetAB);
    dealocare_vettore(&vetAC);



return 0;
}