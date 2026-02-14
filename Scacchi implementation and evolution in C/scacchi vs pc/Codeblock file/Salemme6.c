/***************************************************************************************************
Programma per la gestione degli scrutini di 5 alunni
MENU:
1. Inserimento studenti
2. Verifica Italiano
3. Verifica Matematica
4. Verifica Informatica
5. Scrutinio
0. Fine
?

- Nella Voce "Inserimento" vengono inseriti i nomi degli studenti, i voti a 0 (Immagine1)
  e il tutto viene salvato nel file "Studenti.dat"
- Nelle 3 voci "Verifica" viene assegnato il voto della materia a tutti gli studenti (Immagine2)
  e quindi salvati nel file
- Nello "Scrutinio" si leggono nomi e voti dal file e:
  - se lo studente ha tutte sufficienze viene promosso
  - se lo studente ha 1 o 2 insufficenze viene rimandato
  - se lo studente ha tutte insufficenze viene bocciato
  si utilizzi la funzione gotoxy per visualizzare i dati finali (Immagine3)

  Punteggi:
Voce 1 del menù 1    punto
Voce 2 del menù 1,5  punti
Voce 3 del menù 1,5  punti
Voce 4 del menù 1,5  punti
Voce 5 del menù 2,5  punti
***************************************************************************************************/

#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <time.h>
#include    <conio.h>
#include    <windows.h>

#define     LEN     5


struct studente
{
    char Cognome[20];
    int Voto[3];
};

void Inserimento(void);
void Italiano(void);
void Matematica(void);
void Informatica(void);
void Scrutinio(void);

void  gotoxy(int x, int  y)
{
    COORD CursorPos = {x, y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, CursorPos);
}

int main(void)
{
    int scelta;

    do
    {
        scelta = menu();
        switch(scelta)
        {
            case 1: Inserimento();
                 break;
            case 2: Italiano();
                 break;
            case 3: Matematica();
                 break;
            case 4: Informatica();
                 break;
            case 5: Scrutinio();
                 break;
        }
    }while(scelta);

    remove("Studenti.dat");
}

int menu(void)
{
    int sc;

    system("cls");
    printf("MENU:\nVerifica Informatica\n");
    printf("1. Inserimento studenti\n");
    printf("2. Verifica Italiano\n");
    printf("3. Verifica Matematica\n");
    printf("4. Verifica Informatica\n");
    printf("5. Scrutinio\n");
    printf("0.Fine\n\n");
    printf("?  ");

    scanf("%d", &sc);
    return sc;
}

void Inserimento(void)
{
    struct studente alunni[5];
    FILE *pf;
    int cnt, II;

    pf=fopen("Studenti.dat", "wb");
    fclose(pf);

    system("cls");
    for(cnt=0; cnt<5; cnt++)
    {
        printf("Inserisci il %d cognome: ", cnt+1);
        scanf("%s", alunni[cnt].Cognome);
        for(II=0; II<3; II++)
        {
            alunni[cnt].Voto[II]=0;
        }
    }

    pf=fopen("Studenti.dat", "wb");
    for(cnt=0; cnt<5; cnt++)
    {
        fwrite(&alunni[cnt], sizeof(struct studente), 1, pf);
    }
    fclose(pf);

}

void Italiano(void)
{
    struct studente alunni[5];
    FILE *pf;
    int cnt;

    if(fopen("Studenti.dat", "rb")==NULL)
    {
        printf("Nel file non c'è niente");
    }
    else
    {
        pf=fopen("Studenti.dat", "rb");
        for(cnt=0; cnt<5; cnt++)
        {
            fread(&alunni[cnt], sizeof(struct studente), 1, pf);
        }
        fclose(pf);

        for(cnt=0; cnt<5; cnt++)
        {
            do
            {
                printf("Cognome: %s", alunni[cnt].Cognome);
                printf("\nVoto: ");
                scanf("%d", &alunni[cnt].Voto[0]);
            }while((alunni[cnt].Voto[0]<0) || (alunni[cnt].Voto[0]>10));
        }

        pf=fopen("Studenti.dat", "wb");
        for(cnt=0; cnt<5; cnt++)
        {
            fwrite(&alunni[cnt], sizeof(struct studente), 1, pf);
        }
        fclose(pf);
    }
    getch();
}

