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

    int i=0, Chave;
    BTree* raiz, *Buscado;
    raiz = NovaBTree();

Animal NovoAnimal[101];

 while(!feof(ptr)){

    fscanf(ptr, "%[^,]s", &NovoAnimal[i].nome);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].cabelo);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]",&NovoAnimal[i].penas);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].ovos);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].leite);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].ave);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].aquatico);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].predador);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].dentado);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].espinha);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].respira);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].venenoso);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].barbatanas);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].pernas);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].rabo);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].domestico);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].catsize);

    fseek(ptr, 1, SEEK_CUR);
    fscanf(ptr, "%d[^,]", &NovoAnimal[i].tipo);

    fseek(ptr, 1, SEEK_CUR);

    printf("%s\t", NovoAnimal[i].nome);
     printf("%d ", NovoAnimal[i].cabelo);
      printf("%d ", NovoAnimal[i].penas);
       printf("%d ", NovoAnimal[i].ovos);
        printf("%d ", NovoAnimal[i].leite);
         printf("%d ", NovoAnimal[i].ave);
          printf("%d ", NovoAnimal[i].aquatico);
           printf("%d ", NovoAnimal[i].predador);
            printf("%d ", NovoAnimal[i].dentado);
             printf("%d ", NovoAnimal[i].espinha);
              printf("%d ", NovoAnimal[i].respira);
               printf("%d ", NovoAnimal[i].venenoso);
                printf("%d ", NovoAnimal[i].barbatanas);
                printf("%d ", NovoAnimal[i].pernas);
                printf("%d ", NovoAnimal[i].rabo);
                printf("%d ", NovoAnimal[i].domestico);
                printf("%d ", NovoAnimal[i].catsize);
                printf("%d ", NovoAnimal[i].tipo);

i++;
  }




//}

   /* for (i=0; i<feof(ptr); i++){
       fscanf(ptr, "%[^,]s", &nome);
       Animal *nome[i];
       fscanf(ptr, "%[^,]d", &nome[i]->nome);
    }*/

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
