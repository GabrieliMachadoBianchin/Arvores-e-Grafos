#ifndef EHHAMILTONIANO_H_INCLUDED
#define EHHAMILTONIANO_H_INCLUDED
// Usei a Heurística do vizinho mais próximo
// Ela não funciona para todos os casos, mas para grafos simples ela é suficiente
// Funcionou nos dois casos que eu testei
// O primeiro grafo não é hamiltoniano (com 5 vértices)
// O segundo é (dois vértices)
/*---------------------*/
pVertice copiarVertice(pVertice original)
{
    pVertice copia = malloc(sizeof(Vertice));
    copia->info = original->info;
    copia->grau = original->grau;
    copia->listaAdjacencias = criarLista();

    pNoh nohAtual = original->listaAdjacencias->primeiro;
    while (nohAtual != NULL)
    {
        incluirInfo(copia->listaAdjacencias, nohAtual->info);
        nohAtual = nohAtual->prox;
    }

    return copia;
}
/*--------------------*/
pDGrafo copiarGrafo(pDGrafo original)
{
    pDGrafo copia = criarGrafo();

    pNoh nohAtual = original->listaVertices->primeiro;
    while (nohAtual != NULL)
    {
        pVertice verticeOriginal = (pVertice)nohAtual->info;
        pVertice verticeCopia = copiarVertice(verticeOriginal);
        incluirInfo(copia->listaVertices, verticeCopia);
        nohAtual = nohAtual->prox;
    }

    return copia;
}
/*---------------------*/
int ehHamiltoniano(pDGrafo grafo, FuncaoComparacao fc)
{
    pDGrafo copiaGrafo = copiarGrafo(grafo);
    if (!copiaGrafo)
    {
        printf("Erro ao copiar o grafo.\n");
        return false;
    }

    pNoh nohInicial = copiaGrafo->listaVertices->primeiro;
    if (!nohInicial)
    {
        destruirGrafo(copiaGrafo, fc);
        return false;
    }

    pVertice verticeAtual = nohInicial->info;
    pDLista listaVisitados = criarLista();

    incluirInfo(listaVisitados, verticeAtual);

    while (listaVisitados->quantidade < grafo->listaVertices->quantidade)
    {
        pNoh nohAdj = verticeAtual->listaAdjacencias->primeiro;
        pVertice proximo = NULL;

        while (nohAdj != NULL)
        {
            pVertice verticeAdj = (pVertice) nohAdj->info;
            bool jaVisitado = contemInfo(listaVisitados, verticeAdj, fc) != NULL;

            if (!jaVisitado && (proximo == NULL || verticeAdj->grau < proximo->grau))
            {
                proximo = verticeAdj;
            }
            nohAdj = nohAdj->prox;
        }

        if (proximo == NULL)
        {
            destruirLista(listaVisitados);
            destruirGrafo(copiaGrafo, fc);
            return false;
        }

        incluirInfo(listaVisitados, proximo);
        verticeAtual = proximo;
    }

    destruirLista(listaVisitados);
    destruirGrafo(copiaGrafo, fc);
    return true;
}

#endif // 15_EHHAMILTONIANO_H_INCLUDED
