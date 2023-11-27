#include<stdio.h>
#include<stdlib.h>
#include<string.h>

    //Cria a Struct do evento
struct No{
        int dia, mes;
        char evento[100];
        struct No *esq;
        struct No *dir;
    };
    typedef struct No no;
    typedef no *ArvBin;

    //Cria struct da lista
    struct Node {
    ArvBin arvbin;
    struct Node* prox;
};

typedef struct Node node;
typedef node* lista;

    //Cria a cabeça da arvore
    AvrBin* criarAvr(){
    ArvBin *raiz =(ArvBin*) malloc(sizeof(AvrBin));
    if(raiz != NULL){
        *raiz=NULL;
    }else{
        printf("Erro na alocacao...\n");
        exit(0);
    }
    return raiz;
}
    //Cria a cabeca da lista
    lista* criarlista(){
    lista *inicio = (lista*) malloc(sizeof(lista));
    if (inicio != NULL){
        *inicio = NULL;
    }else{
        printf("Erro na alocação");
    }
    return inicio;
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
    //IMPRIME ARVORE
void imprime_no(no *no_print){
    if(no_print == NULL){
        return;
    }else{
        imprime_no(no_print->esq);
        printf("-> %i/%i - %i\n",no_print->dia, no_print->mes, no_print->evento);
        imprime_no(no_print->dir);
    }
}

int imprime(ArvBin * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        imprime_no(*raiz);
    }
}
    //DELETA
    int deletar(ArvBin * raiz){

}
    //MAIN
int main (){
    ArvBin *raiz = criarAvr();
    int choice;

    do{
    printf("---BEM VINDO(A) AO CALENDARIO---\n O que deseja fazer?\n");
    printf("1. Cadastrar novo evento\n");
    printf("2. Visualizar eventos\n");
    printf("3. Deletar um evento");
    printf("0. Sair\n");
    scanf("%i",&choice);
    switch(choice){
    case 1:
        insere_ArvBin(raiz);
        break;
    case 2:
        imprime(raiz);
        break;
    case 3:
        deletar(raiz);
        break;
    default:
        printf("Erro! Faca uma escolha valida.");
        break;
    }
    }while(choice!=0);
}
