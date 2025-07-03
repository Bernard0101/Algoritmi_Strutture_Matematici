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
void costruire_matrice_identita(matrice *matPtr, int n);
void costruire_matrice_triangolare_superiore(matrice *matPtr, int n);
void costruire_matrice_triangolare_inferiore(matrice *matPtr, int n);
void costruire_matrice_nulla(matrice *matPtr, int n, int m);
void dealocare_matrice(matrice *matPtr);

//Stampa
void stampare_matrice(matrice *matPtr);

//Operazioni sulle matrici
void somma_scalare(matrice *matPtr, float num);
void sottrazione_scalare(matrice *matPtr, float num);
void somma_matriciale(matrice *matPtr, matrice *matSum);
void sottrazione_matriciale(matrice *matPtr, matrice *matSub);
float determinante_matrice2x2(matrice *matPtr);
matrice *moltiplicazione_matriciale(matrice *matPtr, matrice *matMul);
matrice *transporre_matrice(matrice *matPtr);

//operazioni deverse

#endif 