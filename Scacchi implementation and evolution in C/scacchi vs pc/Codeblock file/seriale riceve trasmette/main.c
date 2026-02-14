/*RS232_openComport ha 3 parametri il primo numero della porta secondo velocita
terzo stringa con il protocollo
restituisce 0 se è andato bene la porta deiverso se non è riuscita
RS232_openComport(Numero della porta, velocita, protocollo)
RS232_openComport(cnt,9600,protocollo);

e poi l'utente indichera che porta utilizzare

protocollo= "8e1";  8 bit, evenparity, bit di stop 1
  lung dato(5,6,7,8), parita(n,o,e), bit stop(1,2)
strcpy(protocollo,"8e1");

RS232_PollComport(numero porta, buffer, spazio)
serve per ricevere i dati e ritorna il numero di byte che ho ricevuto

RS232_SendByte(numero della porta, carattere);
serve per inviare un byte
restituisce 1 se ci è stato un erroe e 0 se è andato bene

                               buffer=stringa di caratteri
RS232_SendBuf(numero della porta, buffer, dimensione della stringa)
serve per inviare una intera stringa

RS232_PollComport(numero della porta, buffer, 255)
      restituisce 1 se è andato bene 0 se male
      e al buffer mette il carattere che è stato inviato*/

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>

#include "rs232.h"

int menu(void);
int vediporta();
int sceltaprotocollo(char protocollo[]);
void invia(char protocollo[], int porta, int velo);
void riceve(char protocollo[], int porta, int velo);

int main(void)
{
    int scelta;
    int porta;
    char protocollo[4];
    int velocita;

    strcpy(protocollo,"");
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
            case    3:  invia(protocollo, porta, velocita);
                    break;
            case    4:  riceve(protocollo, porta, velocita);
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
    printf("\n3.  invia dati");
    printf("\n4.  ricevi dati");
    printf("\n0.  Fine");
    printf("\n\n? ");

    scanf("%d", &sc);
    return sc;
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

void invia(char protocollo[], int porta, int velo)
{
    system("cls");
    int quantiTx;
    unsigned char buffer[255];

    if(RS232_OpenComport(porta,velo,protocollo)==1)
    {
        printf("\nImpossibile aprire la porta\n");
    }
    else
    {
        printf("\nLa porta seriale e' stata aperta ...... ora puoi inviare i dati\n");
        quantiTx=0;
        printf("\nChe cosa vuoi trasmettere?");
        scanf("%s", buffer);
        quantiTx=RS232_SendBuf(porta, buffer, 255);
        if(quantiTx==255)
        {
            printf("Non si è riuscito a trasmettere i dati");
        }
        else
        {
            printf("\nhai trasmesso %d caratteri(buffer)", quantiTx);
        }
        RS232_CloseComport(porta);
    }
    getch();
}

void riceve(char protocollo[], int porta, int velo)
{
    int quantiRx;
    unsigned char buffer[255], mess[255];
    int flag;

    if(RS232_OpenComport(porta,velo,protocollo)==1)
    {
        printf("\nImpossibile aprire la porta\n");
    }
    else
    {
        printf("\nLa porta seriale e' stata aperta ...... ora puoi ricevere i dati\n");
        getch();
        strcpy((char*)buffer, "");
        strcpy((char*)mess, "");
        flag=0;
        quantiRx=0;
        do
        {
            quantiRx=RS232_PollComport(porta, buffer, 255);
            if(quantiRx!=0)
            {
                if(buffer[quantiRx-1]==0)
                {
                    flag = 1;
                }
                else
                {
                    buffer[quantiRx]=0;
                }
                strcat((char*)mess, (char*)buffer);
            }
        }while(flag==0);
        printf("\nIl messaggio inviato è: %s", mess);
        RS232_CloseComport(porta);
    }
    getch();
}

