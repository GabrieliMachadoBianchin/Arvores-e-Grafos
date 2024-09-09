#ifndef STRUCT_FILE_H
#define STRUCT_FILE_H

/* --------------------------
   Tipos de dados
   -------------------------- */
struct dFile{
  FILE* arquivo;         // nome do arquivo em disco
  int   tamanhoRegistro; // qtde bytes do tipo de dado (struct)
};

#endif
