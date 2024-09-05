#ifndef EHBIPARTIDO_H_INCLUDED
#define EHBIPARTIDO_H_INCLUDED

int ehConjuntoIndependente(pDLista conjunto, pDGrafo grafo, FuncaoComparacao fc)
{
    pNoh noh = conjunto->primeiro;
    while (noh != NULL)
    {
        pVertice v1 = noh->info;
        pNoh adj = v1->listaAdjacencias->primeiro;
        while (adj != NULL)
        {
            pVertice v2 = adj->info;
            if (contemInfo(conjunto, v2, fc))
            {
                return 0; // Encontrou uma aresta dentro do conjunto
            }
            adj = adj->prox;
        }
        noh = noh->prox;
    }
    return 1; // O conjunto é independente
}

int ehBipartido(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi)
{
    if (fc == NULL)
        fc = grafo->fc;

    if (fi == NULL)
        fi = grafo->fi;


    pDLista conjunto1 = criarLista();
    pDLista conjunto2 = criarLista();

    pNoh noh = grafo->listaVertices->primeiro;
    while (noh != NULL)
    {
        pVertice v = noh->info;
        incluirInfo(conjunto1, v);
        if (!ehConjuntoIndependente(conjunto1, grafo, fc))
        {
            excluirInfo(conjunto1, v, fc);
            incluirInfo(conjunto2, v);
            if (!ehConjuntoIndependente(conjunto2, grafo, fc))
            {
                destruirLista(conjunto1);
                destruirLista(conjunto2);
                return 0;
            }
        }
        noh = noh->prox;
    }

    pNoh noh1 = conjunto1->primeiro;
    while (noh1 != NULL)
    {
        pVertice v1 = noh1->info;
        pNoh adj = v1->listaAdjacencias->primeiro;
        while (adj != NULL)
        {
            pVertice v2 = adj->info;
            if (contemInfo(conjunto1, v2, fc))
            {
                destruirLista(conjunto1);
                destruirLista(conjunto2);
                return 0;
            }
            if (contemInfo(conjunto2, v2, fc))
            {
                // Aresta entre os conjuntos
                // Isso é esperado
            }
            adj = adj->prox;
        }
        noh1 = noh1->prox;
    }

    pNoh noh2 = conjunto2->primeiro;
    while (noh2 != NULL)
    {
        pVertice v2 = noh2->info;
        pNoh adj = v2->listaAdjacencias->primeiro;
        while (adj != NULL)
        {
            pVertice v1 = adj->info;
            if (contemInfo(conjunto2, v1, fc))
            {
                destruirLista(conjunto1);
                destruirLista(conjunto2);
                return 0;
            }
            if (contemInfo(conjunto1, v1, fc))
            {
                // Aresta entre os conjuntos
                // Isso é esperado
            }
            adj = adj->prox;
        }
        noh2 = noh2->prox;
    }

    destruirLista(conjunto1);
    destruirLista(conjunto2);
    return 1;
}

#endif // 18_EHBIPARTIDO_H_INCLUDED
