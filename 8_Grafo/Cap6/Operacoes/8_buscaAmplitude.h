#ifndef BUSCA_AMPLITUDE_H
#define BUSCA_AMPLITUDE_H

/* --------------------------- */
void buscaAmplitude(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi){

   if (fc == NULL)
       fc = grafo->fc;

   if (fi == NULL)
       fi = grafo->fi;

   pDFila verticesPendentes;
   pDLista verticesVisitados;

   verticesPendentes = criarFila();
   verticesVisitados = criarLista();

   /* enfilera o primeiro v�rtice do grafo (ou seja, o primeiro v�rtice da lista) */
   enfileirarInfo(verticesPendentes, grafo->listaVertices->primeiro->info);

   /* processa todos os v�rtices da pilha */
   while(filaVazia(verticesPendentes)!=0)
   {
       pVertice vAtual = desenfileirarInfo(verticesPendentes);

       /* visita o vertice se ainda n�o foi visitado */
       if (contemInfo(verticesVisitados, vAtual, fc) == 0){
          fi(vAtual);
          incluirInfo(verticesVisitados, vAtual);
       }

       /* enfileira todas as adjac�ncias do v�rtice atual que n�o foram visitadas */
       pNoh atual = vAtual->listaAdjacencias->primeiro;
       while(atual != NULL){
          if (contemInfo(verticesVisitados, atual->info, fc) == 0){
             enfileirarInfo(verticesPendentes, atual->info);
          }
          atual = atual->prox;
       }
   }

}
#endif
