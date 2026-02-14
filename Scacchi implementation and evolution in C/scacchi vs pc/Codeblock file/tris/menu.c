#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "rs232.h"

int menu(void);
void  gotoxy(int x, int  y);
int vediporta();
int sceltaprotocollo(char protocollo[]);
void gioco(char protocollo[], int porta, int velo);
void graficagioco(char risp1[5][3], char risp2[5][3], int cnt21, int cnt22);
int devince(char risp[5][3], int cnt);

int simulpc2rand(unsigned char *mess);
int simulpc2risp(unsigned char *mess, char totrisp[9][3], int cnt);

int main(void)
{
    int scelta;
    int porta;
    char protocollo[4];
    int velocita;

    strcpy(protocollo,"");
    srand(time(NULL));
    do
    {
        scelta = menu();
        switch(scelta)
        {
            case    1:  porta=vediporta();
                    break;
            case    2:  velocita=sceltaprotocollo(protocollo);
                        printf("\n protocollo = %s, velocità = %d", protocollo, velocita);
                        getch();
                    break;
            case    3:  gioco(protocollo, porta, velocita);
                    break;
        }
    }while(scelta);

}

int menu(void)
{
    int sc;

    system("Cls");
    printf("\n1.  Vedi porte");
    printf("\n2.  scegli protocollo");
    printf("\n3.  inizia tris");
    printf("\n0.  Fine");
    printf("\n\n? ");

    scanf("%d", &sc);
    return sc;
}

void  gotoxy(int x, int  y)
{
    COORD CursorPos = {x, y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, CursorPos);
}

int vediporta()
{
    int iPortSer, porta;
    int cnt;
    int nporte[16];
    int passa;

    porta=-1;
    cnt=0;
    for(iPortSer=0; iPortSer<16; iPortSer++)
    {
        if(RS232_OpenComport(iPortSer,9600,"8n1")==0)
        {
            printf("********La Com%d e' presente \n", iPortSer);
            RS232_CloseComport(iPortSer);
            nporte[cnt]=iPortSer;
            cnt++;
        }
        else
        {
            printf("La Com%d non e' presente \n", iPortSer);
        }
    }

    if(cnt>0)
    {
        passa=0;
        do
        {
             printf("quale porta seriale vuoi usare?");
             scanf("%d", &porta);

             for(cnt=0; cnt<16; cnt++)
             {
                 if(nporte[cnt] == porta)
                 {
                     passa=1;
                 }
             }

         }while(passa==0);
    }
    else
    {
        printf("\nNon ci sono porte aperte");
    }

    getch();
    return porta;
}

int sceltaprotocollo(char protocollo[])
{
    int vetvelo[]={110,300,600,1200,2400,4800,9600,19200,38400,57600,115200,128000,256000,500000,1000000};
    int velo;
    int cnt;
    int bit;
    char par;
    int stop;

    do
    {
        system("cls");
        for(cnt=0; cnt<15; cnt++)
        {
            printf("\n %d. %d", cnt+1, vetvelo[cnt]);
        }
        printf("\nScegli la velocita con cui trasmettere\n");
        scanf("%d", &velo);
    }while(velo<1 || velo>15);
    velo--;
    velo=vetvelo[velo];

    do
    {
         printf("\nScegli quanti bit vuoi trasmettere (5..8)\n");
         scanf("%d", &bit);
    }while((bit<5) || (bit>8));
    bit=bit+48;
    protocollo[0]=bit;

    do
    {
        printf("\nVuoi aggiungere la parita?");
        scanf("%c", &par);
    }while(par!='s' && par!='n');
    if(par=='n')
    {
        protocollo[1]='n';
    }
    else
    {
        do
        {
            printf("\n Parita pari o dispari?");
            scanf("%c", &par);
        }while(par!='p' && par!='d');
        if(par=='p')
        {
            protocollo[1]='e';
        }
        else
        {
            protocollo[1]='o';
        }
    }

    do
    {
        printf("\nbit di stop 1 o 2?: ");
        scanf("%d", &stop);
    }while(stop<1 || stop>2);
    protocollo[2]=stop+48;
    protocollo[3]='\0';
    getch();
    return velo;
}

