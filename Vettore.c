#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "Vettore.h"

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

//stampa il vettore con n elementi
void stampare_vettore(vettore *vetPtr){
    printf("\n[");
    for(int i=0; i < vetPtr->size; i++){
        printf("%.2f,", *(vetPtr->vet + i));
    }
    printf("]");
}

//somma un vettore con altro 
void sommare_vettore(vettore *vetPtr, vettore *vetSum){
    if(vetPtr->size == vetSum->size){
        for(int i=0; i < vetPtr->size; i++){
            *(vetPtr->vet + i) += *(vetSum->vet + i);
        }
    }
    else{
        printf("\nERRORE: dimensioni dei vettori diversa");
        exit(1);
    }
}

//sotrai un vettore sull'altro
void sotrarre_vettore(vettore *vetPtr, vettore *vetSub){
    if(vetPtr->size == vetSub->size){
        for(int i=0; i < vetPtr->size; i++){
            *(vetPtr->vet + i) -= *(vetSub->vet + i);
        }
    }
    else{
        printf("\nERRORE: dimensioni dei vettori diversa");
        exit(1);
    }
}

//moltiplica un vettore con altro
float prodotto_scalare_algebrico(vettore *vetPtr, vettore *vetMul){
    if(vetPtr->size == vetMul->size){
        float somma=0.0;
        for(int i=0; i < vetPtr->size; i++){
            somma += *(vetPtr->vet + i) * *(vetMul->vet + i);
        }
        printf("\nprodotto scalare formula algebrica: %.2f\n", somma);
        return somma;
    }
    else{
        printf("\nERRORE: dimensioni dei vettori diversa");
        exit(1);
    }
}

float prodotto_scalare_geometrico(vettore *vetPtrv, vettore *vetPtrw, int theta){
    if(vetPtrv->size == vetPtrw->size){
        int magnitude_v=magnitude_vettore(vetPtrv);
        int magnitude_w=magnitude_vettore(vetPtrw);
        float result=magnitude_v * magnitude_w * cos(theta);

        printf("\nprodotto scalare formula goniometrica: %f\n", result);
        return result;
    }
}

vettore prodotto_incrociato(vettore *vetPtr, vettore *vetMul){
    if(vetPtr->size == vetMul->size){

    }
}

//calcola la magnitude del vettore
int magnitude_vettore(vettore *vetPtr){
    if(vetPtr->size > 0){
        float somma=0;
        for(int i=0; i < vetPtr->size; i++){
            somma += pow(*(vetPtr->vet + i), 2);
        }
        int result=sqrt(somma);
        printf("\nla magnitude: %d\n", result);
        return result;
    }
    else{
        printf("\nERRORE: vettore non c'e elemento");
        exit(1);
    }
}

//normalizza il vettore
void normalizare_vettore(vettore *vetPtr){
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
double ottenere_angolo(vettore *vetPtrV, vettore *vetPtrW){
    if(vetPtrV->size > 0 && vetPtrW->size > 0){
        if(vetPtrV->size == vetPtrW->size){
            double angle=0.0;
            float moltiplication=prodotto_scalare_algebrico(vetPtrV, vetPtrW);
            int magnitudeV=magnitude_vettore(vetPtrV);
            int magnitudeW=magnitude_vettore(vetPtrW);
            
            if (angle < -1.0) angle = -1.0;
            if (angle > 1.0) angle = 1.0;

            angle=moltiplication / (magnitudeV * magnitudeW);
            double result=acos(angle);
            double result_degrees = result * (180.0 / 3.141592653589793);

            printf("\nl'angolo formato dai vettori e: %.2lf", result_degrees);
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
        float prodotto=prodotto_scalare_algebrico(vetPtrv, vetPtrw);
        int magnitude_w=magnitude_vettore(vetPtrw);
        float fattore=(prodotto / pow(magnitude_w, 2));

        for(int i=0; i < vetPtrv->size; i++){
            *(vetPtrv->vet + i) *= fattore;
        }
    }
}

//destrugge il vettore
void dealoca_vettore(vettore *vetPtr){
    free(vetPtr->vet);
    vetPtr->vet=NULL;
    vetPtr->size=0;
}

int main(void){

vettore vet1;
vettore vet2;

costruire_vettore(&vet1, 2);
costruire_vettore(&vet2, 2);

stampare_vettore(&vet1);
stampare_vettore(&vet2);

ottenere_angolo(&vet1, &vet2);


return 0;
}