#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>

struct giocatore
{
    int pedoni[8][2];    //da 1 a 8
    int torri[2][2];     //il 9 e 10
    int cavalli[2][2];   //il 11 e 12
    int alfieri[2][2];   //il 13 e 14
    int regina[2];       //il 15
    int re[2];           //il 16
};

         //confronta i dati di x e y per trovare quale casella è
int vedepedina(int contr[8][2], int *controllox, int *controlloy);

         //vede il colore della casella
int trovacolore(int x, int y, int largo, int alto);

void mangiapedina(int x, int y, struct giocatore *giocator2);

void controllopedine(struct giocatore *giocator, int contr[8][2], int largo, int alto, int *controllox, int *controlloy)
{
     //guarda se nel punto in cui ha cliccato si trova una pedina
    int II1, II2;
    int cnt;
                          //controllox
    II1=1;        //numero della pedina che si trova in quella colonna
    cnt=0;        //numero
    for(II2=0; II2<8; II2++)
    {
        if((*controllox>=giocator->pedoni[II2][0]) && (*controllox<giocator->pedoni[II2][0]+largo))
        {
            contr[cnt][0]=II1;       //vedo se nella colonna x ci sono delle pedoni
            cnt++;
            *controllox=giocator->pedoni[II2][0];  //lo metto cosi riesco poi a capire dove incomincia e finisce la casella
        }
        II1++;
    }

    for(II2=0; II2<2; II2++)
    {
        if((*controllox>=giocator->torri[II2][0]) && (*controllox<giocator->torri[II2][0]+largo))
        {
            contr[cnt][0]=II1;    //vedo se nella colonna x ci sono delle torri
            cnt++;
            *controllox=giocator->torri[II2][0];
        }
        II1++;
    }

    for(II2=0; II2<2; II2++)
    {
        if((*controllox>=giocator->cavalli[II2][0]) && (*controllox<giocator->cavalli[II2][0]+largo))
        {
            contr[cnt][0]=II1;        //vedo se nella colonna x ci sono dei cavalli
            cnt++;
            *controllox=giocator->cavalli[II2][0];
        }
        II1++;
    }

    for(II2=0; II2<2; II2++)
    {
        if((*controllox>=giocator->alfieri[II2][0]) && (*controllox<giocator->alfieri[II2][0]+largo))
        {
            contr[cnt][0]=II1;    //vedo se nella colonna x ci sono dei alfieri
            cnt++;
            *controllox=giocator->alfieri[II2][0];
        }
        II1++;
    }

    if((*controllox>=giocator->regina[0]) && (*controllox<giocator->regina[0]+largo))
    {
        contr[cnt][0]=II1;       //vedo se nella colonna x ci sono della regine
        cnt++;
        *controllox=giocator->regina[0];
    }
    II1++;

    if((*controllox>=giocator->re[0]) && (*controllox<giocator->re[0]+largo))
    {
         contr[cnt][0]=II1;   //vedo se nella colonna x ci sono del re
         *controllox=giocator->re[0];
    }
                         //controlloy
    II1=1;        //numero della pedina che si trova in quella colonna
    cnt=0;        //numero
    for(II2=0; II2<8; II2++)
    {
        if((*controlloy>=giocator->pedoni[II2][1]) && (*controlloy<giocator->pedoni[II2][1]+alto))
        {
            contr[cnt][1]=II1;    //vedo se nella colonna y ci sono delle pedoni
            cnt++;
            *controlloy=giocator->pedoni[II2][1];
        }
        II1++;
    }

    for(II2=0; II2<2; II2++)
    {
        if((*controlloy>=giocator->torri[II2][1]) && (*controlloy<giocator->torri[II2][1]+alto))
        {
            contr[cnt][1]=II1;    //vedo se nella colonna y ci sono delle torri
            cnt++;
            *controlloy=giocator->torri[II2][1];
        }
        II1++;
    }

    for(II2=0; II2<2; II2++)
    {
        if((*controlloy>=giocator->cavalli[II2][1]) && (*controlloy<giocator->cavalli[II2][1]+alto))
        {
            contr[cnt][1]=II1; //vedo se nella colonna y ci sono dei cavalli
            cnt++;
            *controlloy=giocator->cavalli[II2][1];
        }
        II1++;
    }

    for(II2=0; II2<2; II2++)
    {
        if((*controlloy>=giocator->alfieri[II2][1]) && (*controlloy<giocator->alfieri[II2][1]+alto))
        {
            contr[cnt][1]=II1;    //vedo se nella colonna y ci sono dei alfieri
            cnt++;
            *controlloy=giocator->alfieri[II2][1];
        }
        II1++;
    }

    if((*controlloy>=giocator->regina[1]) && (*controlloy<giocator->regina[1]+alto))
    {
        contr[cnt][1]=II1;        //vedo se nella colonna y ci sono della regina
        cnt++;
        *controlloy=giocator->regina[1];
    }
    II1++;

    if((*controlloy>=giocator->re[1]) && (*controlloy<giocator->re[1]+alto))
    {
         contr[cnt][1]=II1;      //vedo se nella colonna y ci sono del re
         *controlloy=giocator->re[1];
    }

}

