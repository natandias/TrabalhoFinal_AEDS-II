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

void InserenoNo(BTree* No, char  Chave[], BTree* NoFilho)
{
    int i;
    for(i = No->TotalChaves; i > 0; i--)
    {
       // printf(" work: %d", No->TotalChaves);
     //printf(" %d", No->TotalChaves);
     printf("\n %s", No->Chaves[5]);

        //strcmp < 0: string 1 menor que string 2
        if(strcmp(No->Chaves[i], Chave)<0) {

            strcpy(No->Chaves[i], No->Chaves[i-1]);

            if(!No->EhFolha) No->Filhos[i+1] = No->Filhos[i];
        }
        else break;
    }
         strcpy(No->Chaves[i], Chave);
    if(!No->EhFolha) No->Filhos[i+1] = NoFilho;
    No->TotalChaves++;
}

BTree* DivideNo(BTree* No)
{
    int i, j, mediana = (No->TotalChaves) / 2;
    BTree* Novo = NovoNo(No->Pai);
    Novo->TotalChaves = mediana;
    Novo->EhFolha = No->EhFolha;
    // transfere metade para novo no
    for(i = mediana+1, j = 0; i < No->TotalChaves; i++, j++)
    {
        strcpy(Novo->Chaves[j], No->Chaves[i]);
        Novo->Filhos[j] = No->Filhos[i];
        if(!Novo->EhFolha) Novo->Filhos[j]->Pai = Novo;
    }
    Novo->Filhos[j] = No->Filhos[i];
    if(!Novo->EhFolha) Novo->Filhos[j]->Pai = Novo;
    No->TotalChaves = mediana;

    if (No->Pai == NULL)
    {
        No->Pai = NovoNo(NULL);
        No->Pai->EhFolha = 0;
       strcpy(No->Pai->Chaves[0], No->Chaves[mediana]);
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

BTree* InsereBTree(BTree* No, char  Chave[])
{
    int i;
    if(No->EhFolha)
    {
        if(No->TotalChaves < ORDEM)
        {
            InserenoNo(No, Chave, NULL);
        }
        if(No->TotalChaves >= ORDEM)
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
            if(strcmp(No->Chaves[i], Chave)<0)
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
    if(No->Pai != NULL) return No->Pai;
    return No;
}


BTree* BuscaBTree(BTree* No, char Chave[]){
    int i;
    int Tot = No->TotalChaves;
    //printf("*");
    for(i = 0; i < Tot; i++){
        if(No->Chaves[i] == Chave) return No;
        if(No->Chaves[i] > Chave)
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

void Imprime(BTree *raiz){
    int i;
    static int nivel = 0, contpag = 0;
    if(raiz->Pai == NULL){
        nivel = 0; contpag =0;
    }
    else nivel++;
    //printf("\nraiz->TotalChaves = %d\n", raiz->TotalChaves);
    for(i = 0; i < nivel; i++) printf("\t");
    for(i = 0; i < raiz->TotalChaves; i++){
        printf("%s ", raiz->Chaves[i]);
    }
    printf("\n");
    contpag++;
    if(contpag > 23){
        system("pause"); contpag = 0;
    }
    if(!raiz->EhFolha)
        for(i = 0; i <= raiz->TotalChaves; i++){
            if(raiz->Filhos[i] != NULL) Imprime(raiz->Filhos[i]);
        }
    nivel--;
}

int Altura(BTree *raiz)
{
    if(raiz->EhFolha) return 0;
    else
    return Altura(raiz->Filhos[0]) + 1;
}

int MenorChave(BTree *raiz){
    if(raiz->EhFolha) return raiz->Chaves[0];
    else
    return MenorChave(raiz->Filhos[0]);
}

