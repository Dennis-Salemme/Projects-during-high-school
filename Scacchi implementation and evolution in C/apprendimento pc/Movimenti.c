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

         //confronta i dati di x e y per trovare quale casella è
int vedepedina(int contr[8][2], int *controllox, int *controlloy);

                              //vede le pedine dei 2 giocatori
void guardatuttepedine(struct giocatore giocatore1, struct giocatore giocatore2, int mossax, int mossay, int *pedine1, int *pedine2);

               //mosse delle pedine
void movepedone(struct giocatore giocator1, struct giocatore giocator2, int x, int y,
                int largo, int alto, int nummosse0[], int nummosse1[], int totmosse);

void movetorre(struct giocatore giocator1, struct giocatore giocator2, int x, int y,
                int largo, int alto, int nummosse0[], int nummosse1[]);

void movecavallo(struct giocatore giocator1, struct giocatore giocator2, int x, int y,
                int largo, int alto, int nummosse0[], int nummosse1[]);

void movealfiere(struct giocatore giocator1, struct giocatore giocator2, int x, int y,
                int largo, int alto, int nummosse0[], int nummosse1[]);

void moveregina(struct giocatore giocator1, struct giocatore giocator2, int x, int y,
                int largo, int alto, int nummosse0[], int nummosse1[]);

void movere(struct giocatore giocator1, struct giocatore giocator2, int x, int y,
                int largo, int alto, int nummosse0[], int nummosse1[], int totmosse);

void movimenti(int pedina, struct giocatore *giocator1, struct giocatore *giocator2,
               int x, int y, int largo, int alto, int nummosse0[], int nummosse1[], int *mallocmosse, int totmosse)
{
    if((pedina>0) && (pedina<=8))
    {
        //printf("Pedone");
        movepedone(*giocator1, *giocator2, x, y, largo, alto, nummosse0, nummosse1, totmosse); //mosse del pedone
        *mallocmosse=4;
    }
    if((pedina>8) && (pedina<=10))
    {
        //printf("Torre");
        movetorre(*giocator1, *giocator2, x, y, largo, alto, nummosse0, nummosse1); //mosse della torre
        *mallocmosse=14;
    }
    if((pedina>10) && (pedina<=12))
    {
        //printf("cavallo");
        movecavallo(*giocator1, *giocator2, x, y, largo, alto, nummosse0, nummosse1);
        *mallocmosse=8;
    }
    if((pedina>12) && (pedina<=14))
    {
        //printf("alfiere");
        movealfiere(*giocator1, *giocator2, x, y, largo, alto, nummosse0, nummosse1);
        *mallocmosse=14;
    }
    if(pedina==15)
    {
        //printf("regina");
        moveregina(*giocator1, *giocator2, x, y, largo, alto, nummosse0, nummosse1);
        *mallocmosse=28;
    }
    if(pedina==16)
    {
        //printf("re");
        movere(*giocator1, *giocator2, x, y, largo, alto, nummosse0, nummosse1, totmosse);
        *mallocmosse=10;
    }
    if(pedina>=20)
    {
        //printf("regina");
        moveregina(*giocator1, *giocator2, x, y, largo, alto, nummosse0, nummosse1);
        *mallocmosse=28;
    }

}

