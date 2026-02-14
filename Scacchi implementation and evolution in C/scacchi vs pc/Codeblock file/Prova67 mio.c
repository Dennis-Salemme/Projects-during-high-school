/**************************************************************************************************
Programma che acquisisce i dati dei giocatori di una squadra di calcetto e li salva in un file
**************************************************************************************************/

#include <windows.h> //  header file for gotoxy
#include <CONIO.H>
#include <STDIO.H>
#include <STRING.H>
#include <STDLIB.H>
#include <TIME.H>

#define  LEN     5

COORD coord = {0,0};    // center of axis is set to
                        // the top left corner of the screen
struct  calciatore
{
    char                nome[30];
    char                cognome[30];
    char                ruolo[20];
    int                 numero;
};

int menu(void);
void Acquisisci(void);
void Stampa(void);
void Azzera(void);

void gotoxy(int x,int y);

int main(void)
{
    int scelta;

    srand(time(NULL));
    do
    {
        scelta = menu();
        switch(scelta)
        {
            case    1: Acquisisci();break;
            case    2: Stampa();break;
            case    3: Azzera();break;
        }
    }while(scelta);
}


int menu(void)
{
    int sc;

    system("cls");
    printf("MENU\n\n");
    printf("1. Acquisisci\n");
    printf("2. Stampa\n");
    printf("3. Azzera\n");
    printf("0. Fine\n\n");
    printf("?  ");

    scanf("%d", &sc);
    return sc;
}


void Acquisisci(void)
{
    struct calciatore squadra;
    FILE *pf;
    int num;

    pf=fopen("Squadra.txt", "ab");
        printf("\nInserisci il nome del calciatore: ");
        scanf("%s", squadra.nome);
        printf("\nInserisci il cognome del calciatore: ");
        scanf("%s", squadra.cognome);
        printf("\nInserisci il ruolo del calciatore: ");
        scanf("%s", squadra.ruolo);
        squadra.numero=rand()%99+1;
        fwrite(&squadra, sizeof(struct calciatore), 1, pf);
        fclose(pf);
        pf=fopen("Squadra.txt", "r+b");
        fseek(pf, 0, SEEK_SET);
        num=fgetc(pf);
        num++;
        fseek(pf, 0, SEEK_SET);
        putc(num, pf);
        fclose(pf);

    getch();
}


void Stampa(void)
{
    FILE *pf;
    struct calciatore squadra;
    int num;
    int cnt;

    pf=fopen("Squadra.txt", "rb");
        fseek(pf, 0, SEEK_SET);
        num=fgetc(pf);
        printf("\nNOME\tCOGNOME\tRUOLO\tNUMERO");
        for(cnt=0; cnt<num; cnt++)
        {
            fread(&squadra, sizeof(struct calciatore), 1, pf);
            printf("\n%s\t%s\t%s\t%d", squadra.nome, squadra.cognome, squadra.ruolo, squadra.numero);
        }
        fclose(pf);

    getch();
}


void Azzera(void)
{
    FILE *pf;
    int sc;

    printf("\nVuoi azzerare il file? 1=si 0=no");
    scanf("%d", &sc);
    if(sc==1)
    {
        pf=fopen("Squadra.txt", "wb");
        fputc(0, pf);
        fclose(pf);
        printf("\nFatto");
    }
    getch();
}


void  gotoxy(int x, int  y)
{
    COORD CursorPos = {x, y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, CursorPos);
}




