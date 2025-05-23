CC = gcc
SRC = src
OBJ = main.o Matrice.o Vettore.o Sistema_lineare.o


all: programma 


programma: $(OBJ)
	$(CC) -o programma $(OBJ) -lm

main.o: $(SRC)/main.c
	$(CC) -c  $< -o $@

Vettore.o: $(SRC)/Vettore.c
	$(CC) -c  $< -o $@

Matrice.o: $(SRC)/Matrice.c
	$(CC) -c  $< -o $@

Sistema_lineare.o: $(SRC)/Sistema_lineare.c
	$(CC) -c  $< -o $@

clean:
	rm -f *.o programma
