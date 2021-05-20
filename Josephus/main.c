#include <stdio.h>
#include <stdlib.h>

/*Estrutura que representa um nó da lista*/
typedef struct no
{
    int dado;
    struct no *proxNo;
} tipoNo;

/*Estrutura que guarda as informações de uma lista circular*/
typedef struct listaGerenciada
{
    tipoNo *fim;
    int quant;
} tipoLista;

/*Função que faz a inicialização da lista circular*/
void inicializa(tipoLista *listaEnc)
{
    listaEnc->fim = NULL;
    listaEnc->quant = 0;
}

/*Função que retorna 1 caso a lista esteja vazia e 0 caso esteja povoada*/
int estaVazia(tipoLista *listaEnc)
{
    if (listaEnc->fim == NULL)
        return 1;
    else
        return 0;
}

/*Função que faz a inserção de um nó em uma lista vazia*/
int insereListaVazia(tipoLista *listaEnc, int valor)
{
    tipoNo *novoNo;
    novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if(novoNo == NULL)
        return 0;
    novoNo->dado = valor;
    novoNo->proxNo = novoNo;
    listaEnc->fim = novoNo;
    listaEnc->quant++;
    return 1;
}

/*Função que percorre a lista exibindo todos os seus dados*/
void exibeLista(tipoLista *listaEnc)
{
    tipoNo *atual;  /*Variável que será usada para percorrer a lista*/
    atual = listaEnc->fim->proxNo;
    printf("\nLista encadeada: ");
    printf("%8d",atual->dado);
    while(atual !=listaEnc->fim)
    {
        atual = atual->proxNo;
        printf("%8d",atual->dado);
    }
}

/*Função que insere elemento no inicio da lista*/
int insereNaFrente(tipoLista *listaEnc, int valor)
{
    tipoNo *novoNo;
    if(listaEnc->fim==NULL)
        insereListaVazia(listaEnc, valor);
    else
    {
        novoNo = (tipoNo*)malloc(sizeof(tipoNo));
        if(novoNo==NULL)
            return 0;
        novoNo->dado=valor;
        novoNo->proxNo=listaEnc->fim->proxNo;
        listaEnc->fim->proxNo=novoNo;
        listaEnc->quant++;
        return 1;
    }
}

/*Função que remove elemento do final da lista*/
void removeDoFim(tipoLista *listaEnc)
{
    tipoNo *atual, *antigo;
    atual = listaEnc->fim->proxNo;
    if(atual->proxNo == atual)
    {
        listaEnc->fim = NULL;
        listaEnc->quant--;
    }
    else
    {
        while(atual!=listaEnc->fim)
        {
            antigo = atual;
            atual= atual->proxNo;
        }
        antigo->proxNo=antigo->proxNo->proxNo; /* ou recebe listaEnc->fim->proxNo;*/
        listaEnc->fim=antigo;
    }
    free(atual);
}

/*Função que insere elemento ao final da lista*/
int insereNoFim(tipoLista *listaEnc, int valor)
{
    tipoNo *novoNo;
    if(listaEnc->fim == NULL)
        insereListaVazia(listaEnc, valor);
    else
    {
        novoNo = (tipoNo*) malloc(sizeof (novoNo));
        if(novoNo == NULL)
            return 0;
        novoNo->dado = valor;
        novoNo->proxNo = listaEnc->fim->proxNo;
        listaEnc->fim->proxNo = novoNo;
        listaEnc->fim = novoNo;
        listaEnc->quant++;
    }
}

/*Função que insere elemento no inicio da lista*/
void removeDoInicio(tipoLista *listaEnc)
{
    tipoNo *atual;
    if(listaEnc->quant > 1)
    {
        atual = listaEnc->fim->proxNo;
        printf("\nNo removido ===> %d",atual->dado);
        listaEnc->fim->proxNo = atual->proxNo;
    }
    else
        listaEnc->fim = NULL;
    listaEnc->quant--;
    free(atual);
}

/*Função que destroi a lista, liberando a memória*/
void destruirLista(tipoLista *listaEnc)
{
    while(!estaVazia(listaEnc))
    {
        removeDoInicio(listaEnc);
    }
}

/*Função que busca dado na lista e retorna a posição em que o dado foi encontrado*/
int buscaDado(tipoLista *listaEnc, int valor)
{
    tipoNo *atual, *antigo;
    int cont=1;
    atual=listaEnc->fim;
    do
    {

        atual=atual->proxNo; /*O primeiro ponteiro recebido aponta para o inicio da lista*/
        if(atual->dado == valor)
            antigo->proxNo = atual->proxNo->proxNo;
        free(atual);
        return cont;
        cont++;
    }
    while(atual != listaEnc->fim);
    return 0; /*Caso o dado não seja encontrado, é retornado o valor zero*/
}

int removeDaLista(tipoLista *listaEnc, int valor)
{
    tipoNo *aux, *seguinte;

    if(listaEnc->fim)
    {
        aux = listaEnc->fim;
        seguinte = aux->proxNo;
        while(seguinte != listaEnc->fim)
        {
            if(!strcmp(seguinte->dado, valor))
            {
                aux->proxNo = seguinte->proxNo;
                free(seguinte);
                listaEnc->quant--;
                return 1;
            }
            aux = seguinte;
            seguinte = seguinte ->proxNo;
        }
        if(!strcmp(seguinte->dado, valor))
        {
            if(aux == seguinte)
            {
                listaEnc->fim == NULL;

            }
            else
            {
                aux->proxNo = seguinte->proxNo;
                listaEnc->fim == seguinte->proxNo;
            }
            free(seguinte);
            listaEnc->quant--;
            return 1;
        }
    }
    return 0;
}

void main()
{
    tipoLista lista;
    int aux, aux2, dado, op;
    inicializa(&lista);
    do
    {
        printf("\n===============MENU===============");
        printf("\n1 - Insere elemento em lista vazia");
        printf("\n2 - Insere elemento na frente da lista");
        printf("\n3 - Remove do inicio");
        printf("\n4 - Insere elemento no fim da lista");
        printf("\n5 - Busca dado na lista");
        printf("\n6 - Remove elemento do fim da lista");
        printf("\n9 - Exibe lista");
        printf("\n10 - Projeto");
        printf("\n0 - Encerra programa");
        printf("\nEscolha sua opcao: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("\nDigite o elemento que deseja inserir: ");
            scanf("%d",&aux);
            insereListaVazia(&lista, aux);
            break;
        case 2:
            printf("\nDigite o elemento que deseja inserir: ");
            scanf("%d",&aux);
            insereNaFrente(&lista, aux);
            break;
        case 3:
            removeDoInicio(&lista);
            break;
        case 4:
            printf("\nDigite o elemento que deseja inserir: ");
            scanf("%d",&aux);
            insereNoFim(&lista, aux);
            break;
        case 5:
            printf("\nDigite o elemento que deseja buscar: ");
            scanf("%d",&aux);
            buscaDado(&lista, aux);
            break;
        case 6:
            removeDoFim(&lista);
            break;
        case 9:
            exibeLista(&lista);
            break;
        case 10:
            printf("\nDigite o elemento que deseja remover: ");
            scanf("%d",&aux);
            removeDaLista(&lista, aux);
            break;
        case 0:
            printf("\nEncerrando programa.");
            destruirLista(&lista);
            break;
        }
    }
    while(op != 0);
}
