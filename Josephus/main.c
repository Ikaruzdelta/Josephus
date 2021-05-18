#include <stdio.h>
#include <stdlib.h>

typedef struct no {
int dado;
struct no *proxiNO;

}tipoNo;

typedef struct iLista{
tipoNo *fim;
int quant;
}tipoLista;

void inicia_variavel(tipoLista *lista){
lista->fim = NULL;
lista->quant = 0;

}

int lista_vazia(tipoLista *lista, int valor){

tipoNo *novoNo;

novoNo =(tipoNo*) malloc(sizeof (tipoNo));
if (novoNo == NULL){
    return 0;
}

novoNo->dado = valor;
novoNo->proxiNO = novoNo;
lista->fim= novoNo;
lista->quant++;
return 1;
}

int inserir_noFrente (tipoLista *lista, int valor){

tipoNo *novoNo;

if (lista->fim == NULL){
    lista_vazia(lista,valor);
}
else{
novoNo = (tipoNo*)malloc(sizeof(tipoNo));
if (novoNo == NULL)
{
    return 0;
}

novoNo->dado = valor;
novoNo->proxiNO = lista->fim->proxiNO;
lista->fim->proxiNO = novoNo;
lista->quant++;
}return 1;

}

int inserir_noFim (tipoLista *lista, int valor){

tipoNo *novoNo,*atual;

if (lista->fim == NULL){
    lista_vazia(lista,valor);
}else{
novoNo = (tipoNo*) malloc(sizeof(tipoNo));
if (novoNo == NULL){
    return 0;
}
novoNo->dado =valor;
novoNo->proxiNO = lista->fim->proxiNO;
lista->fim->proxiNO= novoNo;
lista->fim = novoNo;
lista->quant++;
return 1;
}

}

void remover_noFrente (tipoLista *lista){

tipoNo *atual;
atual = lista->fim->proxiNO;
lista->fim->proxiNO = atual->proxiNO;

printf("fim lista %d\n",lista->fim->dado);
free(atual);
}

void destruir_lista (tipoLista *lista){

tipoNo *aux;
aux = lista->fim->proxiNO;
while (aux != lista->fim){
remover_noFrente(&lista);
aux = aux->proxiNO;

}
}

int verificar_posicao (tipoLista *lista,int valor){

int cont = 1;
tipoNo *aux;

aux = lista->fim->proxiNO;
if (aux->dado == valor){
    return 1;
}
while (aux->dado !=lista->fim){
    if (valor == aux->dado)
    {
        return cont;
    }
    cont = cont+1;
    aux = aux->proxiNO;
}

}


void exibir_lista (tipoLista *lista){

tipoNo *atual;
atual = lista->fim->proxiNO;

printf("%5d", atual->dado);
while(atual != lista->fim){
    atual = atual->proxiNO;
    printf("%5d",atual->dado);
}

}


int main()
{
    tipoLista lista;
    int valor,esc;
    inicia_variavel(&lista);

    do{
        printf("\n1 - inserir lista vazia \n");
        printf("2 - inserir no frente \n");
        printf("3 - inserir no fim \n");
        printf("4 - remover no frente \n");
        printf("5 - destruir lista \n");
        printf("9 - exibir lista \n");
        scanf("%d",&esc);

        switch(esc){
    case 1:
        printf("Digite um valor inteiro\n");
        scanf("%d", &valor);
        lista_vazia(&lista,valor);
        break;
    case 2:
        printf("Digite um valor inteiro\n");
        scanf("%d", &valor);
        inserir_noFrente(&lista,valor);
    break;
    case 3:
        printf("Digite um valor inteiro\n");
    scanf("%d", &valor);
    inserir_noFim(&lista,valor);
        break;
    case 4:
        remover_noFrente(&lista);
        break;
    case 5:
        destruir_lista(&lista);
        break;
    case 6:
          printf("digite o numero \n");
          scanf("%d",&valor);
          int rec;
          rec = verificar_posicao(&lista,valor);
          if (rec){
            printf("o numero %d esta na posicao %d \n", valor,rec);
          }
          else{printf("numero nao encontrado\n");}
          break;
    case 9:
        exibir_lista(&lista);
        break;

    case 0:

        break;
    default :
        printf("numero invalido \n");
        break;}
    }while(esc != 0);







    return 0;
}
