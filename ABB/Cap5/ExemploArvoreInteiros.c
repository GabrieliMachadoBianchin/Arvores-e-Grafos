#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "ArvoreBinaria.h"

int main(){
    pDArvore pArvoreInt = criarArvore(2);

    /* teste de inclusao */
    incluirInfo(pArvoreInt, alocaInt(5), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(8), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(6), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(3), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(7), comparaInt);

    desenhaArvore(pArvoreInt, imprimeInt);

    printf("\n Altura: %d \n",      altura(pArvoreInt));
    printf("Qtde Folhas: %d \n", quantidadeFolhas(pArvoreInt));
    printf("Qtde Nohs: %d \n",   quantidadeNohs(pArvoreInt));
    //Busca
    /*
    printf("Digite um numero para busca: \n");
    void *info;
    info = malloc(sizeof(int));
    scanf("%d", info);
    pNohArvore retorno;
    retorno = buscarInfo(pArvoreInt, info, comparaInt);

    if(retorno != NULL || retorno == (int*)info)
      printf("Numero encontrado na arvore\n");
      else
            printf("Numero nao encontrado\n");

            free(info);
            */


    //Exclusão
    printf("Digite um numero para exclusao: \n");
    void *info;
    info = malloc(sizeof(int));
    scanf("%d", info);
    int aux;
     aux = excluirInfo(pArvoreInt, info, comparaInt);




            desenhaArvore(pArvoreInt, imprimeInt);

            free(info);

}
