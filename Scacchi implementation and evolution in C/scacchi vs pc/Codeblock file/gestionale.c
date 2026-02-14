/**************************************************************************************************
Programma per la gestione di un negozio di alimentari

Q.tà    art             PrA     PrV
50   Penne rigate       0.5     0.9
48   Fusilli            0.4     1.0
10   Abbracci           1.5     2.5
15   Rigoli             1.2     2.0
9    Marmellata more    2.0     3.4
12   Marmaellata prugne 1.8     3.1
6    Maionese           1.5     2.0
20   Birra              0.7     1.5
30   Acqua minerale     1.1     1.5
26   Burro              1.3     2.3

struct magazzino
{
    char    Articolo[15]
    float   PrA;
    float   PrV;
    int     Qta;
}


struct vendite
{
    char    Articolo[15]
    int     Qta;
}

Menu:
1.  Carico Magazzino
2.  Vendita
3.  Incasso
4.  Totali
0.  Fine

1. Aumenta le quantità a magazzino del'articolo selezionato
2. Dimuinuiace le quantità di magazzino e aggiorna la quantità del venduto
3. Calcola l'incasso fino a quel momento
4. Visualizza il magazzino e visualizza lo stato della cassa

**************************************************************************************************/
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <time.h>
#include    <conio.h>
#include    <windows.h>

#define     ACQ_PENNE       0.5
#define     ACQ_FUSILLI     0.4
#define     ACQ_ABBRACCI    1.5
#define     ACQ_RIGOLI      1.2
#define     ACQ_MORE        2.0
#define     ACQ_PRUGNE      1.8
#define     ACQ_MAIO        1.5
#define     ACQ_BIRRA       0.7
#define     ACQ_ACQUA       1.1
#define     ACQ_BURRO       1.3

#define     VEN_PENNE       0.9
#define     VEN_FUSILLI     1.0
#define     VEN_ABBRACCI    2.5
#define     VEN_RIGOLI      2.0
#define     VEN_MORE        3.4
#define     VEN_PRUGNE      3.1
#define     VEN_MAIO        2.0
#define     VEN_BIRRA       1.5
#define     VEN_ACQUA       1.5
#define     VEN_BURRO       2.3

#define     NUM             10

struct magazzino
{
    char    Articolo[20];
    float   PrA;
    float   PrV;
    int     Qta;
};


struct vendite
{
    char    Articolo[20];
    int     Qta;
};

void CaricoMagazzino(void);
void Vendita(void);
void Incasso(void);
void Stampa(void);
void Prezzi(void);
void Inizializzazione(void);
int menu(void);
int menu_prodotti(void);
void  gotoxy(int x, int  y);

int main(void)
{
    int     scelta;

    do
    {
        scelta = menu();
        switch(scelta)
        {
            case 1: CaricoMagazzino(); break;
            case 2: Vendita(); break;
            case 3: Incasso(); break;
            case 4: Stampa(); break;
            case 5: Prezzi();break;
            case 6: Inizializzazione(); break;
        }
    }while(scelta);
}


int menu(void)
{
    int sc;

    system("cls");
    printf("MENU':\n\n");
    printf("1. Carico Magazzino\n");
    printf("2. Vendita\n");
    printf("3. Incasso\n");
    printf("4. Stampa\n");
    printf("5. Prezzi\n");
    printf("6. Inizializzazione\n");
    printf("0. Fine\n\n");
    printf("?  ");

    scanf("%d", &sc);
    return sc;
}

