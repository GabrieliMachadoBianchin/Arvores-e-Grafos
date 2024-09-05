#ifndef EXCLUIR_VERTICE_H
#define EXCLUIR_VERTICE_H

/* --------------------------- */
void excluirVertice(pDGrafo grafo, void* info, FuncaoComparacao fc)
{

    if (fc == NULL)
        fc = grafo->fc;

    pVertice vTemp = buscarVertice(grafo, info, fc);
    if(vTemp == NULL)
    {
        printf("Vertice nao existe\n");
        return;
    }
    else
    {
        pNoh NohAux = grafo->listaVertices->primeiro;
        while( NohAux != NULL){
              pVertice aux = NohAux->info;
              excluirInfo(aux->listaAdjacencias, vTemp, fc)?aux->grau -=1    : printf("Nao tem adjacencia\n");
              NohAux = NohAux->prox ;
        }

    }
    excluirInfo(grafo->listaVertices, vTemp, fc);
    destruirLista(vTemp->listaAdjacencias);
    free(vTemp);
    return;
}

#endif
