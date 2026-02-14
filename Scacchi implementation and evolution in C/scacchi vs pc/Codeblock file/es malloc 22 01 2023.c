/*Scrivi una funzione int* create_array(int size) che utilizza malloc per allocare un array
di interi di dimensione "size" e inizializzarlo con i valori da 0 a size-1. La funzione deve
restituire un puntatore all'array creato.

Scrivi una funzione void print_array(int* array, int size) che stampa gli elementi
dell'array passato come parametro.

Scrivi una funzione void free_array(int* array) che libera la memoria allocata per l'array
passato come parametro utilizzando free.

Nel main(), chiedi all'utente di inserire una dimensione N e crea un array di N elementi
utilizzando la funzione create_array().

Utilizza la funzione print_array() per stampare gli elementi dell'array creato.

Utilizza la funzione free_array() per liberare la memoria allocata per l'array.

Aggiungi dei controlli per gestire il caso in cui la memoria non possa essere allocata.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void creare_array(int *elemento, int numero);
void stampa(int *elemento, int numero);

int main(void)
{
    int num;
    int *array;

    srand(time(NULL));

    printf("Inserisci quanti elementi vuoi inserire?\n");
    scanf("%d", &num);

    array = (int *) malloc(num);//creo un array con malloc
    creare_array(&array[0], num);

    stampa(&array[0], num);//stampo l'array per vedere il contenuto

    free(array);//pulisco l'array creato togliendogli tutti gli indirizzi
}

void creare_array(int *elemento, int numero)
{
    int cnt;

    for(cnt=0; cnt<numero; cnt++)
    {
        elemento[cnt]= rand()% numero+1;
    }
}

void stampa(int *elemento, int numero)
{
    int cnt;

    printf("l'array formato è composto da:\n");
    for(cnt=0; cnt<numero; cnt++)
    {
        printf("%d   ", elemento[cnt]);
    }
}