void gioco(char protocollo[], int porta, int velo)
{
    system("cls");
    int quantiTx, quantiRx;
    unsigned char *buffer;
    unsigned char buffer2[3];
    unsigned char mess[3];
    int numparte, numparte2; //decide chi parte
    int flag;
    int parteprima;  //decide chi incomincia tramite l'if
    int vince;  //decide chi vince
    char totgiocrisp[9][3]; //tiene conto di tutte le risposte
    char gioc1risp[5][3];  //tiene conto delle tue risposte
    char gioc2risp[5][3];  //tiene conto delle risposte del nemico
    int cnt, cnt21, cnt22, cnt3;  //tiene conto del numero di risposte
    int passa;  //vede se la risposta non è stata già data

    /*if(RS232_OpenComport(porta,velo,protocollo)==1)
    {
        printf("\nImpossibile collegarsi\n");
    }
    else
    {*/
        quantiTx=0;
        numparte=rand()%100;
        buffer=(unsigned char*)numparte;
        printf("il num uscito è %d", buffer);
        //quantiTx=RS232_SendBuf(porta, buffer, 255);
        flag=0;
        quantiRx=0;
        do
        {
            quantiRx=simulpc2rand(mess);
            //quantiRx=RS232_PollComport(porta, mess, 255);
            if(quantiRx!=0)
            {
                flag = 1;
            }
        }while(flag==0);
        printf("\nIl messaggio inviato è: %d", *mess);
        numparte2=*mess;
        if(numparte>numparte2)
        {
            parteprima=0;
        }
        else
        {
            parteprima=1;
        }

        vince=0;
        cnt=0;
        cnt21=0;
        cnt22=0;
        if(parteprima==0)
        {
            do
            {
                graficagioco(gioc1risp, gioc2risp, cnt21, cnt22);
                quantiTx=0;
                do
                {
                    passa=1;
                    do
                    {
                        printf("\nScrivi le cordinate dove vuoi inserire il cerchio(es: 1A)\n");
                        scanf("%s", buffer2);
                    }while(((buffer2[0]<'1') || (buffer2[0]>'3')) || ((buffer2[1]<'A') || (buffer2[1]>'C')));

                    if(cnt==0)
                    {
                        passa=1;
                    }
                    else
                    {
                        for(cnt3=0; cnt3<cnt; cnt3++)
                        {
                            printf("risp %s", totgiocrisp[cnt3]);
                            if(strcmp(totgiocrisp[cnt3],(char *) buffer2)==0)
                            {
                                passa=0;
                            }
                        }
                    }
                }while(passa==0);
                //printf("\nok");
                strcpy(totgiocrisp[cnt],(char *) buffer2);
                strcpy(gioc1risp[cnt21],(char *) buffer2);
                //quantiTx=RS232_SendBuf(porta, buffer, 255);
                cnt++;
                cnt21++;
                if(cnt21>=3)
                {
                    vince=devince(gioc1risp, cnt21);
                }

                graficagioco(gioc1risp, gioc2risp, cnt21, cnt22);
                if(cnt!=9 || vince==0)
                {
                    flag=0;
                    quantiRx=0;
                    do
                    {
                        quantiRx=simulpc2risp(mess, totgiocrisp, cnt);
                        //quantiRx=RS232_PollComport(porta, mess, 255);
                        if(quantiRx!=0)
                        {
                            flag = 1;
                        }
                    }while(flag==0);
                }
                strcpy(totgiocrisp[cnt],(char *) mess);
                strcpy(gioc2risp[cnt22],(char *) mess);
                cnt++;
                cnt22++;
                if(cnt22>=3)
                {
                    vince=devince(gioc2risp, cnt22);
                    if(vince==1)
                    {
                        vince=2;
                    }
                }
                graficagioco(gioc1risp, gioc2risp, cnt21, cnt22);
            }while((vince==0) && (cnt!=9));
        }

        if(vince==1)
        {
            printf("\n\nHai vinto");
        }
        else
        {
            printf("\n\nHai perso");
        }

    /*    RS232_CloseComport(porta);
    }*/
    getch();
}

int simulpc2rand(unsigned char *mess)
{
    int num;

    num=rand()%100;

    *mess=(unsigned char)num;
    return 1;
}

int simulpc2risp(unsigned char *mess, char totrisp[9][3], int cnt)
{
    int passa;
    int cnt3;

    do
    {
        passa=0;
        do
        {
            printf("\nScrivi le cordinate dove vuoi inserire il cerchio(es: 1A)\n");
            scanf("%s", mess);
        }while(((mess[0]<'1') || (mess[0]>'3')) || ((mess[1]<'A') || (mess[1]>'C')));

        if(cnt==0)
        {
            passa=1;
        }
        else
        {
            for(cnt3=0; cnt3<cnt; cnt3++)
            {
                if(strcmp(totrisp[cnt3],(char *) mess)!=0)
                {
                    passa=1;
                }
            }
        }
    }while(passa==0);

    return 1;
}