int vedepedina(int contr[8][2], int *controllox, int *controlloy)
{
    int cnt1, cnt2;
    int oscuraped;

    cnt1=0;
    oscuraped=0;
    do
    {
        cnt2=0;
        do
        {
            if(contr[cnt1][0]==contr[cnt2][1])
            {
               oscuraped=contr[cnt1][0];
            }
            cnt2++;
        }while((cnt2<8) && (contr[cnt2][1]!=0));
        cnt1++;
    }while((cnt1<8) && (contr[cnt1][0]!=0));

    return oscuraped;
}

int cliccatosumossa(int *x, int *y, int largo, int alto, int nummossex, int nummossey, int pedina, struct giocatore *giocator, struct giocatore *giocator2, int totmosse)
{
    int passa;
    int colore;
    char filename[50];
    char numgiocatore[3];

    passa=0;
    //printf("\npedina%d", pedina);
    if((*x>=nummossex) && (*x<nummossex+largo))
    {
        if((*y>=nummossey) && (*y<nummossey+alto))
        {
            *x=nummossex;
            *y=nummossey;
            passa=1;
        }
    }

    if(totmosse%2==1)
    {
        strcpy(numgiocatore, "1");
    }
    else
    {
        strcpy(numgiocatore, "2");
    }

    if(passa==1)
    {
        mangiapedina(nummossex, nummossey, &*giocator2);
        strcpy(filename, "Pedinescacchi/");

        if((pedina>=0) && (pedina<8))
        {
            giocator->pedoni[pedina][0]=*x;
            giocator->pedoni[pedina][1]=*y;

            colore=trovacolore(*x, *y, largo, alto);
            if(colore==0)     //faccio cosi perchè non so mettere il colore e so idiota
            {
                strcat(filename, "Pedonenero");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->pedoni[pedina][0]+3, giocator->pedoni[pedina][1]+3,
                      giocator->pedoni[pedina][0]+largo-3,giocator->pedoni[pedina][1]+alto-3);
            }
            else
            {
                strcat(filename, "Pedonebianco");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->pedoni[pedina][0]+3,giocator->pedoni[pedina][1]+3,
                      giocator->pedoni[pedina][0]+largo-3,giocator->pedoni[pedina][1]+alto-3);
            }
        }
        if((pedina>=8) && (pedina<10))
        {
            giocator->torri[pedina-8][0]=*x;
            giocator->torri[pedina-8][1]=*y;

            colore=trovacolore(*x, *y, largo, alto);
            if(colore==0)     //faccio cosi perchè non so mettere il colore e so idiota
            {
                strcat(filename, "Torrenero");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->torri[pedina-8][0]+3, giocator->torri[pedina-8][1]+3,
                      giocator->torri[pedina-8][0]+largo-3,giocator->torri[pedina-8][1]+alto-3);
            }
            else
            {
                strcat(filename, "Torrebianco");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->torri[pedina-8][0]+3,giocator->torri[pedina-8][1]+3,
                      giocator->torri[pedina-8][0]+largo-3,giocator->torri[pedina-8][1]+alto-3);
            }
        }
        if((pedina>=10) && (pedina<12))
        {
            giocator->cavalli[pedina-10][0]=*x;
            giocator->cavalli[pedina-10][1]=*y;

            colore=trovacolore(*x, *y, largo, alto);
            if(colore==0)     //faccio cosi perchè non so mettere il colore e so idiota
            {
                strcat(filename, "Cavallonero");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->cavalli[pedina-10][0]+3, giocator->cavalli[pedina-10][1]+3,
                      giocator->cavalli[pedina-10][0]+largo-3,giocator->cavalli[pedina-10][1]+alto-3);
            }
            else
            {
                strcat(filename, "Cavallobianco");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->cavalli[pedina-10][0]+3,giocator->cavalli[pedina-10][1]+3,
                      giocator->cavalli[pedina-10][0]+largo-3,giocator->cavalli[pedina-10][1]+alto-3);
            }
        }
        if((pedina>=12) && (pedina<14))
        {
            giocator->alfieri[pedina-12][0]=*x;
            giocator->alfieri[pedina-12][1]=*y;

            colore=trovacolore(*x, *y, largo, alto);
            if(colore==0)     //faccio cosi perchè non so mettere il colore e so idiota
            {
                strcat(filename, "Alfierenero");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->alfieri[pedina-12][0]+3, giocator->alfieri[pedina-12][1]+3,
                      giocator->alfieri[pedina-12][0]+largo-3,giocator->alfieri[pedina-12][1]+alto-3);
            }
            else
            {
                strcat(filename, "Alfierebianco");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->alfieri[pedina-12][0]+3,giocator->alfieri[pedina-12][1]+3,
                      giocator->alfieri[pedina-12][0]+largo-3,giocator->alfieri[pedina-12][1]+alto-3);
            }
        }
        if(pedina==14)
        {
            giocator->regina[0]=*x;
            giocator->regina[1]=*y;

            colore=trovacolore(*x, *y, largo, alto);
            if(colore==0)     //faccio cosi perchè non so mettere il colore e so idiota
            {
                strcat(filename, "Reginanero");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->regina[0]+3, giocator->regina[1]+3,
                      giocator->regina[0]+largo-3,giocator->regina[1]+alto-3);
            }
            else
            {
                strcat(filename, "Reginabianco");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->regina[0]+3,giocator->regina[1]+3,
                      giocator->regina[0]+largo-3,giocator->regina[1]+alto-3);
            }
        }
        if(pedina==15)
        {
            if((*x==giocator->re[0]+largo+largo) || (*x==giocator->re[0]-largo-largo))
            {
                if(*x==giocator->re[0]+largo+largo)
                {
                    colore=trovacolore(giocator->torri[1][0], giocator->torri[1][1], largo, alto);
                    //printf("\n%d", colore);
                    if(colore==0)     //faccio cosi perchè non so mettere il colore e so idiota
                    {
                        readimagefile("Pedinescacchi/Nero.bmp", giocator->torri[1][0], giocator->torri[1][1],
                                      giocator->torri[1][0]+largo-1, giocator->torri[1][1]+alto-1);
                    }
                    else
                    {
                        readimagefile("Pedinescacchi/Bianco.bmp", giocator->torri[1][0], giocator->torri[1][1],
                                      giocator->torri[1][0]+largo-1, giocator->torri[1][1]+alto-1);
                    }

                    giocator->torri[1][0]=*x-largo;
                    giocator->torri[1][1]=*y;

                    colore=trovacolore(*x-largo, *y, largo, alto);
                    if(colore==0)     //faccio cosi perchè non so mettere il colore e so idiota
                    {
                        strcat(filename, "Torrenero");
                        strcat(filename, numgiocatore);
                        strcat(filename, ".bmp");
                        readimagefile(filename, giocator->torri[1][0]+3, giocator->torri[1][1]+3,
                          giocator->torri[1][0]+largo-3,giocator->torri[1][1]+alto-3);
                    }
                    else
                    {
                        strcat(filename, "Torrebianco");
                        strcat(filename, numgiocatore);
                        strcat(filename, ".bmp");
                        readimagefile(filename, giocator->torri[1][0]+3,giocator->torri[1][1]+3,
                          giocator->torri[1][0]+largo-3,giocator->torri[1][1]+alto-3);
                    }
                }
                else
                {
                    colore=trovacolore(giocator->torri[0][0], giocator->torri[0][1], largo, alto);
                    //printf("\n%d", colore);
                    if(colore==0)     //faccio cosi perchè non so mettere il colore e so idiota
                    {
                        readimagefile("Pedinescacchi/Nero.bmp", giocator->torri[0][0], giocator->torri[0][1],
                                      giocator->torri[0][0]+largo-1, giocator->torri[0][1]+alto-1);
                    }
                    else
                    {
                        readimagefile("Pedinescacchi/Bianco.bmp", giocator->torri[0][0], giocator->torri[0][1],
                                      giocator->torri[0][0]+largo-1, giocator->torri[0][1]+alto-1);
                    }

                    giocator->torri[0][0]=*x+largo;
                    giocator->torri[0][1]=*y;

                    colore=trovacolore(*x+largo, *y, largo, alto);
                    if(colore==0)     //faccio cosi perchè non so mettere il colore e so idiota
                    {
                        strcat(filename, "Torrenero");
                        strcat(filename, numgiocatore);
                        strcat(filename, ".bmp");
                        readimagefile(filename, giocator->torri[0][0]+3, giocator->torri[0][1]+3,
                          giocator->torri[0][0]+largo-3,giocator->torri[0][1]+alto-3);
                    }
                    else
                    {
                        strcat(filename, "Torrebianco");
                        strcat(filename, numgiocatore);
                        strcat(filename, ".bmp");
                        readimagefile(filename, giocator->torri[0][0]+3,giocator->torri[0][1]+3,
                          giocator->torri[0][0]+largo-3,giocator->torri[0][1]+alto-3);
                    }
                }

            }

            strcpy(filename, "Pedinescacchi/");
            giocator->re[0]=*x;
            giocator->re[1]=*y;

            colore=trovacolore(*x, *y, largo, alto);
            if(colore==0)     //faccio cosi perchè non so mettere il colore e so idiota
            {
                strcat(filename, "Renero");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->re[0]+3, giocator->re[1]+3,
                      giocator->re[0]+largo-3,giocator->re[1]+alto-3);
            }
            else
            {
                strcat(filename, "Rebianco");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->re[0]+3,giocator->re[1]+3,
                      giocator->re[0]+largo-3,giocator->re[1]+alto-3);
            }
        }
        if(pedina>=20)
        {
            giocator->pedoni[pedina-21][0]=*x;
            giocator->pedoni[pedina-21][1]=*y;

            colore=trovacolore(*x, *y, largo, alto);
            if(colore==0)     //faccio cosi perchè non so mettere il colore e so idiota
            {
                strcat(filename, "Reginanero");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->pedoni[pedina-21][0]+3, giocator->pedoni[pedina-21][1]+3,
                      giocator->pedoni[pedina-21][0]+largo-3,giocator->pedoni[pedina-21][1]+alto-3);
            }
            else
            {
                strcat(filename, "Reginabianco");
                strcat(filename, numgiocatore);
                strcat(filename, ".bmp");
                readimagefile(filename, giocator->pedoni[pedina-21][0]+3,giocator->pedoni[pedina-21][1]+3,
                      giocator->pedoni[pedina-21][0]+largo-3,giocator->pedoni[pedina-21][1]+alto-3);
            }
        }
    }

    return passa;
}

