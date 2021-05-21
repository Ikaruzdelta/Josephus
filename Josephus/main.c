#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct info
{
    char *nome;
    struct info *proxinfo;
    char *cpf;
    int id;
    int pos;
} info;

typedef struct Genlista
{
    info *fim;
    int quant;

} Lista;

typedef struct ler
{
    char nome[20];
} ler[10];

void inicia_lista(Lista *lista)
{
    lista->fim = NULL;
    lista->quant = 0;
}

int inserir_nome_Lvazia (Lista *lista, int num, char *nome)
{
    info *infoN;

    infoN = (info*)malloc (sizeof(info));
    if (infoN == NULL)
    {
        return 0;
    }
    else
    {
        infoN ->id =num;
        infoN ->nome =nome;
        infoN->proxinfo = infoN;
        lista->fim = infoN;
        return 1;
    }
}

int inserir_lista_inicio(Lista *lista,int num,char *nome)
{
    info *novainfo;
    if (lista == NULL)
    {
        inserir_nome_Lvazia(lista,num,nome);
        return 1;
    }
    novainfo = (info*) malloc(sizeof(info));
    if(novainfo== NULL)
    {
        return 0;
    }
    else
    {
        novainfo->id = num;
        novainfo->nome = nome;
        novainfo->proxinfo= lista->fim->proxinfo;
        lista->fim->proxinfo=novainfo;
        lista->quant++;
        return 1;
    }
}

int inserir_lista_fim (Lista *lista, int num, char *nome)
{

    info *novainfo;
    int cont = 1;
    if (lista->fim == NULL)
    {
        inserir_nome_Lvazia(lista,num,nome);
        return 1;
    }
    novainfo = (info*) malloc(sizeof(info));
    if (novainfo == NULL)
    {
        return 0;
    }
    else
    {
        novainfo->id = num;
        novainfo->nome = nome;
        novainfo->proxinfo = lista->fim->proxinfo;
        lista->fim->proxinfo= novainfo;
        lista->fim=novainfo;
        lista->quant++;
        return 1;
    }
}

int exibir (Lista *lista)
{
    info *aux;
    aux = lista->fim->proxinfo;

    printf("\nPARTICIPANTE: %5s   ID: %d  \n",aux->nome,aux->id);
    while(aux != lista->fim)
    {
        aux = aux ->proxinfo;
        printf("PARTICIPANTE: %5s   ID: %d  \n",aux->nome,aux->id);
    }
}

void remover_do_sorteio (Lista *lista, int pos)
{
    info *aux, *ant,*null;
    aux = lista->fim->proxinfo;
    null = lista->fim;
    if (aux->id == pos)
    {
        printf("Eliminado da rodada %s:\n\n",aux->nome);
        remover_noFrente(lista);
    }
    else if(null->id == pos)
    {
        printf("Eliminado da rodada %s:\n\n",aux->nome);
        remover_fim(lista);
    }
    else
    {
        while (lista->fim!= aux)
        {
            ant = aux;
            aux = aux ->proxinfo;
            if (aux->id == pos)
            {
                printf("Eliminado da rodada %s:\n\n",aux->nome);
                ant->proxinfo = aux->proxinfo;
            }
        }
    }
    printf("Continuam : \n");
}

void remover_fim (Lista *lista)
{
    info *atual, *antigo;
    atual = lista->fim->proxinfo;

    if (atual->proxinfo == atual )
    {
        lista->fim = NULL;
        lista->quant--;
    }
    else
    {
        while(atual != lista->fim)
        {
            antigo = atual;
            atual = atual->proxinfo;
        }
        antigo->proxinfo = antigo->proxinfo->proxinfo;
        lista->fim = antigo;
        free(atual);
    }
}

void remover_noFrente (Lista *lista)
{
    info *atual;
    if (lista->quant > 0)
    {
        atual = lista->fim->proxinfo;
        lista->fim->proxinfo = atual->proxinfo;
    }
    else
    {
        lista->fim = NULL;
        lista->quant--;
    }
    free(atual);
}

int random ()
{
    srand( (unsigned)time(NULL) );
    return rand()%10;
}

void realizar_cadastro (Lista *lista,int *cont)
{
    ler c;
    int pos;
    printf("::::: CADASTRO :::::\n");
    fflush(stdin);
    printf("Digite o nome do participante: ");
    gets(c[*cont].nome);
    system("cls");
    printf("Digite a ID do participante: \n");
    scanf("%d",&pos);
    inserir_lista_fim(lista,pos,c[*cont].nome);
    *cont = *cont+1;
}

int pesquisa_de_sorteio (Lista *lista)
{
    info *aux;
    aux = lista->fim;

    for(int i = 0; i < random(); i++)
    {
        aux = aux->proxinfo;
    }
    return aux->id;
}

void verificar_vencedor(Lista *lista)
{
    info *aux;
    aux = lista->fim->proxinfo;

    if (aux == lista->fim)
    {
        printf("VENCEDOR : %s \n\n",aux->nome);
    }
}


int verificar(Lista * lista)
{
    info *aux;
    aux = lista->fim->proxinfo;
    if (aux == lista->fim )
    {
        return 1;
    }
    return 0;
}

int main()
{
    int pos,esc;
    Lista lista;
    int num = 5,num1,rec,cont = 0;
    char nome1[20];
    ler c;
    inicia_lista(&lista);

    do
    {
        printf("=============MENU============\n");
        printf("1 - Cadastrar participante ");
        printf("\n2 - Sortear");
        printf("\n3 - Exibir participantes");
        printf("\n4 - Excluir participante\n");
        printf("\nEscolha a opcao: ");
        scanf("%d",&esc);
        switch(esc)
        {
        case 1:
            system("cls");
            printf("    ::::: CADASTRO :::::\n");
            fflush(stdin);
            printf("Digite o nome do participante: ");
            gets(c[cont].nome);
            printf("\nID do participante: ");
            scanf("%d",&pos);
            inserir_lista_fim(&lista,pos,c[cont].nome);
            cont = cont+1;
            system("cls");
            break;
        case 2:
            system("cls");
            if (verificar(&lista))
            {
                verificar_vencedor(&lista);
            }
            else
            {
                remover_do_sorteio(&lista,pesquisa_de_sorteio(&lista));
                if (verificar(&lista))
                {
                    verificar_vencedor(&lista);
                }
            }
            exibir(&lista);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            exibir(&lista);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            exibir(&lista);
            printf("/nInforme o id do participante que deseja remover \n");
            scanf("%d",&pos);
            remover_do_sorteio(&lista,pos);
        }
    }
    while (esc != 0);
    printf("%d", pesquisa_de_sorteio(&lista));
    return 0;
}
