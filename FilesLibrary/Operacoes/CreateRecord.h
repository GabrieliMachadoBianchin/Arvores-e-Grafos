#ifndef CREATE_H
#define CREATE_H

void CreateRecord (pDFile arq, void* dados){

    if (arq->arquivo == NULL){
        printf("Arquivo nao foi aberto!");
        return;
    }

    // posiciona o ponteiro do arquivo no final do arquivo
    printf("\nPosicionando....\n");
    fseek (arq->arquivo, 0, SEEK_END);
    printf("\nGravando....\n");
    int result = fwrite(dados, arq->tamanhoRegistro, 1, arq->arquivo);
    if(result == 1){
    printf("\nGravado com sucesso \n");
    }else{
        printf("\nFalha na gravacao de arquivo\n");
    }
}


#endif
