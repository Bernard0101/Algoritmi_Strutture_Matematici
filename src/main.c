#include "Matrice.h"
#include "Vettore.h"

int main(void){

matrice *mat_A=(matrice*)malloc(sizeof(matrice));
matrice *mat_B;
matrice *mat_C;

costruire_matrice(mat_A, 4, 4);
stampare_matrice(mat_A);
mat_B=algoritmo_gauss_jordan(mat_A);
stampare_matrice(mat_B);
dealocare_matrice(mat_A);
dealocare_matrice(mat_B);


}