/**************************************************************************************************
Funzione per il carico a magazzino delle quantità acquistate
**************************************************************************************************/
void CaricoMagazzino(void)
{
    int                 scelta, cnt, quantita;
    struct magazzino    mag[NUM];
    FILE                *pf;

    if((pf = fopen("Magazzino.txt", "rb")) == NULL)
    {
        printf("Magazzino non trovato");
        getch();
        return;
    }
    for(cnt=0; cnt<NUM; cnt++)
    {
        fread(&mag[cnt], sizeof(struct magazzino), 1, pf);
    }
    fclose(pf);
    do
    {
        scelta = menu_prodotti();
        switch(scelta)
        {
            case 1: printf("Quantita' penne rigate = ");
                    scanf("%d", &quantita);
                    mag[0].Qta += quantita;
                    break;
            case 2: printf("Quantita' Fusilli = ");
                    scanf("%d", &quantita);
                    mag[1].Qta += quantita;
                    break;
            case 3: printf("Quantita' Abbracci = ");
                    scanf("%d", &quantita);
                    mag[2].Qta += quantita;
                    break;
            case 4: printf("Quantita' Rigoli = ");
                    scanf("%d", &quantita);
                    mag[3].Qta += quantita;
                    break;
            case 5: printf("Quantita' Marmellata more = ");
                    scanf("%d", &quantita);
                    mag[4].Qta += quantita;
                    break;
            case 6: printf("Quantita' Marmaellata prugne = ");
                    scanf("%d", &quantita);
                    mag[5].Qta += quantita;
                    break;
            case 7: printf("Quantita' Maionese = ");
                    scanf("%d", &quantita);
                    mag[6].Qta += quantita;
                    break;
            case 8: printf("Quantita' Birra = ");
                    scanf("%d", &quantita);
                    mag[7].Qta += quantita;
                    break;
            case 9: printf("Quantita' Acqua minerale = ");
                    scanf("%d", &quantita);
                    mag[8].Qta += quantita;
                    break;
            case 10: printf("Quantita' Burro = ");
                     scanf("%d", &quantita);
                     mag[9].Qta += quantita;
                     break;
        }

    }while(scelta != 0);

    pf = fopen("Magazzino.txt", "wb");
    for(cnt=0; cnt<NUM; cnt++)
    {
        fwrite(&mag[cnt], sizeof(struct magazzino), 1, pf);
    }
    fclose(pf);
}

int menu_prodotti(void)
{
    int sc;

    system("cls");
    printf("MENU:\n\n");
    printf("1. Penne rigate\n");
    printf("2. Fusilli\n");
    printf("3. Abbracci\n");
    printf("4. Rigoli\n");
    printf("5. Marmellata more\n");
    printf("6. Marmaellata prugne\n");
    printf("7. Maionese\n");
    printf("8. Birra\n");
    printf("9. Acqua minerale\n");
    printf("10. Burro\n");
    printf("0. Fine\n\n");
    printf("?  ");

    scanf("%d", &sc);
    return sc;
}

/**************************************************************************************************
Funzione per la registrazione delle vendie
**************************************************************************************************/
void Vendita(void)
{
    int                 scelta, cnt, quantita;
    struct magazzino    mag[NUM];
    struct vendite      ven[NUM];
    FILE                *pf;

    if((pf = fopen("Magazzino.txt", "rb")) == NULL)
    {
        printf("Magazzino non trovato");
        getch();
        return;
    }
    for(cnt=0; cnt<NUM; cnt++)
    {
        fread(&mag[cnt], sizeof(struct magazzino), 1, pf);
    }
    fclose(pf);

    if((pf = fopen("Vendite.txt", "rb")) == NULL)
    {
        printf("Vendite non trovato");
        getch();
        return;
    }
    for(cnt=0; cnt<NUM; cnt++)
    {
        fread(&ven[cnt], sizeof(struct vendite), 1, pf);
    }
    fclose(pf);

    do
    {
        scelta = menu_prodotti();
        switch(scelta)
        {
            case 1: printf("Quantita' penne rigate = ");
                    scanf("%d", &quantita);
                    if(quantita > mag[0].Qta)
                    {
                        printf("quantita' non disponibile");
                        getch();
                    }
                    else
                    {
                        mag[0].Qta -= quantita;
                        ven[0].Qta += quantita;
                    }

                    break;
            case 2: printf("Quantita' Fusilli = ");
                    scanf("%d", &quantita);
                    if(quantita > mag[1].Qta)
                    {
                        printf("quantita' non disponibile");
                        getch();
                    }
                    else
                    {
                        mag[1].Qta -= quantita;
                        ven[1].Qta += quantita;
                    }
                    break;
            case 3: printf("Quantita' Abbracci = ");
                    scanf("%d", &quantita);
                    if(quantita > mag[2].Qta)
                    {
                        printf("quantita' non disponibile");
                        getch();
                    }
                    else
                    {
                        mag[2].Qta -= quantita;
                        ven[2].Qta += quantita;
                    }
                    break;
            case 4: printf("Quantita' Rigoli = ");
                    scanf("%d", &quantita);
                    if(quantita > mag[3].Qta)
                    {
                        printf("quantita' non disponibile");
                        getch();
                    }
                    else
                    {
                        mag[3].Qta -= quantita;
                        ven[3].Qta += quantita;
                    }
                    break;
            case 5: printf("Quantita' Marmellata more = ");
                    scanf("%d", &quantita);
                    if(quantita > mag[4].Qta)
                    {
                        printf("quantita' non disponibile");
                        getch();
                    }
                    else
                    {
                        mag[4].Qta -= quantita;
                        ven[4].Qta += quantita;
                    }
                    break;
            case 6: printf("Quantita' Marmaellata prugne = ");
                    scanf("%d", &quantita);
                    if(quantita > mag[5].Qta)
                    {
                        printf("quantita' non disponibile");
                        getch();
                    }
                    else
                    {
                        mag[5].Qta -= quantita;
                        ven[5].Qta += quantita;
                    }
                    break;
            case 7: printf("Quantita' Maionese = ");
                    scanf("%d", &quantita);
                    if(quantita > mag[6].Qta)
                    {
                        printf("quantita' non disponibile");
                        getch();
                    }
                    else
                    {
                        mag[6].Qta -= quantita;
                        ven[6].Qta += quantita;
                    }
                    break;
            case 8: printf("Quantita' Birra = ");
                    scanf("%d", &quantita);
                    if(quantita > mag[7].Qta)
                    {
                        printf("quantita' non disponibile");
                        getch();
                    }
                    else
                    {
                        mag[7].Qta -= quantita;
                        ven[7].Qta += quantita;
                    }
                    break;
            case 9: printf("Quantita' Acqua minerale = ");
                    scanf("%d", &quantita);
                    if(quantita > mag[8].Qta)
                    {
                        printf("quantita' non disponibile");
                        getch();
                    }
                    else
                    {
                        mag[8].Qta -= quantita;
                        ven[8].Qta += quantita;
                    }
                    break;
            case 10: printf("Quantita' Burro = ");
                     scanf("%d", &quantita);
                     if(quantita > mag[9].Qta)
                    {
                        printf("quantita' non disponibile");
                        getch();
                    }
                    else
                    {
                        mag[9].Qta -= quantita;
                        ven[9].Qta += quantita;
                    }
                     break;
        }

    }while(scelta != 0);

    pf = fopen("Magazzino.txt", "wb");
    for(cnt=0; cnt<NUM; cnt++)
    {
        fwrite(&mag[cnt], sizeof(struct magazzino), 1, pf);
    }
    fclose(pf);

    pf = fopen("Vendite.txt", "wb");
    for(cnt=0; cnt<NUM; cnt++)
    {
        fwrite(&ven[cnt], sizeof(struct vendite), 1, pf);
    }
    fclose(pf);
}

