#ifndef EHCONEXO_H_INCLUDED
#define EHCONEXO_H_INCLUDED

int ehConexo(pDGrafo grafo, FuncaoComparacao fc)
{
    pVertice vDestino ;

    pNoh nohAux = grafo->listaVertices->primeiro;
    pVertice vAux = nohAux->info ;
    pNoh nohAuxDois ;
    while(nohAux != NULL)
    {
        nohAuxDois = grafo->listaVertices->primeiro;
        while(nohAuxDois !=NULL)
        {
            vDestino = nohAuxDois->info ;
            if(existeCaminho(grafo, vAux->info, vDestino->info)==0)
            {
                return 0;
            }
            nohAuxDois = nohAuxDois->prox;
        }
        nohAux = nohAux->prox ;
        vAux = nohAux->info ;
    }

    return 1;
}

#endif // 17_EHCONEXO_H_INCLUDED
