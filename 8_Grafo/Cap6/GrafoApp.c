#include <stdio.h>
#include <stdlib.h>

#include "Grafo.h"
#include "../Cap3/Utils.h"

int comparaVertice(void *info1, void *info2)
{

    pVertice v1 = (pVertice) info1;
    pVertice v2 = (pVertice) info2;

    int *id1 = (int *) v1->info;
    int *id2 = (int *) v2->info;

    return *id2 - *id1;
}

/* ----------------------------- */
void imprimeAdjacencia(void *info1)
{
    pVertice v = (pVertice) info1;
    printf("%d - ", *((int *)(v->info)));
}

/* ----------------------------- */
void imprimeVertice(void *info1)
{
    pVertice v = (pVertice) info1;
    printf("\nVertice %d - Adjacencias [", *((int *)v->info));

    imprimirLista(v->listaAdjacencias, imprimeAdjacencia);
    printf("]\n");
}

/* ----------------------------- */
void imprimeVerticeSemAdjacencias(void *info1)
{
    pVertice v = (pVertice) info1;
    printf("\nVertice %d - ", *((int *)v->info));
}

/* ---------------------------------------- */
void* alocaInfoVertice(void *info)
{
    pVertice pv = (pVertice) malloc(sizeof(Vertice));
    pv->info = alocaInfoInt(((pVertice)info)->info);
    return pv;
}

