#ifndef DELETE_H
#define DELETE_H

void DeleteRecord(pDFile arq, void* chave, FuncaoComparacao pfc) {

    if (arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    rewind(arq->arquivo);
    void* registroAtual = malloc(arq->tamanhoRegistro);
    if (registroAtual == NULL) {
        perror("Erro ao alocar memória");
        CloseFile(arq);
        return;
    }

    while (fread(registroAtual, arq->tamanhoRegistro, 1, arq->arquivo) == 1) {
        if (pfc(registroAtual, chave) == 0) {
            fseek(arq->arquivo, -arq->tamanhoRegistro, SEEK_CUR);
            memset(registroAtual, 0, arq->tamanhoRegistro);
            fwrite(registroAtual, arq->tamanhoRegistro, 1, arq->arquivo);
            printf("Registro deletado\n");
            break;
        }
    }
    free(registroAtual);
    CloseFile(arq);
}

#endif