/**************************************************************************************************
Funzione per il calcolo dell'incazzo effettuato fino a quel momento
**************************************************************************************************/
void Incasso(void)
{
    int                 cnt, y;
    float               inc, totale;
    struct magazzino    mag[NUM];
    struct vendite      ven[NUM];
    FILE                *pf;

    if((pf = fopen("Magazzino.txt", "rb")) == NULL)
    {
        printf("Magazzino non trovato");
        getch();
        return;
    }
    for(cnt=0; cnt<NUM; cnt++)
    {
        fread(&mag[cnt], sizeof(struct magazzino), 1, pf);
    }
    fclose(pf);

    if((pf = fopen("Vendite.txt", "rb")) == NULL)
    {
        printf("Vendite non trovato");
        getch();
        return;
    }
    for(cnt=0; cnt<NUM; cnt++)
    {
        fread(&ven[cnt], sizeof(struct vendite), 1, pf);
    }
    fclose(pf);

    system("cls");
    gotoxy(1,1);
    printf("PRODOTTO");
    gotoxy(20,1);
    printf("QUANTITA");
    gotoxy(40, 1);
    printf("INCASSO");

    y = 3;
    totale = 0;
    for(cnt=0; cnt<NUM; cnt++)
    {
        gotoxy(1, y);
        printf("%s", ven[cnt].Articolo);
        gotoxy(23, y);
        printf("%d", ven[cnt].Qta);
        inc = ven[cnt].Qta * mag[cnt].PrV;
        gotoxy(43, y);
        printf("%.2f", inc);
        totale += inc;
        y++;
    }

    gotoxy(35, 15);
    printf("Totale");
    gotoxy(43, 15);
    printf("%.2f", totale);
    getch();
}