/* ----------------------------- */
void main()
{

    int vertices[] = {1,2,3,4,5};

    int opcao, vOrigem, vDestino;
    int *pv;

    pDGrafo grafo = criarGrafoPlus(comparaVertice, imprimeVertice, alocaInfoVertice);

    do
    {
        printf("\n0  - Criar grafo \n");
        printf("  1  - Incluir Vertice \n");
        printf("  2  - Incluir Aresta \n");
        printf("  3  - Excluir Vertice \n");
        printf("  4  - Excluir Aresta \n");
        printf("  5  - Mostrar grafo \n");
        printf("  6  - Busca em profundidade \n");
        printf("  7  - Busca em amplitude \n");
        printf("  8  - Existe caminho (entre dois vertices) \n");
        printf("  9  - Encontra caminho (entre dois vertices) \n");
        printf("  10  - Verifica se o grafo eh euleriano \n");
        printf("  11  - Verifica se o grafo eh hamiltoniano \n");
        printf("  12  - Verifica se o grafo eh conexo \n");
        printf("  13  - Verifica se o grafo eh bipartido \n");
        printf("  14  - Emparelhamento (conjunto estavel)\n");
        printf("  15  - Coloracao\n");
        printf("16 - Sair \n");

        scanf ("%d", &opcao);

        switch (opcao)
        {

        case 0 :
            /*
                        incluirVertice(grafo, &vertices[0], NULL);
                        incluirVertice(grafo, &vertices[1], NULL);
                        incluirVertice(grafo, &vertices[2], NULL);
                        incluirVertice(grafo, &vertices[3], NULL);
                        incluirVertice(grafo, &vertices[4], NULL);

                        incluirAresta(grafo, &vertices[0], &vertices[1], NULL);
                        incluirAresta(grafo, &vertices[1], &vertices[3], NULL);
                        incluirAresta(grafo, &vertices[2], &vertices[3], NULL);
                        incluirAresta(grafo, &vertices[2], &vertices[4], NULL);
                        incluirAresta(grafo, &vertices[3], &vertices[4], NULL);
                        incluirAresta(grafo, &vertices[4], &vertices[1], NULL);
            */
            //incluirAresta(grafo, &vertices[0], &vertices[2], NULL);

            /*
                        incluirVertice(grafo, &vertices[0], NULL);
                        incluirVertice(grafo, &vertices[1], NULL);

                        incluirAresta(grafo, &vertices[0], &vertices[1], NULL);
                        incluirAresta(grafo, &vertices[1], &vertices[0], NULL);
            */
            incluirVertice(grafo, &vertices[0], NULL);
            incluirVertice(grafo, &vertices[1], NULL);
            incluirVertice(grafo, &vertices[2], NULL);


            incluirAresta(grafo, &vertices[0], &vertices[1], NULL);
            incluirAresta(grafo, &vertices[1], &vertices[2], NULL);
            incluirAresta(grafo, &vertices[2], &vertices[1], NULL);

            mostrarGrafo(grafo, NULL);
            getch();
            break;

        case 1 :

            pv = (int *)malloc(sizeof(int));
            printf ("ID do vértice : ");
            scanf("%d", pv);
            incluirVertice(grafo, pv, NULL);

            mostrarGrafo(grafo, NULL);
            getch();
            break;

        case 2 :

            printf ("\nID do vértice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do vértice destino : ");
            scanf("%d", &vDestino);
            incluirAresta(grafo, &vOrigem, &vDestino, NULL);

            mostrarGrafo(grafo,imprimeVertice);
            getch();
            break;
        case 3 :
            printf ("\nID do vértice para exclusao : ");
            scanf("%d", &vOrigem);

            excluirVertice(grafo, &vOrigem, NULL);

            mostrarGrafo(grafo, imprimeVertice);
            getch();
            break;

        case 4 :
            printf ("\nID do vértice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do vértice destino : ");
            scanf("%d", &vDestino);
            excluirAresta(grafo, &vOrigem, &vDestino, NULL);

            mostrarGrafo(grafo, imprimeVertice);
            getch();
            break;

        case 5 :
            mostrarGrafo(grafo, imprimeVertice);
            getch();
            break;

        case 6 :
            buscaEmProfundidade(grafo, NULL, imprimeVerticeSemAdjacencias);
            getch();
            break;

        case 7 :
            buscaAmplitude(grafo, NULL, imprimeVerticeSemAdjacencias);
            getch();
            break;

        case 8 :
            printf ("\nID do vértice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do vértice destino : ");
            scanf("%d", &vDestino);

            int result = existeCaminho(grafo, &vOrigem, &vDestino);
            // existe um caminho
            if (result != 0)
                printf("Existe caminho!");
            else
                printf("Não existe caminho!");

            getch();
            break;
        case 9 :
            printf ("\nID do vértice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do vértice destino : ");
            scanf("%d", &vDestino);

            pDLista caminho = getCaminho(grafo, &vOrigem, &vDestino);
            if (caminho->quantidade > 0)
            {
                printf("\n Existe um caminho: ");
                imprimirLista(caminho, imprimeVerticeSemAdjacencias);
            }
            else
                printf("\n *** NÃO existe um caminho. *** ");

            getch();
            break;

        case 10 :
            if(ehEuleriano(grafo, comparaVertice))
            {
                printf("Eh euleriano\n");
            }
            else
            {
                printf("Nao eh euleriano\n");
            }
            getch();
            break;
        case 11 :
            if(ehHamiltoniano(grafo, comparaVertice))
            {
                printf("Eh hamiltoniano\n");
            }
            else
            {
                printf("Nao eh hamiltoniano\n");
            }
            getch();
            break;
        case 12 :
            if(ehConexo(grafo, comparaVertice))
            {
                printf("Eh conexo\n");
            }
            else
            {
                printf("Nao eh conexo\n");
            }
            getch();
            break;
        case 13 :
            if(ehBipartido(grafo, NULL, imprimeVerticeSemAdjacencias)== 1)
            {
                printf("Eh bipartido\n");
            }
            else
            {
                printf("Nao eh bipartido\n");
            }
            getch();
            break;
        case 14 :
            emparelhamentoBuscaLocal(grafo, comparaVertice);
            getch();
            break;
        case 15 :
            coloracaoGulosa(grafo, 2);
            getch();
            break;
        }
    }
    while (opcao != 16);
    return ;
}


