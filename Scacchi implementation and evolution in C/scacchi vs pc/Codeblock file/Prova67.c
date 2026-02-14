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
void Acquisisci(struct calciatore *sss);
void Stampa(void);
void Azzera(void);

void gotoxy(int x,int y);

int main(void)
{
    int scelta;
    struct calciatore squadra[LEN];

    srand(time(NULL));
    do
    {
        scelta = menu();
        switch(scelta)
        {
            case    1: Acquisisci(squadra);     break;
            case    2: Stampa();                break;
            case    3: Azzera();                break;
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


void Acquisisci(struct calciatore *sss)
{
    int     cnt;
    FILE    *pf;

    pf = fopen("SQUADRA.TXT", "wt");

    for(cnt=0; cnt<LEN; cnt++)
    {
        printf("Nome: ");
        scanf("%s", sss[cnt].nome);
        printf("Cognome: ");
        scanf("%s", sss[cnt].cognome);
        printf("Ruolo: ");
        scanf("%s", sss[cnt].ruolo);
        printf("Numero: ");
        scanf("%d", &sss[cnt].numero);

        fwrite(&sss[cnt], sizeof(struct calciatore), 1, pf);
    }

    fclose(pf);

}


void Stampa(void)
{
    int     cnt, y;
    FILE    *pf;
    struct calciatore sq_letta[LEN];

    if((pf = fopen("SQUADRA.TXT", "rt")) == NULL)
   {
        printf("FILE NON TROVATO");
        getch();
        return;
   }

    for(cnt=0; cnt<LEN; cnt++)
    {
        fread(&sq_letta[cnt], sizeof(struct calciatore), 1, pf);
    }
    fclose(pf);

    system("cls");
    gotoxy(0, 0);
    printf("NOME");
    gotoxy(25, 0);
    printf("COGNOME");
    gotoxy(50, 0);
    printf("RUOLO");
    gotoxy(70, 0);
    printf("NUMERO");

    y = 2;
    for(cnt=0; cnt<LEN; cnt++)
    {
        gotoxy(0, y);
        printf("%s", sq_letta[cnt].nome);
        gotoxy(25, y);
        printf("%s", sq_letta[cnt].cognome);
        gotoxy(50, y);
        printf("%s", sq_letta[cnt].ruolo);
        gotoxy(70, y);
        printf("%d", sq_letta[cnt].numero);
        y++;
    }
    getch();
}


void Azzera(void)
{
    remove("SQUADRA.TXT");
}


void  gotoxy(int x, int  y)
{
    COORD CursorPos = {x, y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, CursorPos);
}