void movepedone(struct giocatore giocator1, struct giocatore giocator2, int x, int y,
                int largo, int alto, int nummosse0[], int nummosse1[], int totmosse)
{
    int mossex, mossey;
    int cnt;
    int pedine1, pedine2;
    int suogiu;

    suogiu=totmosse%2;

if(suogiu==1)
{
    mossex=x;
    mossey=y;
    cnt=0;
    mossey=mossey-alto;
    guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
    if((pedine1==0) && (pedine2==0))
    {
        nummosse0[cnt]=mossex;
        nummosse1[cnt]=mossey;
        cnt++;
        if(alto*6==y)
        {
            guardatuttepedine(giocator1, giocator2, mossex, mossey-alto, &pedine1, &pedine2);
            if((pedine1==0) && (pedine2==0))
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey-alto;
                cnt++;
            }
        }
    }

    guardatuttepedine(giocator1, giocator2, mossex-largo, mossey, &pedine1, &pedine2);
    if((pedine2!=0) && (pedine1==0))
    {
        nummosse0[cnt]=mossex-largo;
        nummosse1[cnt]=mossey;
        cnt++;
    }

    guardatuttepedine(giocator1, giocator2, mossex+largo, mossey, &pedine1, &pedine2);
    if((pedine2!=0) && (pedine1==0))
    {
        nummosse0[cnt]=mossex+largo;
        nummosse1[cnt]=mossey;
        cnt++;
    }
}
else
{
    mossex=x;
    mossey=y;
    cnt=0;
    mossey=mossey+alto;
    guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
    if((pedine1==0) && (pedine2==0))
    {
        nummosse0[cnt]=mossex;
        nummosse1[cnt]=mossey;
        cnt++;
        if(alto*1==y)
        {
            guardatuttepedine(giocator1, giocator2, mossex, mossey+alto, &pedine1, &pedine2);
            if((pedine1==0) && (pedine2==0))
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey+alto;
                cnt++;
            }
        }
    }

    guardatuttepedine(giocator1, giocator2, mossex-largo, mossey, &pedine1, &pedine2);
    if((pedine2!=0) && (pedine1==0))
    {
        nummosse0[cnt]=mossex-largo;
        nummosse1[cnt]=mossey;
        cnt++;
    }

    guardatuttepedine(giocator1, giocator2, mossex+largo, mossey, &pedine1, &pedine2);
    if((pedine2!=0) && (pedine1==0))
    {
        nummosse0[cnt]=mossex+largo;
        nummosse1[cnt]=mossey;
        cnt++;
    }
}

}

void movetorre(struct giocatore giocator1, struct giocatore giocator2, int x, int y,
                int largo, int alto, int nummosse0[], int nummosse1[])
{
    int mossex, mossey;
    int cnt, II;
    int pedine1, pedine2;
    int casellax, casellay;
    int nodietropedina;

    cnt=0;
    nodietropedina=0;
    mossex=x;
    mossey=y;
    casellax = mossex / largo;
    casellay = mossey / alto;
    casellax = casellax + 1;   //perchè non intende la casella prima ma quella dopo visto che partono da 0
    casellay = casellay + 1;

    for(II=0; II<casellax-1; II++)
    {
        mossex = mossex - largo;
        guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
        if(pedine1==0)
        {
            if(nodietropedina==0)
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey;
                cnt++;
            }
        }

        if((pedine1!=0) || (pedine2!=0))
        {
            nodietropedina=1;
        }
    }

    mossex=x;
    mossey=y;
    nodietropedina=0;
    for(II=casellax; II<8; II++)
    {
        mossex = mossex + largo;
        guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
        if(pedine1==0)
        {
            if(nodietropedina==0)
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey;
                cnt++;
            }
        }

        if((pedine1!=0) || (pedine2!=0))
        {
            nodietropedina=1;
        }
    }

    mossex = x;
    mossey = y;
    nodietropedina=0;
    for(II=0; II<casellay-1; II++)
    {
        mossey = mossey -alto;
        guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
        if(pedine1==0)
        {
            if(nodietropedina==0)
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey;
                cnt++;
            }
        }

        if((pedine1!=0) || (pedine2!=0))
        {
            nodietropedina=1;
        }
    }

    mossex=x;
    mossey=y;
    nodietropedina=0;
    for(II=casellay; II<8; II++)
    {
        mossey = mossey +alto;
        guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
        if(pedine1==0)
        {
            if(nodietropedina==0)
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey;
                cnt++;
            }
        }

        if((pedine1!=0) || (pedine2!=0))
        {
            nodietropedina=1;
        }
    }

}

