#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 15:20
//1 HORA E 10 MIN PRA FAZER!
typedef struct {
    char nome[50];
    char email[20];
    char contato[10];
}Agenda;

struct lista{
    Agenda agenda;
    struct lista * direito;
};
typedef struct lista no;
int tamanho;

void inserir_contato(no** inicio, Agenda agenda);
void ordena_alfabeticamente(no**inicio);
int busca(no *inicio,Agenda agenda);
int buscaPosicao(no *inicio,Agenda agenda);
void remover(no**inicio, Agenda agenda);
void remover_inicio(no**inicio);
void remover_fim(no**inicio);
void imprimir(no*inicio);
int main()
{
    int op;
    no *inicio=NULL;
    Agenda agenda;
    tamanho=0;
    do{
        printf("\n1-Inserir 2-remover 3-mostrar 4-sair:");
        fflush(stdin);
        scanf("%d",&op);
        switch(op){
            case 1:{
            fflush(stdin);
              printf("\nDIGITE NOME:");
              gets(agenda.nome);
              printf("\nDIGITE COONTATO:");
              gets(agenda.contato);
              printf("\nDIGITE EMAIL:");
              gets(agenda.email);
              inserir_contato(&inicio,agenda);
              break;
            }
            case 2:{
              fflush(stdin);
              printf("\n--remover---");
              printf("\nDIGITE NOME:");
              gets(agenda.nome);
              printf("\nDIGITE COONTATO:");
              gets(agenda.contato);
              printf("\nDIGITE EMAIL:");
              gets(agenda.email);
              remover(&inicio,agenda);
              break;
            }
            case 3:{
                printf("\n--Mostrar---");
                system("cls");
                imprimir(inicio);
                break;
            }
            case 4:{
                printf("\nSAIR");
                break;
            }
            default:{
                break;
            }
        }


    }while(op!=4);
    return 0;
}
void inserir_contato(no** inicio, Agenda agenda){
  if(busca(*inicio,agenda)!=EXIT_SUCCESS){
        no*novo=(no*)malloc(sizeof(no));
        if(novo!=NULL){
            novo->direito=*inicio;
            novo->agenda=agenda;
            *inicio=novo;
            novo=NULL;
            free(novo);
            tamanho++;
            ordena_alfabeticamente(inicio);
        }
    }else
    printf("\nVALOR EXISTE");

}
void ordena_alfabeticamente(no**inicio){
    int i,j;
    no *auxI=*inicio,*auxJ=*inicio;
    Agenda ajuda;
    for(i=0;i<tamanho;i++){
        auxI=*inicio;
        auxJ=auxI->direito;
        for(j=0;j<tamanho-1;j++){
            if(strcasecmp(auxI->agenda.nome,auxJ->agenda.nome)==1){
                ajuda=auxI->agenda;
                auxI->agenda=auxJ->agenda;
                auxJ->agenda=ajuda;
            }
            auxI=auxI->direito;
            auxJ=auxI->direito;
        }
    }
auxJ=NULL;
auxI=NULL;
free(auxJ);
free(auxI);
}
int busca(no *inicio,Agenda agenda){
    int i;
    no *aux=inicio;
    for(i=0;i<tamanho;i++){
        if(strcasecmp(aux->agenda.nome,agenda.nome)==0 || strcasecmp(aux->agenda.email,agenda.email)==0 ||strcasecmp(aux->agenda.contato,agenda.contato)==0){
            i=tamanho-1;//faz parar
            return EXIT_SUCCESS;
        }
        aux=aux->direito;
    }
    return EXIT_FAILURE;
}
void remover(no**inicio, Agenda agenda){
    if(busca(*inicio,agenda)==EXIT_SUCCESS){
       int posicao=buscaPosicao(*inicio,agenda);
       if(posicao<=1){
            remover_inicio(inicio);
            return;
       }
       if(posicao>=tamanho){
            remover_fim(inicio);
            return;
       }
       no* anterior=*inicio,*lixo;
       int i;
       for(i=1;i<posicao-1;i++){
           anterior=anterior->direito;
       }
       lixo=anterior->direito;
       anterior->direito=lixo->direito;
       lixo->direito=NULL;
       lixo=NULL;
       anterior=NULL;
       free(anterior);
       free(NULL);
       tamanho--;
    }
    else
        printf("\nNAO EXISTE");

}
int buscaPosicao(no *inicio,Agenda agenda){
    int i;
    no *aux=inicio;
    for(i=0;i<tamanho;i++){
        if(strcasecmp(aux->agenda.nome,agenda.nome)==0 || strcasecmp(aux->agenda.email,agenda.email)==0 ||strcasecmp(aux->agenda.contato,agenda.contato)==0){
            return i+1;
        }
        aux=aux->direito;
    }
    aux=NULL;
    free(aux);
    return EXIT_FAILURE;
}
void remover_inicio(no**inicio){
     no *aux=*inicio;
     *inicio=aux->direito;
     aux->direito=NULL;
     free(aux);
     aux=NULL;
     tamanho--;
}
void remover_fim(no**inicio){
    no *penultimo=*inicio,*ultimo=*inicio;
    while(ultimo->direito!=NULL){
        penultimo=ultimo;
        ultimo=ultimo->direito;
    }
    penultimo->direito=NULL;
    free(ultimo);
    ultimo=NULL;
    penultimo=NULL;
    free(penultimo);
    tamanho--;
}
void imprimir(no*inicio){
    no*aux=inicio;
    int i;
    for(i=0;i<tamanho;i++){
        printf("\n-------------------------");
        printf("\nNOME:%s",aux->agenda.nome);
        printf("\nCONTATO:%s",aux->agenda.contato);
        printf("\nEMAIL:%s",aux->agenda.email);
        aux=aux->direito;
        printf("\n-------------------------");
    }
    aux=NULL;
    free(aux);
}