void mangiapedina(int x, int y, struct giocatore *giocator2)
{
    int cnt;

    for(cnt=0; cnt<8; cnt++)
    {
        if((x==giocator2->pedoni[cnt][0]) && (y==giocator2->pedoni[cnt][1]))
        {
            giocator2->pedoni[cnt][0]=getmaxx()+100;
            giocator2->pedoni[cnt][1]=getmaxy()+100;
        }
    }
    for(cnt=0; cnt<2; cnt++)
    {
        if((x==giocator2->torri[cnt][0]) && (y==giocator2->torri[cnt][1]))
        {
            giocator2->torri[cnt][0]=getmaxx()+100;
            giocator2->torri[cnt][1]=getmaxy()+100;
        }
    }
    for(cnt=0; cnt<2; cnt++)
    {
        if((x==giocator2->cavalli[cnt][0]) && (y==giocator2->cavalli[cnt][1]))
        {
            giocator2->cavalli[cnt][0]=getmaxx()+100;
            giocator2->cavalli[cnt][1]=getmaxy()+100;
        }
    }
    for(cnt=0; cnt<2; cnt++)
    {
        if((x==giocator2->alfieri[cnt][0]) && (y==giocator2->alfieri[cnt][1]))
        {
            giocator2->alfieri[cnt][0]=getmaxx()+100;
            giocator2->alfieri[cnt][1]=getmaxy()+100;
        }
    }
    if((x==giocator2->regina[0]) && (y==giocator2->regina[1]))
    {
        giocator2->regina[0]=getmaxx()+100;
        giocator2->regina[1]=getmaxy()+100;
    }
    if((x==giocator2->re[0]) && (y==giocator2->re[1]))
    {
        giocator2->re[0]=getmaxx()+100;
        giocator2->re[1]=getmaxy()+100;
    }
}
