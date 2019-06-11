#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define ORDEM 5

struct animal
{
    char nome[20];
    int cabelo;
    int penas;
    int ovos;
    int leite;
    int ave;
    int aquatico;
    int predador;
    int dentado;
    int espinha;
    int respira;
    int venenoso;
    int barbatanas;
    int pernas;
    int rabo;
    int domestico;
    int catsize;
    int tipo;
};
typedef struct animal Animal;

typedef struct btree
{
    int TotalChaves;
    int EhFolha;
    Animal Chaves[ORDEM];
    struct btree* Filhos[ORDEM+1];
    struct btree* Pai;
} BTree;

BTree* NovaBTree();
BTree* Insere(BTree* No, Animal Chave);
BTree* BuscaBTree(BTree* No, char Chave[]);
void Imprime(BTree *raiz);

void ListarAnimais(Animal *animal, int tam);
int Pesquisa (Animal *chave,char key[]);

#endif // BTREE_H_INCLUDED
