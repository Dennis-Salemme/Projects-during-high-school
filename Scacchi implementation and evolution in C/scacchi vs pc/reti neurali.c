#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <time.h>
#include    <conio.h>
#include    <math.h>

#define  PERCENTUALE 100

struct giocatore
{
    int pedoni[8][2];
    int torri[2][2];
    int cavalli[2][2];
    int alfieri[2][2];
    int regina[2];
    int re[2];
};

struct tuttineuroni
{
    float pesixy1[30][64];//in input metto le posizioni di tutte le pedine
    float biasxy1[30];
    float pesixy2[30][30];
    float biasxy2[30];
    float pesixy3[16][30];
    float biasxy3[16];

    float pesipedone1[30][64];//in input metto le posizioni di tutte le pedine
    float biaspedone1[30];
    float pesipedone2[30][30];
    float biaspedone2[30];
    float pesipedone3[4][30];
    float biaspedone3[4];

    float pesitorre1[30][64];//in input metto le posizioni di tutte le pedine
    float biastorre1[30];
    float pesitorre2[30][30];
    float biastorre2[30];
    float pesitorre3[28][30];
    float biastorre3[28];

    float pesicavallo1[30][64];//in input metto le posizioni di tutte le pedine
    float biascavallo1[30];
    float pesicavallo2[30][30];
    float biascavallo2[30];
    float pesicavallo3[8][30];
    float biascavallo3[8];

    float pesialfiere1[30][64];//in input metto le posizioni di tutte le pedine
    float biasalfiere1[30];
    float pesialfiere2[30][30];
    float biasalfiere2[30];
    float pesialfiere3[28][30];
    float biasalfiere3[28];

    float pesiregina1[30][64];//in input metto le posizioni di tutte le pedine
    float biasregina1[30];
    float pesiregina2[30][30];
    float biasregina2[30];
    float pesiregina3[56][30];
    float biasregina3[56];

    float pesire1[30][64];//in input metto le posizioni di tutte le pedine
    float biasre1[30];
    float pesire2[30][30];
    float biasre2[30];
    float pesire3[10][30];
    float biasre3[10];
};

void tuttemossecomputer(int pedina, int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[]);

void computerpedone(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[]);
void computertorre(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[]);
void computercavallo(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[]);
void computeralfiere(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[]);
void computerregina(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[]);
void computerre(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[]);

