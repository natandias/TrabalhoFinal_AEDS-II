#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define ORDEM 5

typedef struct btree{
    int TotalChaves;
    int EhFolha;
    int Chaves[ORDEM];
    struct btree* Filhos[ORDEM+1];
    struct btree* Pai;
} BTree;

BTree* NovaBTree();
BTree* Insere(BTree* No, int Chave);
BTree* BuscaBTree(BTree* No, int Chave);
void Imprime(BTree *raiz);
int Altura(BTree *raiz);
int MenorChave(BTree *raiz);
#endif // BTREE_H_INCLUDED
