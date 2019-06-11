#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include <string.h>
#include <locale.h>
#define MAXITENS 20

int main()
{
    setlocale(LC_ALL, "");
    printf("=============================================\n");
    printf("================ZOO DATABASE=================\n\n");

    FILE* ptr;
    if (fopen("zoo.data", "rb")==NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n\n");
        return 1;
    }

    ptr = fopen("zoo.data", "rb");

    int i=0;
    BTree*raiz, *Buscado;
    raiz = NovaBTree();

    Animal NovoAnimal[101];

    while(!feof(ptr))
    {
        fseek(ptr, 1, SEEK_CUR);
        fscanf(ptr, "%[^,]s", NovoAnimal[i].nome);

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

        raiz = InsereBTree(raiz, NovoAnimal[i]);
        i++;
    };

//printf("%s", NovoAnimal[100].nome);
    int op, p;
    char Chave[20];
    while (op!=4)
    {
        printf("\nOpcoes: \n");
        printf("1 - Listar\n");
        printf("2 - Pesquisar por animal (sequencial)\n");
        printf("3 - Pesquisar por animal (otimizado)\n");//funcionando somente para algumas chaves
        printf("4 - Sair\n");

        printf("\nOpção desejada: ");
        scanf("%d", &op);

        //system("cls");
        if (op == 1)
            ListarAnimais(NovoAnimal, i);

        if (op == 2)
        {
            char key[20];
            printf("Digite o nome do animal: ");
            scanf("%s", &key);

            p = Pesquisa(NovoAnimal, key);
            if (p!=1)
                printf("\nAnimal não encontrado!!! \n");
        }

        if (op == 3)
        {
            printf("Digite o nome do animal: ");
            scanf("%s", Chave);
            Buscado = BuscaBTree(raiz, Chave);
            printf("\n");

            if(Buscado == NULL)
            {
                printf("Chave nao encontrada!!\n");
            }
            else
            {
                printf("Chave Encontrada!!\n");
            }
        }
        if (op == 4)
            return 0;
    };

    return 0;
}
