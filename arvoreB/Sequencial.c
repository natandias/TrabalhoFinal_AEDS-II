#ifndef SEQUENCIAL_C_INCLUDED
#define SEQUENCIAL_C_INCLUDED
#include "BTree.h"

void ListarAnimais(Animal *animal, int tam)
{
    int i=0;

    for (i=0; i<tam; i++)
    {
        printf("\nAnimal: %s", animal[i].nome);
        }
        printf("\n");
    }


int Pesquisa (Animal *chave,char key[]){
    int i, achou=0;
    for  (i=0; i<101; i++){
        if (strcmp(chave[i].nome, key)==0)
        {
        achou = 1;
        printf("\n\nAnimal encontrado");
        printf("\nNome do animal: %s", chave[i].nome);
        printf("\nPossui cabelo: ");if  (chave[i].cabelo==0) printf("Não "); else printf("Sim ");
        printf("\nPossui penas: ");if  (chave[i].penas==0) printf("Não "); else printf("Sim ");
        printf("\nBota ovos: ");if  (chave[i].ovos==0) printf("Não "); else printf("Sim ");
        printf("\nProduz leite: ");if  (chave[i].leite==0) printf("Não "); else printf("Sim ");
        printf("\nÉ uma ave: ");if  (chave[i].ave==0) printf("Não "); else printf("Sim ");
        printf("\nÉ aquático: ");if  (chave[i].aquatico==0) printf("Não "); else printf("Sim ");
        printf("\nÉ predador: ");if  (chave[i].predador==0) printf("Não "); else printf("Sim ");
        printf("\nÉ dentado: ");if  (chave[i].dentado==0) printf("Não "); else printf("Sim ");
        printf("\nPossui espinha: ");if  (chave[i].espinha==0) printf("Não "); else printf("Sim ");
        printf("\nRespira: ");if  (chave[i].respira==0) printf("Não "); else printf("Sim ");
        printf("\nÉ venenoso: ");if  (chave[i].venenoso==0) printf("Não "); else printf("Sim ");
        printf("\nPossui barbatanas: ");if  (chave[i].barbatanas==0) printf("Não "); else printf("Sim ");
        printf("\nQuantas pernas possui: %d ", chave[i].pernas);
        printf("\nPossui rabo: ");if  (chave[i].rabo==0) printf("Não "); else printf("Sim ");
        printf("\nÉ doméstico: ");if  (chave[i].domestico==0) printf("Não "); else printf("Sim ");
        printf("\nÉ de tamanho comparável a um gato: ");if  (chave[i].catsize==0) printf("Não "); else printf("Sim ");
        printf("\nClasse do animal: ");
        switch (chave[i].tipo){
        case 1:
            printf("Mamífero\n");
            break;
        case 2:
            printf("Ave\n");
            break;
        case 3:
            printf("Réptil\n");
            break;
        case 4:
            printf("Peixe\n");
            break;
        case 5:
            printf("Anfíbio\n");
            break;
        case 6:
            printf("Inseto\n");
            break;
        case 7:
            printf("Artrópodes\n");
            break;
        }
    }
  }return achou;
}

#endif // SEQUENCIAL_C_INCLUDED
