#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Vettore.h"
#include "Matrice.h"

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
    

    equazione_parametrica(&vetAB, &vetAC);

    
    dealocare_vettore(&vetAB);
    dealocare_vettore(ProdottoAB_AC);
    dealocare_vettore(&vetAC);



return 0;
}