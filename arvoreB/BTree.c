#include "BTree.h"
#include <string.h>

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
    // printf("%s ",Chave.nome);
    //printf("%d ", No->TotalChaves);
    int i;
    for(i = No->TotalChaves; i > 0; i--)
    {
        //strcmp < 0: string 1 menor que string 2
        if(strcmp(No->Chaves[i].nome, Chave.nome)>0)
        {
            No->Chaves[i] = No->Chaves[i-1];

            if(!No->EhFolha)
                No->Filhos[i+1] = No->Filhos[i];
        }
        else
            break;
    }
    strcpy(No->Chaves[i].nome, Chave.nome);

    if(!No->EhFolha)
        No->Filhos[i+1] = NoFilho;
    No->TotalChaves++;
}

BTree* DivideNo(BTree* No)
{
    int i=0, j=0, mediana = (No->TotalChaves) / 2;
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

    //printf("%d ", No->TotalChaves);
    int i;
    if(No->EhFolha)
    {
        InserenoNo(No, Chave, NULL);

        if(No->TotalChaves >= ORDEM)
        {
            return DivideNo(No);
        }
    }
    else
    {
        //Escolhe Filho e Chama Recursivo
        for(i = 0; i < No->TotalChaves; i++)
        {
            if(strcmp(No->Chaves[i].nome, Chave.nome)<0)
            {
                InsereBTree(No->Filhos[i], Chave);
                break;
            }
        }
        if(i >= No->TotalChaves)
        {
            InsereBTree(No->Filhos[i], Chave);
        }
    }
    if(No->Pai != NULL)
        return No->Pai;
    return No;
}

BTree* BuscaBTree(BTree* No, char buscado[])
{
    int i;
    for(i = 0; i < 50; i++)
    {
        if(strcmp(No->Chaves[i].nome, buscado)==0)
            return No;
        if(strcmp(No->Chaves[i].nome, buscado)>0);
        {
            while(!No->EhFolha)
                return BuscaBTree(No->Filhos[i], buscado);
            //break;
        }
    }
    return NULL;
}

/*
void Imprime(BTree *raiz)
{
    //printf("%i ", raiz->TotalChaves);
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
            //printf("%d", raiz->TotalChaves);
            if(raiz->Filhos[i] != NULL)
                Imprime(raiz->Filhos[i]);
        }
    nivel--;
}

*/
