#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

// Versão 5.1.2 (tem uma versão 6)

/* --------------------------*/
pNohArvore obterIrmao(pNohArvore noh)
{
    if (noh->pai == NULL)
        return NULL;

    if (noh == noh->pai->esquerda)
        return noh->pai->direita;

    return noh->pai->esquerda;
}
/*---------------------------*/
// FixDoubleBlack

void fixDoubleBlack(pNohArvore *raiz, pNohArvore x)
{
    if (x == *raiz)
        return;

    pNohArvore pai = x->pai;
    pNohArvore irmao = obterIrmao(x);

    if (irmao == NULL)
    {
        // Irmão é NULL, duplo preto sobe
        fixDoubleBlack(raiz, pai);
    }
    else
    {
        if (irmao->cor == RED)
        {
            // Irmão é vermelho
            pai->cor = RED;
            irmao->cor = BLACK;
            if (irmao == pai->esquerda)
            {
                rotacaoDireitaEx(pai);
            }
            else
            {
                rotacaoEsquerdaEx(pai);
            }
            fixDoubleBlack(raiz, x);
        }
        else
        {
            // Irmão é preto
            if ((irmao->esquerda != NULL && irmao->esquerda->cor == RED) ||
                    (irmao->direita != NULL && irmao->direita->cor == RED))
            {
                // Pelo menos um filho do irmão é vermelho
                if (irmao->esquerda != NULL && irmao->esquerda->cor == RED)
                {
                    if (irmao == pai->esquerda)
                    {
                        // Left-Left
                        irmao->esquerda->cor = irmao->cor;
                        irmao->cor = pai->cor;
                        rotacaoDireitaEx(pai);
                    }
                    else
                    {
                        // Right-Left
                        irmao->esquerda->cor = pai->cor;
                        rotacaoDireitaEx(irmao);
                        rotacaoEsquerdaEx(pai);
                    }
                }
                else
                {
                    if (irmao == pai->esquerda)
                    {
                        // Left-Right
                        irmao->direita->cor = pai->cor;
                        rotacaoEsquerdaEx(irmao);
                        rotacaoDireitaEx(pai);
                    }
                    else
                    {
                        // Right-Right
                        irmao->direita->cor = irmao->cor;
                        irmao->cor = pai->cor;
                        rotacaoEsquerdaEx(pai);
                    }
                }
                pai->cor = BLACK;
            }
            else
            {
                // Ambos os filhos do irmão são pretos
                irmao->cor = RED;
                if (pai->cor == BLACK)
                {
                    fixDoubleBlack(raiz, pai);
                }
                else
                {
                    pai->cor = BLACK;
                }
            }
        }
    }
}

/*--------------------------*/
// Rotação Direita

void rotacaoDireitaEx(pNohArvore val)
{
    pNohArvore filho = val->esquerda;
    val->esquerda = filho->direita;
    if(filho->direita != NULL)
    {
        filho->direita->pai = val;
    }
    filho->pai = val->pai;
    if(filho->pai == NULL)
    {
        arvore->raiz = filho ;
    }
    else if(val == val->pai->direita)
    {
        val->pai->direita = filho ;
    }
    else
    {
        val->pai->esquerda = filho;
    }
    filho->direita = val;
    val->pai = filho;

}

// Rotação Esquerda

void rotacaoEsquerdaEx(pNohArvore val)
{
    pNohArvore filho = val->direita ;
    val->direita = filho->esquerda;
    if(filho->esquerda!= NULL)
        filho->esquerda->pai = val;

    filho->pai = val->pai;
    if(val->pai == NULL)
    {
        arvore->raiz = filho;
    }
    else if(val == val->pai->esquerda)
    {
        val->pai->esquerda = filho ;
    }
    else
    {
        val->pai->direita = filho;
    }

    filho->esquerda = val;
    val->pai = filho;

}

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if (raiz == NULL)
    {
        //printf("raiz nula\n");
        return raiz;
    }
    //printf("Passou aqui 1\n");

    int comparacao = pfc(info, raiz->info);
    if (comparacao > 0)
    {
        //printf("esquerda 1\n");
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, pfc);
    }
    else if (comparacao < 0)
    {
        //printf("direita 1\n");
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, pfc);
    }
    else
    {
        //printf("Passou aqui 2 nem esquerda nem direita\n");
        if (raiz->esquerda == NULL || raiz->direita == NULL)
        {
            // Caso 1 e 2 - Nó com nenhum ou 1 filho
            pNohArvore temp = (raiz->esquerda == NULL) ? raiz->direita : raiz->esquerda;

            if (temp == NULL)
            {
                // Sem filhos
                temp = raiz;
                raiz = NULL;
            }
            else
            {
                // Um filho
                *raiz = *temp;
            }
            free(temp);
        }
        else
        {
            // Caso 2 - Nó com 2 filhos
            pNohArvore tmp = raiz->direita;
            while (tmp->esquerda != NULL)
            {
                tmp = tmp->esquerda;
            }
            raiz->info = tmp->info;
            raiz->direita = excluirInfoRecursivo(raiz->direita, tmp->info, pfc);
        }

        if (raiz == NULL)
        {
            return raiz;
        }

        if (raiz->cor == BLACK)
        {
            if (raiz->esquerda != NULL && raiz->esquerda->cor == RED)
            {
                raiz->esquerda->cor = BLACK;
            }
            else if (raiz->direita != NULL && raiz->direita->cor == RED)
            {
                raiz->direita->cor = BLACK;
            }
            else
            {
                fixDoubleBlack(&raiz, raiz);
            }
        }
    }
    return raiz;
}

/* ---------------------------------------------------------- */
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    //printf("Passou aqui -1\n");
    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
    if (arvore->raiz != NULL)
    {
        arvore->raiz->cor = BLACK;
    }

    arvore->quantidadeNohs--;
    return 1;

}

#endif
