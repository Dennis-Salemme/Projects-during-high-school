#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <graphics.h>

                        //Inserimento delle x e y delle strutture di tutte le pedine
void inserimentopedine(int maxx, int maxy, struct giocatore *giocatore1, struct giocatore *giocatore2);

void schermo_scacchi(int maxx, int maxy); //tavola base per gli scacchi

                     //serve per inserire l'immagine dei pedoni sulla scacchiera ma anche per muoverli
void scacchierapedine(int maxx, int maxy, struct giocatore *giocatore1, struct giocatore *giocatore2);

                              //guarda se nel punto in cui ha cliccato si trova una pedina
void controllopedine(struct giocatore *giocatore1, int contr[8][2], int largo, int alto, int *controllox, int *controlloy);

          //confronta i dati di x e y per trovare quale casella è
int vedepedina(int contr[8][2], int *controllox, int *controlloy);

         //vede il colore della casella
int trovacolore(int x, int y, int largo, int alto);

             //movimenti segnati delle pedine
void movimenti(int pedina, struct giocatore *giocator1, struct giocatore *giocator2,
               int x, int y, int largo, int alto, int nummosse0[], int nummosse1[], int *mallocmosse, int totmosse);

               //vede il click se è su una casella della mossa
int cliccatosumossa(int *x, int *y, int largo, int alto, int nummossex, int nummossey, int pedina, struct giocatore *giocator, struct giocatore *giocator2, int totmosse);

                 //vede se qualche pedone è in promozione
int controllopromozioni(int pedone, struct giocatore giocatore, int numpromozione[], int promozionigioc, int alto);

                //rete neurale
                //controlla se le pedine ci sono e non siano già mangiate
int celapedina(int pedina, struct giocatore giocatore, int *x, int *y);

                 //mi da tutte le mosse possibili per la pedina selezionata
void massimemosse(int pedina, struct giocatore giocatore, int x, int y, int largo, int alto, int totmosse[56][2], int suogiu);

                  //rete neurale fatta male
void reteneuronalepedoni(int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[]);
void tuttemossecomputer(int pedina, int totmosse, struct giocatore giocatore1, struct giocatore giocatore2, int classifica[]);

struct giocatore
{
    int pedoni[8][2];
    int torri[2][2];
    int cavalli[2][2];
    int alfieri[2][2];
    int regina[2];
    int re[2];
};

