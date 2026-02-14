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

void mossepedone(struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2], int suogiu);

void mossetorre(struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2]);

void mossecavallo(struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2]);

void mossealfiere(struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2]);

void mosseregina(struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2]);

void mossere(struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2]);

void massimemosse(int pedina, struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2], int suogiu)
{
    if((pedina>0) && (pedina<=8))
    {
        //printf("Pedone");
        mossepedone(giocatore, x, y, largo, alto, totmosse, suogiu);
    }
    if((pedina>8) && (pedina<=10))
    {
        //printf("Torre");
        mossetorre(giocatore, x, y, largo, alto, totmosse);
    }
    if((pedina>10) && (pedina<=12))
    {
        //printf("cavallo");
        mossecavallo(giocatore, x, y, largo, alto, totmosse);
    }
    if((pedina>12) && (pedina<=14))
    {
        //printf("alfiere");
        mossealfiere(giocatore, x, y, largo, alto, totmosse);
    }
    if(pedina==15)
    {
        //printf("regina");
        mosseregina(giocatore, x, y, largo, alto, totmosse);
    }
    if(pedina==16)
    {
        //printf("re");
        mossere(giocatore, x, y, largo, alto, totmosse);
    }
    if(pedina>=20)
    {
        //printf("regina");
        mosseregina(giocatore, x, y, largo, alto, totmosse);
    }
}

void mossepedone(struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2], int suogiu)
{
    int mossex, mossey;
    int cnt;

if(suogiu%2==1)
{
    mossex=x;
    mossey=y;
    cnt=0;
    mossey=mossey-alto;
    totmosse[cnt][0]=mossex;
    totmosse[cnt][1]=mossey;
    cnt++;

    totmosse[cnt][0]=mossex;
    totmosse[cnt][1]=mossey-alto;
    cnt++;

    totmosse[cnt][0]=mossex-largo;
    totmosse[cnt][1]=mossey;
    cnt++;

    totmosse[cnt][0]=mossex+largo;
    totmosse[cnt][1]=mossey;
    cnt++;
}
else
{
    mossex=x;
    mossey=y;
    cnt=0;
    mossey=mossey+alto;
    totmosse[cnt][0]=mossex;
    totmosse[cnt][1]=mossey;
    cnt++;

    totmosse[cnt][0]=mossex;
    totmosse[cnt][1]=mossey+alto;
    cnt++;

    totmosse[cnt][0]=mossex-largo;
    totmosse[cnt][1]=mossey;
    cnt++;

    totmosse[cnt][0]=mossex+largo;
    totmosse[cnt][1]=mossey;
    cnt++;
}

}

void mossetorre(struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2])
{
    int mossex, mossey;
    int cnt, II;

    cnt=0;
    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossex = mossex - largo;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }

    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossex = mossex + largo;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }

    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossey = mossey - alto;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }

    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossey = mossey + alto;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }
}

void mossecavallo(struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2])
{
    int mossex, mossey;
    int cnt;

    cnt=0;
    mossex=x;
    mossey=y;
    mossey=mossey-(alto*2);
    totmosse[cnt][0]=mossex-largo;
    totmosse[cnt][1]=mossey;
    cnt++;
    totmosse[cnt][0]=mossex+largo;
    totmosse[cnt][1]=mossey;
    cnt++;

    mossex=x;
    mossey=y;
    mossey=mossey+(alto*2);
    totmosse[cnt][0]=mossex-largo;
    totmosse[cnt][1]=mossey;
    cnt++;
    totmosse[cnt][0]=mossex+largo;
    totmosse[cnt][1]=mossey;
    cnt++;

    mossex=x;
    mossey=y;
    mossex=mossex-(largo*2);
    totmosse[cnt][0]=mossex;
    totmosse[cnt][1]=mossey-alto;
    cnt++;
    totmosse[cnt][0]=mossex;
    totmosse[cnt][1]=mossey+alto;
    cnt++;

    mossex=x;
    mossey=y;
    mossex=mossex+(largo*2);
    totmosse[cnt][0]=mossex;
    totmosse[cnt][1]=mossey-alto;
    cnt++;
    totmosse[cnt][0]=mossex;
    totmosse[cnt][1]=mossey+alto;
    cnt++;
}

void mossealfiere(struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2])
{
    int mossex, mossey;
    int cnt, II;

    cnt=0;
    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossex = mossex - largo;
        mossey = mossey - alto;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }

    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossex = mossex + largo;
        mossey = mossey - alto;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }

    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossex = mossex - largo;
        mossey = mossey + alto;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }

    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossex = mossex + largo;
        mossey = mossey + alto;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }
}

void mosseregina(struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2])
{
    int mossex, mossey;
    int cnt, II;

    cnt=0;
    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossex = mossex - largo;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }

    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossex = mossex + largo;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }

    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossey = mossey - alto;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }

    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossey = mossey + alto;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }

    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossex = mossex - largo;
        mossey = mossey - alto;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }

    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossex = mossex + largo;
        mossey = mossey - alto;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }

    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossex = mossex - largo;
        mossey = mossey + alto;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }

    mossex=x;
    mossey=y;
    for(II=0; II<7; II++)
    {
        mossex = mossex + largo;
        mossey = mossey + alto;
        totmosse[cnt][0]=mossex;
        totmosse[cnt][1]=mossey;
        cnt++;
    }
}

void mossere(struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2])
{
    int mossex, mossey;
    int cnt;

    cnt=0;
    mossex=x;
    mossey=y;
    totmosse[cnt][0]=mossex+largo;
    totmosse[cnt][1]=mossey;
    cnt++;

    totmosse[cnt][0]=mossex-largo;
    totmosse[cnt][1]=mossey;
    cnt++;

    totmosse[cnt][0]=mossex;
    totmosse[cnt][1]=mossey+alto;
    cnt++;

    totmosse[cnt][0]=mossex;
    totmosse[cnt][1]=mossey-alto;
    cnt++;

    totmosse[cnt][0]=mossex+largo;
    totmosse[cnt][1]=mossey+alto;
    cnt++;

    totmosse[cnt][0]=mossex+largo;
    totmosse[cnt][1]=mossey-alto;
    cnt++;

    totmosse[cnt][0]=mossex-largo;
    totmosse[cnt][1]=mossey+alto;
    cnt++;

    totmosse[cnt][0]=mossex-largo;
    totmosse[cnt][1]=mossey-alto;
    cnt++;

    totmosse[cnt][0]=mossex-largo-largo;
    totmosse[cnt][1]=mossey;
    cnt++;

    totmosse[cnt][0]=mossex+largo+largo;
    totmosse[cnt][1]=mossey;
    cnt++;
}
