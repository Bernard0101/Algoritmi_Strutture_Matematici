#ifndef MATRICE_H
#define MATRICE_H

#include <stdio.h>
#include <stdlib.h>

//la struttura principale della matrice
typedef struct matrice{
    float *mat;
    int lin;
    int col;
}matrice;



//Creazione e deallocazione
void costruire_matrice(matrice *matPtr, int n, int m);
void costruire_matrice_random(matrice *matPtr, int n, int m);
void dealocare_matrice(matrice *matPtr);

//Stampa
void stampare_matrice(matrice *matPtr);

//Operazioni sulle matrici
void somare_matrice(matrice *matPtr, matrice *matSum, float num);
void sotrarre_matrice(matrice *matPtr, matrice *matSub, float num);
matrice *moltiplicare_matrice(matrice *matPtr, matrice *matMul, float num);

//operazioni deverse
matrice *applicare_filtro(matrice *matPtr, matrice *kernel);

#endif //ALGORITMI_MATRICE_H