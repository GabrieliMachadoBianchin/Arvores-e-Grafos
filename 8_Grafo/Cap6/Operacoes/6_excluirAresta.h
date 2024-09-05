#ifndef EXCLUIR_ARESTA_H
#define EXCLUIR_ARESTA_H

/* --------------------------- */
void excluirAresta(pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc)
{

    if (fc == NULL)
        fc = grafo->fc;

    pVertice OrigTemp = buscarVertice(grafo, vOrig, fc);
    pVertice DestTemp = buscarVertice(grafo, vDest, fc);
    if(OrigTemp == NULL || DestTemp == NULL)
    {
        printf("OrigTemp ou DestTemp Nulo\n");
    }
    else
    {
        excluirInfo(OrigTemp->listaAdjacencias, DestTemp, fc);
        OrigTemp->grau -=1;
    }
    return;

}

#endif
