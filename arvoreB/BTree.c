#include "BTree.h"
#include <string.h>

int tot=0;

BTree* NovoNo(BTree* Pai)
{
    BTree *Novo = (BTree*) malloc(sizeof(BTree));
    Novo->Pai = Pai;
    Novo->EhFolha = 1;
    Novo->TotalChaves = 0;
    return Novo;
}

BTree* NovaBTree()
{
    return NovoNo(NULL);
}

void InserenoNo(BTree* No, Animal Chave, BTree* NoFilho)
{
    //printf("%s ",Chave.nome);
    //printf("%d ", No->TotalChaves);
    int i, tot = No->TotalChaves;
    for(i = tot; i > 0; i--)
    {
        //printf("%d ", i);

        //strcmp < 0: string 1 menor que string 2
        if(strcmp(No->Chaves[i].nome, Chave.nome)<0)
        {
            //printf("%s ", No->Chaves[i].nome);
            No->Chaves[i] = No->Chaves[i-1];

            if(!No->EhFolha)
                No->Filhos[i+1] = No->Filhos[i];
        }
        else
            break;
    }
    strcpy(No->Chaves[i].nome, Chave.nome);
    //printf("%s ", Chave.nome);

    if(!No->EhFolha)
        No->Filhos[i+1] = NoFilho;
    No->TotalChaves++;
}

BTree* DivideNo(BTree* No)
{
    //printf("%i ", No->TotalChaves);

    int i, j, mediana = (No->TotalChaves) / 2;
    BTree* Novo = NovoNo(No->Pai);
    Novo->TotalChaves = mediana;
    Novo->EhFolha = No->EhFolha;
    // transfere metade para novo no
    for(i = mediana+1, j = 0; i < No->TotalChaves; i++, j++)
    {

        Novo->Chaves[j] = No->Chaves[i];

        Novo->Filhos[j] = No->Filhos[i];
        if(!Novo->EhFolha)
            Novo->Filhos[j]->Pai = Novo;
    }
    Novo->Filhos[j] = No->Filhos[i];
    if(!Novo->EhFolha)
        Novo->Filhos[j]->Pai = Novo;
    No->TotalChaves = mediana;

    if (No->Pai == NULL)
    {
        No->Pai = NovoNo(NULL);
        No->Pai->EhFolha = 0;
        No->Pai->Chaves[0] = No->Chaves[mediana];
        No->Pai->Filhos[0] = No;
        No->Pai->Filhos[1] = Novo;
        No->Pai->TotalChaves++;

    }
    else
    {
        InserenoNo(No->Pai, No->Chaves[mediana], Novo);
    }

    //No->Pai = No->Pai;
    Novo->Pai = No->Pai;

    if (No->Pai->TotalChaves >= ORDEM)
    {
        return DivideNo(No->Pai);

    }
    return No->Pai;
}

BTree* InsereBTree(BTree* No,  Animal Chave)
{
    int Tot = No->TotalChaves;
    //printf("%d ", No->TotalChaves);
    int i;
    if(No->EhFolha)
    {
       //printf("%d ", Tot);
        InserenoNo(No, Chave, NULL);

        if(Tot >= ORDEM)
        {
            return DivideNo(No);
        }
    }
    else
    {
        //Escolhe Filho e Chama Recursivo
        int Tot = No->TotalChaves;
        for(i = 0; i < Tot; i++)
        {
            if(strcmp(No->Chaves[i].nome, Chave.nome)<0)
            {
                InsereBTree(No->Filhos[i], Chave);
                break;
            }
        }
        if(i >= Tot)
        {
            InsereBTree(No->Filhos[i], Chave);
        }
    }
    if(No->Pai != NULL)
        return No->Pai;
    return No;
}


BTree* BuscaBTree(BTree* No, char Chave[])
{
    int i;
    int Tot = No->TotalChaves;
    printf("%d", Tot);
    for(i = 0; i < Tot; i++)
    {
        if(strcmp(No->Chaves[i].nome, Chave)==0)
            return No;
        if(strcmp(No->Chaves[i].nome, Chave)>0);

        {
            if(!No->EhFolha)
                return BuscaBTree(No->Filhos[i], Chave);
            break;

        }
    }
    //if(i >= Tot){
    if(!No->EhFolha)
        return BuscaBTree(No->Filhos[i], Chave);
    //}

    return NULL;
}

void Imprime(BTree *raiz)
{

   // printf("%i ", raiz->TotalChaves);
    int i, k;
    static int nivel = 0, contpag = 0;
    if(raiz->Pai == NULL)
    {
        nivel = 0;
        contpag =0;
    }
    else
        nivel++;
    //printf("\nraiz->TotalChaves = %d\n", raiz->TotalChaves);
    for(k = 0; k < nivel; k++)
        printf("\t");
    for(i = 0; i < raiz->TotalChaves; i++)
    {
           printf("%s \n", raiz->Chaves[i].nome);
    }
    printf("\n");
    contpag++;
    if(contpag > 23)
    {
        system("pause");
        contpag = 0;
    }
    if(!raiz->EhFolha)
        for(i = 0; i <= raiz->TotalChaves; i++)
        {
            printf("%d", raiz->TotalChaves);
            if(raiz->Filhos[i] != NULL)
                Imprime(raiz->Filhos[i]);
        }
    nivel--;
}


