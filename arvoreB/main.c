#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include <string.h>
#include <locale.h>
#define MAXITENS 20

void ListarAnimais(Animal *animal, int tam)
{
    int i=0;

    for (i=0; i<tam; i++)
    {
        printf("\nNome do animal: %s", animal[i].nome);
        printf("\nPossui cabelo: ");if  (animal[i].cabelo==0) printf("Não "); else printf("Sim ");
        printf("\nPossui penas: ");if  (animal[i].penas==0) printf("Não "); else printf("Sim ");
       printf("\nBota ovos: ");if  (animal[i].ovos==0) printf("Não "); else printf("Sim ");
        printf("\nProduz leite: ");if  (animal[i].leite==0) printf("Não "); else printf("Sim ");
        printf("\nÉ uma ave: ");if  (animal[i].ave==0) printf("Não "); else printf("Sim ");
        printf("\nÉ aquático: ");if  (animal[i].aquatico==0) printf("Não "); else printf("Sim ");
        printf("\nÉ predador: ");if  (animal[i].predador==0) printf("Não "); else printf("Sim ");
        printf("\nÉ dentado: ");if  (animal[i].dentado==0) printf("Não "); else printf("Sim ");
        printf("\nPossui espinha: ");if  (animal[i].espinha==0) printf("Não "); else printf("Sim ");
        printf("\nRespira: ");if  (animal[i].respira==0) printf("Não "); else printf("Sim ");
        printf("\nÉ venenoso: ");if  (animal[i].venenoso==0) printf("Não "); else printf("Sim ");
        printf("\nPossui barbatanas: ");if  (animal[i].barbatanas==0) printf("Não "); else printf("Sim ");
        printf("\nQuantas pernas possui: %d ", animal[i].pernas);
        printf("\nPossui rabo: ");if  (animal[i].rabo==0) printf("Não "); else printf("Sim ");
        printf("\nÉ doméstico: ");if  (animal[i].domestico==0) printf("Não "); else printf("Sim ");
        printf("\nÉ de tamanho comparável a um gato: ");if  (animal[i].catsize==0) printf("Não "); else printf("Sim ");
        printf("\nClasse do animal: ");
        switch (animal[i].tipo){
        case 1:
            printf("Mamífero");
            break;
        case 2:
            printf("Ave");
            break;
        case 3:
            printf("Réptil");
            break;
        case 4:
            printf("Peixe");
            break;
        case 5:
            printf("Anfíbio");
            break;
        case 6:
            printf("Inseto");
            break;
        case 7:
            printf("Artrópodes");
            break;
        }

        printf("\n");
    }
}

int Pesquisa (Animal *chave,char key[]){
    int i, achou=0;
    for  (i=0; i<101; i++){
        if (strcmp(chave[i].nome, key)==0)
        {
        achou = 1;
        printf("Animal encontrado\n");
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
            printf("Mamífero");
            break;
        case 2:
            printf("Ave");
            break;
        case 3:
            printf("Réptil");
            break;
        case 4:
            printf("Peixe");
            break;
        case 5:
            printf("Anfíbio");
            break;
        case 6:
            printf("Inseto");
            break;
        case 7:
            printf("Artrópodes");
            break;
        }

    }
  }return achou;
}

int main()
{
    setlocale(LC_ALL, "");
    printf("===================================\n");
    printf("===========ZOO DATABASE============\n\n");

    FILE* ptr;
    if (fopen("zoo.data", "rb")==NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n\n");
        return 1;
    }

    ptr = fopen("zoo.data", "rb");

    int i=0,k, pula, Chave;
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

   //InsereBTree(raiz, NovoAnimal[i]);
    i++;
    };


// Imprime(raiz);

//printf("%s", NovoAnimal[100].nome);
    int opcao, p;
do {
    printf("\n\nOpcoes: \n");
    printf("1 - Listar\n");
    printf("2 - Pesquisar por animal\n");
    printf("3 - Sair\n");

    scanf("%d", &opcao);
    if (opcao == 1)
        ListarAnimais(NovoAnimal, i);
    if (opcao == 2){
        char key[20];
        printf("Digite o nome do animal: ");
        scanf("%s", &key);

        p = Pesquisa(NovoAnimal, key);
        if (p!=1) printf("Animal não encontrado!!! \n");

    }
    if (opcao == 3)
        return 0;
}while (opcao != 3);

/*
            printf("Chave para buscar: ");
            scanf("%s ", &Chave);
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
