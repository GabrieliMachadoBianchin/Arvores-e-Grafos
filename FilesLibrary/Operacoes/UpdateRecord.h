#ifndef UPDATE_H
#define UPDATE_H

void UpdateRecord(pDFile arq, void* chave, void* dados, FuncaoComparacao pfc, FuncaoAloca pfa) {
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    void* registroEncontrado = RetrieveRecord(arq, chave, pfc);

    if (registroEncontrado != NULL) {
        memcpy(registroEncontrado, dados, arq->tamanhoRegistro);
        fseek(arq->arquivo, -arq->tamanhoRegistro, SEEK_CUR);

        if (fwrite(registroEncontrado, arq->tamanhoRegistro, 1, arq->arquivo) != 1) {
            perror("Erro ao escrever no arquivo");
        }

        fflush(arq->arquivo);
        free(registroEncontrado);
    }
    else {
        printf("Registro nao encontrado para atualizacao.\n");
    }
}

#endif
