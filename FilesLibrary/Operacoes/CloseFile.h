#ifndef CLOSE_H
#define CLOSE_H

void CloseFile(pDFile arq){

    fclose(arq->arquivo);

}

#endif
