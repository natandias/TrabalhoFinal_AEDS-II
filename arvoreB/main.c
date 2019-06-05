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

void ListarAnimais(Animal *animal, int tam)
{
    int i=0;

    for (i=0; i<tam; i++)
    {
        printf("%s ", animal[i].nome);
       printf("%d ", animal[i].cabelo);
        printf("%d ", animal[i].penas);
        printf("%d ", animal[i].ovos);
        printf("%d ", animal[i].leite);
        printf("%d ", animal[i].ave);
        printf("%d ", animal[i].aquatico);
        printf("%d ", animal[i].predador);
        printf("%d ", animal[i].dentado);
        printf("%d ", animal[i].espinha);
        printf("%d ", animal[i].respira);
        printf("%d ", animal[i].venenoso);
        printf("%d ", animal[i].barbatanas);
        printf("%d ", animal[i].pernas);
        printf("%d ", animal[i].rabo);
        printf("%d ", animal[i].domestico);
        printf("%d ", animal[i].catsize);
        printf("%d ", animal[i].tipo);
    }
}



int main()
{
    printf("===================================\n");
    printf("===========ZOO DATABASE============\n\n");

    FILE* ptr;
    if (fopen("zoo.data", "rb")==NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n\n");
        return 1;
    }

    ptr = fopen("zoo.data", "rb");

    int i=0, Chave;
    BTree* raiz, *Buscado;
    raiz = NovaBTree();

    Animal NovoAnimal[101];

    while(!feof(ptr))
    {
        fscanf(ptr, "%[^,]s", &NovoAnimal[i].nome);
        //printf("%s", NovoAnimal[i].nome);


        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].cabelo);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d",&NovoAnimal[i].penas);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].ovos);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].leite);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].ave);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].aquatico);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].predador);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].dentado);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].espinha);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].respira);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].venenoso);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].barbatanas);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].pernas);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].rabo);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].domestico);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].catsize);

        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%d", &NovoAnimal[i].tipo);


        if (feof(ptr))
            break;

   InsereBTree(raiz, NovoAnimal[i], i);
    i++;
 //printf("%d ", i);
    };
Imprime(raiz);

//printf("%s", NovoAnimal[100].nome);
/*
    int opcao;
    printf("Opcoes: \n");
    printf("1 - Listar\n");

    scanf("%d", &opcao);
    if (opcao == 1) ListarAnimais(NovoAnimal, i);*/


/*
            printf("Altura = %d\n\n", Altura(raiz));
            printf("MenorChave = %s\n\n", MenorChave(raiz));*/
/*
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
