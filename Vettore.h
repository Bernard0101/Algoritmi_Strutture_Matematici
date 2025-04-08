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
void dealocare_vettore(vettore *vetPtr);

//funzioni per manipulare i vettori
void sommare_vettore(vettore *vetPtr, vettore *vetSum, int show);
void sotrarre_vettore(vettore *vetPtr, vettore *vetSub, int show);
float prodotto_scalare_algebrico(vettore *vetPtrv, vettore *vetPtrw, int show);
float prodotto_scalare_geometrico(vettore *vetPtrv, vettore *vetPtrw, int theta, int show);
vettore *prodotto_incrociato_algebrico(vettore *vetPtrv, vettore *vetPtrw);
void proiezione_ortogonale(vettore *vetPtrv, vettore *vetPrtw);
void normalizzare_vettore(vettore *vetPtr);
float magnitude_vettore(vettore *vetPtr, int show);
float angolo_tra_vettori(vettore *vetPtrv, vettore *vetPtrw, int show);
void equazione_vettoriale(vettore *vetPtrv, vettore *vetPrtw);
void equazione_parametrica(vettore *vetPtrv, vettore *vetPtrw);
void equazione_del_piano(vettore *vetPtrv, vettore *vetPtrw);

#endif
