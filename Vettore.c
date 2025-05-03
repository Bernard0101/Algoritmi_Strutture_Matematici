#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "Vettore.h"
#include "Matrice.h"

//l'utente costroi un vettore matematico di dimensione n
void costruire_vettore(vettore *vetPtr, int n){
    vetPtr->size=n;
    vetPtr->vet=(float *)malloc(n * sizeof(float));

    printf("digita i valori del vettore:\n\n");
    for(int i=0; i < n; i++){
        float num=0;
        printf("posizione %d: ", i);
        scanf("%f", &num);
        *(vetPtr->vet + i)=num;
    }
}

//costruisce un vettore ranodomico di dimensione n
void costruire_vettore_random(vettore *vetPtr, int n){
    vetPtr->size=n;
    vetPtr->vet=(float *)malloc(n * sizeof(float));

    for(int i=0; i < n; i++){
        float num=rand() % 100;
        *(vetPtr->vet + i)=num;
    }
}

//costruisce un vettore tra due punti
void costruire_vettore_dapunti(vettore *vetPtr, int n){
    vetPtr->size=n;
    vetPtr->vet=(float *)malloc(n * sizeof(float));
    
    printf("\ninserisce le coordinate dei punti\n");
    for(int i=0; i < n; i++){
        int punto1, punto2;
        printf("\ncoordinata %d punto 1: ", i);
        scanf("%d", &punto1);
        printf("\ncoordinata %d punto 2: ", i);
        scanf("%d", &punto2);

        float fattore=punto2-punto1;
        *(vetPtr->vet + i)=fattore;
    }
      
}

vettore *copiare_vettore(vettore *vetPtr){
    vettore *vetcopy=(vettore *)malloc(sizeof(vettore));
    vetcopy->size=vetPtr->size;
    vetcopy->vet=(float *)malloc(vetcopy->size * sizeof(float));
    for(int i=0; i < vetPtr->size; i++){
        *(vetcopy->vet + i)= *(vetPtr->vet+i);
    }
    printf("vettore copiato con sucesso\n");
    return vetcopy;
}

//stampa il vettore con n elementi
void stampare_vettore(vettore *vetPtr){
    printf("\n[");
    for(int i=0; i < vetPtr->size; i++){
        printf("%.2f,", *(vetPtr->vet + i));
    }
    printf("]");
}

//somma un vettore con altro 
void sommare_vettore(vettore *vetPtr, vettore *vetSum, int show){
    if(vetPtr->size == vetSum->size){
        for(int i=0; i < vetPtr->size; i++){
            *(vetPtr->vet + i) += *(vetSum->vet + i);
        }
        if(show){
            stampare_vettore(vetPtr);
        }
    }
    else{
        printf("\nERRORE: dimensioni dei vettori diversa");
        exit(1);
    }
}

//sotrai un vettore sull'altro
void sotrarre_vettore(vettore *vetPtr, vettore *vetSub, int show){
    if(vetPtr->size == vetSub->size){
        for(int i=0; i < vetPtr->size; i++){
            *(vetPtr->vet + i) -= *(vetSub->vet + i);
        }
        if(show){
            stampare_vettore(vetPtr);
        }
    }
    else{
        printf("\nERRORE: dimensioni dei vettori diversa");
        exit(1);
    }
}

//moltiplica un vettore con altro
float prodotto_scalare_algebrico(vettore *vetPtr, vettore *vetMul, int show){
    if(vetPtr->size == vetMul->size){
        float somma=0.0;
        for(int i=0; i < vetPtr->size; i++){
            somma += *(vetPtr->vet + i) * *(vetMul->vet + i);
        }
        if(show){
            printf("\nprodotto scalare formula algebrica: %.2f\n", somma);
        }
        return somma;
    }
    else{
        printf("\nERRORE: dimensioni dei vettori diversa");
        exit(1);
    }
}

float prodotto_scalare_geometrico(vettore *vetPtrv, vettore *vetPtrw, int theta, int show){
    if(vetPtrv->size == vetPtrw->size){
        float magnitude_v=magnitude_vettore(vetPtrv, 0);
        float magnitude_w=magnitude_vettore(vetPtrw, 0);
        float result=magnitude_v * magnitude_w * cos(theta);
        if(show){
            printf("\nprodotto scalare formula geometrica: %f\n", result);
        }
        return result;
    }
}