/**************************************************************************************************
Funzione di atampa del magazzino
**************************************************************************************************/
void Stampa(void)
{
    FILE    *pf;
    struct magazzino app;
    int              cnt;
    int              x, y;

    if((pf = fopen("Magazzino.txt", "rb")) == NULL)
    {
        printf("Magazzino non trovato");
        getch();
        return;
    }

    system("cls");
    gotoxy(1,1);
    printf("PRODOTTO");
    gotoxy(20,1);
    printf("PREZZO ACQUISTO");
    gotoxy(40, 1);
    printf("PREZZO VENDITA");
    gotoxy(60, 1);
    printf("QUANTITA'");

    y = 3;
    for(cnt=0; cnt<NUM; cnt++)
    {
        fread(&app, sizeof(struct magazzino), 1, pf);
        gotoxy(1, y);
        printf("%s", app.Articolo);
        gotoxy(25, y);
        printf("%.2f", app.PrA);
        gotoxy(45, y);
        printf("%.2f", app.PrV);
        gotoxy(63, y);
        printf("%d", app.Qta);
        y++;
    }
    fclose(pf);
    getch();
}

/**************************************************************************************************
Funzione per l'impostazione dei prezzi di acquisto e vendita
**************************************************************************************************/
void Prezzi(void)
{
    int                 cnt, scelta;
    struct magazzino    mag[NUM];
    FILE                *pf;

    if((pf = fopen("Magazzino.txt", "rb")) == NULL)
    {
        printf("Magazzino non trovato");
        getch();
        return;
    }
    for(cnt=0; cnt<NUM; cnt++)
    {
        fread(&mag[cnt], sizeof(struct magazzino), 1, pf);
    }
    fclose(pf);

    do
    {
        scelta = menu_prodotti();
        switch(scelta)
        {
            case 1: printf("Prezzi penne rigate\n");
                    printf("Acquisto   %.2f   ", mag[0].PrA);
                    scanf("%f", &mag[0].PrA);
                    printf("Vendita    %.2f   ", mag[0].PrV);
                    scanf("%f", &mag[0].PrV);
                    break;
            case 2: printf("Prezzi Fusilli");
                    printf("Acquisto   %.2f   ", mag[0].PrA);
                    scanf("%f", &mag[1].PrA);
                    printf("Vendita    %.2f   ", mag[0].PrV);
                    scanf("%f", &mag[1].PrV);
                    break;
            case 3: printf("Prezzi Abbracci");
                    printf("Acquisto   %.2f   ", mag[0].PrA);
                    scanf("%f", &mag[2].PrA);
                    printf("Vendita    %.2f   ", mag[0].PrV);
                    scanf("%f", &mag[2].PrV);
                    break;
            case 4: printf("Prezzi Rigoli");
                    printf("Acquisto   %.2f   ", mag[0].PrA);
                    scanf("%f", &mag[3].PrA);
                    printf("Vendita    %.2f   ", mag[0].PrV);
                    scanf("%f", &mag[3].PrV);
                    break;
            case 5: printf("Prezzi Marmellata more");
                    printf("Acquisto   %.2f   ", mag[0].PrA);
                    scanf("%f", &mag[4].PrA);
                    printf("Vendita    %.2f   ", mag[0].PrV);
                    scanf("%f", &mag[4].PrV);
                    break;
            case 6: printf("Prezzi Marmaellata prugne");
                    printf("Acquisto   %.2f   ", mag[0].PrA);
                    scanf("%f", &mag[5].PrA);
                    printf("Vendita    %.2f   ", mag[0].PrV);
                    scanf("%f", &mag[5].PrV);
                    break;
            case 7: printf("Prezzi Maionese");
                    printf("Acquisto   %.2f   ", mag[0].PrA);
                    scanf("%f", &mag[6].PrA);
                    printf("Vendita    %.2f   ", mag[0].PrV);
                    scanf("%f", &mag[6].PrV);
                    break;
            case 8: printf("Prezzi Birra");
                    printf("Acquisto   %.2f   ", mag[0].PrA);
                    scanf("%f", &mag[7].PrA);
                    printf("Vendita    %.2f   ", mag[0].PrV);
                    scanf("%f", &mag[7].PrV);
                    break;
            case 9: printf("Prezzi Acqua minerale");
                    printf("Acquisto   %.2f   ", mag[0].PrA);
                    scanf("%f", &mag[8].PrA);
                    printf("Vendita    %.2f   ", mag[0].PrV);
                    scanf("%f", &mag[8].PrV);
                    break;
            case 10: printf("Prezzi Burro");
                     printf("Acquisto   %.2f   ", mag[0].PrA);
                     scanf("%f", &mag[9].PrA);
                     printf("Vendita    %.2f   ", mag[0].PrV);
                     scanf("%f", &mag[9].PrV);
                     break;
        }

    }while(scelta != 0);

    pf = fopen("Magazzino.txt", "wb");
    for(cnt=0; cnt<NUM; cnt++)
    {
        fwrite(&mag[cnt], sizeof(struct magazzino), 1, pf);
    }
    fclose(pf);
}

