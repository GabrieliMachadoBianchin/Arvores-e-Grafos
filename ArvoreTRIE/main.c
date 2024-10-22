#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ArvoreTRIE.h"

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
