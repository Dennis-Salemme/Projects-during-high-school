#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>

struct giocatore
{
    int pedoni[8][2];
    int torri[2][2];
    int cavalli[2][2];
    int alfieri[2][2];
    int regina[2];
    int re[2];
};

int controllopromozioni(int pedone, struct giocatore giocatore, int numpromozione[], int passapromozioni, int alto)
{
    int cnt;
    int salta;
    int ritorna;

    salta=0;
    ritorna=0;
    if(passapromozioni!=0)
    {
        for(cnt=0; cnt<8; cnt++)
        {
            if(pedone-21==numpromozione[cnt])
            {
                salta=1;
            }
        }
    }

    if(salta==0)
    {
        if((giocatore.pedoni[pedone][1]==0) || (giocatore.pedoni[pedone][1]==alto*7))
        {
            numpromozione[passapromozioni]=pedone;
            ritorna=1;
        }
    }

    return ritorna;
}
