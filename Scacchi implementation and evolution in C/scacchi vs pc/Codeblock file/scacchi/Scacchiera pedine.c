#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>

void pedoniplayer1(int largo, int alto, struct giocatore *giocatore1);
void pedoniplayer2(int largo, int alto, struct giocatore *giocatore2);
void torriplayer1(int largo, int alto, struct giocatore *giocatore1);
void torriplayer2(int largo, int alto, struct giocatore *giocatore2);
void cavalliplayer1(int largo, int alto, struct giocatore *giocatore1);
void cavalliplayer2(int largo, int alto, struct giocatore *giocatore2);
void alfieriplayer1(int largo, int alto, struct giocatore *giocatore1);
void alfieriplayer2(int largo, int alto, struct giocatore *giocatore2);
void reginaplayer1(int largo, int alto, struct giocatore *giocatore1);
void reginaplayer2(int largo, int alto, struct giocatore *giocatore2);
void replayer1(int largo, int alto, struct giocatore *giocatore1);
void replayer2(int largo, int alto, struct giocatore *giocatore2);

struct giocatore
{
    int pedoni[8][2];
    int torri[2][2];
    int cavalli[2][2];
    int alfieri[2][2];
    int regina[2];
    int re[2];
};

void scacchierapedine(int maxx, int maxy, struct giocatore *giocatore1, struct giocatore *giocatore2)
{
    int quadlargo, quadalto;

    quadalto=maxy/8;
    quadlargo=maxx/8;
    quadlargo=quadlargo-4;
    quadalto=quadalto-4;

    pedoniplayer1(quadlargo, quadalto, giocatore1);  //stampa immagine dei pedoni bianchi
    pedoniplayer2(quadlargo, quadalto, giocatore2);  //stampa immagine dei pedoni neri
    torriplayer1(quadlargo, quadalto, giocatore1);  //stampa immagine delle torri bianche
    torriplayer2(quadlargo, quadalto, giocatore2);  //stampa immagine delle torri nere
    cavalliplayer1(quadlargo, quadalto, giocatore1);  //stampa immagine dei cavalli bianchi
    cavalliplayer2(quadlargo, quadalto, giocatore2);  //stampa immagine dei cavalli neri
    alfieriplayer1(quadlargo, quadalto, giocatore1);  //stampa immagine dei alfieri bianchi
    alfieriplayer2(quadlargo, quadalto, giocatore2);  //stampa immagine dei alfieri neri
    reginaplayer1(quadlargo, quadalto, giocatore1);  //stampa immagine della regina bianca
    reginaplayer2(quadlargo, quadalto, giocatore2);  //stampa immagine della regina nera
    replayer1(quadlargo, quadalto, giocatore1);  //stampa immagine della re bianca
    replayer2(quadlargo, quadalto, giocatore2);  //stampa immagine della re nero
}

void pedoniplayer1(int largo, int alto, struct giocatore *giocatore1)
{
    int cnt;            //stampa immagine dei pedoni bianchi

    for(cnt=0; cnt<8; cnt++)
    {
        readimagefile("Pedinescacchi/Pedonebianco1.bmp",giocatore1->pedoni[cnt][0]+3,giocatore1->pedoni[cnt][1]+3,
                      giocatore1->pedoni[cnt][0]+largo,giocatore1->pedoni[cnt][1]+alto);
        cnt++;
        readimagefile("Pedinescacchi/Pedonenero1.bmp",giocatore1->pedoni[cnt][0]+3, giocatore1->pedoni[cnt][1]+3,
                      giocatore1->pedoni[cnt][0]+largo,giocatore1->pedoni[cnt][1]+alto);
    }
}

void pedoniplayer2(int largo, int alto, struct giocatore *giocatore2)
{
    int cnt;             //stampa immagine dei pedoni neri

    for(cnt=0; cnt<8; cnt++)
    {
        readimagefile("Pedinescacchi/Pedonenero2.bmp",giocatore2->pedoni[cnt][0]+3, giocatore2->pedoni[cnt][1]+3,
                      giocatore2->pedoni[cnt][0]+largo,giocatore2->pedoni[cnt][1]+alto);
        cnt++;
        readimagefile("Pedinescacchi/Pedonebianco2.bmp",giocatore2->pedoni[cnt][0]+3,giocatore2->pedoni[cnt][1]+3,
                      giocatore2->pedoni[cnt][0]+largo,giocatore2->pedoni[cnt][1]+alto);
    }
}

void torriplayer1(int largo, int alto, struct giocatore *giocatore1)
{
                      //stampa immagine delle torri bianche
    readimagefile("Pedinescacchi/Torrenero1.bmp",giocatore1->torri[0][0]+3,giocatore1->torri[0][1]+3,
                  giocatore1->torri[0][0]+largo,giocatore1->torri[0][1]+alto);

    readimagefile("Pedinescacchi/Torrebianco1.bmp",giocatore1->torri[1][0]+3,giocatore1->torri[1][1]+3,
                  giocatore1->torri[1][0]+largo,giocatore1->torri[1][1]+alto);
}

