/*
Programma per la gestione delle classi di un triennio di un istituto.
menu
1: iscrizione
2: smistamento alunni
3: stampa alunni
4: stampa classi
5: Inizializzazione

la voce Inizializzazione crea i 4 file utilizzati:
il file "alunni.txt" in cui vengono caricati tutti gli alunni che si iscrivono

il files "Terza", "quarta" e "quinta" in cui vengono caricati gli alunni in base
all'anno di nascita.
 gli alunni nati nel 2006 nel file "Terza"
 gli alunni nel 2005 nel "quarta"
 gli alunni nel 2004 nel "quinto"

 la voce "smistamento" legge il file "alunni" e carica nel file opportuno lo studente appena letto
 il voce "stampa" stampa incollonnati le classi e gli alunni

 i dati degli alunni vengono memorizzati in una struttura cosi fatta:
 struct alunno
 {
    char Cognome[15]
     int Anno;
 }
 */
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <time.h>
#include    <conio.h>

struct alunno
{
    char    Cognome[15];
    int     Anno;
};

void inizializzazione(void);
void iscrizione(void);
void stampaalunni(void);
void smistamento(void);
void stampaclassi(void);

int main(void)
{
    struct alunno alunno;
    int             scelta;

    do
    {
        scelta = menu();
        switch(scelta)
        {
            case 1: iscrizione();
                 break;
            case 2: smistamento();
                 break;
            case 3: stampaalunni();
                 break;
            case 4: stampaclassi();
                 break;
            case 5: inizializzazione();
                 break;
        }
    }while(scelta);
}

int menu(void)
{
    int sc;

    system("cls");
    printf("MENU:\n\n");
    printf("1. Iscrizione\n");
    printf("2. Smistamento alunni\n");
    printf("3. Stampa alunni\n");
    printf("4. Stampa classi\n");
    printf("5. Inizializzazione\n");
    printf("0.Fine\n\n");
    printf("?  ");

    scanf("%d", &sc);
    return sc;
}

void inizializzazione(void)
{
    char sc;
    FILE *pf;

    printf("Cancello il file con tutti i dati? si=1, no=0 ");
    scanf("%d", &sc);
    if(sc == 1)
    {
        pf = fopen("Alunni.txt", "wb");
        fputc(0, pf);
        fclose(pf);
        pf = fopen("Terza.txt", "wb");
        fputc(0, pf);
        fclose(pf);
        pf = fopen("Quarta.txt", "wb");
        fputc(0, pf);
        fclose(pf);
        pf = fopen("Quinta.txt", "wb");
        fputc(0, pf);
        fclose(pf);
        printf("\n\nfatto");
    }

    getch();
}

void iscrizione(void)
{
    struct alunno alunno;
    FILE *pf;
    unsigned char num;

    printf("\nNome: ");
    scanf("%s", alunno.Cognome);
    printf("\nAnno: ");
    scanf("%d", &alunno.Anno);

    pf=fopen("Alunni.txt", "ab");
    fwrite(&alunno, sizeof(struct alunno), 1, pf);
    fclose(pf);
    pf=fopen("Alunni.txt", "r+b");
    fseek(pf, 0, SEEK_SET);
    num=fgetc(pf);
    num++;
    fseek(pf, 0, SEEK_SET);
    fputc(num, pf);
    fclose(pf);
    getch();
}

void stampaalunni(void)
{
    struct alunno alunno;
    FILE *pf;
    unsigned char num;
    int cnt;

    pf = fopen("Alunni.txt", "rb");
    num=fgetc(pf);
    printf("\n");
    for(cnt=0; cnt<num; cnt++)
    {
        fread(&alunno, sizeof(struct alunno), 1, pf);
        printf("%s\t%d\n", alunno.Cognome, alunno.Anno);
    }
    fclose(pf);
    getch();
}

void smistamento(void)
{
    struct alunno alunno;
    FILE *pfA, *pf2;
    unsigned char num, num2;
    int cnt;

    pfA = fopen("Alunni.txt", "rb");
    num=fgetc(pfA);
    for(cnt=0; cnt<num; cnt++)
    {
        fread(&alunno, sizeof(struct alunno), 1, pfA);
        printf("%d\n", alunno.Anno);
        if(alunno.Anno == 2004)
        {
            pf2=fopen("Terza.txt", "ab");
            fwrite(&alunno, sizeof(struct alunno), 1, pf2);
            fclose(pf2);
            pf2=fopen("Terza.txt", "r+b");
            fseek(pf2, 0, SEEK_SET);
            num2=fgetc(pf2);
            num2++;
            fseek(pf2, 0, SEEK_SET);
            fputc(num2, pf2);
            fclose(pf2);
            printf("\n%d terza", cnt);
        }

        if(alunno.Anno == 2005)
        {
            pf2=fopen("Quarta.txt", "ab");
            fwrite(&alunno, sizeof(struct alunno), 1, pf2);
            fclose(pf2);
            pf2=fopen("Quarta.txt", "r+b");
            fseek(pf2, 0, SEEK_SET);
            num2=fgetc(pf2);
            num2++;
            fseek(pf2, 0, SEEK_SET);
            fputc(num2, pf2);
            fclose(pf2);
            printf("\n%d quarta", cnt);
        }

        if(alunno.Anno == 2006)
        {
            pf2=fopen("Quinta.txt", "ab");
            fwrite(&alunno, sizeof(struct alunno), 1, pf2);
            fclose(pf2);
            pf2=fopen("Quinta.txt", "r+b");
            fseek(pf2, 0, SEEK_SET);
            num2=fgetc(pf2);
            num2++;
            fseek(pf2, 0, SEEK_SET);
            fputc(num2, pf2);
            fclose(pf2);
            printf("\n%d quinta", cnt);
        }
    }
    fclose(pfA);
    getch();
}

void stampaclassi(void)
{
    struct alunno alunno;
    FILE *pf;
    unsigned char num;
    int cnt;

    printf("Alunni della terza");
    pf = fopen("Terza.txt", "rb");
    num=fgetc(pf);
    printf("\n");
    for(cnt=0; cnt<num; cnt++)
    {
        fread(&alunno, sizeof(struct alunno), 1, pf);
        printf("%s\t%d\n", alunno.Cognome, alunno.Anno);
    }
    fclose(pf);

    printf("Alunni della quarta");
    pf = fopen("Quarta.txt", "rb");
    num=fgetc(pf);
    printf("\n");
    for(cnt=0; cnt<num; cnt++)
    {
        fread(&alunno, sizeof(struct alunno), 1, pf);
        printf("%s\t%d\n", alunno.Cognome, alunno.Anno);
    }
    fclose(pf);

    printf("Alunni della quinta");
    pf = fopen("Quinta.txt", "rb");
    num=fgetc(pf);
    printf("\n");
    for(cnt=0; cnt<num; cnt++)
    {
        fread(&alunno, sizeof(struct alunno), 1, pf);
        printf("%s\t%d\n", alunno.Cognome, alunno.Anno);
    }
    fclose(pf);

    getch();
}