/**************************************************************************************************
Funzione per l'inizializzazione del magazzino e dello ststo delle vendite
vengono impostate le quantità a 0 e i prezzi al valore di default
come riportato all'inizio del listato
**************************************************************************************************/
void Inizializzazione(void)
{
    int                 cnt;
    char                scelta;
    struct magazzino    mag[NUM];
    struct vendite      ven[NUM];
    FILE                *pf;

    printf("Questa procedura imposta tutti i valori di magazzino\n");
    printf("con le quantità azzerate\n");
    printf("Sei sicuro di voler coninuare? (s/n) ");
    fflush(stdin);
    scanf("%c", &scelta);

    if(scelta == 's')
    {
        strcpy(mag[0].Articolo, "Penne rigate");
        strcpy(mag[1].Articolo, "Fusilli");
        strcpy(mag[2].Articolo, "Abbracci");
        strcpy(mag[3].Articolo, "Rigoli");
        strcpy(mag[4].Articolo, "Marmellata more");
        strcpy(mag[5].Articolo, "Marmaellata prugne");
        strcpy(mag[6].Articolo, "Maionese");
        strcpy(mag[7].Articolo, "Birra");
        strcpy(mag[8].Articolo, "Acqua minerale");
        strcpy(mag[9].Articolo, "Burro");

        mag[0].PrA = ACQ_PENNE;
        mag[1].PrA = ACQ_FUSILLI;
        mag[2].PrA = ACQ_ABBRACCI;
        mag[3].PrA = ACQ_RIGOLI;
        mag[4].PrA = ACQ_MORE;
        mag[5].PrA = ACQ_PRUGNE;
        mag[6].PrA = ACQ_MAIO;
        mag[7].PrA = ACQ_BIRRA;
        mag[8].PrA = ACQ_ACQUA;
        mag[9].PrA = ACQ_BURRO;

        mag[0].PrV = VEN_PENNE;
        mag[1].PrV = VEN_FUSILLI;
        mag[2].PrV = VEN_ABBRACCI;
        mag[3].PrV = VEN_RIGOLI;
        mag[4].PrV = VEN_MORE;
        mag[5].PrV = VEN_PRUGNE;
        mag[6].PrV = VEN_MAIO;
        mag[7].PrV = VEN_BIRRA;
        mag[8].PrV = VEN_ACQUA;
        mag[9].PrV = VEN_BURRO;

        mag[0].Qta = 0;
        mag[1].Qta = 0;
        mag[2].Qta = 0;
        mag[3].Qta = 0;
        mag[4].Qta = 0;
        mag[5].Qta = 0;
        mag[6].Qta = 0;
        mag[7].Qta = 0;
        mag[8].Qta = 0;
        mag[9].Qta = 0;

        pf = fopen("Magazzino.txt", "wb");
        for(cnt=0; cnt<NUM; cnt++)
        {
            fwrite(&mag[cnt], sizeof(struct magazzino), 1, pf);
        }
        fclose(pf);

        strcpy(ven[0].Articolo, "Penne rigate");
        strcpy(ven[1].Articolo, "Fusilli");
        strcpy(ven[2].Articolo, "Abbracci");
        strcpy(ven[3].Articolo, "Rigoli");
        strcpy(ven[4].Articolo, "Marmellata more");
        strcpy(ven[5].Articolo, "Marmaellata prugne");
        strcpy(ven[6].Articolo, "Maionese");
        strcpy(ven[7].Articolo, "Birra");
        strcpy(ven[8].Articolo, "Acqua minerale");
        strcpy(ven[9].Articolo, "Burro");

        ven[0].Qta = 0;
        ven[1].Qta = 0;
        ven[2].Qta = 0;
        ven[3].Qta = 0;
        ven[4].Qta = 0;
        ven[5].Qta = 0;
        ven[6].Qta = 0;
        ven[7].Qta = 0;
        ven[8].Qta = 0;
        ven[9].Qta = 0;

        pf = fopen("Vendite.txt", "wb");
        for(cnt=0; cnt<NUM; cnt++)
        {
            fwrite(&ven[cnt], sizeof(struct vendite), 1, pf);
        }
        fclose(pf);

        printf("Fatto");
        getch();
    }
}

void  gotoxy(int x, int  y)
{
    COORD CursorPos = {x, y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, CursorPos);
}

