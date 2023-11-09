#include<stdio.h>
#include<stdlib.h>

struct No{
        int dia, mes;
        char evento[100];
        struct No *esq;
        struct No *dir;
    };
    typedef struct No no;
    typedef no *ArvBin;

    AvrBin* criarAvrBin(){
    ArvBin *raiz =(ArvBin*) malloc(sizeof(AvrBin));
    if(raiz != NULL){
        *raiz=NULL;
    }else{
        printf("Erro na alocacao...\n");
        exit(0);
    }
    return raiz;
}

    //INSERE NA ARVORE
int insere_ArvBin(ArvBin* raiz){
    no *novo=(no *)malloc (sizeof(no));
    if(novo==NULL){
        printf("Sem memoria disponivel!\n");
        exit(0);
    }
    printf("Insira o nome do evento: ");
    gets(novo->num);
    printf("Insira o dia do evento: ");
    scanf("%i",&novo->dia);
    printf("Insira o mes do evento: ");
    scanf("%i",&novo->mes);
    novo->dir=NULL;
    novo->esq=NULL;
    if(*raiz==NULL){
        *raiz =novo;
    }else{
        no *atual =*raiz;
        no *ant = NULL;
        while(atual!=NULL){
            ant=atual;
            if(novo->dia==atual->dia&&novo->mes==atual->mes){
                printf("Ja existe um evento marcado para esse dia que e:\n %s",atual->evento);
                free(novo);
                return 0;
            }
            if (novo->mes>atual->mes){//mes maior
                atual=atual->dir;
            }else if(novo->mes==atual->mes){//mes igual
                if(novo->dia>atual->dia){//compara o dia maior
                    atual=atual->dir;
                }else if(novo->dia==atual->dia){//dia igual
                    printf("Ja existe um evento marcado para esse dia que e:\n %s",atual->evento);
                }else if(novo->dia<atual->dia){//dia menor
                    atual=atual->esq;
                }
            }else if (novo->mes<novo->mes){//mes menor
                atual=atual->esq;
            }
        }
        if(novo->mes > ant->mes){
            if(novo->dia>ant->dia){
                ant->dir=novo;
            }else{
                ant->esq=novo;
            }
        }else{
            if(novo->dia>ant->dia){
                ant->dir=novo;
            }else{
                ant->esq=novo;
            }
        }
    }
}

int main (){

}
