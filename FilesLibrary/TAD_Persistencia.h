/* --------------------------
   Tipos de dados
   -------------------------- */
typedef struct dFile DFile;
typedef DFile*       pDFile;

typedef int   (*FuncaoComparacao)(void *, void *);
typedef void* (*FuncaoAloca)     ();
typedef void  (*FuncaoImpressao) (void *);
typedef int   (*FuncaoPredicado) (void *);

/* --------------------------
   Operações CRUD
   -------------------------- */
pDFile   OpenFile      (char[30], int);
void     CreateRecord   (pDFile, void*);                          // dados
void*    RetrieveRecord  (pDFile, void*, FuncaoComparacao);        // chave
void     UpdateRecord    (pDFile, void*, void*, FuncaoComparacao, FuncaoAloca); // chave e os dados
void     DeleteRecord    (pDFile, void*, FuncaoComparacao);        // chave
void     CloseFile     (pDFile);

pDLista  QueryAll  (pDFile, FuncaoAloca);
pDLista  QueryBy   (pDFile, FuncaoPredicado);
void     PersistRecordList (pDFile, pDLista);




