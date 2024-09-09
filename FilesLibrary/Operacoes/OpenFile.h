#ifndef OPEN_H
#define OPEN_H

pDFile OpenFile(char arquivo[30], int tamanho){

    pDFile pdf = (pDFile) malloc(sizeof(struct dFile));

    pdf->arquivo         = fopen(arquivo, "r+b");
    pdf->tamanhoRegistro = tamanho;

    return pdf;
}


#endif
