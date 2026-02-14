#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>

void Inserlettere(int largx, int largy, int massimox);
void Insernumeri(int largx, int largy, int massimoy);

void schermo_scacchi(int maxx, int maxy)
{
    int larghezzax, larghezzay; //Larghezza e altezza dello schermo in pixell
    int cnt, cnt1;              //contatori

    larghezzax=0;
    larghezzay=0;

    Inserlettere(larghezzax,larghezzay, maxx);  //Inserisco le lettere e numeri
    Insernumeri(larghezzax,larghezzay, maxy);

                        //tavola dei scacchi
    for(cnt=0; cnt<8; cnt++)
    {
        for(cnt1=0; cnt1<4; cnt1++)
        {
            bar(larghezzax,larghezzay,larghezzax+maxx/8,larghezzay+maxy/8);
            larghezzax=larghezzax+maxx/4;     //coloro solo col nero quindi salto il doppio per evitare passaggi inutili
        }

        larghezzax=0;
        larghezzay=larghezzay+maxy/8;

        if(cnt%2==1)
        {
            larghezzax=0;           //guardo il cnt per non ripetere lo stesso pattern di colori per fare una scacchiera
        }
        else
        {
            larghezzax=larghezzax+maxx/8;
        }

    }

}

void Inserlettere(int largx, int largy, int massimox)
{
                  //inserimento lettere
    int cnt;
    char lettera[2];

    largx=0;            //metto l'arghezza a 0 sia per le lettere
    largy=getmaxy();         //metto l'altezza al massimo perchè mi serve quella per le lettere in fondo
    strcpy(lettera, "A");

    for(cnt=0; cnt<8; cnt++)
    {
        outtextxy(largx+massimox/16, largy-15, lettera);  //divido per 16 per metterlo in mezzo alla casella
        largx=largx+massimox/8;        //divido per 8 per metterlo sotto alla prossima casella
        lettera[0]++;
    }

}

void Insernumeri(int largx, int largy, int massimoy)
{
                 //inserimento numeri
    int cnt;
    char numero[2];

    largx=getmaxx();           //metto l'arghezza al massimo perchè mi serve quella per le lettere in fondo
    largy=0;         //metto l'altezza a 0 sia per le lettere
    strcpy(numero, "1");

    for(cnt=0; cnt<8; cnt++)
    {
        outtextxy(largx-15, largy+massimoy/16, numero);   //divido per 16 per metterlo in mezzo alla casella
        largy=largy+massimoy/8;
        numero[0]++;
    }

}

