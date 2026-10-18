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
            scanf("%f", (matPtr->mat + i * matPtr->col + j));
            
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
    matPtr->lin=n;
    matPtr->col=n;
    matPtr->mat=(float *)malloc(n * n * sizeof(float));
    for (int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(j == i){
                *(matPtr->mat + i * matPtr->col + j) = 1;
            }
            else{
                *(matPtr->mat + i * matPtr->col + j) = 0;
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

matrice* copiare_matrice(matrice *matPtr){
    matrice *matCopy =(matrice*)malloc(sizeof(matrice));
    matCopy->lin=matPtr->lin;
    matCopy->col=matPtr->col;
    matCopy->mat=(float *)malloc(matCopy->lin * matCopy->col * sizeof(float));
    for(int i=0; i < matCopy->lin; i++){
        for(int j=0; j < matCopy->col; j++){
            *(matCopy->mat + i * matCopy->col + j) = *(matPtr->mat + i * matPtr->col + j);
        }
    }
    return matCopy;
}

void stampare_matrice(matrice *matPtr){
    printf("\n");
    for(int i=0; i < matPtr->lin; i++){
        printf("[ ");
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
        printf("ERRORE: matrici null");
        exit(1);
    }
    
}

matrice *moltiplicazione_matriciale(matrice *matPtr, matrice *matMul){
    if(matPtr != NULL && matMul != NULL){
        if(matPtr->col == matMul->lin){

            //costruttore della matrice
            matrice *matSol=(matrice*)malloc(sizeof(matrice));
            matSol->lin=matPtr->lin;
            matSol->col=matMul->col;
            matSol->mat=(float *)malloc(matSol->lin * matSol->col * sizeof(float));
            
            //logica della moltiplicazione matriciale
            for(int i=0; i < matPtr->lin; i++){
                for(int j=0; j < matMul->col; j++){
                float num=0;                
                    for(int k=0; k < matPtr->col; k++){
                        *(matSol->mat + i * matSol->col + j) += *(matPtr->mat + i * matPtr->col + k) * *(matMul->mat + k * matMul->col + j);
                    }
                    printf("num result: %.2f\n", *(matSol->mat + i * matSol->col + j));
                }
            }
            return matSol;
        }
        else{
            printf("ERRORE: dimensioni matrici disuguali, dim1: %.2f != dim2: %.2f", matPtr->col, matMul->lin);
            exit(1);
        }
    }
    else{
        printf("ERRORE: Matrici null");
        exit(1);
    }
}

matrice *transporre_matrice(matrice *matPtr){
    if(matPtr != NULL){
        matrice *matSol=(matrice *)malloc(sizeof(matrice));
        matSol->lin=matPtr->col;
        matSol->col=matPtr->lin;
        matSol->mat=(float *)malloc(matSol->lin * matSol->col * sizeof(float));

        for(int i=0; i < matPtr->lin; i++){
            for(int j=0; j < matPtr->col; j++){
                *(matSol->mat + j * matSol->col + i) = *(matPtr->mat + i * matPtr->col + j);
            }
        }
        return matSol;
    }
    else{
        printf("ERRORE: matrice is null");
        exit(1);
    }
}

void riduzione_scala(matrice *matScala, int mat_i, int mat_j){
    for(int i=0; i < matScala->lin; i++){
        float fattore= *(matScala->mat + i * matScala->col + mat_j);
        printf("fattore -> (%f)\n", fattore);
        if(i == mat_i || fattore == 0){
            continue;
        }
        else{
            for(int j=mat_j; j < matScala->col; j++){
                *(matScala->mat + i * matScala->col + j) -= fattore * *(matScala->mat + mat_i * matScala->col + j);
                printf("risultato in pos(%d, %d): %f", i, j, *(matScala->mat + i * matScala->col + j));
            }    
        }   
    }
}

matrice *algoritmo_gauss_jordan(matrice *matPtr){
    matrice *matScala;

    if(matPtr != NULL){
        //copia la matrice originale ad una nuova
        matScala=copiare_matrice(matPtr);

        //itera su tutta la matrice
        for(int i=0; i < matScala->lin; i++){
            for(int j=0; j < matScala->col; j++){
                printf("pos matrice principale (%d, %d)\n\n", i, j);

                //esegue l'operazione di riduzione a scala se il fattore i==j e se il valore assosciato e uguale a 1
                if(i == j && *(matScala->mat + i * matScala->col + j) == 1){
                    riduzione_scala(matScala, i, j);
                }   
                //esegue l'operazione di riduzione a scala se il fattore e i==j e se il valore assosciato e e diverso da zero
                else if(i == j && *(matScala->mat + i * matScala->col + j) != 0){
                    float factor=*(matScala->mat + i * matScala->col + j);
                    for(int k=j; k < matScala->col; k++){
                        *(matScala->mat + i * matScala->col + k) /= factor;
                    }        
                    riduzione_scala(matScala, i, j);
                }
            }
        }
        return matScala;
    }
    else{
        printf("ERRORE: matrice is null");
        exit(1);
    }
}

float determinante_matrice(matrice *matPtr){
    matrice* matScala=(matrice *)malloc(sizeof(matrice));
    matScala->lin=matPtr->lin;
    matScala->col=matPtr->col;
    matScala->mat=(float *)malloc(matScala->lin * matScala->col * sizeof(float));
    matScala=algoritmo_gauss_jordan(&matPtr);
    float det;
    for(int i=0, j=0; i < matScala->lin; i++, j++){
        det *= *(matScala->mat + i * matScala->col + j);
    }
    return det;
}

void dealocare_matrice(matrice *matPtr) {
    free(matPtr->mat);
    matPtr->lin=0;
    matPtr->col=0;
    free(matPtr);
}