int main(void)
{
    struct giocatore giocatore1, giocatore2;

    int maxx, maxy;             //mi tengono i pixell massimi della finestra
    int quadlargo, quadalto;     //sono i punti della grandezza dei quadrati della scacchiera

    printf("Inserisci  la risoluzione della tavola di x\n");   //l'utente inserisce di quanto vuole la finestra della scacchiera
    scanf("%d", &maxx);
    fflush(stdin);
    printf("Inserisci  la risoluzione della tavola di y\n");
    scanf("%d", &maxy);

    quadalto=maxy/8;
    quadlargo=maxx/8;

    inserimentopedine(maxx, maxy, &giocatore1, &giocatore2);   //Inserimento delle x e y delle strutture di tutte le pedine

    initwindow(maxx+30,maxy+30,"Scacchi");   //apre la finestra

    schermo_scacchi(maxx, maxy);    //tavola base per gli scacchi

    scacchierapedine(maxx, maxy, &giocatore1, &giocatore2);    //serve per inserire l'immagine dei pedoni
                          //sulla scacchiera ma anche per muoverli

/*cnt1=1;
    for(cnt2=0; cnt2<8; cnt2++)
    {
        printf("\npedone%d = %d,%d", cnt1, giocatore1.pedoni[cnt2][0], giocatore1.pedoni[cnt2][1]);
        cnt1++;
    }
    for(cnt2=0; cnt2<2; cnt2++)
    {
        printf("\ntorre%d = %d,%d", cnt1, giocatore1.torri[cnt2][0], giocatore1.torri[cnt2][1]);
        cnt1++;
    }
    for(cnt2=0; cnt2<2; cnt2++)
    {
        printf("\ncavallo%d = %d,%d", cnt1, giocatore1.cavalli[cnt2][0], giocatore1.cavalli[cnt2][1]);
        cnt1++;
    }
    for(cnt2=0; cnt2<2; cnt2++)
    {
        printf("\nalfiere%d = %d,%d", cnt1, giocatore1.alfieri[cnt2][0], giocatore1.alfieri[cnt2][1]);
        cnt1++;
    }
    printf("\nregina = %d,%d", giocatore1.regina[0], giocatore1.regina[1]);
    printf("\nre = %d,%d", giocatore1.re[0], giocatore1.re[1]);*/


              //rileva quando il muose clicca
    int AA;                     //contatore
    int x, y, contrx, contry;                   //tiene x e y del muose al momento del click col sinistro
    int controllo[8][2];        //controlla che pedina è in base ai numeri inseriti all'interno
    int oscurapedone;           //numero della pedina
    int colore;                 //mi da il colore della casella
    int nummosse0[30], nummosse1[30];   //numero di mosse x y puntatore perchè non so quante mosse avra la pedina
    int cnt;                   //contatore
    int mallocmosse;           //numero di mosse che ci potrebbero essere riferito a **nummosse
    int clickmosse;            //vero o farlo se ha cliccato su una casella delle mosse
    int passa;                //vede se è ritornato 1 da cliccatosumossa cosi non melo cambia quando lo trova
    int totmosse;            //vede il numero di mosse in modo da sapere che giocatore deve giocare
    int finemossa;
    int finegioco;
    int promozionigioc1, promozionigioc2;
    int numpromozioni1[8], numpromozioni2[8];
    int passapromozioni;

    int tuttemosse[56][2];
    int sceltamossarand;
    int classificapedine[56];
    int contacicli;

    promozionigioc1=0;
    promozionigioc2=0;
    totmosse=1;
    finegioco=0;
    srand(time(NULL));

    for(cnt=0; cnt<8; cnt++)
    {
        numpromozioni1[cnt]=18;
        numpromozioni2[cnt]=18;
    }

do
{
    for(cnt=0; cnt<30; cnt++)
    {
        nummosse0[cnt]=getmaxx()+100;
        nummosse1[cnt]=getmaxy()+100;
    }

    finemossa=0;
    do
    {
        for(AA=0; AA<8; AA++)      //azzero la variabile per poi non trovarmi numeri strani
        {
            controllo[AA][0]=0;
            controllo[AA][1]=0;
        }
        oscurapedone=0;
        x=0;
        y=0;
        mallocmosse=0;
        do
        {    //funzione di come penso:ismouseclick è come se fosse una variabile e quando te clicchi
             //col mouse in questo caso col sinistro quella variabile diventa true e lo fa passare
             //quando riclicchi diventa false
            while(ismouseclick(WM_LBUTTONDOWN))  //aspetta il click sinistro del mouse quindi diventa true
            {
                getmouseclick(WM_LBUTTONDOWN, x, y);
                clearmouseclick(WM_LBUTTONDOWN);
                           //guarda se nel punto in cui ha cliccato si trova una pedina
                controllopedine(&giocatore1, controllo, quadlargo, quadalto, &x, &y);
                oscurapedone=vedepedina(controllo, &x, &y);     //mi vede se ha cliccato una pedina

            }
        }while(oscurapedone==0);

        clickmosse=0;
        passa=0;
        if(oscurapedone!=0)
        {
            if(promozionigioc1!=0)
            {
                if((oscurapedone>0) && (oscurapedone<=8))
                {
                    for(cnt=0; cnt<8; cnt++)
                    {
                        if(oscurapedone-1==numpromozioni1[cnt])
                        {
                            oscurapedone=21+oscurapedone;
                        }
                    }
                }
            }

            movimenti(oscurapedone, &giocatore1, &giocatore2, x, y, quadlargo, quadalto, nummosse0, nummosse1, &mallocmosse, totmosse);

            while(!ismouseclick(WM_LBUTTONDOWN)); //aspetta il click sinistro del mouse pero diventa false
            {
                getmouseclick(WM_LBUTTONDOWN, contrx, contry);
                clearmouseclick(WM_LBUTTONDOWN);

                cnt=0;
                while((nummosse0[cnt]!=getmaxx()+100) && (passa!=1))
                {
                    if(nummosse0[cnt]!=getmaxx()+100)
                    {
                        passa=cliccatosumossa(&contrx, &contry, quadlargo, quadalto, nummosse0[cnt], nummosse1[cnt], oscurapedone-1, &giocatore1, &giocatore2, totmosse);  //si trova in controllopedine
                        if(passa==1)
                        {
                            clickmosse=passa;  //in questo modo non lo cambia nel controllo degli altri
                        }
                    }
                    cnt++;
                }

                if(oscurapedone<9)
                {
                    passapromozioni=0;
                    passapromozioni=controllopromozioni(oscurapedone-1, giocatore1, numpromozioni1, promozionigioc1, quadalto);
                    if(passapromozioni==1)
                    {
                        promozionigioc1++;
                    }
                }

                if(clickmosse==1)
                {
                    colore=trovacolore(x, y, quadlargo, quadalto);
                    //printf("\n%d", colore);
                    if(colore==0)     //faccio cosi perchè non so mettere il colore e so idiota
                    {
                        readimagefile("Pedinescacchi/Nero.bmp", x, y, x+quadlargo-1, y+quadalto-1);
                    }
                    else
                    {
                        readimagefile("Pedinescacchi/Bianco.bmp", x, y, x+quadlargo-1, y+quadalto-1);
                    }
                    totmosse++;
                    finemossa=1;
                }
            }
        }
    }while(finemossa==0);

    /*for(cnt=0; cnt<30; cnt++)
    {
        printf("\nmosse %d, %d", nummosse0[cnt], nummosse1[cnt]);
    }*/

    if(giocatore2.re[0]==getmaxx()+100)
    {
        printf("\nHa vinto il Bianco");
        finegioco=1;
    }
    if(giocatore1.re[0]==getmaxx()+100)
    {
        printf("\nHa vinto il Nero");
        finegioco=1;
    }

    if(finegioco==0)
    {

        for(cnt=0; cnt<56; cnt++)
        {
            tuttemosse[cnt][0]=getmaxx()+100;
            tuttemosse[cnt][1]=getmaxy()+100;
        }

        passa=0;
        oscurapedone=0;
        contacicli=0;
        do
        {
            for(cnt=0; cnt<30; cnt++)
            {
                nummosse0[cnt]=getmaxx()+100;
                nummosse1[cnt]=getmaxy()+100;
            }

            if(oscurapedone==0)
            {
                reteneuronalepedoni(totmosse, giocatore1, giocatore2, classificapedine);   // prima rete neurale
                oscurapedone=classificapedine[0];
            }
            else
            {
                oscurapedone=classificapedine[contacicli];
            }
            //printf("\n%d", oscurapedone);
            contacicli++;

            passa=celapedina(oscurapedone, giocatore2, &x, &y);
            //printf("\n%d\n", oscurapedone);
            if(passa==1)
            {
                mallocmosse=0;
                passa=0;
                if(promozionigioc2!=0)
                {
                    if((oscurapedone>0) && (oscurapedone<=8))
                    {
                        for(cnt=0; cnt<8; cnt++)
                        {
                            if(oscurapedone-1==numpromozioni2[cnt])
                            {
                                oscurapedone=21+oscurapedone;
                            }
                        }
                    }
                }

                movimenti(oscurapedone, &giocatore2, &giocatore1, x, y, quadlargo, quadalto, nummosse0, nummosse1, &mallocmosse, totmosse);

            }

            if(nummosse0[0]!=getmaxx()+100)
            {
                passa=1;
            }

        }while(passa==0);

        massimemosse(oscurapedone, giocatore2, x, y, quadlargo, quadalto, tuttemosse, totmosse);

        passa=0;
        sceltamossarand=0;
        if((oscurapedone>0) && (oscurapedone<=8))
        {
            contacicli=0;
            do
            {
                if(contacicli==0)
                {
                    tuttemossecomputer(oscurapedone, totmosse, giocatore1, giocatore2, classificapedine);
                    sceltamossarand=classificapedine[0];
                }
                else
                {
                    sceltamossarand=classificapedine[contacicli];
                }
                contacicli++;

                for(cnt=0; cnt<4; cnt++)
                {
                    if((tuttemosse[sceltamossarand][0]==nummosse0[cnt]) && (tuttemosse[sceltamossarand][1]==nummosse1[cnt]))
                    {
                        passa=1;
                    }
                }

            }while(passa==0);
        }
        if((oscurapedone>8) && (oscurapedone<=10))
        {
            contacicli=0;
            do
            {
                if(contacicli==0)
                {
                    tuttemossecomputer(oscurapedone, totmosse, giocatore1, giocatore2, classificapedine);
                    sceltamossarand=classificapedine[0];
                }
                else
                {
                    sceltamossarand=classificapedine[contacicli];
                }
                contacicli++;

                for(cnt=0; cnt<14; cnt++)
                {
                    if((tuttemosse[sceltamossarand][0]==nummosse0[cnt]) && (tuttemosse[sceltamossarand][1]==nummosse1[cnt]))
                    {
                        passa=1;
                    }
                }

            }while(passa==0);
        }
        if((oscurapedone>10) && (oscurapedone<=12))
        {
            contacicli=0;
            do
            {
                if(contacicli==0)
                {
                    tuttemossecomputer(oscurapedone, totmosse, giocatore1, giocatore2, classificapedine);
                    sceltamossarand=classificapedine[0];
                }
                else
                {
                    sceltamossarand=classificapedine[contacicli];
                }
                contacicli++;

                for(cnt=0; cnt<8; cnt++)
                {
                    if((tuttemosse[sceltamossarand][0]==nummosse0[cnt]) && (tuttemosse[sceltamossarand][1]==nummosse1[cnt]))
                    {
                        passa=1;
                    }
                }

            }while(passa==0);
        }
        if((oscurapedone>12) && (oscurapedone<=14))
        {
            contacicli=0;
            do
            {
                if(contacicli==0)
                {
                    tuttemossecomputer(oscurapedone, totmosse, giocatore1, giocatore2, classificapedine);
                    sceltamossarand=classificapedine[0];
                }
                else
                {
                    sceltamossarand=classificapedine[contacicli];
                }
                contacicli++;

                for(cnt=0; cnt<14; cnt++)
                {
                    if((tuttemosse[sceltamossarand][0]==nummosse0[cnt]) && (tuttemosse[sceltamossarand][1]==nummosse1[cnt]))
                    {
                        passa=1;
                    }
                }

            }while(passa==0);
        }
        if(oscurapedone==15)
        {
            contacicli=0;
            do
            {
                if(contacicli==0)
                {
                    tuttemossecomputer(oscurapedone, totmosse, giocatore1, giocatore2, classificapedine);
                    sceltamossarand=classificapedine[0];
                }
                else
                {
                    sceltamossarand=classificapedine[contacicli];
                }
                contacicli++;

                for(cnt=0; cnt<30; cnt++)
                {
                    if((tuttemosse[sceltamossarand][0]==nummosse0[cnt]) && (tuttemosse[sceltamossarand][1]==nummosse1[cnt]))
                    {
                        passa=1;
                    }
                }

            }while(passa==0);
        }
        if(oscurapedone==16)
        {
            contacicli=0;
            do
            {
                if(contacicli==0)
                {
                    tuttemossecomputer(oscurapedone, totmosse, giocatore1, giocatore2, classificapedine);
                    sceltamossarand=classificapedine[0];
                }
                else
                {
                    sceltamossarand=classificapedine[contacicli];
                }
                contacicli++;

                for(cnt=0; cnt<8; cnt++)
                {
                    if((tuttemosse[sceltamossarand][0]==nummosse0[cnt]) && (tuttemosse[sceltamossarand][1]==nummosse1[cnt]))
                    {
                        passa=1;
                    }
                }

            }while(passa==0);
        }
        if(oscurapedone>=20)
        {
            contacicli=0;
            do
            {
                if(contacicli==0)
                {
                    tuttemossecomputer(oscurapedone, totmosse, giocatore1, giocatore2, classificapedine);
                    sceltamossarand=classificapedine[0];
                }
                else
                {
                    sceltamossarand=classificapedine[contacicli];
                }
                contacicli++;

                for(cnt=0; cnt<30; cnt++)
                {
                    if((tuttemosse[sceltamossarand][0]==nummosse0[cnt]) && (tuttemosse[sceltamossarand][1]==nummosse1[cnt]))
                    {
                        passa=1;
                    }
                }

            }while(passa==0);
        }

        contrx=tuttemosse[sceltamossarand][0];
        contry=tuttemosse[sceltamossarand][1];
        clickmosse=cliccatosumossa(&contrx, &contry, quadlargo, quadalto, tuttemosse[sceltamossarand][0], tuttemosse[sceltamossarand][1], oscurapedone-1, &giocatore2, &giocatore1, totmosse);

        if(oscurapedone<9)
        {
            passapromozioni=0;
            passapromozioni=controllopromozioni(oscurapedone-1, giocatore2, numpromozioni2, promozionigioc2, quadalto);
            if(passapromozioni==1)
            {
                promozionigioc2++;
            }
        }

        if(clickmosse==1)
        {
            colore=trovacolore(x, y, quadlargo, quadalto);
            //printf("\n%d", colore);
            if(colore==0)     //faccio cosi perchè non so mettere il colore e so idiota
            {
                readimagefile("Pedinescacchi/Nero.bmp", x, y, x+quadlargo-1, y+quadalto-1);
            }
            else
            {
                readimagefile("Pedinescacchi/Bianco.bmp", x, y, x+quadlargo-1, y+quadalto-1);
            }
            totmosse++;
        }

        if(giocatore2.re[0]==getmaxx()+100)
        {
            printf("\nHa vinto il Bianco");
            finegioco=1;
        }
        if(giocatore1.re[0]==getmaxx()+100)
        {
            printf("\nHa vinto il Nero");
            finegioco=1;
        }
    }

}while(finegioco==0);

    getch();

    closegraph();
}