void movecavallo(struct giocatore giocator1, struct giocatore giocator2, int x, int y,
                int largo, int alto, int nummosse0[], int nummosse1[])
{
    int mossex, mossey;
    int cnt;
    int pedine1, pedine2;
    int casellax, casellay;

    cnt=0;
    mossex=x;
    mossey=y;
    casellax = mossex / largo;
    casellay = mossey / alto;
    casellax = casellax + 1;   //perchè non intende la casella prima ma quella dopo visto che partono da 0
    casellay = casellay + 1;

    if(casellay>2)
    {
        mossey=mossey-(alto*2);
        if(casellax>1)
        {
            guardatuttepedine(giocator1, giocator2, mossex-largo, mossey, &pedine1, &pedine2);
            if(pedine1==0)
            {
                nummosse0[cnt]=mossex-largo;
                nummosse1[cnt]=mossey;
                cnt++;
            }
        }

        if(casellax<8)
        {
            guardatuttepedine(giocator1, giocator2, mossex+largo, mossey, &pedine1, &pedine2);
            if(pedine1==0)
            {
                nummosse0[cnt]=mossex+largo;
                nummosse1[cnt]=mossey;
                cnt++;
            }
        }
    }

    mossex=x;
    mossey=y;
    if(casellay<7)
    {
        mossey=mossey+(alto*2);
        if(casellax>1)
        {
            guardatuttepedine(giocator1, giocator2, mossex-largo, mossey, &pedine1, &pedine2);
            if(pedine1==0)
            {
                nummosse0[cnt]=mossex-largo;
                nummosse1[cnt]=mossey;
                cnt++;
            }
        }

        if(casellax<8)
        {
            guardatuttepedine(giocator1, giocator2, mossex+largo, mossey, &pedine1, &pedine2);
            if(pedine1==0)
            {
                nummosse0[cnt]=mossex+largo;
                nummosse1[cnt]=mossey;
                cnt++;
            }
        }
    }

    mossex=x;
    mossey=y;
    if(casellax>2)
    {
        mossex=mossex-(largo*2);
        if(casellay>1)
        {
            guardatuttepedine(giocator1, giocator2, mossex, mossey-alto, &pedine1, &pedine2);
            if(pedine1==0)
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey-alto;
                cnt++;
            }
        }

        if(casellay<8)
        {
            guardatuttepedine(giocator1, giocator2, mossex, mossey+alto, &pedine1, &pedine2);
            if(pedine1==0)
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey+alto;
                cnt++;
            }
        }
    }

    mossex=x;
    mossey=y;
    if(casellax<7)
    {
        mossex=mossex+(largo*2);
        if(casellay>1)
        {
            guardatuttepedine(giocator1, giocator2, mossex, mossey-alto, &pedine1, &pedine2);
            if(pedine1==0)
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey-alto;
                cnt++;
            }
        }

        if(casellay<8)
        {
            guardatuttepedine(giocator1, giocator2, mossex, mossey+alto, &pedine1, &pedine2);
            if(pedine1==0)
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey+alto;
                cnt++;
            }
        }
    }
}

