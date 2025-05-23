#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "Matrice.h"



void costruire_matrice(matrice *matPtr, int n, int m){
    
    //alloca e costroi la matrice con le dimensioni n X m 
    matPtr->lin=n;
    matPtr->col=m;
    matPtr->mat=(float *)malloc(n * m * sizeof(float));
    
    
    //adizionare valori alla matrice
    printf("\ninserisci i valori della matrice\n");
    for(int i=0; i < matPtr->lin; i++){
        for(int j=0; j < matPtr->col; j++){
            printf("\nposizione %d, %d: ", i, j);
            scanf("%f", (matPtr->mat + i * m + j));
            
        }
    }
}

void costruire_matrice_random(matrice *matPtr, int n, int m){
    
    //alloca e costroi la matrice con le dimensioni n X m 
    matPtr->lin=n;
    matPtr->col=m;
    matPtr->mat=(float *)malloc(n * m * sizeof(float));

    for(int i=0; i < matPtr->lin; i++){
        for(int j=0; j < matPtr->col; j++){
            *(matPtr->mat + i * matPtr->col +j) = rand() % 100;
        }
    }
}

void costruire_matrice_identita(matrice *matPtr, int n){
    
    //fa l'allocazione dinamica della struttura matriciale
    matPtr->lin=n;
    matPtr->col=n;
    matPtr->mat=(float *)malloc(n * n * sizeof(float));

    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(i == j){
                *(matPtr->mat + i * n + j)=1;
            }
            else{
                *(matPtr->mat + i * n + j)=0;
            }
        }
    }
}

void costruire_matrice_triangolare_superiore(matrice *matPtr, int n){
    matPtr->lin=n;
    matPtr->col=n;
    matPtr->mat=(float *)malloc(n * n * sizeof(float));

    for(int i=0; i < matPtr->lin; i++){
        for(int j=0; j < matPtr->col; j++){
            if(i == j || i < j){
                *(matPtr->mat + i * matPtr->col + j) = rand() % 100;
            }
            else{
                *(matPtr->mat + i * matPtr->col + j) = 0;
            }
        }
    }
}

void costruire_matrice_triangolare_inferiore(matrice *matPtr, int n){
    matPtr->lin=n;
    matPtr->col=n;
    matPtr->mat=(float *)malloc(n * n * sizeof(float));

    for(int i=0; i < matPtr->lin; i++){
        for(int j=0; j < matPtr->col; j++){
            if(i == j || i > j){
                *(matPtr->mat + i * matPtr->col + j) = rand() % 100;
            }
            else{
                *(matPtr->mat + i * matPtr->col + j) = 0;
            }
        }
    }
} 

void costruire_matrice_nulla(matrice *matPtr, int n, int m){
    matPtr->lin=n;
    matPtr->col=m;
    matPtr->mat=(float *)malloc(n * m * sizeof(float));

    for(int i=0; i < matPtr->lin; i++){
        for(int j=0; j < matPtr->col; j++){
            *(matPtr->mat + i * matPtr->col + j) = 0;
        }
    }
}




void stampare_matrice(matrice *matPtr){
    printf("\n");
    for(int i=0; i < matPtr->lin; i++){
        printf("[");
        for(int j=0; j < matPtr->col; j++){
            printf("%.2f ", *(matPtr->mat + i * matPtr->col + j));
        }
        printf("]\n");
    }
    printf("\n");
}

void somma_scalare(matrice *matPtr, float num){
    if(matPtr != NULL){
        for(int i=0; i < matPtr->lin; i++){
            for(int j=0; j < matPtr->col; j++){
                *(matPtr->mat + i * matPtr->col + j) += num;
            }
        }
    }
    else{
        printf("ERRORE: Matrice nulla");
    }
}

void sottrazione_scalare(matrice *matPtr, float num){
    if(matPtr != NULL){
        for(int i=0; i < matPtr->lin; i++){
            for(int j=0; j < matPtr->col; j++){
                *(matPtr->mat + i * matPtr->col + j) -= num;
            }
        }
    }
    else{
        printf("ERRORE: Matrice nulla");
    }
}

void somma_matriciale(matrice *matPtr, matrice *matSum){
    if(matPtr != NULL && matSum != NULL){
        if(matPtr->lin == matSum->lin && matPtr->col == matSum->col){
            for(int i=0; i < matPtr->lin; i++){
                for(int j=0; j < matPtr->col; j++){
                    *(matPtr->mat + i * matPtr->col + j) += *(matSum->mat + i * matSum->col + j);
                }
            }
        }
        else{
            printf("ERRORE: matrici con dimensioni diverse");
            exit(1);
        }
    }
    else{
        printf("ERRORE: matrici nulle");
        exit(1);
    }   
}

void sottrazione_matriciale(matrice *matPtr, matrice *matSub){
    if(matPtr != NULL && matSub != NULL){
        if(matPtr->lin == matSub->lin && matPtr->col == matSub->col){
            for(int i=0; i < matPtr->lin; i++){
                for(int j=0; j < matPtr->col; j++){
                    *(matPtr->mat + i * matPtr->col + j) -= *(matSub->mat + i * matSub->col + j);
                }
            }
        }
        else{
            printf("ERRORE: matrici con dimensioni diverse");
            exit(1);
        }
    }
    else{
        printf("ERRORE: matrici nulle");
        exit(1);
    }
    
}

matrice *moltiplicazione_matriciale(matrice *matPtr, matrice *matMul, float num){
    
}

matrice *transporre_matrice(matrice *matPtr){

}

float determinante_matrice2x2(matrice *matPtr){
    if(matPtr->lin == 2 && matPtr->col == 2){
        float a= *(matPtr->mat + 0 * matPtr->col + 0);
        float b= *(matPtr->mat + 0 * matPtr->col + 1);
        float c= *(matPtr->mat + 1 * matPtr->col + 0);
        float d= *(matPtr->mat + 1 * matPtr->col + 1);
        
        return (a*d) - (b*c);
    }
    else{
        printf("ERRORE: matrice non ha dimensioni 2x2");
        exit(1);
    }
}


void dealocare_matrice(matrice *matPtr) {
    free(matPtr->mat);
    matPtr->mat=NULL;
    matPtr->lin=0;
    matPtr->col=0;
}
