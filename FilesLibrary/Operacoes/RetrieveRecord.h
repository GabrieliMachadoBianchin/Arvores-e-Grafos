#ifndef RETRIEVE_H
#define RETRIEVE_H

void* RetrieveRecord(pDFile arq, void* chave, FuncaoComparacao pfc) {

    if (arq->arquivo == NULL) {
        printf("Arquivo nao foi aberto!\n");
        return NULL;
    }

    rewind(arq->arquivo);

    int result;
    void* dados = malloc(arq->tamanhoRegistro);

    do {
        result = fread(dados, arq->tamanhoRegistro, 1, arq->arquivo);
        if (pfc(dados, chave) == 0) {
            return dados;
        }
    } while (result != 0);
}

#endif