void movealfiere(struct giocatore giocator1, struct giocatore giocator2, int x, int y,
                int largo, int alto, int nummosse0[], int nummosse1[])
{
    int mossex, mossey;
    int cnt, II;
    int pedine1, pedine2;
    int nodietropedina;

    cnt=0;
    nodietropedina=0;
    mossex=x;
    mossey=y;
    for(II=0; II<8; II++)
    {
        mossex = mossex - largo;
        mossey = mossey - alto;
        if((mossex>=0) && (mossex<getmaxx()-30))
        {
            if((mossey>=0) && (mossey<getmaxy()-30))
            {
                guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
                if(pedine1==0)
                {
                    if(nodietropedina==0)
                    {
                        nummosse0[cnt]=mossex;
                        nummosse1[cnt]=mossey;
                        cnt++;
                    }
                }

                if((pedine1!=0) || (pedine2!=0))
                {
                    nodietropedina=1;
                 }
             }
         }
    }

    mossex=x;
    mossey=y;
    nodietropedina=0;
    for(II=0; II<8; II++)
    {
        mossex = mossex + largo;
        mossey = mossey - alto;
        if((mossex>=0) && (mossex<getmaxx()-30))
        {
            if((mossey>=0) && (mossey<getmaxy()-30))
            {
                guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
                if(pedine1==0)
                {
                    if(nodietropedina==0)
                    {
                        nummosse0[cnt]=mossex;
                        nummosse1[cnt]=mossey;
                        cnt++;
                    }
                }

                if((pedine1!=0) || (pedine2!=0))
                {
                    nodietropedina=1;
                 }
             }
         }
    }

    mossex = x;
    mossey = y;
    nodietropedina=0;
    for(II=0; II<8; II++)
    {
        mossex = mossex -largo;
        mossey = mossey +alto;
        if((mossex>=0) && (mossex<getmaxx()-30))
        {
            if((mossey>=0) && (mossey<getmaxy()-30))
            {
                guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
                if(pedine1==0)
                {
                    if(nodietropedina==0)
                    {
                        nummosse0[cnt]=mossex;
                        nummosse1[cnt]=mossey;
                        cnt++;
                    }
                }

                if((pedine1!=0) || (pedine2!=0))
                {
                    nodietropedina=1;
                 }
             }
         }
    }

    mossex=x;
    mossey=y;
    nodietropedina=0;
    for(II=0; II<8; II++)
    {
        mossex = mossex +largo;
        mossey = mossey +alto;
        if((mossex>=0) && (mossex<getmaxx()-30))
        {
            if((mossey>=0) && (mossey<getmaxy()-30))
            {
                guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
                if(pedine1==0)
                {
                    if(nodietropedina==0)
                    {
                        nummosse0[cnt]=mossex;
                        nummosse1[cnt]=mossey;
                        cnt++;
                    }
                }

                if((pedine1!=0) || (pedine2!=0))
                {
                    nodietropedina=1;
                 }
             }
         }
    }

}