void graficagioco(char risp1[5][3], char risp2[5][3], int cnt21, int cnt22)
{
    int cnt;
    int x, y;

    system("cls");
    gotoxy(12, 0);
    printf("A");
    gotoxy(28, 0);
    printf("B");
    gotoxy(43, 0);
    printf("C");
    gotoxy(0, 5);
    printf("1");
    gotoxy(0, 13);
    printf("2");
    gotoxy(0, 20);
    printf("3");

    if(cnt22!=0)
    {
        for(cnt=0; cnt<5; cnt++)
        {

        if(risp2[cnt][0]==49)
        {
            y=6;
        }

        if(risp2[cnt][0]==50)
        {
            y=13;
        }

        if(risp2[cnt][0]==51)
        {
            y=20;
        }

        if(risp2[cnt][1]==65)
        {
            x=13;
        }

        if(risp2[cnt][1]==66)
        {
            x=29;
        }

        if(risp2[cnt][1]==67)
        {
            x=44;
        }

        gotoxy(x-8, y-2);
        printf("xx          xx");
        gotoxy(x-6, y-1);
        printf("xxx    xxx");
        gotoxy(x-3, y);
        printf("xxxx");
        gotoxy(x-3, y+1);
        printf("xxxx");
        gotoxy(x-6, y+2);
        printf("xxx    xxx");
        gotoxy(x-8, y+3);
        printf("xx          xx");
        }
    }

    if(cnt21!=0)
    {
        for(cnt=0; cnt<5; cnt++)
        {

        if(risp1[cnt][0]==49)
        {
            y=6;
        }

        if(risp1[cnt][0]==50)
        {
            y=13;
        }

        if(risp1[cnt][0]==51)
        {
            y=20;
        }

        if(risp1[cnt][1]==65)
        {
            x=13;
        }

        if(risp1[cnt][1]==66)
        {
            x=29;
        }

        if(risp1[cnt][1]==67)
        {
            x=44;
        }

        gotoxy(x-3, y-2);
        printf("OOOO");
        gotoxy(x-6, y-1);
        printf("OOO    OOO");
        gotoxy(x-8, y);
        printf("OO          OO");
        gotoxy(x-8, y+1);
        printf("OO          OO");
        gotoxy(x-6, y+2);
        printf("OOO    OOO");
        gotoxy(x-3, y+3);
        printf("OOOO");
        }
    }

    for(cnt=0; cnt<45; cnt++)
    {
        gotoxy(cnt+6, 10);
        printf("-");
        gotoxy(cnt+6, 17);
        printf("-");
    }

    for(cnt=0; cnt<20; cnt++)
    {
        gotoxy(20, cnt+4);
        printf("|");
        gotoxy(35, cnt+4);
        printf("|");
    }
}

int devince(char risp[5][3], int cnt)
{
    int n;
    int vince;
    int vnt;
    vince=0;

    n=0;
    for(vnt=0; vnt<cnt; vnt++)
    {
        if((strcmp(risp[vnt], "1A")==0) || (strcmp(risp[vnt], "1B")==0) || (strcmp(risp[vnt], "1C")==0))
        {
            n++;
            if(n==3)
            {
                vince=1;
            }
        }
    }

    n=0;
    for(vnt=0; vnt<cnt; vnt++)
    {
        if((strcmp(risp[vnt], "2A")==0) || (strcmp(risp[vnt], "2B")==0) || (strcmp(risp[vnt], "2C")==0))
        {
            n++;
            if(n==3)
            {
                vince=1;
            }
        }
    }

    n=0;
    for(vnt=0; vnt<cnt; vnt++)
    {
        if((strcmp(risp[vnt], "3A")==0) || (strcmp(risp[vnt], "3B")==0) || (strcmp(risp[vnt], "3C")==0))
        {
            n++;
            if(n==3)
            {
                vince=1;
            }
        }
    }

    n=0;
    for(vnt=0; vnt<cnt; vnt++)
    {
        if((strcmp(risp[vnt], "1A")==0) || (strcmp(risp[vnt], "2A")==0) || (strcmp(risp[vnt], "3A")==0))
        {
            n++;
            if(n==3)
            {
                vince=1;
            }
        }
    }

    n=0;
    for(vnt=0; vnt<cnt; vnt++)
    {
        if((strcmp(risp[vnt], "1B")==0) || (strcmp(risp[vnt], "2B")==0) || (strcmp(risp[vnt], "3B")==0))
        {
            n++;
            if(n==3)
            {
                vince=1;
            }
        }
    }

    n=0;
    for(vnt=0; vnt<cnt; vnt++)
    {
        if((strcmp(risp[vnt], "1C")==0) || (strcmp(risp[vnt], "2C")==0) || (strcmp(risp[vnt], "3C")==0))
        {
            n++;
            if(n==3)
            {
                vince=1;
            }
        }
    }

    n=0;
    for(vnt=0; vnt<cnt; vnt++)
    {
        if((strcmp(risp[vnt], "1A")==0) || (strcmp(risp[vnt], "2B")==0) || (strcmp(risp[vnt], "3C")==0))
        {
            n++;
            if(n==3)
            {
                vince=1;
            }
        }
    }

    n=0;
    for(vnt=0; vnt<cnt; vnt++)
    {
        if((strcmp(risp[vnt], "1C")==0) || (strcmp(risp[vnt], "2B")==0) || (strcmp(risp[vnt], "3A")==0))
        {
            n++;
            if(n==3)
            {
                vince=1;
            }
        }
    }


    return vince;
}
