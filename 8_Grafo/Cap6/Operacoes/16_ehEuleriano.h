#ifndef EHEULERIANO_H_INCLUDED
#define EHEULERIANO_H_INCLUDED
// Usei o algoritmo de Hierholzer
int ehEuleriano(pDGrafo grafo,FuncaoComparacao fc)
{
    pNoh Aux = grafo->listaVertices->primeiro;

    while (Aux != NULL)
    {
        pVertice vertice = (pVertice)Aux->info;

        int grauEntrada = 0, grauSaida = 0;
        pNoh adjacencia = grafo->listaVertices->primeiro;

        while (adjacencia != NULL)
        {
            pVertice Adj = (pVertice)adjacencia->info;
            if (Adj != vertice)
            {
                if (buscarNohInfo(Adj->listaAdjacencias, vertice,fc) != NULL)
                {
                    grauEntrada++;
                }
            }
            adjacencia = adjacencia->prox;
        }
        grauSaida = vertice->listaAdjacencias->quantidade;
        if (grauEntrada != grauSaida)
        {
            return 0;
        }
        Aux = Aux->prox;
    }
    return 1;
}

#endif // 16_EHEULERIANO_H_INCLUDED
