#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "Vettore.h"
#include "Matrice.h"

//l'utente costroi un vettore matematico di dimensione n
void costruire_vettore(vettore *vetPtr, int n){
    vetPtr->size=n;
    vetPtr->vet=(float *)malloc(n * sizeof(float));

    printf("digita i valori del vettore:\n\n");
    for(int i=0; i < n; i++){
        float num=0;
        printf("posizione %d: ", i);
        scanf("%f", &num);
        *(vetPtr->vet + i)=num;
    }
}

//costruisce un vettore ranodomico di dimensione n
void costruire_vettore_random(vettore *vetPtr, int n){
    vetPtr->size=n;
    vetPtr->vet=(float *)malloc(n * sizeof(float));

    for(int i=0; i < n; i++){
        float num=rand() % 100;
        *(vetPtr->vet + i)=num;
    }
}

//costruisce un vettore tra due punti
void costruire_vettore_dapunti(vettore *vetPtr, int n){
    vetPtr->size=n;
    vetPtr->vet=(float *)malloc(n * sizeof(float));
    
    printf("inserisce le coordinate dei punti");
    for(int i=0; i < n; i++){
        int punto1, punto2;
        printf("coordinata %d punto 1: ", i);
        scanf("%d", &punto1);
        printf("coordinata %d punto 2: ", i);
        scanf("%d", &punto2);

        int fattore=punto2-punto1;
        *(vetPtr->vet + i)=fattore;
    }
      
}

//stampa il vettore con n elementi
void stampare_vettore(vettore *vetPtr){
    printf("\n[");
    for(int i=0; i < vetPtr->size; i++){
        printf("%.2f,", *(vetPtr->vet + i));
    }
    printf("]");
}

//somma un vettore con altro 
void sommare_vettore(vettore *vetPtr, vettore *vetSum, int show){
    if(vetPtr->size == vetSum->size){
        for(int i=0; i < vetPtr->size; i++){
            *(vetPtr->vet + i) += *(vetSum->vet + i);
        }
        if(show){
            stampare_vettore(vetPtr);
        }
    }
    else{
        printf("\nERRORE: dimensioni dei vettori diversa");
        exit(1);
    }
}

//sotrai un vettore sull'altro
void sotrarre_vettore(vettore *vetPtr, vettore *vetSub, int show){
    if(vetPtr->size == vetSub->size){
        for(int i=0; i < vetPtr->size; i++){
            *(vetPtr->vet + i) -= *(vetSub->vet + i);
        }
        if(show){
            stampare_vettore(vetPtr);
        }
    }
    else{
        printf("\nERRORE: dimensioni dei vettori diversa");
        exit(1);
    }
}

//moltiplica un vettore con altro
float prodotto_scalare_algebrico(vettore *vetPtr, vettore *vetMul, int show){
    if(vetPtr->size == vetMul->size){
        float somma=0.0;
        for(int i=0; i < vetPtr->size; i++){
            somma += *(vetPtr->vet + i) * *(vetMul->vet + i);
        }
        if(show){
            printf("\nprodotto scalare formula algebrica: %.2f\n", somma);
        }
        return somma;
    }
    else{
        printf("\nERRORE: dimensioni dei vettori diversa");
        exit(1);
    }
}

float prodotto_scalare_geometrico(vettore *vetPtrv, vettore *vetPtrw, int theta, int show){
    if(vetPtrv->size == vetPtrw->size){
        float magnitude_v=magnitude_vettore(vetPtrv, 0);
        float magnitude_w=magnitude_vettore(vetPtrw, 0);
        float result=magnitude_v * magnitude_w * cos(theta);
        if(show){
            printf("\nprodotto scalare formula geometrica: %f\n", result);
        }
        return result;
    }
}

