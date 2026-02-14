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

void guardatuttepedine(struct giocatore giocatore1, struct giocatore giocatore2, int mossax, int mossay, int *pedine1, int *pedine2)
{
    int II2;
    int cnt1, cnt2;

    *pedine1=0;      //gli azzero in modo che lo zero significhi niente pedine
    *pedine2=0;
                          //controllo del giocatore 1
    cnt1=1;        //numero delle pedine del giocatore 1
    for(II2=0; II2<8; II2++)
    {
        if((mossax==giocatore1.pedoni[II2][0]) && (mossay==giocatore1.pedoni[II2][1]))
        {
            *pedine1=cnt1;
        }
        cnt1++;
    }

    for(II2=0; II2<2; II2++)
    {
        if((mossax==giocatore1.torri[II2][0]) && (mossay==giocatore1.torri[II2][1]))
        {
            *pedine1=cnt1;
        }
        cnt1++;
    }

    for(II2=0; II2<2; II2++)
    {
        if((mossax==giocatore1.cavalli[II2][0]) && (mossay==giocatore1.cavalli[II2][1]))
        {
            *pedine1=cnt1;
        }
        cnt1++;
    }

    for(II2=0; II2<2; II2++)
    {
        if((mossax==giocatore1.alfieri[II2][0]) && (mossay==giocatore1.alfieri[II2][1]))
        {
            *pedine1=cnt1;
        }
        cnt1++;
    }

    if((mossax==giocatore1.regina[0]) && (mossay==giocatore1.regina[1]))
    {
        *pedine1=cnt1;
    }
    cnt1++;

    if((mossax==giocatore1.re[0]) && (mossay==giocatore1.re[1]))
    {
        *pedine1=cnt1;
    }

                             //controllo del giocatore 2
    cnt2=1;        //numero delle pedine del giocatore 2
    for(II2=0; II2<8; II2++)
    {
        if((mossax==giocatore2.pedoni[II2][0]) && (mossay==giocatore2.pedoni[II2][1]))
        {
            *pedine2=cnt2;
        }
        cnt2++;
    }

    for(II2=0; II2<2; II2++)
    {
        if((mossax==giocatore2.torri[II2][0]) && (mossay==giocatore2.torri[II2][1]))
        {
            *pedine2=cnt2;
        }
        cnt2++;
    }

    for(II2=0; II2<2; II2++)
    {
        if((mossax==giocatore2.cavalli[II2][0]) && (mossay==giocatore2.cavalli[II2][1]))
        {
            *pedine2=cnt2;
        }
        cnt2++;
    }

    for(II2=0; II2<2; II2++)
    {
        if((mossax==giocatore2.alfieri[II2][0]) && (mossay==giocatore2.alfieri[II2][1]))
        {
            *pedine2=cnt2;
        }
        cnt2++;
    }

    if((mossax==giocatore2.regina[0]) && (mossay==giocatore2.regina[1]))
    {
        *pedine2=cnt2;
    }
    cnt2++;

    if((mossax==giocatore2.re[0]) && (mossay==giocatore2.re[1]))
    {
        *pedine2=cnt2;
    }
}
