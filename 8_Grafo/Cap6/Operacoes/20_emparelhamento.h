#ifndef EMPARELHAMENTO_H_INCLUDED
#define EMPARELHAMENTO_H_INCLUDED
// Conjunto com número maximo de vértices não adjancentes.
// emparelhamento ??
// ok, usei a heurística de busca local para encontrar o emparelhamento
// Não utilizei a função conjuntosEstaveis XD

pDLista conjuntosEstaveis(pDGrafo grafo, FuncaoAlocacao fa, FuncaoComparacao fc)
{
    if (fc == NULL || fa == NULL)
    {
        fc = grafo->fc;
        fa = grafo->fa;
    }
    pVertice verticeAtual, vAux, vDestino ;
    pNoh verticeAtualAux, vAuxAux, vDestinoAux;
    pDLista listaRetorno = criarLista();
    pDLista listaTemp = criarLista();

    verticeAtualAux = grafo->listaVertices->primeiro;
    verticeAtual = verticeAtualAux->info;

    while(verticeAtual != NULL)
    {
        vAuxAux = grafo->listaVertices->primeiro;
        vAux = vAuxAux->info;
        while(vAux != NULL)
        {
            if(contemInfo(verticeAtual->listaAdjacencias, vAux, fc))
            {
                break;
            }
            else
            {
                incluirInfo(listaTemp, vAux);
            }

            vAuxAux= vAuxAux->prox ;
            vAux = vAuxAux->info;
        }

        //cont == 1?duplicarLista(listaTemp, fa); esqueci pq fiz isso, não vou tirar vai que eu lembro /o\

        if(listaTemp->quantidade > listaRetorno->quantidade)
        {
            listaRetorno = duplicarLista(listaTemp, fa);
        }

        verticeAtualAux= verticeAtualAux->prox ;
        verticeAtual = verticeAtualAux->info ;
        destruirLista(listaTemp);
    }

    return listaRetorno;
}

int buscarPos(pDGrafo grafo, void *info, FuncaoComparacao fc)
{
    pNoh atual = grafo->listaVertices->primeiro;
    int pos = 1;
    while (atual != NULL)
    {
        if (fc(atual->info, info) == 0)
        {
            return pos;
        }
        atual = atual->prox;
        pos++;
    }
    return -1;  // vértice não encontrado
}

bool melhorarEmparelhamento(pVertice verticeOrigem, int *emparelhamento, pDGrafo grafo, FuncaoComparacao fc)
{
    if (verticeOrigem == NULL || emparelhamento == NULL || grafo == NULL) return false;

    pNoh adjacencia = verticeOrigem->listaAdjacencias->primeiro;
    while (adjacencia != NULL)
    {
        pVertice verticeDestino = adjacencia->info;
        int posDestino = buscarPos(grafo, verticeDestino->info, fc) - 1;

        if (posDestino >= 0 && (emparelhamento[posDestino] == -1 || melhorarEmparelhamento(buscarInfoPos(grafo->listaVertices, emparelhamento[posDestino] + 1), emparelhamento, grafo, fc)))
        {
            int posOrigem = buscarPos(grafo, verticeOrigem->info, fc) - 1;
            if (posOrigem >= 0)
            {
                emparelhamento[posDestino] = posOrigem;
                return true;
            }
        }
        adjacencia = adjacencia->prox;
    }
    return false;
}

void emparelhamentoBuscaLocal(pDGrafo grafo, FuncaoComparacao fc)
{
    if (grafo == NULL || grafo->listaVertices == NULL) return;

    int totalVertices = grafo->listaVertices->quantidade;
    int *emparelhamento = (int *)calloc(totalVertices, sizeof(int));
    if (emparelhamento == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        return;
    }

    bool houveMelhoria;

    for (int i = 0; i < totalVertices; i++)
    {
        emparelhamento[i] = -1;
    }

    do
    {
        houveMelhoria = false;
        for (int i = 0; i < totalVertices; i++)
        {
            pVertice verticeAtual = buscarInfoPos(grafo->listaVertices, i + 1);
            if (verticeAtual != NULL && emparelhamento[i] == -1 && melhorarEmparelhamento(verticeAtual, emparelhamento, grafo, fc))
            {
                houveMelhoria = true;
            }
        }
    }
    while (houveMelhoria);

    for (int i = 0; i < totalVertices; i++)
    {
        if (emparelhamento[i] != -1)
        {
            pVertice verticeOrigem = buscarInfoPos(grafo->listaVertices, emparelhamento[i] + 1);
            pVertice verticeDestino = buscarInfoPos(grafo->listaVertices, i + 1);
            if (verticeOrigem != NULL && verticeDestino != NULL)
            {
                printf("Emparelhamento: %d -> %d\n", verticeOrigem->info, verticeDestino->info);
            }
        }
    }

    free(emparelhamento);
}

#endif // 20_EMPARELHAMENTO_H_INCLUDED
