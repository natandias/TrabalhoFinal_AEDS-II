#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include <string.h>
#define MAXITENS 20

/*  1. animal name:      Unique for each instance
   2. cabelo		Boolean
   3. penas		Boolean
   4. ovos		Boolean
   5. leite		Boolean
   6. ave		Boolean
   7. aquatico		Boolean
   8. predador		Boolean
   9. dentado		Boolean
  10. espinha		Boolean
  11. respira		Boolean
  12. venenoso		Boolean
  13. barbatanas		Boolean
  14. pernas		Numeric (set of values: {0,2,4,5,6,8})
  15. rabo		Boolean
  16. domestico		Boolean
  17. catsize		Boolean
  18. type		Numeric (integer values in range [1,7])
  */

  struct animal {
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

    Animal *NovoAnimal(){
       return NULL;
    }

int main()
{
    printf("===================================\n");
    printf("===========ZOO DATABASE============\n");

    FILE* ptr;
   if (fopen("zoo.data", "r")==NULL) {
        printf("Nao foi possivel abrir o arquivo\n\n");
        return 1;
   }

   ptr = fopen("zoo.data", "r");

    int i, Chave;
    BTree* raiz, *Buscado;
    raiz = NovaBTree();


    char nome[30]; char pesq[30];


    while(!feof(ptr)){
       fscanf(ptr, "%[^,]s", &nome);
       nome[i] = NovoAnimal();

    }






    /*for(i = 0; i < MAXITENS; i++)
    {
        Chave = (rand() % (MAXITENS * 5));
        if(BuscaBTree(raiz, Chave) == NULL)
            raiz = InsereBTree(raiz, Chave);
    }*/
/*

   raiz = InsereBTree(raiz, 10);



    Imprime(raiz);

    printf("Altura = %d\n\n", Altura(raiz));
    printf("MenorChave = %d\n\n", MenorChave(raiz));

    printf("Chave para buscar: ");
    scanf("%d", &Chave);
    Buscado = BuscaBTree(raiz, Chave);
    printf("\n");

    if(Buscado == NULL)
    {
        printf("Chave nao encontrada!!\n");
    }
    else
    {
        printf("Chave Encontrada!!\n");
        printf("Em %d\n", Buscado->Chaves[0]);
    }
*/
    return 0;
   }
