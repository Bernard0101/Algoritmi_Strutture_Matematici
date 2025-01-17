#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "Algoritmi_Matrice.h"

    

    //definire la misura della matrice e sue valori
    void costruire_matrice(matrice *matPtr, int n, int m){
        
        //alloca e costroi la matrice con le dimensioni n X m 
        matPtr->lin=n;
        matPtr->col=m;
        matPtr->mat=(float *)malloc(n * m * sizeof(float));
        
        
        //adizionare valori alla matrice
        printf("inserisci i valori della matrice\n");
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
                *(matPtr->mat + i * m +j) = rand() % 100;
            }
        }
    }

    //stamapa la matrice
    void stampare_matrice(matrice *matPtr){
        for(int i=0; i < matPtr->lin; i++){
            printf("[");
            for(int j=0; j < matPtr->col; j++){
                printf("%f", *(matPtr->mat + i * matPtr->col + j));
            }
            printf("]\n");
        }
        printf("\n");
    }

    //funzione per somare matrici
    void somare_matrice(matrice *matPtr, matrice *matSum, float num){

        //verifica della condizione dell'eseguimento dell'operazione
        if(matPtr == NULL){
            printf("matrice e nulla");
            exit(1);
        }
        //soma con scalare
        if(matSum == NULL && num != 0){
            for(int i=0; i < matPtr->lin; i++){
                for(int j=0; j < matPtr->col; j++){
                    *(matPtr->mat + i * matPtr->col + j) += num;
                }
            }
        }
        //soma tra matrici
        else if (matPtr->lin == matSum->lin && matPtr->col == matSum->col){
            for(int i=0; i < matPtr->lin; i++){
                for(int j=0; j < matPtr->col; j++){
                    *(matPtr->mat + i * matPtr->col + j) += *(matSum->mat + i * matSum->col + j);
                }
            }
        }
    }

    //funzione per sotrarre matrici
    void sotrarre_matrice(matrice *matPtr, matrice *matSub, float num){

        //condizione per eseguimento dell'operazione
        if(matPtr == NULL){
            printf("matrice e nulla");
            exit(1);
        }
        //sotrazione con scalare
        if(matSub == NULL && num != 0){
            for(int i=0; i < matPtr->lin; i++){
                for(int j=0; j < matPtr->col; j++){
                    *(matPtr->mat + i * matPtr->col + j) += num;
                }
            }
        }
        //sotrazione tra matrici
        else if (matPtr->lin == matSub->lin && matPtr->col == matSub->col){
            for(int i=0; i < matPtr->lin; i++){
                for(int j=0; j < matPtr->col; j++){
                    *(matPtr->mat + i * matPtr->col + j) -= *(matSub->mat + i * matSub->col + j);
                }
            }
        }
    }

    matrice *moltiplicare_matrice(matrice *matPtr, matrice *matMul, float num){
        if(matPtr->col == matMul->lin && num == 0){

            //creare la nuova matrice risultato
            matrice *matSol = (matrice *)malloc(sizeof(matrice));
            matSol->lin = matPtr->lin;
            matSol->col = matMul->col;
            matSol->mat = (float*)malloc(matPtr->lin * matMul->col * sizeof(float));


            //iterare sulle linee di matPtr
            for(int i=0; i < matPtr->lin; i++){

                //iterare sulle cologne di matMul
                for(int j=0; j < matMul->col; j++){

                    //eseguire la moltiplicazione e adizionare i nuovi numeri alla matrice
                    for(int k=0; k < matPtr->col; k++){
                        *(matSol->mat + i * matSol->col +j) += *(matPtr->mat + i * matPtr->col + k) * *(matMul->mat + k * matMul->col + j);
                    }
                }
            }
            return matSol;
        }
        else if(num != 0){

            //esegue la moltiplicazione scalare
            for(int i=0; i < matPtr->lin; i++){
                for(int j=0; j < matPtr->col; j++){
                    *(matPtr->mat + i * matPtr->col + j) *= num;
                }
            }
            return matPtr;
        }
    }

    matrice *applicare_filtro(matrice *matPtr, matrice *kernel){

        matrice *matFil = (matrice *)malloc(sizeof(matrice));
        matFil->lin = matPtr->lin;
        matFil->col = matPtr->col;
        matFil->mat=(float *)malloc(matFil->lin * matFil->col * sizeof(float));

        //prende il centro dello kernel
        int centroLin=kernel->lin / 2;
        int centroCol=kernel->col / 2;

        //itera sulla matrice cioe l'immagine
        for(int i=0; i < matPtr->lin; i++){
            for(int j=0; j < matPtr->col; j++){
                float somma = 0.0;

                //itera sull kernel cioe il filtro
                for(int ki=0; ki < kernel->lin; ki++){
                    for(int kj=0; kj < kernel->col; kj++){

                        //calcola le cordinate nella matrice a rispeto del kernel
                        int lin = i + ki - centroLin;
                        int col = j + kj - centroCol;

                        if(lin >= 0 && lin < matPtr->lin && col >= 0 && col < matPtr->col){
                            somma += *(matPtr->mat + lin * matPtr->col + col) * *(kernel->mat + ki * kernel->col + kj);
                        }
                    }
                }
                *(matFil->mat + i * matFil->col + j) = somma;
            }
        }
        return matFil;
    }

    void Algoritmo_Gauss_Jordan(matrice *matPtr){

        //la matrice deve essere quadratta
        if(matPtr->col != matPtr->lin){
            printf("ERROR matrice non quadratta");
            exit(1);
        }
        //scende la scala degli pivot
        for(int i=0, j=0; i < matPtr->lin && j < matPtr->col; i++, j++){
            if(*(matPtr->mat + i * j) != 1){

                //prende il pivot per dividere la riga e dividela
                int pivot= *(matPtr->mat+ i * matPtr->col + j);
                for(int k=j; k < matPtr->col; k++){
                    *(matPtr->mat + i * matPtr->col + j) /= pivot;
                }
            }
            else{
                //pivotare e zerare
                for(int i=0; i < matPtr->lin; i++){
                    for(int j=0; j < matPtr->col; j++){
                        *(matPtr->mat + j);
                    }
                } 
            }
        }
    }

    void dealocare_matrice(matrice *matPtr) {
    if (matPtr != NULL) {
        free(matPtr->mat); // Libera la memoria degli elementi
        free(matPtr);      // Libera la struttura
    }
}
    
int main(void){

    matrice immagine;
    matrice kernel;

    costruire_matrice_random(&immagine, 20, 20); 
    costruire_matrice(&kernel, 3, 3);
    stampare_matrice(&kernel);
    applicare_filtro(&immagine, &kernel);
    stampare_matrice(&immagine);

    dealocare_matrice(&kernel);
    dealocare_matrice(&immagine);
    
   
}