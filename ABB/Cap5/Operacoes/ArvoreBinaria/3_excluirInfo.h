#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){
 if (raiz == NULL){
        printf("Numero nao encontrado na arvore\n");
        return raiz;
 }

    //Caso 1 e 2 - Nó com nenhum ou 1 filho
    int comparacao = pfc(info, raiz->info);
    if (comparacao > 0)
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, pfc);
    else if (comparacao < 0)
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, pfc);
    else {
        if (raiz->esquerda == NULL) {
            pNohArvore temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            pNohArvore temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        //Caso 3 - Noh com 2 filhos
        pNohArvore temp = raiz->direita ;
        while (temp && temp->esquerda != NULL){
        temp = temp->esquerda;
    }
        raiz->info = temp->info;
        raiz->direita = excluirInfoRecursivo(raiz->direita, temp->info, pfc);
    }
    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

printf("Excluindo...\n");
pNohArvore auxiliar ;

auxiliar = excluirInfoRecursivo(arvore->raiz, info, pfc);
return 0 ;

}

#endif
