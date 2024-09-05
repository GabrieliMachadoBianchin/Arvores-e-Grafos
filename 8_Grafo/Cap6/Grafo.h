#ifndef GRAFO_IMPL_H
#define GRAFO_IMPL_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/* observe que o grafo utiliza as bibliotecas Lista.h e Pilha.h*/
#include "../Cap3/Lista.h"
#include "../Cap4/Pilha.h"
#include "../Cap4/Fila.h"

/* implementacao de grafo */
#include "TAD_Grafo.h"

#include "Operacoes/0_structs.h"

#include "Operacoes/1_criarGrafo.h"
#include "Operacoes/1_1_criarGrafoPlus.h"

#include "Operacoes/2_incluirVertice.h"

#include "Operacoes/3_incluirAresta.h"

#include "Operacoes/4_mostrarGrafo.h"

#include "Operacoes/5_excluirVertice.h"
#include "Operacoes/6_excluirAresta.h"

#include "Operacoes/7_buscaProfundidade.h"
#include "Operacoes/8_buscaAmplitude.h"

#include "Operacoes/9_existeCaminho.h"
#include "Operacoes/10_getCaminho.h"
#include "Operacoes/11_buscarVerticesIncidentes.h"

#include "Operacoes/14_buscarVertice.h"

#include "Operacoes/15_ehHamiltoniano.h"
#include "Operacoes/16_ehEuleriano.h"
// #include "Operacoes/20_subGrafo.h"

#include "Operacoes/17_ehConexo.h"
#include "Operacoes/18_ehBipartido.h"

#include "Operacoes/19_destruirGrafo.h"
#include "Operacoes/20_emparelhamento.h"
#include "Operacoes/21_coloracaoGulosa.h"

#endif