void moveregina(struct giocatore giocator1, struct giocatore giocator2, int x, int y,
                int largo, int alto, int nummosse0[], int nummosse1[])
{
    int mossex, mossey;
    int cnt, II;
    int pedine1, pedine2;
    int casellax, casellay;
    int nodietropedina;

    cnt=0;
    nodietropedina=0;
    mossex=x;
    mossey=y;
    casellax = mossex / largo;
    casellay = mossey / alto;
    casellax = casellax + 1;   //perchè non intende la casella prima ma quella dopo visto che partono da 0
    casellay = casellay + 1;

    for(II=0; II<casellax-1; II++)
    {
        mossex = mossex - largo;
        guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
        if(pedine1==0)
        {
            if(nodietropedina==0)
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey;
                cnt++;
            }
        }

        if((pedine1!=0) || (pedine2!=0))
        {
            nodietropedina=1;
        }
    }

    mossex=x;
    mossey=y;
    nodietropedina=0;
    for(II=casellax; II<8; II++)
    {
        mossex = mossex + largo;
        guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
        if(pedine1==0)
        {
            if(nodietropedina==0)
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey;
                cnt++;
            }
        }

        if((pedine1!=0) || (pedine2!=0))
        {
            nodietropedina=1;
        }
    }

    mossex = x;
    mossey = y;
    nodietropedina=0;
    for(II=0; II<casellay-1; II++)
    {
        mossey = mossey -alto;
        guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
        if(pedine1==0)
        {
            if(nodietropedina==0)
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey;
                cnt++;
            }
        }

        if((pedine1!=0) || (pedine2!=0))
        {
            nodietropedina=1;
        }
    }

    mossex=x;
    mossey=y;
    nodietropedina=0;
    for(II=casellay; II<8; II++)
    {
        mossey = mossey +alto;
        guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
        if(pedine1==0)
        {
            if(nodietropedina==0)
            {
                nummosse0[cnt]=mossex;
                nummosse1[cnt]=mossey;
                cnt++;
            }
        }

        if((pedine1!=0) || (pedine2!=0))
        {
            nodietropedina=1;
        }
    }

    nodietropedina=0;
    mossex=x;
    mossey=y;
    for(II=0; II<8; II++)
    {
        mossex = mossex - largo;
        mossey = mossey - alto;
        if((mossex>=0) && (mossex<getmaxx()-30))
        {
            if((mossey>=0) && (mossey<getmaxy()-30))
            {
                guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
                if(pedine1==0)
                {
                    if(nodietropedina==0)
                    {
                        nummosse0[cnt]=mossex;
                        nummosse1[cnt]=mossey;
                        cnt++;
                    }
                }

                if((pedine1!=0) || (pedine2!=0))
                {
                    nodietropedina=1;
                 }
             }
         }
    }

    mossex=x;
    mossey=y;
    nodietropedina=0;
    for(II=0; II<8; II++)
    {
        mossex = mossex + largo;
        mossey = mossey - alto;
        if((mossex>=0) && (mossex<getmaxx()-30))
        {
            if((mossey>=0) && (mossey<getmaxy()-30))
            {
                guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
                if(pedine1==0)
                {
                    if(nodietropedina==0)
                    {
                        nummosse0[cnt]=mossex;
                        nummosse1[cnt]=mossey;
                        cnt++;
                    }
                }

                if((pedine1!=0) || (pedine2!=0))
                {
                    nodietropedina=1;
                 }
             }
         }
    }

    mossex = x;
    mossey = y;
    nodietropedina=0;
    for(II=0; II<8; II++)
    {
        mossex = mossex -largo;
        mossey = mossey +alto;
        if((mossex>=0) && (mossex<getmaxx()-30))
        {
            if((mossey>=0) && (mossey<getmaxy()-30))
            {
                guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
                if(pedine1==0)
                {
                    if(nodietropedina==0)
                    {
                        nummosse0[cnt]=mossex;
                        nummosse1[cnt]=mossey;
                        cnt++;
                    }
                }

                if((pedine1!=0) || (pedine2!=0))
                {
                    nodietropedina=1;
                 }
             }
         }
    }

    mossex=x;
    mossey=y;
    nodietropedina=0;
    for(II=0; II<8; II++)
    {
        mossex = mossex +largo;
        mossey = mossey +alto;
        if((mossex>=0) && (mossex<getmaxx()-30))
        {
            if((mossey>=0) && (mossey<getmaxy()-30))
            {
                guardatuttepedine(giocator1, giocator2, mossex, mossey, &pedine1, &pedine2);
                if(pedine1==0)
                {
                    if(nodietropedina==0)
                    {
                        nummosse0[cnt]=mossex;
                        nummosse1[cnt]=mossey;
                        cnt++;
                    }
                }

                if((pedine1!=0) || (pedine2!=0))
                {
                    nodietropedina=1;
                 }
             }
         }
    }

}

