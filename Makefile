CC = gcc
SRC = src
OBJ = main.o Matrice.o Vettore.o Sistema_lineare.o
CFLAGS = -g

all: programma 


programma: $(OBJ)
	$(CC) $(CFLAGS) -o programma $(OBJ) -lm

main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) -c  $< -o $@

Vettore.o: $(SRC)/Vettore.c
	$(CC) $(CFLAGS) -c  $< -o $@

Matrice.o: $(SRC)/Matrice.c
	$(CC) $(CFLAGS) -c  $< -o $@

Sistema_lineare.o: $(SRC)/Sistema_lineare.c
	$(CC) $(CFLAGS) -c  $< -o $@

clean:
	rm -f *.o programma
