#ifndef GRAFO_TAD_H
#define GRAFO_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
typedef struct vertice  Vertice;
typedef Vertice*       pVertice;

typedef struct dGrafo  DGrafo;
typedef DGrafo*       pDGrafo;

/* tipos referentes aos ponteiros para funcao */
typedef int   (*FuncaoComparacao)(void*, void*);
typedef void  (*FuncaoImpressao) (void*);
typedef void* (*FuncaoAlocacao) (void*);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDGrafo    criarGrafo();

void       incluirVertice   (pDGrafo, void *, FuncaoComparacao);
void       incluirAresta    (pDGrafo, void*, void*, FuncaoComparacao);

void       excluirVertice   (pDGrafo, void*, FuncaoComparacao);
void       excluirAresta    (pDGrafo, void*, void*, FuncaoComparacao);

void       mostrarGrafo     (pDGrafo, FuncaoImpressao);

pVertice   buscarVertice           (pDGrafo, void *, FuncaoComparacao);
pDLista    buscarVerticesIncidentes(pDGrafo, pVertice, FuncaoComparacao);

void       buscaProfundidade(pDGrafo, FuncaoComparacao, FuncaoImpressao);
void       buscaAmplitude   (pDGrafo, FuncaoComparacao, FuncaoImpressao);

int        existeCaminho(pDGrafo, void *,  void *);
pDLista    getCaminho   (pDGrafo, void *,  void *);

int        existeCircuito(pDGrafo, void *,  void *);
pDLista    getCircuito   (pDGrafo, void *,  void *);

int        existeCaminhoHamiltoniano (pDGrafo);
int        existeCaminhoEuleriano    (pDGrafo); // pontes de Königsberg

// é o conjunto de todos os vértices que têm algum vizinho na lista de vertices
pDLista    vizinhanca(pDGrafo, pDLista);

// é o conjunto de todas as arestas que têm uma ponta em um vértice da
// lista de vertices
pDLista    corte(pDGrafo, pDLista);

int        ehSubGrafo(pDGrafo, pDGrafo, FuncaoComparacao);
int        isomorfos(pDGrafo, pDGrafo);  // complexidade de ordem fatorial

int        grafoConexo(pDGrafo, FuncaoComparacao);
int        grafoRegular(pDGrafo);

// Um conjunto de vértices de um grafo é estável, se seus elementos são dois a dois
// não-adjacentes, ou seja, se nenhuma aresta tem ambas as pontas no conjunto.
 pDLista    conjuntosEstaveis(pDGrafo, FuncaoAlocacao, FuncaoComparacao);

// Um conjunto estável X é maximal se não faz parte de um conjunto estável maior
pDLista    conjuntoEstavelMaximal(pDGrafo);
pDLista    conjuntosEstaveisMaximos(pDGrafo);

//Uma clique ou conjunto completo num grafo é qualquer conjunto de vértices dois
//a dois adjacentes
pDLista    clique(pDGrafo);

// Uma cobertura de um grafo é qualquer conjunto de vértices que contenha
// pelo menos uma das pontas de cada aresta.
pDLista    coberturas(pDGrafo);

int        coloracao(pDGrafo);

pDLista    emparelhamento(pDGrafo, pDGrafo);

pDGrafo copiarGrafo(pDGrafo);
pVertice copiarVertice(pVertice);
void destruirGrafo(pDGrafo, FuncaoComparacao);

#endif