vettore *prodotto_incrociato_algebrico(vettore *vetPtrv, vettore *vetPtrw){
    if(vetPtrv->size == vetPtrw->size && vetPtrv->size > 2){
        
        //dichiarazione e allocazione delle variabile e strutture
        vettore *normale=(vettore *)malloc(sizeof(vettore));
        normale->size=3;
        normale->vet=(float *)malloc(normale->size * sizeof(float));
        float det1, det2, det3;

        //costruzione delle matrice
        matrice *mat1=(matrice *)malloc(sizeof(matrice));
        mat1->mat=(float *)malloc(4 * sizeof(float));
        mat1->lin=2;
        mat1->col=2;

        matrice *mat2=(matrice *)malloc(sizeof(matrice));
        mat2->mat=(float *)malloc(4 * sizeof(float));
        mat2->lin=2;
        mat2->col=2;

        matrice *mat3=(matrice *)malloc(sizeof(matrice));
        mat3->mat=(float *)malloc(4 * sizeof(float));
        mat3->lin=2;
        mat3->col=2;

        //inserire i valori dei vettori nelle matrici
        mat1->mat[0 * 2 + 0]=vetPtrv->vet[1]; 
        mat1->mat[0 * 2 + 1]=vetPtrw->vet[1]; 
        mat1->mat[1 * 2 + 0]=vetPtrv->vet[2];
        mat1->mat[1 * 2 + 1]=vetPtrw->vet[2];
        
        mat2->mat[0 * 2 + 0]=vetPtrv->vet[0]; 
        mat2->mat[0 * 2 + 1]=vetPtrw->vet[0]; 
        mat2->mat[1 * 2 + 0]=vetPtrv->vet[2];
        mat2->mat[1 * 2 + 1]=vetPtrw->vet[2];
        
        mat3->mat[0 * 2 + 0]=vetPtrv->vet[0]; 
        mat3->mat[0 * 2 + 1]=vetPtrw->vet[0]; 
        mat3->mat[1 * 2 + 0]=vetPtrv->vet[1];
        mat3->mat[1 * 2 + 1]=vetPtrw->vet[1];


        //prende il risultato di ogni determinante
        det1=determinante_matrice2x2(mat1);
        det2=determinante_matrice2x2(mat2);
        det3=determinante_matrice2x2(mat3);
        
        //assegna i valori al nuovo vettore normale
        normale->vet[0]= det1;
        normale->vet[1]= -det2;
        normale->vet[2]= det3;
        printf("\n\nprodotto incrociato: ");
        stampare_vettore(normale);

        //dealocare le matrici di temporarie
        free(mat1->mat); free(mat1);
        free(mat2->mat); free(mat2);
        free(mat3->mat); free(mat3);
        printf("\n");
        return normale;
    }
    else{
        printf("ERRORE: vettori hanno dimensioni non adeguate");
        exit(1);
    }
}

//calcola la magnitude del vettore
float magnitude_vettore(vettore *vetPtr, int show){
    if(vetPtr->size > 0){
        float somma=0;
        for(int i=0; i < vetPtr->size; i++){
            somma += pow(*(vetPtr->vet + i), 2);
        }
        float result=sqrt(somma);
        if(show){
            printf("\n\nla magnitude: %f\n", result);
        }
        return result;
    }
    else{
        printf("\nERRORE: vettore non c'e elemento");
        exit(1);
    }
}

//normalizza il vettore
void normalizzare_vettore(vettore *vetPtr){
    if(vetPtr->size > 0){
        float somma=0.0;
        for(int i=0; i < vetPtr->size; i++){
            somma += pow(*(vetPtr->vet + i), 2);
        }
        float magnitude=sqrt(somma);
        for(int i=0; i < vetPtr->size; i++){
            *(vetPtr->vet + i) /= magnitude;
        }
    }
    else{
        printf("\nERRORE: vettore non c'e elemento");
        exit(1);
    }
}

