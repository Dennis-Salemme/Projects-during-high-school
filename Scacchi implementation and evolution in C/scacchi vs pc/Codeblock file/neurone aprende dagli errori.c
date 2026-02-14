#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <time.h>
#include    <conio.h>
#include    <math.h>

#define  LEARNINGRATE 0.001

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
    float pesire3[8][30];
    float biasre3[8];
};

void reteneuronalepedoni(int classifica[]);
void reterissoftmax(float classifica[]);
void retesigmoide2(float classifica[]);
void retesigmoide1(float classifica[]);

int main(void)
{
    int risposta;
    int cambiorandom;
    int classificapedine[16];
    struct tuttineuroni strneuroni;
    FILE *pf;
    pf=fopen("migliore.txt", "rb");
    fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
    fclose(pf);

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

    int numes;
    int mossapedina;
    int mossagiusta;
    float diff;
    int sommadiff;
    float MSE;
    float neuronediattivazione;
    float softmax[16];
    float errorepredetto;
    float sigmoide[30];

    numes=0;
    numes++;
    sommadiff=0;
    reteneuronalepedoni(classificapedine);
    mossapedina=classificapedine[0];
    printf("   %d",mossapedina);
    printf("Inserisci quale pedina bisognava muovere\n");
    scanf("%d", &mossagiusta);
    diff=0;
    diff=mossapedina-mossagiusta;
    diff= diff * diff;
    sommadiff=sommadiff+diff;
    //printf("  %d", sommadiff);
    MSE=0;
    MSE=sommadiff/numes;
    //printf("\n%f", MSE);

    if(MSE!=0)
    {
        reteneuronalepedoni(classificapedine);
        mossapedina=classificapedine[0];
        diff=0;
        diff=mossapedina-mossagiusta;
        diff=diff*2;

        reterissoftmax(softmax);

        for(cnt=0; cnt<16; cnt++)
        {
            neuronediattivazione=0;
            if(mossapedina==mossagiusta)
            {
                neuronediattivazione=1-softmax[cnt];
                neuronediattivazione=softmax[cnt]*neuronediattivazione;
            }
            else
            {
                printf("\n%f", softmax);
                neuronediattivazione=-softmax[cnt];
                printf("\n%f", neuronediattivazione);
                neuronediattivazione=neuronediattivazione*softmax[cnt];
            }

            for(II=0; II<30; II++)
            {
                errorepredetto=0;
                errorepredetto=diff*neuronediattivazione*strneuroni.pesixy3[cnt][II];
                strneuroni.pesixy3[cnt][II]=strneuroni.pesixy3[cnt][II]-LEARNINGRATE*errorepredetto;
            }

            errorepredetto=0;
            errorepredetto=diff+neuronediattivazione*strneuroni.biasxy3[cnt];
            strneuroni.biasxy3[cnt]=strneuroni.biasxy3[cnt]-LEARNINGRATE*errorepredetto;
        }

        retesigmoide2(sigmoide);
        for(cnt=0; cnt<30; cnt++)
        {
            neuronediattivazione=0;
            neuronediattivazione=1-sigmoide[cnt];
            neuronediattivazione=sigmoide[cnt]*neuronediattivazione;

            for(II=0; II<30; II++)
            {
                errorepredetto=0;
                errorepredetto=diff*neuronediattivazione*strneuroni.pesixy2[cnt][II];
                strneuroni.pesixy2[cnt][II]=strneuroni.pesixy2[cnt][II]-LEARNINGRATE*errorepredetto;
            }

            errorepredetto=0;
            errorepredetto=diff+neuronediattivazione*strneuroni.biasxy2[cnt];
            strneuroni.biasxy2[cnt]=strneuroni.biasxy2[cnt]-LEARNINGRATE*errorepredetto;
        }

        retesigmoide1(sigmoide);
        for(cnt=0; cnt<30; cnt++)
        {
            neuronediattivazione=0;
            neuronediattivazione=1-sigmoide[cnt];
            neuronediattivazione=sigmoide[cnt]*neuronediattivazione;

            for(II=0; II<64; II++)
            {
                errorepredetto=0;
                errorepredetto=diff*neuronediattivazione*strneuroni.pesixy1[cnt][II];
                strneuroni.pesixy1[cnt][II]=strneuroni.pesixy1[cnt][II]-LEARNINGRATE*errorepredetto;
            }

            errorepredetto=0;
            errorepredetto=diff+neuronediattivazione*strneuroni.biasxy1[cnt];
            strneuroni.biasxy1[cnt]=strneuroni.biasxy1[cnt]-LEARNINGRATE*errorepredetto;
        }
    }

}

void reteneuronalepedoni(int classifica[])
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

    pf=fopen("migliore.txt", "rb");
    fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
    fclose(pf);
    pf=fopen("DatiNeuroni.txt", "wb");
    fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
    fclose(pf);
    pf=fopen("DatiNeuroni.txt", "rb");
    fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
    fclose(pf);

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

void reterissoftmax(float classifica[])
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

    pf=fopen("migliore.txt", "rb");
    fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
    fclose(pf);
    pf=fopen("DatiNeuroni.txt", "wb");
    fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
    fclose(pf);
    pf=fopen("DatiNeuroni.txt", "rb");
    fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
    fclose(pf);

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
            }
        }
        classifica[cnt]=mossa;
        lista[giocata]=0;
    }

}

void retesigmoide2(float classifica[])
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    int input[64];
    float moltiplicazione;
    float sommepesate[56];
    float outputneuroni1[30];
    float outputneuroni2[30];
    float sommasoftmax;
    int cnt, cnt1, cnt2, II;
    int giocata;
    float mossa;
    float lista[30];

    pf=fopen("migliore.txt", "rb");
    fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
    fclose(pf);
    pf=fopen("DatiNeuroni.txt", "wb");
    fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
    fclose(pf);
    pf=fopen("DatiNeuroni.txt", "rb");
    fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
    fclose(pf);

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

    giocata=0;
    for(cnt=0; cnt<30; cnt++)
    {
        classifica[cnt]=0;
        lista[cnt]=outputneuroni2[cnt];
    }

    for(cnt=0; cnt<30; cnt++)
    {
        mossa=0;
        for(cnt1=0; cnt1<30; cnt1++)
        {
            if(mossa<lista[cnt1])
            {
                mossa=lista[cnt1];
            }
        }
        classifica[cnt]=mossa;
        lista[giocata]=0;
    }

}

void retesigmoide1(float classifica[])
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    int input[64];
    float moltiplicazione;
    float sommepesate[56];
    float outputneuroni1[30];
    float outputneuroni2[30];
    float sommasoftmax;
    int cnt, cnt1, cnt2, II;
    int giocata;
    float mossa;
    float lista[64];

    pf=fopen("migliore.txt", "rb");
    fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
    fclose(pf);
    pf=fopen("DatiNeuroni.txt", "wb");
    fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
    fclose(pf);
    pf=fopen("DatiNeuroni.txt", "rb");
    fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
    fclose(pf);

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

    giocata=0;
    for(cnt=0; cnt<30; cnt++)
    {
        classifica[cnt]=0;
        lista[cnt]=outputneuroni1[cnt];
    }

    for(cnt=0; cnt<30; cnt++)
    {
        mossa=0;
        for(cnt1=0; cnt1<64; cnt1++)
        {
            if(mossa<lista[cnt1])
            {
                mossa=lista[cnt1];
            }
        }
        classifica[cnt]=mossa;
        lista[giocata]=0;
    }

}
