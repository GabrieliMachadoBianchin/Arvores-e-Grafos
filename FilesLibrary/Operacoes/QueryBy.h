#ifndef QUERY_H
#define QUERY_H

pDLista QueryBy(pDFile arq, FuncaoPredicado pred) {

    if (arq->arquivo == NULL) {
        printf("Arquivo nao foi aberto!");
        return NULL;
    }
    rewind(arq->arquivo);

    pDLista lista = CreateList();

    void* dados = malloc(arq->tamanhoRegistro);

    if (dados == NULL) {
        printf("Erro ao alocar memoria!");
        DestructList(lista);
        return NULL;
    }
    while (fread(dados, arq->tamanhoRegistro, 1, arq->arquivo) == 1) {
        if (pred(dados)) {
            IncludeInfo(lista, dados);
        }
    }

    free(dados);

    return lista;
}

#endif
