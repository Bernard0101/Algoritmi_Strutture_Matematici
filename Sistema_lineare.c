#include <stdio.h>
#include <stdlib.h>

#include "Matrice.h"
#include "Vettore.h"


typedef struct sistema_lineare{
    int lin;
    int col;
    matrice *matPtr; 
    vettore *vetPtr;
}sistema_lineare;



void costruire_sistema_lineare(sistema_lineare *sistemaPtr, matrice *matPtr, vettore *vetPtr){
    if(matPtr->lin == vetPtr->size){
        sistemaPtr->lin=matPtr->lin;
        sistemaPtr->col=matPtr->col;
        sistemaPtr->matPtr=*(&matPtr);
        sistemaPtr->vetPtr=*(&vetPtr);
    }
    else{
        printf("ERRORE: le colonne della Matrice non hanno la stessa misuara che il vettore");
        exit(1);
    }
}

void stampare_sistema_lineare(sistema_lineare *sistemaPtr){
    if(sistemaPtr != NULL){   
        printf("\n");
        for(int i=0; i < sistemaPtr->matPtr->lin; i++){
            printf("[");
            for(int j=0; j < sistemaPtr->matPtr->col; j++){
                printf("%.1f ", *(sistemaPtr->matPtr->mat + i * sistemaPtr->matPtr->col + j));
            }
            printf("|%.1f]", *(sistemaPtr->vetPtr->vet + i));
            printf("\n");
        }
    }
    else{
        printf("ERRORE: sistema lineare NULL");
        exit(1);
    }
}

void moltiplicare_riga_sistema_lineare(sistema_lineare *sistemaPtr, int riga, int num){
    if(sistemaPtr != NULL){
        for(int i=0; i < sistemaPtr->matPtr->col; i++){
            *(sistemaPtr->matPtr->mat + (riga-1) * sistemaPtr->matPtr->col + i) *= num; 
        }
        *(sistemaPtr->vetPtr->vet + riga - 1) *= num;
    }
    else{
        printf("ERRORE: sistema lineare NULL");
        exit(1);
    }
}

void dividere_riga_sistema_lineare(sistema_lineare *sistemaPtr, int riga, int num){
    if(sistemaPtr != NULL){
        for(int i=0; i < sistemaPtr->matPtr->col; i++){
            *(sistemaPtr->matPtr->mat + (riga-1) * sistemaPtr->matPtr->col + i) /= num; 
        }
        *(sistemaPtr->vetPtr->vet + (riga-1)) /= num;
        }
    else{
        printf("ERRORE: sistema lineare NULL");
        exit(1);
    }
}   

void scambiare_righe_sistema_lineare(sistema_lineare *sistemaPtr, int riga1, int riga2){
    if(sistemaPtr != NULL){
        if(riga1 <= sistemaPtr->lin && riga2 <= sistemaPtr->lin){
            for(int i=0; i < sistemaPtr->col; i++){
                float *elemento_riga1=sistemaPtr->matPtr->mat + (riga1-1) * sistemaPtr->matPtr->col + i;
                float *elemento_riga2=sistemaPtr->matPtr->mat + (riga2-1) * sistemaPtr->matPtr->col + i;

                //scambia gli elementi della matrice
                float swap = *elemento_riga1;
                *elemento_riga1 = *elemento_riga2;
                *elemento_riga2 = swap;
            }
            //scambia gli elementi del vettore
            float swap= *(sistemaPtr->vetPtr->vet + (riga1-1));
            *(sistemaPtr->vetPtr->vet + (riga1-1)) = *(sistemaPtr->vetPtr->vet + (riga2-1));
            *(sistemaPtr->vetPtr->vet + (riga2-1))=swap;
        }
        else{
            printf("ERRORE: posizione riga invalida");
            exit(1);
        }
    }else{
        printf("ERRORE: sistema lineare NULL");
        exit(1);
    }
}

int main(void){
    sistema_lineare sistema_test;
    matrice matPtr;
    vettore vetPtr;

    costruire_matrice(&matPtr, 3, 3);
    costruire_vettore(&vetPtr, 3);

    costruire_sistema_lineare(&sistema_test, &matPtr, &vetPtr);
    stampare_sistema_lineare(&sistema_test);
    scambiare_righe_sistema_lineare(&sistema_test, 2, 3);
    stampare_sistema_lineare(&sistema_test);
    moltiplicare_riga_sistema_lineare(&sistema_test, 3, 3);
    stampare_sistema_lineare(&sistema_test);
}