#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <time.h>
#include    <conio.h>
#include    <math.h>

#define  LEARNINGRATE 0.01

struct tuttineuroni
{
    double pesixy3[16][64];
    double biasxy3[16];

    double pesipedone3[4][64];
    double biaspedone3[4];

    double pesitorre3[28][64];
    double biastorre3[28];

    double pesicavallo3[8][64];
    double biascavallo3[8];

    double pesialfiere3[28][64];
    double biasalfiere3[28];

    double pesiregina3[56][64];
    double biasregina3[56];

    double pesire3[10][64];
    double biasre3[10];
};

struct giocatore
{
    int pedoni[8][2];
    int torri[2][2];
    int cavalli[2][2];
    int alfieri[2][2];
    int regina[2];
    int re[2];
};

void reterissoftmax(double classifica[], double input[], int totmosse);

void retepedonesoftmax(double classifica[], double input[], int totmosse);

void retetorresoftmax(double classifica[], double input[], int totmosse);

void retecavallosoftmax(double classifica[], double input[], int totmosse);

void retealfieresoftmax(double classifica[], double input[], int totmosse);

void retereginasoftmax(double classifica[], double input[], int totmosse);

void reteresoftmax(double classifica[], double input[], int totmosse);


void apprendimento(int pedina, struct giocatore giocatore1, struct giocatore giocatore2, int nummossapedina, int numes, int totmosse,
                   int numespedone, int numestorre, int numescavallo, int numesalfiere, int numesregina, int numesre,
                   double *sommadiff, double *sommadiffpedone, double *sommadifftorre, double *sommadiffcavallo, double *sommadiffalfiere,
                   double *sommadiffregina, double *sommadiffre)
{
    double input[64];
    int cnt, II, cnt1, cnt2;
    struct tuttineuroni strneuroni;
    FILE *pf;

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
    }

    if(totmosse%2==1)
    {
        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=input[cnt]+50;
    }


    for(cnt=0; cnt<64; cnt++)
    {
        input[cnt]=input[cnt]/1000;
    }

    int mossapedina;
    int mossagiusta;
    int mossagiustapedina;
    double diff;
    double MSE;
    double neuronediattivazione;
    double softmax[56];
    double errorepredetto;
    double outputgiusto[56];

    reterissoftmax(softmax, input, totmosse);

    mossapedina=pedina;
    printf("   %d",mossapedina);
    printf("Inserisci quale pedina bisognava muovere\n");
    scanf("%d", &mossagiusta);
    mossapedina=nummossapedina;
    printf("   %d",mossapedina);
    printf("Inserisci quale mossa bisognava fare\n");
    scanf("%d", &mossagiustapedina);
    diff=0;
    diff=mossapedina - mossagiusta ;
    diff= diff * diff;
    *sommadiff=*sommadiff+diff;
    //printf("  %d", sommadiff);
    MSE=0;
    MSE=*sommadiff/numes;
    //printf("\n%f", MSE);

    if(MSE!=0)
    {
for(cnt1=0; cnt1<1000; cnt1++)
{
        for(cnt=0; cnt<16; cnt++)
        {
            outputgiusto[cnt]=0.01;
            if(cnt==mossagiusta-1)
            {
                outputgiusto[cnt]=0.84;
            }
        }

        if(totmosse%2==1)
        {
            pf=fopen("DatiNeuronibianco.txt", "rb");
            fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
            fclose(pf);
        }
        else
        {
            pf=fopen("DatiNeuroninero.txt", "rb");
            fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
            fclose(pf);
        }

        reterissoftmax(softmax, input, totmosse);

        for(cnt=0; cnt<16; cnt++)
        {
            diff=0;
            diff=softmax[cnt] - outputgiusto[cnt];
            diff=diff*2;

            neuronediattivazione=0;
            if(mossapedina==mossagiusta)
            {
                neuronediattivazione=1-softmax[cnt];
                neuronediattivazione=softmax[cnt]*neuronediattivazione;
            }
            else
            {
                //printf("\n%.2f", softmax);
                neuronediattivazione=-softmax[cnt];
                //printf("\n%.2f", neuronediattivazione);
                neuronediattivazione=neuronediattivazione*softmax[cnt];
            }

            for(II=0; II<64; II++)
            {
                errorepredetto=0;
                errorepredetto=diff*neuronediattivazione*input[II];
                strneuroni.pesixy3[cnt][II]=strneuroni.pesixy3[cnt][II]+(LEARNINGRATE*errorepredetto);
            }

            errorepredetto=0;
            errorepredetto=diff*neuronediattivazione*1;
            strneuroni.biasxy3[cnt]=strneuroni.biasxy3[cnt]+(LEARNINGRATE*errorepredetto);
        }
        if(totmosse%2==1)
        {
            pf=fopen("DatiNeuronibianco.txt", "wb");
            fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
            fclose(pf);
        }
        else
        {
            pf=fopen("DatiNeuroninero.txt", "wb");
            fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
            fclose(pf);
        }
}
    }

    if((pedina>0) && (pedina<=8))
    {
        mossapedina=nummossapedina;
        diff=0;
        diff=mossapedina - mossagiustapedina;
        diff= diff * diff;
        *sommadiffpedone=*sommadiffpedone+diff;
        //printf("  %d", sommadiff);
        MSE=0;
        MSE=*sommadiffpedone/numespedone;
        //printf("\n%f", MSE);

        if(MSE!=0)
        {
for(cnt1=0; cnt1<1000; cnt1++)
{
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }

            for(cnt=0; cnt<4; cnt++)
            {
                outputgiusto[cnt]=0.01;
                if(cnt==mossagiustapedina)
                {
                    outputgiusto[cnt]=0.84;
                }
            }

            retepedonesoftmax(softmax, input, totmosse);

            for(cnt=0; cnt<4; cnt++)
            {
                diff=0;
                diff=softmax[cnt] - outputgiusto[cnt];
                diff=diff*2;

                neuronediattivazione=0;
                if(mossapedina==mossagiusta)
                {
                    neuronediattivazione=1-softmax[cnt];
                    neuronediattivazione=softmax[cnt]*neuronediattivazione;
                }
                else
                {
                    //printf("\n%.2f", softmax);
                    neuronediattivazione=-softmax[cnt];
                    //printf("\n%.2f", neuronediattivazione);
                    neuronediattivazione=neuronediattivazione*softmax[cnt];
                }

                for(II=0; II<64; II++)
                {
                    errorepredetto=0;
                    errorepredetto=diff*neuronediattivazione*input[II];
                    strneuroni.pesipedone3[cnt][II]=strneuroni.pesipedone3[cnt][II]+(LEARNINGRATE*errorepredetto);
                }

                errorepredetto=0;
                errorepredetto=diff*neuronediattivazione*1;
                strneuroni.biaspedone3[cnt]=strneuroni.biaspedone3[cnt]+(LEARNINGRATE*errorepredetto);
            }
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
}
        }
    }
    if((pedina>8) && (pedina<=10))
    {
        mossapedina=nummossapedina;
        diff=0;
        diff=mossapedina - mossagiustapedina;
        diff= diff * diff;
        *sommadifftorre=*sommadifftorre+diff;
        //printf("  %d", sommadiff);
        MSE=0;
        MSE=*sommadifftorre/numestorre;
        //printf("\n%f", MSE);

        if(MSE!=0)
        {
for(cnt1=0; cnt1<1000; cnt1++)
{
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            for(cnt=0; cnt<28; cnt++)
            {
                outputgiusto[cnt]=0.01;
                if(cnt==mossagiustapedina)
                {
                    outputgiusto[cnt]=0.84;
                }
            }
            retetorresoftmax(softmax, input, totmosse);

            for(cnt=0; cnt<28; cnt++)
            {
                diff=0;
                diff=softmax[cnt] - outputgiusto[cnt];
                diff=diff*2;

                neuronediattivazione=0;
                if(mossapedina==mossagiusta)
                {
                    neuronediattivazione=1-softmax[cnt];
                    neuronediattivazione=softmax[cnt]*neuronediattivazione;
                }
                else
                {
                    //printf("\n%.2f", softmax);
                    neuronediattivazione=-softmax[cnt];
                    //printf("\n%.2f", neuronediattivazione);
                    neuronediattivazione=neuronediattivazione*softmax[cnt];
                }

                for(II=0; II<64; II++)
                {
                    errorepredetto=0;
                    errorepredetto=diff*neuronediattivazione*input[II];
                    strneuroni.pesitorre3[cnt][II]=strneuroni.pesitorre3[cnt][II]+(LEARNINGRATE*errorepredetto);
                }

                errorepredetto=0;
                errorepredetto=diff*neuronediattivazione*1;
                strneuroni.biastorre3[cnt]=strneuroni.biastorre3[cnt]+(LEARNINGRATE*errorepredetto);
            }
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
}
        }
    }
    if((pedina>10) && (pedina<=12))
    {
        mossapedina=nummossapedina;
        diff=0;
        diff=mossapedina - mossagiustapedina;
        diff= diff * diff;
        *sommadiffcavallo=*sommadiffcavallo+diff;
        //printf("  %d", sommadiff);
        MSE=0;
        MSE=*sommadiffcavallo/numescavallo;
        //printf("\n%f", MSE);

        if(MSE!=0)
        {
for(cnt1=0; cnt1<1000; cnt1++)
{
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            for(cnt=0; cnt<8; cnt++)
            {
                outputgiusto[cnt]=0.01;
                if(cnt==mossagiustapedina)
                {
                    outputgiusto[cnt]=0.84;
                }
            }
            retecavallosoftmax(softmax, input, totmosse);

            for(cnt=0; cnt<8; cnt++)
            {
                diff=0;
                diff=softmax[cnt] - outputgiusto[cnt];
                diff=diff*2;

                neuronediattivazione=0;
                if(mossapedina==mossagiusta)
                {
                    neuronediattivazione=1-softmax[cnt];
                    neuronediattivazione=softmax[cnt]*neuronediattivazione;
                }
                else
                {
                    //printf("\n%.2f", softmax);
                    neuronediattivazione=-softmax[cnt];
                    //printf("\n%.2f", neuronediattivazione);
                    neuronediattivazione=neuronediattivazione*softmax[cnt];
                }

                for(II=0; II<64; II++)
                {
                    errorepredetto=0;
                    errorepredetto=diff*neuronediattivazione*input[II];
                    strneuroni.pesicavallo3[cnt][II]=strneuroni.pesicavallo3[cnt][II]+(LEARNINGRATE*errorepredetto);
                }

                errorepredetto=0;
                errorepredetto=diff*neuronediattivazione*1;
                strneuroni.biascavallo3[cnt]=strneuroni.biascavallo3[cnt]+(LEARNINGRATE*errorepredetto);
            }
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
}
        }
    }
    if((pedina>12) && (pedina<=14))
    {
        mossapedina=nummossapedina;
        diff=0;
        diff=mossapedina - mossagiustapedina;
        diff= diff * diff;
        *sommadiffalfiere=*sommadiffalfiere+diff;
        //printf("  %d", sommadiff);
        MSE=0;
        MSE=*sommadiffalfiere/numesalfiere;
        //printf("\n%f", MSE);

        if(MSE!=0)
        {
for(cnt1=0; cnt1<1000; cnt1++)
{
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            for(cnt=0; cnt<28; cnt++)
            {
                outputgiusto[cnt]=0.01;
                if(cnt==mossagiustapedina)
                {
                    outputgiusto[cnt]=0.84;
                }
            }
            retealfieresoftmax(softmax, input, totmosse);

            for(cnt=0; cnt<28; cnt++)
            {
                diff=0;
                diff=softmax[cnt] - outputgiusto[cnt];
                diff=diff*2;

                neuronediattivazione=0;
                if(mossapedina==mossagiusta)
                {
                    neuronediattivazione=1-softmax[cnt];
                    neuronediattivazione=softmax[cnt]*neuronediattivazione;
                }
                else
                {
                    //printf("\n%.2f", softmax);
                    neuronediattivazione=-softmax[cnt];
                    //printf("\n%.2f", neuronediattivazione);
                    neuronediattivazione=neuronediattivazione*softmax[cnt];
                }

                for(II=0; II<64; II++)
                {
                    errorepredetto=0;
                    errorepredetto=diff*neuronediattivazione*input[cnt];
                    strneuroni.pesialfiere3[cnt][II]=strneuroni.pesialfiere3[cnt][II]+(LEARNINGRATE*errorepredetto);
                }

                errorepredetto=0;
                errorepredetto=diff*neuronediattivazione*1;
                strneuroni.biasalfiere3[cnt]=strneuroni.biasalfiere3[cnt]+(LEARNINGRATE*errorepredetto);
            }
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
}
        }
    }
    if(pedina==15)
    {
        mossapedina=nummossapedina;
        diff=0;
        diff=mossapedina - mossagiustapedina;
        diff= diff * diff;
        *sommadiffregina=*sommadiffregina+diff;
        //printf("  %d", sommadiff);
        MSE=0;
        MSE=*sommadiffregina/numesregina;
        //printf("\n%f", MSE);

        if(MSE!=0)
        {
for(cnt1=0; cnt1<1000; cnt1++)
{
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            for(cnt=0; cnt<56; cnt++)
            {
                outputgiusto[cnt]=0.01;
                if(cnt==mossagiustapedina)
                {
                    outputgiusto[cnt]=0.84;
                }
            }
            retereginasoftmax(softmax, input, totmosse);

            for(cnt=0; cnt<56; cnt++)
            {
                diff=0;
                diff=softmax[cnt] - outputgiusto[cnt];
                diff=diff*2;

                neuronediattivazione=0;
                if(mossapedina==mossagiusta)
                {
                    neuronediattivazione=1-softmax[cnt];
                    neuronediattivazione=softmax[cnt]*neuronediattivazione;
                }
                else
                {
                    //printf("\n%.2f", softmax);
                    neuronediattivazione=-softmax[cnt];
                    //printf("\n%.2f", neuronediattivazione);
                    neuronediattivazione=neuronediattivazione*softmax[cnt];
                }

                for(II=0; II<64; II++)
                {
                    errorepredetto=0;
                    errorepredetto=diff*neuronediattivazione*input[II];
                    strneuroni.pesiregina3[cnt][II]=strneuroni.pesiregina3[cnt][II]+(LEARNINGRATE*errorepredetto);
                }

                errorepredetto=0;
                errorepredetto=diff*neuronediattivazione*1;
                strneuroni.biasregina3[cnt]=strneuroni.biasregina3[cnt]+(LEARNINGRATE*errorepredetto);
            }
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
}
        }
    }
    if(pedina==16)
    {
        mossapedina=nummossapedina;
        diff=0;
        diff=mossapedina - mossagiustapedina;
        diff= diff * diff;
        *sommadiffre=*sommadiffre+diff;
        //printf("  %d", sommadiff);
        MSE=0;
        MSE=*sommadiffre/numesre;
        //printf("\n%f", MSE);

        if(MSE!=0)
        {
for(cnt1=0; cnt1<1000; cnt1++)
{
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            for(cnt=0; cnt<10; cnt++)
            {
                outputgiusto[cnt]=0.01;
                if(cnt==mossagiustapedina)
                {
                    outputgiusto[cnt]=0.84;
                }
            }
            reteresoftmax(softmax, input, totmosse);

            for(cnt=0; cnt<10; cnt++)
            {
                diff=0;
                diff=softmax[cnt] - outputgiusto[cnt];
                diff=diff*2;

                neuronediattivazione=0;
                if(mossapedina==mossagiusta)
                {
                    neuronediattivazione=1-softmax[cnt];
                    neuronediattivazione=softmax[cnt]*neuronediattivazione;
                }
                else
                {
                    //printf("\n%.2f", softmax);
                    neuronediattivazione=-softmax[cnt];
                    //printf("\n%.2f", neuronediattivazione);
                    neuronediattivazione=neuronediattivazione*softmax[cnt];
                }

                for(II=0; II<64; II++)
                {
                    errorepredetto=0;
                    errorepredetto=diff*neuronediattivazione*input[II];
                    strneuroni.pesire3[cnt][II]=strneuroni.pesire3[cnt][II]+(LEARNINGRATE*errorepredetto);
                }

                errorepredetto=0;
                errorepredetto=diff*neuronediattivazione*1;
                strneuroni.biasre3[cnt]=strneuroni.biasre3[cnt]+(LEARNINGRATE*errorepredetto);
            }
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
}
        }
    }
    if(pedina>=20)
    {
        mossapedina=nummossapedina;
        diff=0;
        diff=mossapedina - mossagiustapedina;
        diff= diff * diff;
        *sommadiffregina=*sommadiffregina+diff;
        //printf("  %d", sommadiff);
        MSE=0;
        MSE=*sommadiffregina/numesregina;
        //printf("\n%f", MSE);

        if(MSE!=0)
        {
for(cnt1=0; cnt1<1000; cnt1++)
{
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "rb");
                fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            for(cnt=0; cnt<56; cnt++)
            {
                outputgiusto[cnt]=0.01;
                if(cnt==mossagiustapedina)
                {
                    outputgiusto[cnt]=0.84;
                }
            }
            retereginasoftmax(softmax, input, totmosse);

            for(cnt=0; cnt<56; cnt++)
            {
                diff=0;
                diff=softmax[cnt] - outputgiusto[cnt];
                diff=diff*2;

                neuronediattivazione=0;
                if(mossapedina==mossagiusta)
                {
                    neuronediattivazione=1-softmax[cnt];
                    neuronediattivazione=softmax[cnt]*neuronediattivazione;
                }
                else
                {
                    //printf("\n%.2f", softmax);
                    neuronediattivazione=-softmax[cnt];
                    //printf("\n%.2f", neuronediattivazione);
                    neuronediattivazione=neuronediattivazione*softmax[cnt];
                }

                for(II=0; II<64; II++)
                {
                    errorepredetto=0;
                    errorepredetto=diff*neuronediattivazione*input[II];
                    strneuroni.pesiregina3[cnt][II]=strneuroni.pesiregina3[cnt][II]+(LEARNINGRATE*errorepredetto);
                }

                errorepredetto=0;
                errorepredetto=diff*neuronediattivazione*1;
                strneuroni.biasregina3[cnt]=strneuroni.biasregina3[cnt]+(LEARNINGRATE*errorepredetto);
            }
            if(totmosse%2==1)
            {
                pf=fopen("DatiNeuronibianco.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
            else
            {
                pf=fopen("DatiNeuroninero.txt", "wb");
                fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
                fclose(pf);
            }
}
        }
    }

    if(totmosse%2==1)
    {
        pf=fopen("DatiNeuronibianco.txt", "wb");
        fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        pf=fopen("DatiNeuroninero.txt", "wb");
        fwrite(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

}

void reterissoftmax(double classifica[], double input[], int totmosse)
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    double moltiplicazione;
    double sommepesate[56];
    double sommasoftmax;
    double outputneuroni3[16];
    int cnt, II;

    if(totmosse%2==1)
    {
        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<16; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesixy3[cnt][II];
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

    for(cnt=0; cnt<16; cnt++)
    {
        classifica[cnt]=0;
        classifica[cnt]=outputneuroni3[cnt];
    }

}

void retepedonesoftmax(double classifica[], double input[], int totmosse)
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    double moltiplicazione;
    double sommepesate[56];
    double sommasoftmax;
    double outputneuroni3[4];
    int cnt, II;

    if(totmosse%2==1)
    {
        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<4; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesipedone3[cnt][II];
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

    for(cnt=0; cnt<4; cnt++)
    {
        classifica[cnt]=0;
        classifica[cnt]=outputneuroni3[cnt];
    }

}

void retetorresoftmax(double classifica[], double input[], int totmosse)
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    double moltiplicazione;
    double sommepesate[56];
    double sommasoftmax;
    double outputneuroni3[28];
    int cnt, II;

    if(totmosse%2==1)
    {
        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<28; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesitorre3[cnt][II];
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

    for(cnt=0; cnt<28; cnt++)
    {
        classifica[cnt]=0;
        classifica[cnt]=outputneuroni3[cnt];
    }

}

void retecavallosoftmax(double classifica[], double input[], int totmosse)
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    double moltiplicazione;
    double sommepesate[56];
    double sommasoftmax;
    double outputneuroni3[8];
    int cnt, II;

    if(totmosse%2==1)
    {
        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<8; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesicavallo3[cnt][II];
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

    for(cnt=0; cnt<8; cnt++)
    {
        classifica[cnt]=0;
        classifica[cnt]=outputneuroni3[cnt];
    }

}

void retealfieresoftmax(double classifica[], double input[], int totmosse)
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    double moltiplicazione;
    double sommepesate[56];
    double sommasoftmax;
    double outputneuroni3[28];
    int cnt, II;

    if(totmosse%2==1)
    {
        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<28; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesialfiere3[cnt][II];
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

    for(cnt=0; cnt<28; cnt++)
    {
        classifica[cnt]=0;
        classifica[cnt]=outputneuroni3[cnt];
    }

}

void retereginasoftmax(double classifica[], double input[], int totmosse)
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    double moltiplicazione;
    double sommepesate[56];
    double sommasoftmax;
    double outputneuroni3[56];
    int cnt, II;

    if(totmosse%2==1)
    {
        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<56; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesiregina3[cnt][II];
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

    for(cnt=0; cnt<56; cnt++)
    {
        classifica[cnt]=0;
        classifica[cnt]=outputneuroni3[cnt];
    }

}

void reteresoftmax(double classifica[], double input[], int totmosse)
{
    struct tuttineuroni strneuroni;
    FILE *pf;
    double moltiplicazione;
    double sommepesate[56];
    double sommasoftmax;
    double outputneuroni3[8];
    int cnt, II;

    if(totmosse%2==1)
    {
        pf=fopen("DatiNeuronibianco.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }
    else
    {
        pf=fopen("DatiNeuroninero.txt", "rb");
        fread(&strneuroni, sizeof(struct tuttineuroni), 1, pf);
        fclose(pf);
    }

    for(cnt=0; cnt<56; cnt++)
    {
        sommepesate[cnt]=0;
    }

    for(cnt=0; cnt<10; cnt++)
    {
        for(II=0; II<64; II++)
        {
            moltiplicazione=input[II]*strneuroni.pesire3[cnt][II];
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

    for(cnt=0; cnt<10; cnt++)
    {
        classifica[cnt]=0;
        classifica[cnt]=outputneuroni3[cnt];
    }

}
