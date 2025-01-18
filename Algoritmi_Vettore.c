#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "Algoritmi_Vettore.h"

//l'utente costroi un vettore di misura n
void costruire_vettore(vettore *vetPtr, int n){
    vetPtr->size=n;
    vetPtr->vet=(float *)malloc(n * sizeof(float));

    printf("digita i valori del vettore");
    for(int i=0; i < n; i++){
        int num=0;
        printf("posizione %f: ", i);
        scanf("%f", &num);
        *(vetPtr->vet + i)=num;
    }
}

//costruisce un vettore ranodomico de misura n
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
    printf("[");
    for(int i=0; i < vetPtr->size; i++){
        printf("%f,", *(vetPtr->vet + i));
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
        printf("misura dei vettori diversa");
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
        printf("misura dei vettori diversa");
    }
}

//adiziona un elemento o concatena un'altro vettore
void aggiungere_elemento(vettore *vetPtr, vettore *vetConcat, float x){

    //adiziona un'elemento al vettore
    if(vetConcat == NULL){
        vetPtr->vet=realloc(vetPtr->vet, (vetPtr->size + 1) * sizeof(float)); 
        vetPtr->vet[vetPtr->size] = x;
        vetPtr->size++;
    }

    //concatena un vettore sull'altro
    else{
        vetPtr->vet=realloc(vetPtr->vet, (vetPtr->size + vetConcat->size) * sizeof(float));
        for(int i=0; i < vetConcat->size; i++){
            vetPtr->vet[vetPtr->size + i] = *(vetConcat->vet + i);
            vetPtr->size++;
        }
    }
}

//rimouve un elemento al fine del vettore o rimouve una serie di elementi
void rimuovere_vettore(vettore *vetPtr, int pos){
    vetPtr->vet[vetPtr->size] = 0;
    vetPtr->vet=realloc(vetPtr->vet, vetPtr->size-1 * sizeof(float));
    vetPtr->size--;
}

//destrugge il vettore
void dealoca_vettore(vettore *vetPtr){
    free(vetPtr->vet);
    vetPtr->vet=NULL;
    vetPtr->size=0;
}