#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct atleta
{
    char nome[15];
    int salto;
    struct atleti *next;
};

struct atleta *inserimento(void);
void stampa(struct atleta *punt_lista);
struct atleta *ordalfa(struct atleta *punt_lista);

int main(void)
{
    struct atleta *p_lista;

    p_lista=inserimento();
    stampa(p_lista);
    p_lista=ordalfa(p_lista);
}

struct atleta *inserimento(void)
{
    struct atleta *punt_lista, *p_app;
    int num, cnt;

    printf("Quanti atleti vuoi inserire?\n");
    scanf("%d", &num);

    punt_lista=(struct atleta *)malloc(sizeof(struct atleta));
    printf("Inserisci il nome dell'atleta: ");
    scanf("%s", punt_lista->nome);
    punt_lista->next=NULL;
    p_app=punt_lista;
    for(cnt=1; cnt<num; cnt++)
    {
        p_app->next=(struct atleta *)malloc(sizeof(struct atleta));
        p_app=p_app->next;
        printf("Inserisci il nome dell'atleta: ");
        scanf("%s", punt_lista->nome);
    }
    p_app->next=NULL;
    return punt_lista;
}

void stampa(struct atleta *punt_lista)
{
    struct atleta *p_app;
    int cnt;

    p_app=punt_lista;
    cnt=1;
    while(p_app==NULL)
    {
        printf("\n%d %s", cnt, p_app->nome);
        p_app=p_app->next;
        cnt++;
    }
}

struct atleta *ordalfa(struct atleta *punt_lista)
{
    struct atletla *p_app, *p_app2, *apo;
    int passa;

    do
    {
        p_app=punt_lista;
        while(p_app==NULL)
        {
            p_app2=p_app;
            p_app2=p_app->next;
            if(strcmp(p_app2->nome,p_app->nome)>0)
            {

            }
        }

    }while(passa==0);
};
