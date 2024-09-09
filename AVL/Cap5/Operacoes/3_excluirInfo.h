#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H
#include <stdlib.h>

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if (raiz == NULL)
    {
        printf("raiz nula\n");
        return raiz;
    }
    printf("Passou aqui 1\n");
    //Caso 1 e 2 - N� com nenhum ou 1 filho
    int comparacao = pfc(info, raiz->info);
    if (comparacao > 0)
    {
        printf("esquerda 1\n");
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, pfc);
    }
    else if (comparacao < 0)
    {
        printf("direita 1\n");
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, pfc);
    }
    else
    {
        printf("Passou aqui 2 nem esquerda nem direita\n");
        if (raiz->esquerda == NULL)
        {
            pNohArvore temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL)
        {
            pNohArvore temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        printf("Passou aqui 3 - com 2 filhos\n");
        //Caso 3 - Noh com 2 filhos
        pNohArvore temp = raiz->direita ;
        while (temp && temp->esquerda != NULL)
        {
            temp = temp->esquerda;
        }
        raiz->info = temp->info;
        raiz->direita = excluirInfoRecursivo(raiz->direita, temp->info, pfc);
    }

    //At� aqui � a mesma l�gica da ABB
    //Agora � s� balancear, se necess�rio
    //c�digo de balanceamento da fun��o de inclus�o
    printf("Passou aqui 4 - agr vai balancear\n");
    /*
         if (raiz == NULL) {
            return raiz;
        }
    */
    raiz->fb = alturaRecursiva(raiz->direita) -
               alturaRecursiva(raiz->esquerda);

    if (raiz->fb == 2 || raiz->fb == -2)
    {
        // precisa balancear, ent�o verifica qual rota��o aplicar

        if (raiz->fb == 2)
        {
            // sinais iguais -> rota��o simples
            if ((raiz->direita  != NULL && (raiz->direita->fb  == 1 || raiz->direita->fb  == 0)) ||
                    (raiz->esquerda !=NULL  && (raiz->esquerda->fb == 1 || raiz->esquerda->fb == 0)))
            {
                printf("rotacao simples esquerda\n");
                // rotacao simples esquerda
                pNohArvore novaRaiz = rotacaoEsquerda(raiz);
                recalcularFB_Recursivo(novaRaiz);
                return novaRaiz;
            }

            // sinais diferentes -> rotacao dupla direita-esquerda
            if ((raiz->direita != NULL && raiz->direita->fb  == -1) ||
                    (raiz->esquerda != NULL && raiz->esquerda->fb == -1))
            {
                printf("rotacao dupla direita-esquerda\n");
                // rotacao dupla direita-esquerda
                pNohArvore novaRaiz = rotacaoDireitaEsquerda(raiz);
                recalcularFB_Recursivo(novaRaiz);
                return novaRaiz;
            }
        }


        if (raiz->fb == -2)
        {
            // sinais iguais -> rota��o simples
            if ((raiz->direita != NULL && (raiz->direita->fb  == -1 || raiz->direita->fb  == 0)) ||
                    (raiz->esquerda !=NULL && (raiz->esquerda->fb == -1 || raiz->esquerda->fb == 0)))
            {
                printf(" -> Rotacao simples Direita <- ");
                printf("rotacao simples direita\n");
                // rotacao simples direita
                pNohArvore novaRaiz = rotacaoDireita(raiz);
                recalcularFB_Recursivo(novaRaiz);
                return novaRaiz;
            }

            // sinais diferentes -> rotacao dupla
            if ((raiz->direita != NULL && raiz->direita->fb  == 1) ||
                    (raiz->esquerda != NULL && raiz->esquerda->fb == 1))
            {
                printf("rotacao dupla esquerda-direita\n");
                // rotacao dupla esquerda-direita
                pNohArvore novaRaiz = rotacaoEsquerdaDireita(raiz);
                recalcularFB_Recursivo(novaRaiz);
                return novaRaiz;
            }

        }
    }

    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{

    printf("Excluindo...\n");
    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
//desenhaArvore(arvore,imprimeInt);

    return 0;


}



#endif