int trovacolore(int x, int y, int largo, int alto)
{
    int color[2]={7, 7}; //colore della x e y
    int cnt;
    int verocolor;

    for(cnt=0; cnt<8; cnt++)      //trova il colore secondo x
    {
        if((x>=largo*cnt) && (x<(largo*cnt)+largo))
        {
            if(cnt%2==0)
            {
                color[0]=15;
            }
            else
            {
                color[0]=0;
            }
        }
    }

    for(cnt=0; cnt<8; cnt++)  //trova il colore secondo y
    {
        if((y>=alto*cnt) && (y<(alto*cnt)+alto))
        {
            if(cnt%2==0)
            {
                color[1]=15;
            }
            else
            {
                color[1]=0;
            }
        }
    }

    if(color[0]==color[1]) //se uguali il colore è bianco, diversi e nero
    {
        verocolor=15;
    }
    else
    {
        verocolor=0;
    }

    return verocolor;
}

int celapedina(int pedina, struct giocatore giocatore, int *x, int *y)
{
    int passa;

    passa=0;
    if((pedina>0) && (pedina<=8))
    {
        if((giocatore.pedoni[pedina-1][0]!=getmaxx()+100) && (giocatore.pedoni[pedina-1][1]!=getmaxy()+100))
        {
            *x=giocatore.pedoni[pedina-1][0];
            *y=giocatore.pedoni[pedina-1][1];
            passa=1;
        }
    }
    if((pedina>8) && (pedina<=10))
    {
        if((giocatore.torri[pedina-9][0]!=getmaxx()+100) && (giocatore.torri[pedina-9][1]!=getmaxy()+100))
        {
            *x=giocatore.torri[pedina-9][0];
            *y=giocatore.torri[pedina-9][1];
            passa=1;
        }
    }
    if((pedina>10) && (pedina<=12))
    {
        if((giocatore.cavalli[pedina-11][0]!=getmaxx()+100) && (giocatore.cavalli[pedina-11][1]!=getmaxy()+100))
        {
            *x=giocatore.cavalli[pedina-11][0];
            *y=giocatore.cavalli[pedina-11][1];
            passa=1;
        }
    }
    if((pedina>12) && (pedina<=14))
    {
        if((giocatore.alfieri[pedina-13][0]!=getmaxx()+100) && (giocatore.alfieri[pedina-13][1]!=getmaxy()+100))
        {
            *x=giocatore.alfieri[pedina-13][0];
            *y=giocatore.alfieri[pedina-13][1];
            passa=1;
        }
    }
    if(pedina==15)
    {
        if((giocatore.regina[0]!=getmaxx()+100) && (giocatore.regina[1]!=getmaxy()+100))
        {
            *x=giocatore.regina[0];
            *y=giocatore.regina[1];
            passa=1;
        }
    }
    if(pedina==16)
    {
        if((giocatore.re[0]!=getmaxx()+100) && (giocatore.re[1]!=getmaxy()+100))
        {
            *x=giocatore.re[0];
            *y=giocatore.re[1];
            passa=1;
        }
    }

    return passa;
}
