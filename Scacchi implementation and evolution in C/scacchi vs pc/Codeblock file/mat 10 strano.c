#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

#define LEN 9

void azzero(int zeri[LEN][LEN]);
void uno(int uni[LEN][LEN]);
void due(int dui[LEN][LEN]);
void tre(int tri[LEN][LEN]);
void quatro(int quatri[LEN][LEN]);

int main(void)
{
    int mat[LEN][LEN];
    int cnt, cnt1;

    azzero(mat);
    uno(mat);
    due(mat);
    tre(mat);
    quatro(mat);
    mat[4][4]=0;

    for(cnt=0; cnt<LEN; cnt++)
    {
        for(cnt1=0; cnt1<LEN; cnt1++)
        {
            printf("%d  ", mat[cnt][cnt1]);
        }
        printf("\n");
    }
}

void azzero(int zeri[LEN][LEN])
{
    int II1, II2;

    for(II1=0; II1<LEN; II1++)
    {
        for(II2=0; II2<LEN; II2++)
        {
            zeri[II1][II2]=0;
        }
    }
}

void uno(int uni[LEN][LEN])
{
    int cnt1;
    int tengo1;

    tengo1=0;
    for(cnt1=0; cnt1<LEN; cnt1++)
    {
        uni[cnt1][tengo1]=uni[cnt1][tengo1]+1;
        tengo1++;
    }
}

void due(int dui[LEN][LEN])
{
    int cnt2;
    int tengo2;

    tengo2=4;
    for(cnt2=0; cnt2<LEN; cnt2++)
    {
        dui[cnt2][tengo2]=dui[cnt2][tengo2]+2;
    }
}

void tre(int tri[LEN][LEN])
{
    int cnt3;
    int tengo3;

    tengo3=8;
    for(cnt3=0; cnt3<LEN; cnt3++)
    {
        tri[cnt3][tengo3]=tri[cnt3][tengo3]+3;
        tengo3--;
    }
}

void quatro(int quatri[LEN][LEN])
{
    int cnt4;
    int tengo4;

    tengo4=4;
    for(cnt4=0; cnt4<LEN; cnt4++)
    {
        quatri[tengo4][cnt4]=quatri[tengo4][cnt4]+4;
    }
}
