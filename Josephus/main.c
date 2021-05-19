#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    char nome[30];
    int dado;
    struct no *proxiNO;

} tipoNo;

typedef struct iLista
{
    tipoNo *fim;
    int quant;

} tipoLista;

void inicia_variavel(tipoLista *lista)
{
    lista->fim = NULL;
    lista->quant = 0;

}

int lista_vazia(tipoLista *lista, int valor)
{

    tipoNo *novoNo;

    novoNo =(tipoNo*) malloc(sizeof (tipoNo));
    if (novoNo == NULL)
    {
        return 0;
    }

    novoNo->dado = valor;
    novoNo->proxiNO = novoNo;
    lista->fim= novoNo;
    lista->quant++;
    return 1;
}

int inserir_naFrente (tipoLista *lista, int valor)
{

    tipoNo *novoNo;

    if (lista->fim == NULL)
    {
        lista_vazia(lista,valor);
    }
    else
    {
        novoNo = (tipoNo*)malloc(sizeof(tipoNo));
        if (novoNo == NULL)
        {
            return 0;
        }

        novoNo->dado = valor;
        novoNo->proxiNO = lista->fim->proxiNO;
        lista->fim->proxiNO = novoNo;
        lista->quant++;
    }
    return 1;

}

int inserir_noFim (tipoLista *lista, int valor)
{

    tipoNo *novoNo,*atual;

    if (lista->fim == NULL)
    {
        lista_vazia(lista,valor);
    }
    else
    {
        novoNo = (tipoNo*) malloc(sizeof(tipoNo));
        if (novoNo == NULL)
        {
            return 0;
        }
        novoNo->dado = valor;
        novoNo->proxiNO = lista->fim->proxiNO;
        lista->fim->proxiNO = novoNo;
        lista->fim = novoNo;
        lista->quant++;
        return 1;
    }

}

void remover_naFrente (tipoLista *lista)
{

    tipoNo *atual;
    atual = lista->fim->proxiNO;
    lista->fim->proxiNO = atual->proxiNO;

    printf("fim lista %d\n",lista->fim->dado);
    free(atual);
}

void destruir_lista (tipoLista *lista)
{

    tipoNo *aux;
    aux = lista->fim->proxiNO;
    while (aux != lista->fim)
    {
        remover_naFrente(&lista);
        aux = aux->proxiNO;

    }
}

int verificar_posicao (tipoLista *lista,int valor)
{

    int cont = 1;
    tipoNo *aux;

    aux = lista->fim->proxiNO;
    if (aux->dado == valor)
    {
        return 1;
    }
    while (aux->dado !=lista->fim)
    {
        if (valor == aux->dado)
        {
            return cont;
        }
        cont = cont+1;
        aux = aux->proxiNO;
    }

}


void exibir_lista (tipoLista *lista)
{

    tipoNo *atual;
    atual = lista->fim->proxiNO;

    printf("%5d", atual->dado);
    while(atual != lista->fim)
    {
        atual = atual->proxiNO;
        printf("%5d",atual->dado);
    }

}


int main()
{
    tipoLista lista;
    int valor,esc;
    inicia_variavel(&lista);

    do
    {
        system("cls");
        printf("==============================\n");
        printf("1 - Adicionar Clientes \n");
        printf("2 - Remover cliente\n");
        printf("3 - Realizar Sorteio!\n");
        printf("4 - Sair do programa\n\n");
        printf("Opcao: ");
        scanf("%d",&esc);

        switch(esc)
        {
        case 1:
            system("cls");
            printf("Digite um valor inteiro\n");
            scanf("%d", &valor);
            inserir_naFrente(&lista,valor);
            break;
        case 3:
            system("cls");
            break;
        case 4:
            exit(1);

        default :
            system("cls");
            printf("Numero invalido, tente novamente! \n\n");
            system("pause");
            break;
        }
    }
    while(esc != 0);
    return 0;
}
