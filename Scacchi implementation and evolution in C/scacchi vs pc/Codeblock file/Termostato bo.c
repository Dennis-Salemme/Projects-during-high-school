/**************************************************************************************************
                                        TERMOSTATO
Vengono impostate le temperature desiderate in 3 ambienti:
Sala, camera, bagno
Il programma legge le temperature ambiente e le confronta con quanto impostato.
Se la temperatura è maggiore del valore impostato il termostato viene spento
Se la temperatura è minore del valore impostato il termostato viene acceso
**************************************************************************************************/

#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <time.h>
#include    <conio.h>

#define     DELTA   0.5

int menu(void);
void Tempambie(float *sal, float *cam, float *bag);
void Tempdesi(float sal, float cam, float bag, int *acc);
void Regotermo(int acc[]);

int main(void)
{
    int scelta;
    float sala, camera, bagno;
    int acceso[3];
    int cnt;

    srand(time(NULL));
    do
    {
        scelta=menu();
        switch(scelta)
        {
        case 1: Tempambie(&sala, &camera, &bagno);
            break;
        case 2: for(cnt=0; cnt<3; cnt++)
                {
                    acceso[cnt]=0;
                }
                Tempdesi(sala, camera, bagno, &acceso[0]);
            break;
        case 3: Regotermo(acceso);
            break;
        }
    }while(scelta);
}

int menu(void)
{
    int sc;

    system("cls");
    printf("MENU'\n\n");
    printf("1. Temperatura ambiente\n");
    printf("2. Imposta la temperatura desiderata\n");
    printf("3. Regolazione termostati\n");
    printf("0. Esci\n\n");
    printf("? ");

    scanf("%d", &sc);
    return sc;
}

void Tempambie(float *sal, float *cam, float *bag)
{
    *sal=rand()%20+11;
    *cam=rand()%20+11;
    *bag=rand()%20+11;

    printf("\nLa temp in sala e': %.2f", *sal);
    printf("\nLa temp in camera e': %.2f", *cam);
    printf("\nLa temp in bagno e': %.2f", *bag);
    getch();
}

void Tempdesi(float sal, float cam, float bag, int *acc)
{
    float temp;

    printf("\nLa temp in sala e': %.2f", sal);
    printf("\nLa temp in camera e': %.2f", cam);
    printf("\nLa temp in bagno e': %.2f", bag);

    printf("\nInserisci la temp desiderata\n");
    scanf("%f", &temp);

    if(temp>sal)
    {
        acc[0]++;
    }

    if(temp>cam)
    {
        acc[1]++;
    }

    if(temp>bag)
    {
        acc[2]++;
    }
}

void Regotermo(int acc[])
{
    printf("\nIl termometro nella sala e' %d", acc[0]);
    printf("\nIl termometro nella camera e' %d", acc[1]);
    printf("\nIl termometro nella bagno e' %d", acc[2]);
    getch();
}