void reteneuronalepedoni(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[])
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    int input[64];
    float moltiplicazione;
    float sommepesate[56];
    float outputneuroni1[30];
    float outputneuroni2[30];
    float sommasoftmax;
    float outputneuroni3[16];
    int cnt, cnt1, cnt2, II;
    int giocata;
    float mossa;
    float lista[16];

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=0;
    }

    if(totmosse%2==1)
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=input[cnt]/1000;
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesixy1[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biasxy1[cnt];
        //printf("\n%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni1[cnt]=0;
        outputneuroni1[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t%f", outputneuroni1[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni1[II]*strneuroni.pesixy2[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biasxy2[cnt];
        //printf("\n\t\t%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni2[cnt]=0;
        outputneuroni2[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t\t\t%f", outputneuroni2[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<16; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni2[cnt]*strneuroni.pesixy3[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biasxy3[cnt];
        //printf("\n\t\t\t\t%f", sommepesate[cnt]);
    }

    sommasoftmax=0;
    for(cnt=0; cnt<16; cnt++)
    {
        outputneuroni3[cnt]=0;
        sommasoftmax=sommasoftmax + exp(sommepesate[cnt]);
    }

    for(cnt=0; cnt<16; cnt++)
    {
        outputneuroni3[cnt]=exp(sommepesate[cnt])/ sommasoftmax;
        //printf("\n%f", outputneuroni3[cnt]);
    }

    giocata=0;
    for(cnt=0; cnt<16; cnt++)
    {
        classifica[cnt]=0;
        lista[cnt]=outputneuroni3[cnt];
    }

    for(cnt=0; cnt<16; cnt++)
    {
        //printf("\n%f", lista[cnt]);
    }

    for(cnt=0; cnt<16; cnt++)
    {
        mossa=0;
        for(cnt1=0; cnt1<16; cnt1++)
        {
            if(mossa<lista[cnt1])
            {
                mossa=lista[cnt1];
                giocata=cnt1;
            }
        }
        classifica[cnt]=giocata+1;
        lista[giocata]=0;
    }

    for(cnt=0; cnt<16; cnt++)
    {
        //printf("\n%d", classifica[cnt]);
    }
}


void tuttemossecomputer(int pedina, int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[])
{
    if((pedina>0) && (pedina<=8))
    {
        computerpedone(totmosse, giocatore1, giocatore2, classifica);
    }
    if((pedina>8) && (pedina<=10))
    {
        computertorre(totmosse, giocatore1, giocatore2, classifica);
    }
    if((pedina>10) && (pedina<=12))
    {
        computercavallo(totmosse, giocatore1, giocatore2, classifica);
    }
    if((pedina>12) && (pedina<=14))
    {
        computeralfiere(totmosse, giocatore1, giocatore2, classifica);
    }
    if(pedina==15)
    {
        computerregina(totmosse, giocatore1, giocatore2, classifica);
    }
    if(pedina==16)
    {
        computerre(totmosse, giocatore1, giocatore2, classifica);
    }
    if(pedina>=20)
    {
        computerregina(totmosse, giocatore1, giocatore2, classifica);
    }
}

void computerpedone(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[])
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    int input[64];
    float moltiplicazione;
    float sommepesate[56];
    float outputneuroni1[30];
    float outputneuroni2[30];
    float sommasoftmax;
    float outputneuroni3[4];
    int cnt, cnt1, cnt2, II;
    int giocata;
    float mossa;
    float lista[4];

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=0;
    }

    if(totmosse%2==1)
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=input[cnt]/1000;
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesipedone1[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biaspedone1[cnt];
        //printf("\n%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni1[cnt]=0;
        outputneuroni1[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t%f", outputneuroni1[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni1[II]*strneuroni.pesipedone2[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biaspedone2[cnt];
        //printf("\n\t\t%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni2[cnt]=0;
        outputneuroni2[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t\t\t%f", outputneuroni2[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<4; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni2[cnt]*strneuroni.pesipedone3[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biaspedone3[cnt];
        //printf("\n\t\t\t\t%f", sommepesate[cnt]);
    }

    sommasoftmax=0;
    for(cnt=0; cnt<4; cnt++)
    {
        outputneuroni3[cnt]=0;
        sommasoftmax=sommasoftmax + exp(sommepesate[cnt]);
    }

    for(cnt=0; cnt<4; cnt++)
    {
        outputneuroni3[cnt]=exp(sommepesate[cnt])/ sommasoftmax;
        //printf("\n%f", outputneuroni3[cnt]);
    }

    giocata=0;
    for(cnt=0; cnt<4; cnt++)
    {
        classifica[cnt]=0;
        lista[cnt]=outputneuroni3[cnt];
    }

    for(cnt=0; cnt<4; cnt++)
    {
        //printf("\n%f", lista[cnt]);
    }

    for(cnt=0; cnt<4; cnt++)
    {
        mossa=0;
        for(cnt1=0; cnt1<4; cnt1++)
        {
            if(mossa<lista[cnt1])
            {
                mossa=lista[cnt1];
                giocata=cnt1;
            }
        }
        classifica[cnt]=giocata;
        lista[giocata]=0;
    }

    for(cnt=0; cnt<4; cnt++)
    {
        //printf("\n%d", classifica[cnt]);
    }
}

void computertorre(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[])
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    int input[64];
    float moltiplicazione;
    float sommepesate[56];
    float outputneuroni1[30];
    float outputneuroni2[30];
    float sommasoftmax;
    float outputneuroni3[28];
    int cnt, cnt1, cnt2, II;
    int giocata;
    float mossa;
    float lista[28];

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=0;
    }

    if(totmosse%2==1)
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=input[cnt]/1000;
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesitorre1[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biastorre1[cnt];
        //printf("\n%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni1[cnt]=0;
        outputneuroni1[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t%f", outputneuroni1[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni1[II]*strneuroni.pesitorre2[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biastorre2[cnt];
        //printf("\n\t\t%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni2[cnt]=0;
        outputneuroni2[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t\t\t%f", outputneuroni2[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<28; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni2[cnt]*strneuroni.pesitorre3[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biastorre3[cnt];
        //printf("\n\t\t\t\t%f", sommepesate[cnt]);
    }

    sommasoftmax=0;
    for(cnt=0; cnt<28; cnt++)
    {
        outputneuroni3[cnt]=0;
        sommasoftmax=sommasoftmax + exp(sommepesate[cnt]);
    }

    for(cnt=0; cnt<28; cnt++)
    {
        outputneuroni3[cnt]=exp(sommepesate[cnt])/ sommasoftmax;
        //printf("\n%f", outputneuroni3[cnt]);
    }

    giocata=0;
    for(cnt=0; cnt<28; cnt++)
    {
        classifica[cnt]=0;
        lista[cnt]=outputneuroni3[cnt];
    }

    for(cnt=0; cnt<28; cnt++)
    {
        //printf("\n%f", lista[cnt]);
    }

    for(cnt=0; cnt<28; cnt++)
    {
        mossa=0;
        for(cnt1=0; cnt1<28; cnt1++)
        {
            if(mossa<lista[cnt1])
            {
                mossa=lista[cnt1];
                giocata=cnt1;
            }
        }
        classifica[cnt]=giocata;
        lista[giocata]=0;
    }

    for(cnt=0; cnt<28; cnt++)
    {
        //printf("\n%d", classifica[cnt]);
    }
}

void computercavallo(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[])
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    int input[64];
    float moltiplicazione;
    float sommepesate[56];
    float outputneuroni1[30];
    float outputneuroni2[30];
    float sommasoftmax;
    float outputneuroni3[8];
    int cnt, cnt1, cnt2, II;
    int giocata;
    float mossa;
    float lista[8];

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=0;
    }

    if(totmosse%2==1)
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=input[cnt]/1000;
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesicavallo1[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biascavallo1[cnt];
        //printf("\n%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni1[cnt]=0;
        outputneuroni1[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t%f", outputneuroni1[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni1[II]*strneuroni.pesicavallo2[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biascavallo2[cnt];
        //printf("\n\t\t%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni2[cnt]=0;
        outputneuroni2[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t\t\t%f", outputneuroni2[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<8; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni2[cnt]*strneuroni.pesicavallo3[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biascavallo3[cnt];
        //printf("\n\t\t\t\t%f", sommepesate[cnt]);
    }

    sommasoftmax=0;
    for(cnt=0; cnt<8; cnt++)
    {
        outputneuroni3[cnt]=0;
        sommasoftmax=sommasoftmax + exp(sommepesate[cnt]);
    }

    for(cnt=0; cnt<8; cnt++)
    {
        outputneuroni3[cnt]=exp(sommepesate[cnt])/ sommasoftmax;
        //printf("\n%f", outputneuroni3[cnt]);
    }

    giocata=0;
    for(cnt=0; cnt<8; cnt++)
    {
        classifica[cnt]=0;
        lista[cnt]=outputneuroni3[cnt];
    }

    for(cnt=0; cnt<8; cnt++)
    {
        //printf("\n%f", lista[cnt]);
    }

    for(cnt=0; cnt<8; cnt++)
    {
        mossa=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            if(mossa<lista[cnt1])
            {
                mossa=lista[cnt1];
                giocata=cnt1;
            }
        }
        classifica[cnt]=giocata;
        lista[giocata]=0;
    }

    for(cnt=0; cnt<8; cnt++)
    {
        //printf("\n%d", classifica[cnt]);
    }
}