void movere(struct giocatore giocator1, struct giocatore giocator2, int x, int y,
                int largo, int alto, int nummosse0[], int nummosse1[], int totmosse)
{
    int mossex, mossey;
    int cnt;
    int pedine1, pedine2;
    int passa;

    mossex=x;
    mossey=y;
    cnt=0;
    if(mossex-largo>=0)
    {
        if(mossey-alto>=0)
        {
            guardatuttepedine(giocator1, giocator2, mossex-largo, mossey-alto, &pedine1, &pedine2);
            if(pedine1==0)
            {
                nummosse0[cnt]=mossex-largo;
                nummosse1[cnt]=mossey-alto;
                cnt++;
            }
        }
    }

    if(mossey-alto>=0)
    {
        guardatuttepedine(giocator1, giocator2, mossex, mossey-alto, &pedine1, &pedine2);
        if(pedine1==0)
        {
            nummosse0[cnt]=mossex;
            nummosse1[cnt]=mossey-alto;
            cnt++;
        }
    }

    if(mossex+largo<=getmaxx()-30)
    {
        if(mossey-alto>=0)
        {
            guardatuttepedine(giocator1, giocator2, mossex+largo, mossey-alto, &pedine1, &pedine2);
            if(pedine1==0)
            {
                nummosse0[cnt]=mossex+largo;
                nummosse1[cnt]=mossey-alto;
                cnt++;
            }
        }
    }

    if(mossex-largo>=0)
    {
        guardatuttepedine(giocator1, giocator2, mossex-largo, mossey, &pedine1, &pedine2);
        if(pedine1==0)
        {
            nummosse0[cnt]=mossex-largo;
            nummosse1[cnt]=mossey;
            cnt++;
        }
    }

    if(mossex+largo<=getmaxx()-30)
    {
        guardatuttepedine(giocator1, giocator2, mossex+largo, mossey, &pedine1, &pedine2);
        //printf("\nc'e amico %d, c'e nemico %d", pedine1, pedine2);
        if(pedine1==0)
        {
            nummosse0[cnt]=mossex+largo;
            nummosse1[cnt]=mossey;
            cnt++;
        }
    }

    if(mossex-largo>=0)
    {
        if(mossey+alto<=getmaxy()-30)
        {
            guardatuttepedine(giocator1, giocator2, mossex-largo, mossey+alto, &pedine1, &pedine2);
            if(pedine1==0)
            {
                nummosse0[cnt]=mossex-largo;
                nummosse1[cnt]=mossey+alto;
                cnt++;
            }
        }
    }

    if(mossey+alto<=getmaxy()-30)
    {
        guardatuttepedine(giocator1, giocator2, mossex, mossey+alto, &pedine1, &pedine2);
        if(pedine1==0)
        {
            nummosse0[cnt]=mossex;
            nummosse1[cnt]=mossey+alto;
            cnt++;
        }
    }

    if(mossex+largo<=getmaxx()-30)
    {
        if(mossey+alto<=getmaxy()-30)
        {
            guardatuttepedine(giocator1, giocator2, mossex+largo, mossey+alto, &pedine1, &pedine2);
            if(pedine1==0)
            {
                nummosse0[cnt]=mossex+largo;
                nummosse1[cnt]=mossey+alto;
                cnt++;
            }
        }
    }

    passa=0;
    if(totmosse%2==1)
    {
        if((mossex==largo*4) && (mossey==alto*7))
        {
            passa=1;
        }
    }
    else
    {
        if((mossex==largo*4) && (mossey==0))
        {
            passa=1;
        }
    }

    if(passa==1)
    {
        guardatuttepedine(giocator1, giocator2, mossex+largo, mossey, &pedine1, &pedine2);
        if((pedine1==0) && (pedine2==0))
        {
            mossex=mossex+largo;
            guardatuttepedine(giocator1, giocator2, mossex+largo, mossey, &pedine1, &pedine2);
            if((pedine1==0) && (pedine2==0))
            {
                mossex=mossex+largo;
                if((mossex+largo==giocator1.torri[1][0]) && (mossey==giocator1.torri[1][1]))
                {
                    nummosse0[cnt]=mossex;
                    nummosse1[cnt]=mossey;
                    cnt++;
                }
            }
        }

        guardatuttepedine(giocator1, giocator2, mossex-largo, mossey, &pedine1, &pedine2);
        if((pedine1==0) && (pedine2==0))
        {
            mossex=mossex-largo;
            guardatuttepedine(giocator1, giocator2, mossex-largo, mossey, &pedine1, &pedine2);
            if((pedine1==0) && (pedine2==0))
            {
                mossex=mossex-largo;
                guardatuttepedine(giocator1, giocator2, mossex-largo, mossey, &pedine1, &pedine2);
                if((pedine1==0) && (pedine2==0))
                {
                    if((mossex-largo-largo==giocator1.torri[0][0]) && (mossey==giocator1.torri[0][1]))
                    {
                        nummosse0[cnt]=mossex;
                        nummosse1[cnt]=mossey;
                        cnt++;
                    }
                }
            }
        }
    }


}
