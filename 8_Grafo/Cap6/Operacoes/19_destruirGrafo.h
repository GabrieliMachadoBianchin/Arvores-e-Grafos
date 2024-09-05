#ifndef DESTRUIRGRAFO_H_INCLUDED
#define DESTRUIRGRAFO_H_INCLUDED

void destruirGrafo(pDGrafo grafo, FuncaoComparacao fc)
{
    if (grafo == NULL) return;

    while (grafo->listaVertices->primeiro != NULL)
    {
        pVertice vertice = (pVertice) grafo->listaVertices->primeiro->info;
        excluirVertice(grafo, vertice->info, fc);
    }

    free(grafo);
}


#endif // 19_DESTRUIRGRAFO_H_INCLUDED