//ricava l'angolo formato dai vettori v e w
float angolo_tra_vettori(vettore *vetPtrV, vettore *vetPtrW, int show){
    if(vetPtrV->size > 0 && vetPtrW->size > 0){
        if(vetPtrV->size == vetPtrW->size){
            float angle=0.0;
            float moltiplication=prodotto_scalare_algebrico(vetPtrV, vetPtrW, 0);
            float magnitudeV=magnitude_vettore(vetPtrV, 0);
            float magnitudeW=magnitude_vettore(vetPtrW, 0);
            
            angle=moltiplication / (magnitudeV * magnitudeW);

            if (angle < -1.0) angle = -1.0;
            if (angle > 1.0) angle = 1.0;

            float result=acos(angle);
            float result_degrees = result * (180.0 / 3.14);

            if(show){
                printf("\nl'angolo formato dai vettori e:\n %.2lf gradi", result_degrees);
            }
            return result;
        }
        else{
            printf("\nERRORE: dimensioni disuguali");
            exit(1);
        }
    }
    else{
        printf("\nERRORE: vettore non c'e elemento");
        exit(1);
    }
}


void proiezione_ortogonale(vettore *vetPtrv, vettore *vetPtrw){
    if(vetPtrv->size == vetPtrw->size){
        float prodotto=prodotto_scalare_algebrico(vetPtrv, vetPtrw, 0);
        float magnitude_w=magnitude_vettore(vetPtrw, 0);
        float fattore=(prodotto / pow(magnitude_w, 2));

        for(int i=0; i < vetPtrw->size; i++){
            *(vetPtrw->vet + i) *= fattore;
        }
        printf("\nvettore proiezione ortogonale:");
        stampare_vettore(vetPtrw);
        printf("\n");
    }
    else{
        printf("ERRORE: dimensioni disuguali");
        exit(1);
    }
}

void equazione_vettoriale(vettore *Punto_A, vettore *Punto_B){
    if(Punto_A->size == Punto_B->size){
        vettore *vettoreAB=(vettore *)malloc(sizeof(vettore));
        vettoreAB->size=3;
        vettoreAB->vet=(float *)malloc(vettoreAB->size * sizeof(float));

        for(int i=0; i < vettoreAB->size; i++){
            *(vettoreAB->vet + i)= *(Punto_B->vet + i) - *(Punto_A->vet + i);
        }

        printf("\n\nl'equazione vettoriale della retta: \n%.1fx + %.1fy + %.1fz + d = 0", *(vettoreAB->vet+0), *(vettoreAB->vet+1), *(vettoreAB->vet+2));
        free(vettoreAB);
    }
    else{
        printf("ERRORE: dimensioni disuguali");
        exit(1);
    }
}

void equazione_parametrica(vettore *Punto_A, vettore *Punto_B){
    if(Punto_A->size == Punto_B->size){
        vettore *vettoreAB=(vettore *)malloc(sizeof(vettore));
        vettoreAB->size=3;
        vettoreAB->vet=(float *)malloc(vettoreAB->size * sizeof(float));


        for(int i=0; i < vettoreAB->size; i++){
            *(vettoreAB->vet + i) = *(Punto_B->vet + i) - *(Punto_A->vet + i);
        }

        printf("\n\nl'equazione parametrica della retta: ");
        printf("\nx=%.1f + %.1ft",*(Punto_A->vet+0), *(vettoreAB->vet + 0));
        printf("\ny=%.1f + %.1ft",*(Punto_A->vet+1), *(vettoreAB->vet + 1));
        printf("\nz=%.1f + %.1ft",*(Punto_A->vet+2), *(vettoreAB->vet + 2));
        free(vettoreAB);
    }
    else{
        printf("ERRORE: dimensioni disuguali");
        exit(1);
    }
}

void equazione_del_piano(vettore *vetPtrv, vettore *vetPtrw){
    if(vetPtrv->size == vetPtrw->size ){
        vettore *prodotto_vetvw=prodotto_incrociato_algebrico(vetPtrv, vetPtrw);
        printf("\n\nl'equazione del piano: \n%.1fx + %.1fy + %.1fz + d = 0", *(prodotto_vetvw->vet+0), *(prodotto_vetvw->vet+1), *(prodotto_vetvw->vet+2));
        free(prodotto_vetvw);
    }
    else{
        printf("ERRORE: dimensioni disuguali");
        exit(1);
    }
}


//destrugge il vettore
void dealocare_vettore(vettore *vetPtr){
    free(vetPtr->vet);
    vetPtr->vet=NULL;
    vetPtr->size=0;
}