void torriplayer2(int largo, int alto, struct giocatore *giocatore2)
{
                             //stampa immagine delle torri nere
    readimagefile("Pedinescacchi/Torrebianco2.bmp",giocatore2->torri[0][0]+3,giocatore2->torri[0][1]+3,
                  giocatore2->torri[0][0]+largo,giocatore2->torri[0][1]+alto);

    readimagefile("Pedinescacchi/Torrenero2.bmp",giocatore2->torri[1][0]+3,giocatore2->torri[1][1]+3,
                  giocatore2->torri[1][0]+largo,giocatore2->torri[1][1]+alto);
}

void cavalliplayer1(int largo, int alto, struct giocatore *giocatore1)
{
                               //stampa immagine dei cavalli bianchi
    readimagefile("Pedinescacchi/Cavallobianco1.bmp",giocatore1->cavalli[0][0]+3,giocatore1->cavalli[0][1]+3,
                  giocatore1->cavalli[0][0]+largo,giocatore1->cavalli[0][1]+alto);

    readimagefile("Pedinescacchi/Cavallonero1.bmp",giocatore1->cavalli[1][0]+3,giocatore1->cavalli[1][1]+3,
                  giocatore1->cavalli[1][0]+largo,giocatore1->cavalli[1][1]+alto);
}

void cavalliplayer2(int largo, int alto, struct giocatore *giocatore2)
{
                             //stampa immagine dei cavalli neri
    readimagefile("Pedinescacchi/Cavallonero2.bmp",giocatore2->cavalli[0][0]+3,giocatore2->cavalli[0][1]+3,
                  giocatore2->cavalli[0][0]+largo,giocatore2->cavalli[0][1]+alto);

    readimagefile("Pedinescacchi/Cavallobianco2.bmp",giocatore2->cavalli[1][0]+3,giocatore2->cavalli[1][1]+3,
                  giocatore2->cavalli[1][0]+largo,giocatore2->cavalli[1][1]+alto);
}

void alfieriplayer1(int largo, int alto, struct giocatore *giocatore1)
{
                               //stampa immagine dei alfieri bianchi
    readimagefile("Pedinescacchi/Alfierenero1.bmp",giocatore1->alfieri[0][0]+3,giocatore1->alfieri[0][1]+3,
                  giocatore1->alfieri[0][0]+largo,giocatore1->alfieri[0][1]+alto);

    readimagefile("Pedinescacchi/Alfierebianco1.bmp",giocatore1->alfieri[1][0]+3,giocatore1->alfieri[1][1]+3,
                  giocatore1->alfieri[1][0]+largo,giocatore1->alfieri[1][1]+alto);
}

void alfieriplayer2(int largo, int alto, struct giocatore *giocatore2)
{
                              //stampa immagine dei alfieri neri
    readimagefile("Pedinescacchi/Alfierebianco2.bmp",giocatore2->alfieri[0][0]+3,giocatore2->alfieri[0][1]+3,
                  giocatore2->alfieri[0][0]+largo,giocatore2->alfieri[0][1]+alto);

    readimagefile("Pedinescacchi/Alfierenero2.bmp",giocatore2->alfieri[1][0]+3,giocatore2->alfieri[1][1]+3,
                  giocatore2->alfieri[1][0]+largo,giocatore2->alfieri[1][1]+alto);
}

void reginaplayer1(int largo, int alto, struct giocatore *giocatore1)
{
                           //stampa immagine della regina bianca
    readimagefile("Pedinescacchi/Reginabianco1.bmp",giocatore1->regina[0]+3,giocatore1->regina[1]+3,
                  giocatore1->regina[0]+largo,giocatore1->regina[1]+alto);
}

void reginaplayer2(int largo, int alto, struct giocatore *giocatore2)
{
                        //stampa immagine della regina nera
    readimagefile("Pedinescacchi/Reginanero2.bmp",giocatore2->regina[0]+3,giocatore2->regina[1]+3,
                  giocatore2->regina[0]+largo,giocatore2->regina[1]+alto);
}

void replayer1(int largo, int alto, struct giocatore *giocatore1)
{
                         //stampa immagine della re bianca
    readimagefile("Pedinescacchi/Renero1.bmp",giocatore1->re[0]+3,giocatore1->re[1]+3,
                  giocatore1->re[0]+largo,giocatore1->re[1]+alto);
}

void replayer2(int largo, int alto, struct giocatore *giocatore2)
{
                         //stampa immagine della re nero
    readimagefile("Pedinescacchi/Rebianco2.bmp",giocatore2->re[0]+3,giocatore2->re[1]+3,
                  giocatore2->re[0]+largo,giocatore2->re[1]+alto);
}
