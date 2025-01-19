#ifndef VETTORE_H
#define VETTORE_H

#include <stdio.h>
#include <stdlib.h>

//la seconda struttura principale un vettore
typedef struct vettore
{
    float *vet;
    int size;
}vettore;


void costruire_vettore(vettore *vetPtr, int n);
void costruire_vettore_random(vettore *vetPtr, int n);
void stampare_vettore(vettore *vetPtr);
void sommare_vettore(vettore *vetPtr, vettore *vetSum);
void sottrarre_vettore(vettore *vetPtr, vettore *vetSub);
void aggiungere_elemento(vettore *vetPtr, vettore *vetConcat, float x);
void rimuovere_vettore(vettore *vetPtr);
void dealoca_vettore(vettore *vetPtr);

#endif