void computeralfiere(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[])
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    int input[64];
    float moltiplicazione;
    float sommepesate[56];
    float outputneuroni1[30];
    float outputneuroni2[30];
    float sommasoftmax;
    float outputneuroni3[28];
    int cnt, cnt1, cnt2, II;
    int giocata;
    float mossa;
    float lista[28];

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=0;
    }

    if(totmosse%2==1)
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=input[cnt]/1000;
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesialfiere1[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biasalfiere1[cnt];
        //printf("\n%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni1[cnt]=0;
        outputneuroni1[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t%f", outputneuroni1[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni1[II]*strneuroni.pesialfiere2[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biasalfiere2[cnt];
        //printf("\n\t\t%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni2[cnt]=0;
        outputneuroni2[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t\t\t%f", outputneuroni2[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<28; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni2[cnt]*strneuroni.pesialfiere3[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biasalfiere3[cnt];
        //printf("\n\t\t\t\t%f", sommepesate[cnt]);
    }

    sommasoftmax=0;
    for(cnt=0; cnt<28; cnt++)
    {
        outputneuroni3[cnt]=0;
        sommasoftmax=sommasoftmax + exp(sommepesate[cnt]);
    }

    for(cnt=0; cnt<28; cnt++)
    {
        outputneuroni3[cnt]=exp(sommepesate[cnt])/ sommasoftmax;
        //printf("\n%f", outputneuroni3[cnt]);
    }

    giocata=0;
    for(cnt=0; cnt<28; cnt++)
    {
        classifica[cnt]=0;
        lista[cnt]=outputneuroni3[cnt];
    }

    for(cnt=0; cnt<28; cnt++)
    {
        //printf("\n%f", lista[cnt]);
    }

    for(cnt=0; cnt<28; cnt++)
    {
        mossa=0;
        for(cnt1=0; cnt1<28; cnt1++)
        {
            if(mossa<lista[cnt1])
            {
                mossa=lista[cnt1];
                giocata=cnt1;
            }
        }
        classifica[cnt]=giocata;
        lista[giocata]=0;
    }

    for(cnt=0; cnt<28; cnt++)
    {
        //printf("\n%d", classifica[cnt]);
    }
}

void computerregina(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[])
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    int input[64];
    float moltiplicazione;
    float sommepesate[56];
    float outputneuroni1[30];
    float outputneuroni2[30];
    float sommasoftmax;
    float outputneuroni3[56];
    int cnt, cnt1, cnt2, II;
    int giocata;
    float mossa;
    float lista[56];

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=0;
    }

    if(totmosse%2==1)
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=input[cnt]/1000;
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesiregina1[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biasregina1[cnt];
        //printf("\n%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni1[cnt]=0;
        outputneuroni1[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t%f", outputneuroni1[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni1[II]*strneuroni.pesiregina2[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biasregina2[cnt];
        //printf("\n\t\t%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni2[cnt]=0;
        outputneuroni2[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t\t\t%f", outputneuroni2[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<56; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni2[cnt]*strneuroni.pesiregina3[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biasregina3[cnt];
        //printf("\n\t\t\t\t%f", sommepesate[cnt]);
    }

    sommasoftmax=0;
    for(cnt=0; cnt<56; cnt++)
    {
        outputneuroni3[cnt]=0;
        sommasoftmax=sommasoftmax + exp(sommepesate[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        outputneuroni3[cnt]=exp(sommepesate[cnt])/ sommasoftmax;
        //printf("\n%f", outputneuroni3[cnt]);
    }

    giocata=0;
    for(cnt=0; cnt<56; cnt++)
    {
        classifica[cnt]=0;
        lista[cnt]=outputneuroni3[cnt];
    }

    for(cnt=0; cnt<56; cnt++)
    {
        //printf("\n%f", lista[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        mossa=0;
        for(cnt1=0; cnt1<56; cnt1++)
        {
            if(mossa<lista[cnt1])
            {
                mossa=lista[cnt1];
                giocata=cnt1;
            }
        }
        classifica[cnt]=giocata;
        lista[giocata]=0;
    }

    for(cnt=0; cnt<56; cnt++)
    {
        //printf("\n%d", classifica[cnt]);
    }
}

void computerre(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[])
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    int input[64];
    float moltiplicazione;
    float sommepesate[56];
    float outputneuroni1[30];
    float outputneuroni2[30];
    float sommasoftmax;
    float outputneuroni3[10];
    int cnt, cnt1, cnt2, II;
    int giocata;
    float mossa;
    float lista[10];

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=0;
    }

    if(totmosse%2==1)
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        cnt2=0;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore2.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore2.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore2.regina[0];
        cnt2++;
        input[cnt2]=giocatore2.regina[1];
        cnt2++;
        input[cnt2]=giocatore2.re[0];
        cnt2++;
        input[cnt2]=giocatore2.re[1];
        cnt2++;
        for(cnt1=0; cnt1<8; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.torri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.torri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.alfieri[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.alfieri[cnt1][1];
            cnt2++;
        }
        for(cnt1=0; cnt1<2; cnt1++)
        {
            input[cnt2]=giocatore1.pedoni[cnt1][0];
            cnt2++;
            input[cnt2]=giocatore1.pedoni[cnt1][1];
            cnt2++;
        }
        input[cnt2]=giocatore1.regina[0];
        cnt2++;
        input[cnt2]=giocatore1.regina[1];
        cnt2++;
        input[cnt2]=giocatore1.re[0];
        cnt2++;
        input[cnt2]=giocatore1.re[1];
        cnt2++;

        /*for(cnt=0; cnt<64; cnt++)
    {
        printf("\n %d", input[cnt]);
        cnt++;
        printf("   %d", input[cnt]);
    }*/

        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=input[cnt]/1000;
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesire1[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biasre1[cnt];
        //printf("\n%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni1[cnt]=0;
        outputneuroni1[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t%f", outputneuroni1[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<30; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni1[II]*strneuroni.pesire2[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biasre2[cnt];
        //printf("\n\t\t%f", sommepesate[cnt]);
    }

    for(cnt=0; cnt<30; cnt++)
    {
        outputneuroni2[cnt]=0;
        outputneuroni2[cnt]=1/(1+exp(sommepesate[cnt]));
        //printf("\n\t\t\t%f", outputneuroni2[cnt]);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<10; cnt++)
    {
        for(II=0; II<30; II++)
        {
            moltiplicazione=outputneuroni2[cnt]*strneuroni.pesire3[cnt][II];
            sommepesate[cnt]=sommepesate[cnt]+moltiplicazione;
        }
        sommepesate[cnt]=sommepesate[cnt]+strneuroni.biasre3[cnt];
        //printf("\n\t\t\t\t%f", sommepesate[cnt]);
    }

    sommasoftmax=0;
    for(cnt=0; cnt<10; cnt++)
    {
        outputneuroni3[cnt]=0;
        sommasoftmax=sommasoftmax + exp(sommepesate[cnt]);
    }

    for(cnt=0; cnt<10; cnt++)
    {
        outputneuroni3[cnt]=exp(sommepesate[cnt])/ sommasoftmax;
        //printf("\n%f", outputneuroni3[cnt]);
    }

    giocata=0;
    for(cnt=0; cnt<10; cnt++)
    {
        classifica[cnt]=0;
        lista[cnt]=outputneuroni3[cnt];
    }

    for(cnt=0; cnt<10; cnt++)
    {
        //printf("\n%f", lista[cnt]);
    }

    for(cnt=0; cnt<10; cnt++)
    {
        mossa=0;
        for(cnt1=0; cnt1<10; cnt1++)
        {
            if(mossa<lista[cnt1])
            {
                mossa=lista[cnt1];
                giocata=cnt1;
            }
        }
        classifica[cnt]=giocata;
        lista[giocata]=0;
    }

    for(cnt=0; cnt<10; cnt++)
    {
        //printf("\n%d", classifica[cnt]);
    }
}