void Matematica(void)
{
    struct studente alunni[5];
    FILE *pf;
    int cnt;

    if(fopen("Studenti.dat", "rb")==NULL)
    {
        printf("Nel file non c'è niente");
    }
    else
    {
        pf=fopen("Studenti.dat", "rb");
        for(cnt=0; cnt<5; cnt++)
        {
            fread(&alunni[cnt], sizeof(struct studente), 1, pf);
        }
        fclose(pf);

        for(cnt=0; cnt<5; cnt++)
        {
            do
            {
                printf("Cognome: %s", alunni[cnt].Cognome);
                printf("\nVoto: ");
                scanf("%d", &alunni[cnt].Voto[1]);
            }while((alunni[cnt].Voto[1]<0) || (alunni[cnt].Voto[1]>10));
        }

        pf=fopen("Studenti.dat", "wb");
        for(cnt=0; cnt<5; cnt++)
        {
            fwrite(&alunni[cnt], sizeof(struct studente), 1, pf);
        }
        fclose(pf);
    }
    getch();
}

void Informatica(void)
{
    struct studente alunni[5];
    FILE *pf;
    int cnt;

    if(fopen("Studenti.dat", "rb")==NULL)
    {
        printf("Nel file non c'è niente");
    }
    else
    {
        pf=fopen("Studenti.dat", "rb");
        for(cnt=0; cnt<5; cnt++)
        {
            fread(&alunni[cnt], sizeof(struct studente), 1, pf);
        }
        fclose(pf);

        for(cnt=0; cnt<5; cnt++)
        {
            do
            {
                printf("Cognome: %s", alunni[cnt].Cognome);
                printf("\nVoto: ");
                scanf("%d", &alunni[cnt].Voto[2]);
            }while((alunni[cnt].Voto[2]<0) || (alunni[cnt].Voto[2]>10));
        }

        pf=fopen("Studenti.dat", "wb");
        for(cnt=0; cnt<5; cnt++)
        {
            fwrite(&alunni[cnt], sizeof(struct studente), 1, pf);
        }
        fclose(pf);
    }
    getch();
}

void Scrutinio(void)
{
    struct studente alunni[5];
    FILE *pf;
    int cnt, II;
    int x, y;
    int voti;

    if(fopen("Studenti.dat", "rb")==NULL)
    {
        printf("Nel file non c'è niente");
    }
    else
    {
        pf=fopen("Studenti.dat", "rb");
        for(cnt=0; cnt<5; cnt++)
        {
            fread(&alunni[cnt], sizeof(struct studente), 1, pf);
        }
        fclose(pf);

        system("cls");
        x=1;
        y=1;
        gotoxy(x,y);
        printf("COGNOME");
        x=21;
        gotoxy(x,y);
        printf("VOTO.ITA");
        x=41;
        gotoxy(x,y);
        printf("VOTO.MATE");
        x=61;
        gotoxy(x,y);
        printf("VOTO.INFO");
        for(cnt=0; cnt<5; cnt++)
        {
            voti=0;
            x=1;
            y=cnt+4;
            gotoxy(x,y);
            printf("%s", alunni[cnt].Cognome);
            x=26;
            gotoxy(x,y);
            printf("%d", alunni[cnt].Voto[0]);
            x=46;
            gotoxy(x,y);
            printf("%d", alunni[cnt].Voto[1]);
            x=66;
            gotoxy(x,y);
            printf("%d", alunni[cnt].Voto[2]);
            x=86;
            for(II=0; II<3; II++)
            {
                if(alunni[cnt].Voto[II]<6)
                {
                    voti++;
                }
            }

            gotoxy(x,y);
            if(voti==0)
            {
                printf("PROMOSSO");
            }
            if((voti==1) || (voti==2))
            {
                printf("RIMANDATO");
            }
            if(voti==3)
            {
                printf("BOCCIATO");
            }
        }
    }
    getch();

}



