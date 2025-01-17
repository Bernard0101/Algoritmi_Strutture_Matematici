#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "Algoritmi_Vettore.h"

void cosutruire_vettore(vettore *vetPtr, int n){
    vetPtr->size=n;
    vetPtr->vet=(float *)malloc(n * sizeof(float));

    printf("digita i valori del vettore");
    for(int i=0; i < n; i++){
        int num=0;
        printf("posizione %d: ", i);
        scanf("%d", &num);
        *(vetPtr->vet + i)=num;
    }
}