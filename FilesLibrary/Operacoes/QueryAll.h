#ifndef QUERYALL_H
#define QUERYALL_H

pDLista QueryAll(pDFile arq, FuncaoAloca pfa) {

   if (arq->arquivo == NULL) {
      printf("Arquivo nao foi aberto!");
      return NULL;
   }

   pDLista lista = CreateList();

   rewind(arq->arquivo);
   int result;

   do {
      void* dados = pfa();
      result = fread(dados, arq->tamanhoRegistro, 1, arq->arquivo);
      if (result == 0)
         continue;
      IncludeInfo(lista, dados);
   } while (result != 0);

   return lista;
}

#endif
