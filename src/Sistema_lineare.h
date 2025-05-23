#ifndef SISTEMA_LINEARE_H
#define SISTEMA_LINEARE_H

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

void costruire_sistema_lineare(sistema_lineare *sistemaPtr, matrice *matPtr, vettore *vetPtr);
void stampare_sistema_lineare(sistema_lineare *sistemaPtr);
void moltiplicare_riga_sistema_lineare(sistema_lineare *sistemaPtr, int riga, int num);
void dividere_riga_sistema_lineare(sistema_lineare *sistemaPtr, int riga, int num);
void scambiare_righe_sistema_lineare(sistema_lineare *sistemaPtr, int riga1, int riga2);
void scalonare_riga_sistema_lineare(sistema_lineare *sistemaPtr, int riga_pivot, int riga_scalonare, int colonna_pivot);
void Eliminazione_Gauss_Jordan(sistema_lineare *sistemaPtr);

#endif