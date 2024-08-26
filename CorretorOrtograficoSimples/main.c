#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ArvoreTRIE.h"

// Fiz em dupla com o Murilo Pistore de Ramos (Buda)
int main()
{
    Noh *raiz = NULL;

    carregarDicionario(&raiz, "dicionario.txt");

    char palavra[256];

    printf("Digite uma palavra para verificar: "); // depois vou mudar para uma frase ..... Deixa quieto
    scanf("%s", palavra);

    if (incluirInfoTRIE(&raiz, palavra) != true)
    {
        printf("Palavra já está correta.\n");
    }
    else
    {
        corrigirPalavra(raiz, palavra);
    }

    return 0;
}
/*
int main()
{
    Noh *raiz = NULL;

    incluirInfoTRIE(&raiz, "GABI");
    incluirInfoTRIE(&raiz, "GABO");
    incluirInfoTRIE(&raiz, "GALA");
    incluirInfoTRIE(&raiz, "FABI");
    imprimirArvoreTRIE(raiz);
 printf("Buscar por Gabi: %s\n",
         buscarInfoTRIE(raiz, "GABI") ? "Achou" : "Nao encontrada");
  printf("Buscar por Gabo: %s\n",
         buscarInfoTRIE(raiz, "GABO") ? "Achou" : "Nao encontrada");
  printf("Buscar por Gabu: %s\n",
         buscarInfoTRIE(raiz, "GABU") ? "Achou" : "Nao encontrada");


    excluirInfoTRIE(&raiz, "GALA");
    imprimirArvoreTRIE(raiz);
}
*/