vettore *prodotto_incrociato_algebrico(vettore *vetPtr, vettore *vetMul){
    if(vetPtr->size == vetMul->size && vetPtr->size > 2){
        
        //dichiarazione e allocazione delle variabile e strutture
        vettore *normale = (vettore *)malloc(sizeof(vettore));
        normale->size = 3;
        normale->vet = (float *)malloc(3 * sizeof(float));
        matrice mat1, mat2, mat3;
        float det1, det2, det3;

        //costruzione delle matrici
        costruire_matrice(&mat1, 2, 2);
        costruire_matrice(&mat2, 2, 2);
        costruire_matrice(&mat3, 2, 2);
        
        //prende il risultato di ogni determinante
        det1=determinante_matrice2x2(&mat1);
        det2=determinante_matrice2x2(&mat2);
        det3=determinante_matrice2x2(&mat3);
        
        //assegna i valori al nuovo vettore normale
        normale->vet[0] = det1;
        normale->vet[1] = -det2;
        normale->vet[2] = det3;

        
        //dealocca la memoria delle strutture temporarie
        dealocare_matrice(&mat1);
        dealocare_matrice(&mat2);
        dealocare_matrice(&mat3);

        return normale;
    }
    else{
        printf("ERRORE: vettori hanno dimensioni non adeguate");
        exit(1);
    }
}

//calcola la magnitude del vettore
float magnitude_vettore(vettore *vetPtr, int show){
    if(vetPtr->size > 0){
        float somma=0;
        for(int i=0; i < vetPtr->size; i++){
            somma += pow(*(vetPtr->vet + i), 2);
        }
        float result=sqrt(somma);
        if(show){
            printf("\nla magnitude: %f\n", result);
        }
        return result;
    }
    else{
        printf("\nERRORE: vettore non c'e elemento");
        exit(1);
    }
}

//normalizza il vettore
void normalizzare_vettore(vettore *vetPtr){
    if(vetPtr->size > 0){
        float somma=0.0;
        for(int i=0; i < vetPtr->size; i++){
            somma += pow(*(vetPtr->vet + i), 2);
        }
        float magnitude=sqrt(somma);
        for(int i=0; i < vetPtr->size; i++){
            *(vetPtr->vet + i) /= magnitude;
        }
    }
    else{
        printf("\nERRORE: vettore non c'e elemento");
        exit(1);
    }
}

//ricava l'angolo formato dai vettori v e w
float ottenere_angolo(vettore *vetPtrV, vettore *vetPtrW, int show){
    if(vetPtrV->size > 0 && vetPtrW->size > 0){
        if(vetPtrV->size == vetPtrW->size){
            float angle=0.0;
            float moltiplication=prodotto_scalare_algebrico(vetPtrV, vetPtrW, 0);
            float magnitudeV=magnitude_vettore(vetPtrV, 0);
            float magnitudeW=magnitude_vettore(vetPtrW, 0);
            
            angle=moltiplication / (magnitudeV * magnitudeW);

            if (angle < -1.0) angle = -1.0;
            if (angle > 1.0) angle = 1.0;

            float result=acos(angle);
            float result_degrees = result * (180.0 / 3.14);

            if(show){
                printf("\nl'angolo formato dai vettori e: %.2lf", result_degrees);
            }
            return result;
        }
        else{
            printf("\nERRORE: dimensioni disuguali");
            exit(1);
        }
    }
    else{
        printf("\nERRORE: vettore non c'e elemento");
        exit(1);
    }
}

void proiezione_ortogonale(vettore *vetPtrv, vettore *vetPtrw){
    if(vetPtrv->size == vetPtrw->size){
        float prodotto=prodotto_scalare_algebrico(vetPtrv, vetPtrw, 1);
        float magnitude_w=magnitude_vettore(vetPtrw, 1);
        float fattore=(prodotto / pow(magnitude_w, 2));

        for(int i=0; i < vetPtrw->size; i++){
            *(vetPtrw->vet + i) *= fattore;
        }
        stampare_vettore(vetPtrw);
    }
    else{
        printf("ERRORE: dimensioni disuguali");
    }
}

//destrugge il vettore
void dealocare_vettore(vettore *vetPtr){
    free(vetPtr->vet);
    vetPtr->vet=NULL;
    vetPtr->size=0;
}

int main(void){

vettore vet1;
vettore vet2;

costruire_vettore(&vet1, 2, NULL);
costruire_vettore(&vet2, 2, NULL);

stampare_vettore(&vet1);
stampare_vettore(&vet2);

prodotto_scalare_algebrico(&vet1, &vet2, 1);

destrurre_vettore(&vet1);
destrurre_vettore(&vet2);


}