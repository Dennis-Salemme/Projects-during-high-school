#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>

void inserpedoniplayer1(int x, int y, int largo, int alto, struct giocatore *giocatore1);
void inserpedoniplayer2(int x, int y, int largo, int alto, struct giocatore *giocatore2);
void insertorriplayer1(int largo, int alto, struct giocatore *giocatore1);
void insertorriplayer2(int largo, int alto, struct giocatore *giocatore2);
void insercavalliplayer1(int largo, int alto, struct giocatore *giocatore1);
void insercavalliplayer2(int largo, int alto, struct giocatore *giocatore2);
void inseralfieriplayer1(int largo, int alto, struct giocatore *giocatore1);
void inseralfieriplayer2(int largo, int alto, struct giocatore *giocatore2);
void inserreginaplayer1(int largo, int alto, struct giocatore *giocatore1);
void inserreginaplayer2(int largo, int alto, struct giocatore *giocatore2);
void inserreplayer1(int largo, int alto, struct giocatore *giocatore1);
void inserreplayer2(int largo, int alto, struct giocatore *giocatore2);

struct giocatore
{
    int pedoni[8][2];
    int torri[2][2];
    int cavalli[2][2];
    int alfieri[2][2];
    int regina[2];
    int re[2];
};

void inserimentopedine(int maxx, int maxy, struct giocatore *giocatore1, struct giocatore *giocatore2)
{
    int quadlargo, quadalto;     //sono i punti della grandezza dei quadrati della scacchiera

    quadalto=maxy/8;
    quadlargo=maxx/8;

    inserpedoniplayer1(maxx, maxy, quadlargo, quadalto, giocatore1); //pedoni bianchi
    inserpedoniplayer2(maxx, maxy, quadlargo, quadalto, giocatore2); //pedoni neri
    insertorriplayer1(quadlargo, quadalto, giocatore1);  //torri bianche
    insertorriplayer2(quadlargo, quadalto, giocatore2);  //torri nere
    insercavalliplayer1(quadlargo, quadalto, giocatore1);  //cavalli bianchi
    insercavalliplayer2(quadlargo, quadalto, giocatore2);  //cavalli neri
    inseralfieriplayer1(quadlargo, quadalto, giocatore1);  //alfieri bianchi
    inseralfieriplayer2(quadlargo, quadalto, giocatore2);  //alfieri neri
    inserreginaplayer1(quadlargo, quadalto, giocatore1); //regina bianca
    inserreginaplayer2(quadlargo, quadalto, giocatore2); //regina nera
    inserreplayer1(quadlargo, quadalto, giocatore1); //re bianco
    inserreplayer2(quadlargo, quadalto, giocatore2); //re nero
}

void inserpedoniplayer1(int x, int y, int largo, int alto, struct giocatore *giocatore1)
{
    int cnt;
    int tengox;

    tengox=0;
    for(cnt=0; cnt<8; cnt++)
    {
        giocatore1->pedoni[cnt][0]=tengox;   //inserimento della x e y dei pedoni bianchi sul bianco
        giocatore1->pedoni[cnt][1]=alto*6;
        tengox=tengox+largo;
        cnt++;
        giocatore1->pedoni[cnt][0]=tengox;  //inserimento della x e y dei pedoni bianchi sul nero
        giocatore1->pedoni[cnt][1]=alto*6;
        tengox=tengox+largo;
    }

}

void inserpedoniplayer2(int x, int y, int largo, int alto, struct giocatore *giocatore2)
{
    int cnt;
    int tengox;

    tengox=0;
    for(cnt=0; cnt<8; cnt++)
    {
        giocatore2->pedoni[cnt][0]=tengox;  //inserimento della x e y dei pedoni neri sui neri
        giocatore2->pedoni[cnt][1]=alto;
        tengox=tengox+largo;
        cnt++;
        giocatore2->pedoni[cnt][0]=tengox;  //inserimento della x e y dei pedoni neri sui bianchi
        giocatore2->pedoni[cnt][1]=alto;
        tengox=tengox+largo;
    }

}

void insertorriplayer1(int largo, int alto, struct giocatore *giocatore1)
{

    giocatore1->torri[0][0]=0;         //inserimento della x e y  delle torri bianche sul nero
    giocatore1->torri[0][1]=alto*7;

    giocatore1->torri[1][0]=largo*7;   //inserimento della x e y  delle torri bianche sul bianco
    giocatore1->torri[1][1]=alto*7;

}

void insertorriplayer2(int largo, int alto, struct giocatore *giocatore2)
{

    giocatore2->torri[0][0]=0;      //inserimento della x e y delle torri nere sul nero
    giocatore2->torri[0][1]=0;

    giocatore2->torri[1][0]=largo*7;            //inserimento della x e y delle torri nere sul bianco
    giocatore2->torri[1][1]=0;

}

void insercavalliplayer1(int largo, int alto, struct giocatore *giocatore1)
{

    giocatore1->cavalli[0][0]=largo;    //inserimento della x e y dei cavalli bianchi sul bianco
    giocatore1->cavalli[0][1]=alto*7;

    giocatore1->cavalli[1][0]=largo*6;  //inserimento della x e y dei cavalli bianchi sul nero
    giocatore1->cavalli[1][1]=alto*7;

}

void insercavalliplayer2(int largo, int alto, struct giocatore *giocatore2)
{

    giocatore2->cavalli[0][0]=largo;   //inserimento della x e y dei cavalli neri sul nero
    giocatore2->cavalli[0][1]=0;

    giocatore2->cavalli[1][0]=largo*6; //inserimento della x e y dei cavalli neri sul bianco
    giocatore2->cavalli[1][1]=0;

}

void inseralfieriplayer1(int largo, int alto, struct giocatore *giocatore1)
{
    giocatore1->alfieri[0][0]=largo*2;  //inserimento della x e y dei alfieri bianchi sul nero
    giocatore1->alfieri[0][1]=alto*7;

    giocatore1->alfieri[1][0]=largo*5;  //inserimento della x e y dei alfieri bianchi sul bianco
    giocatore1->alfieri[1][1]=alto*7;
}

void inseralfieriplayer2(int largo, int alto, struct giocatore *giocatore2)
{
    giocatore2->alfieri[0][0]=largo*2; //inserimento della x e y dei alfieri neri sul bianco
    giocatore2->alfieri[0][1]=0;

    giocatore2->alfieri[1][0]=largo*5; //inserimento della x e y dei alfieri neri sul nero
    giocatore2->alfieri[1][1]=0;
}

void inserreginaplayer1(int largo, int alto, struct giocatore *giocatore1)
{
    giocatore1->regina[0]=largo*3; //inserimento della x e y della regina bianca sul bianco
    giocatore1->regina[1]=alto*7;
}

void inserreginaplayer2(int largo, int alto, struct giocatore *giocatore2)
{
    giocatore2->regina[0]=largo*3;  //inserimento della x e y della regina nera sul nero
    giocatore2->regina[1]=0;
}

void inserreplayer1(int largo, int alto, struct giocatore *giocatore1)
{
    giocatore1->re[0]=largo*4;  //inserimento della x e y del re bianco sul nero
    giocatore1->re[1]=alto*7;
}

void inserreplayer2(int largo, int alto, struct giocatore *giocatore2)
{
    giocatore2->re[0]=largo*4;  //inserimento della x e y del re nero sul bianco
    giocatore2->re[1]=0;
}
