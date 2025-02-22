#ifndef VETTORE_H
#define VETTORE_H

#include <stdio.h>
#include <stdlib.h>

//la struttura del vettore matematico
typedef struct vettore
{
    float *vet;
    int size;
}vettore;

//funzione che construiscono la struttura vettoriale
void costruire_vettore(vettore *vetPtr, int n);
void costruire_vettore_random(vettore *vetPtr, int n);
void stampare_vettore(vettore *vetPtr);
void dealoca_vettore(vettore *vetPtr);

//funzioni manipulano vettori
void sommare_vettore(vettore *vetPtr, vettore *vetSum);
void sottrarre_vettore(vettore *vetPtr, vettore *vetSub);
float prodotto_scalare_algebrico(vettore *vetPtrv, vettore *vetPtrw);
float prodotto_scalare_geometrico(vettore *vetPtrv, vettore *vetPtrw, int theta);
void normalizzare_vettore(vettore *vetPtr);
int magnitude_vettore(vettore *vetPtr);
double ottenere_angolo(vettore *vetPtrv, vettore *vetPtrw);


#endif
