#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//#include "./Lib/FilesLibrary/Persistencia.h"
#include "./Lib/ABB/Cap5/ArvoreBinaria.h"
//#include "./Lib/AVL/Cap5/ArvoreAvl.h"
//#include "./Lib/RubroNegraNovaNova/Cap5/ArvoreRubroNegra.h"
//Só dá pra testar uma árvore por vez, senão sobreescreve as funções

/*--------------------*/
int compararInt(void *a, void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    return (*x) - (*y);
}
/*-------------------*/
int main()
{
    clock_t inicio;
    clock_t fim;
    /* --- Geração de arquivos com números randomicos --
    srand(time(NULL));

    int *auxUm = malloc(1000 * sizeof(int));
    int *auxDois = malloc(10000 * sizeof(int));
    int *auxTres = malloc(100000 * sizeof(int));
    int *auxQuatro = malloc(1000000 * sizeof(int));

    if (auxQuatro == NULL )
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    preencherVetor(auxUm, 1000);
    preencherVetor(auxDois, 10000);
    preencherVetor(auxTres, 100000);
    preencherVetor(auxQuatro, 1000000);

    salvarVetorNoArquivo(auxUm, 1000, "CasoUm.txt");
    salvarVetorNoArquivo(auxDois, 10000, "CasoDois.txt");
    salvarVetorNoArquivo(auxTres, 100000, "CasoTres.txt");
    salvarVetorNoArquivo(auxQuatro, 1000000, "CasoQuatro.txt");

    free(auxUm);
    free(auxDois);
    free(auxTres);
    free(auxQuatro);
*/
    // variáveis auxiliares

    int *incluirUm = malloc(sizeof(int)) ;
    int *incluirDois = malloc(sizeof(int));
    int *incluirTres = malloc(sizeof(int));
    int *incluirQuatro = malloc(sizeof(int));

    *incluirUm = 1001;
    *incluirDois = 10001;
    *incluirTres = 100001;
    *incluirQuatro = 1000001;

    int *auxiliarUm = malloc(sizeof(int));
    int *auxiliarDois = malloc(sizeof(int));
    int *auxiliarTres = malloc(sizeof(int));
    int *auxiliarQuatro = malloc(sizeof(int));

    *auxiliarUm = 500;
    *auxiliarDois = 5001;
    *auxiliarTres = 50000;
    *auxiliarQuatro = 500000;

    // Árvore ABB
    // Criar Arvore ABB
    // Criar Arquivos Binários para testar todos os casos

        pDArvore arvore_abbUm = criarArvore(sizeof(int));
        pDArvore arvore_abbDois = criarArvore(sizeof(int));
        pDArvore arvore_abbTres = criarArvore(sizeof(int));
        pDArvore arvore_abbQuatro = criarArvore(sizeof(int));

        inserirArquivoNaArvore("CasoUm.txt", arvore_abbUm, 1000);
        inserirArquivoNaArvore("CasoDois.txt", arvore_abbDois, 10000 );
        inserirArquivoNaArvore("CasoTres.txt", arvore_abbTres, 100000);
        inserirArquivoNaArvore("CasoQuatro.txt", arvore_abbQuatro, 1000000);
        clock_t inicio = clock();
        incluirInfo(arvore_abbUm, incluirUm, compararInt);
        clock_t fim = clock();
        double tempoInsercaoUm = (double)(fim-inicio)/CLOCKS_PER_SEC ;
        printf("Passou aqui\n");
        inicio = clock();
        incluirInfo(arvore_abbDois, incluirDois, compararInt);
        fim = clock();
        double tempoInsercaoDois = (double)(fim-inicio)/CLOCKS_PER_SEC ;
        inicio = clock();
        incluirInfo(arvore_abbTres, incluirTres, compararInt);
        fim = clock();
        double tempoInsercaoTres = (double)(fim-inicio)/CLOCKS_PER_SEC ;
        inicio = clock();
        incluirInfo(arvore_abbQuatro, incluirQuatro, compararInt);
        fim = clock();
        double tempoInsercaoQuatro = (double)(fim-inicio)/CLOCKS_PER_SEC ;

        inicio = clock();
        buscarInfo(arvore_abbUm, auxiliarUm, compararInt);
        fim = clock();
        double tempoBuscaUm = (double)(fim-inicio)/CLOCKS_PER_SEC ;
        inicio = clock();
        buscarInfo(arvore_abbDois, auxiliarDois, compararInt);
        fim = clock();
        double tempoBuscaDois = (double)(fim-inicio)/CLOCKS_PER_SEC ;
        inicio = clock();
        buscarInfo(arvore_abbTres, auxiliarTres, compararInt);
        fim = clock();
        double tempoBuscaTres = (double)(fim-inicio)/CLOCKS_PER_SEC ;
        inicio = clock();
        buscarInfo(arvore_abbQuatro, auxiliarQuatro, compararInt);
        fim = clock();
        double tempoBuscaQuatro = (double)(fim-inicio)/CLOCKS_PER_SEC ;

        inicio = clock();
        excluirInfo(arvore_abbUm, auxiliarUm, compararInt);
        fim = clock();
        double tempoExclusaoUm = (double)(fim-inicio)/CLOCKS_PER_SEC ;
        inicio = clock();
        excluirInfo(arvore_abbDois, auxiliarDois, compararInt);
        fim = clock();
        double tempoExclusaoDois = (double)(fim-inicio)/CLOCKS_PER_SEC ;
        inicio = clock();
        excluirInfo(arvore_abbTres, auxiliarTres, compararInt);
        fim = clock();
        double tempoExclusaoTres = (double)(fim-inicio)/CLOCKS_PER_SEC ;
        inicio = clock();
        excluirInfo(arvore_abbQuatro, auxiliarQuatro, compararInt);
        fim = clock();
        double tempoExclusaoQuatro = (double)(fim-inicio)/CLOCKS_PER_SEC ;

    // Árvore AVL
    // Criar Arvore AVL
    // Criar Arquivos Binários para testar todos os casos
    /*
        pDArvore arvore_avlUm = criarArvore(sizeof(int));
        pDArvore arvore_avlDois = criarArvore(sizeof(int));
        pDArvore arvore_avlTres = criarArvore(sizeof(int));
        pDArvore arvore_avlQuatro = criarArvore(sizeof(int));

        inserirArquivoNaArvore("CasoUm", arvore_avlUm, 1000);
        inserirArquivoNaArvore("CasoDois", arvore_avlDois, 10000 );
        inserirArquivoNaArvore("CasoTres", arvore_avlTres, 100000);
        inserirArquivoNaArvore("CasoQuatro", arvore_avlQuatro, 1000000);

        inicio = clock();
        incluirInfo(arvore_avlUm, incluirUm, compararInt);
        fim = clock();
        double tempoInsercaoUm = (double)(fim-incio)/CLOCKS_PER_SEC ;
        inicio = clock();
        incluirInfo(arvore_avlDois, incluirDois, compararInt);
        fim = clock();
        double tempoInsercaoDois = (double)(fim-incio)/CLOCKS_PER_SEC ;
        inicio = clock();
        incluirInfo(arvore_avlTres, incluirTres, compararInt);
        fim = clock();
        double tempoInsercaoTres = (double)(fim-incio)/CLOCKS_PER_SEC ;
        inicio = clock();
        incluirInfo(arvore_avlQuatro, incluirQuatro, compararInt);
        fim = clock();
        double tempoInsercaoQuatro = (double)(fim-incio)/CLOCKS_PER_SEC ;

        inicio = clock();
        buscarInfo(arvore_avlUm, auxiliarUm, compararInt);
        fim = clock();
        double tempoBuscaUm = (double)(fim-incio)/CLOCKS_PER_SEC ;
        inicio = clock();
        buscarInfo(arvore_avlDois, auxiliarDois, compararInt);
        fim = clock();
        double tempoBuscaDois = (double)(fim-incio)/CLOCKS_PER_SEC ;
        inicio = clock();
        buscarInfo(arvore_avlTres, auxiliarTres, compararInt);
        fim = clock();
        double tempoBuscaTres = (double)(fim-incio)/CLOCKS_PER_SEC ;
        inicio = clock();
        buscarInfo(arvore_avlQuatro, auxiliarQuatro, compararInt);
        fim = clock();
        double tempoBuscaQuatro = (double)(fim-incio)/CLOCKS_PER_SEC ;

        inicio = clock();
        excluirInfo(arvore_avlUm, auxiliarUm, compararInt);
        fim = clock();
        double tempoExclusaoUm = (double)(fim-incio)/CLOCKS_PER_SEC ;
        inicio = clock();
        excluirInfo(arvore_avlDois, auxiliarDois, compararInt);
        fim = clock();
        double tempoExclusaoDois = (double)(fim-incio)/CLOCKS_PER_SEC ;
        inicio = clock();
        excluirInfo(arvore_avlTres, auxiliarTres, compararInt);
        fim = clock();
        double tempoExclusaoTres = (double)(fim-incio)/CLOCKS_PER_SEC ;
        inicio = clock();
        excluirInfo(arvore_avlQuatro, auxiliarQuatro, compararInt);
        fim = clock();
        double tempoExclusaoQuatro = (double)(fim-incio)/CLOCKS_PER_SEC ;
    */
    // Árvore Rubro Negra
    // Criar Arvore Rubro Negra
    // Criar Arquivos Binários para testar todos os casos
    /*
    pDArvore arvore_rbUm = criarArvore(sizeof(int));
    pDArvore arvore_rbDois = criarArvore(sizeof(int));
    pDArvore arvore_rbTres = criarArvore(sizeof(int));
    pDArvore arvore_rbQuatro = criarArvore(sizeof(int));

    inserirArquivoNaArvore("CasoUm", arvore_rbUm, 1000);
    inserirArquivoNaArvore("CasoDois", arvore_rbDois, 10000 );
    inserirArquivoNaArvore("CasoTres", arvore_rbTres, 100000);
    inserirArquivoNaArvore("CasoQuatro", arvore_rbQuatro, 1000000);

    inicio = clock();
    incluirInfo(arvore_rbUm, incluirUm, compararInt);
    fim = clock();
    double tempoInsercaoUm = (double)(fim-incio)/CLOCKS_PER_SEC ;
    inicio = clock();
    incluirInfo(arvore_rbDois, incluirDois, compararInt);
    fim = clock();
    double tempoInsercaoDois = (double)(fim-incio)/CLOCKS_PER_SEC ;
    inicio = clock();
    incluirInfo(arvore_rbTres, incluirTres, compararInt);
    fim = clock();
    double tempoInsercaoTres = (double)(fim-incio)/CLOCKS_PER_SEC ;
    inicio = clock();
    incluirInfo(arvore_rbQuatro, incluirQuatro, compararInt);
    fim = clock();
    double tempoInsercaoQuatro = (double)(fim-incio)/CLOCKS_PER_SEC ;

    inicio = clock();
    buscarInfo(arvore_rbUm, auxiliarUm, compararInt);
    fim = clock();
    double tempoBuscaUm = (double)(fim-incio)/CLOCKS_PER_SEC ;
    inicio = clock();
    buscarInfo(arvore_rbDois, auxiliarDois, compararInt);
    fim = clock();
    double tempoBuscaDois = (double)(fim-incio)/CLOCKS_PER_SEC ;
    inicio = clock();
    buscarInfo(arvore_rbTres, auxiliarTres, compararInt);
    fim = clock();
    double tempoBuscaTres = (double)(fim-incio)/CLOCKS_PER_SEC ;
    inicio = clock();
    buscarInfo(arvore_rbQuatro, auxiliarQuatro, compararInt);
    fim = clock();
    double tempoBuscaQuatro = (double)(fim-incio)/CLOCKS_PER_SEC ;

    inicio = clock();
    excluirInfo(arvore_rbUm, auxiliarUm, compararInt);
    fim = clock();
    double tempoExclusaoUm = (double)(fim-incio)/CLOCKS_PER_SEC ;
    inicio = clock();
    excluirInfo(arvore_rbDois, auxiliarDois, compararInt);
    fim = clock();
    double tempoExclusaoDois = (double)(fim-incio)/CLOCKS_PER_SEC ;
    inicio = clock();
    excluirInfo(arvore_rbTres, auxiliarTres, compararInt);
    fim = clock();
    double tempoExclusaoTres = (double)(fim-incio)/CLOCKS_PER_SEC ;
    inicio = clock();
    excluirInfo(arvore_rbQuatro, auxiliarQuatro, compararInt);
    fim = clock();
    double tempoExclusaoQuatro = (double)(fim-incio)/CLOCKS_PER_SEC ;
    */
    // IMPRESSÃO DOS RESULTADOS

    //printf("1-Tempo de execucao (Insercao): %.10f segundos\n", tempoInsercaoUm);
    printf("2-Tempo de execucao (Insercao): %.10f segundos\n", tempoInsercaoDois);
    //printf("3-Tempo de execucao (Insercao): %.10f segundos\n", tempoInsercaoTres);
    //printf("4-Tempo de execucao (Insercao): %.10f segundos\n", tempoInsercaoQuatro);
    //printf("1-Tempo de execucao (Busca): %.10f segundos\n", tempoBuscaUm);
    printf("2-Tempo de execucao (Busca): %.10f segundos\n", tempoBuscaDois);
    //printf("3-Tempo de execucao (Busca): %.10f segundos\n", tempoBuscaTres);
    //printf("4-Tempo de execucao (Busca): %.10f segundos\n", tempoBuscaQuatro);
    //printf("1-Tempo de execucao (Exclusao): %.10f segundos\n", tempoExclusaoUm);
    printf("2-Tempo de execucao (Exclusao): %.10f segundos\n", tempoExclusaoDois);
    //printf("3-Tempo de execucao (Exclusao): %.10f segundos\n", tempoExclusaoTres);
    //printf("4-Tempo de execucao (Exclusao): %.10f segundos\n", tempoExclusaoQuatro);

    // Liberar memória alocada das variáveis auxiliares

    free(incluirUm);
    free(incluirDois);
    free(incluirTres);
    free(incluirQuatro);
    free(auxiliarUm);
    free(auxiliarDois);
    free(auxiliarTres);
    free(auxiliarQuatro);

    return 0;
}

/*-------------------*/
// Preencher vetor
void preencherVetor(int *vetor, int tamanho)
{
    for(int i = 0 ; i < tamanho ; i++)
    {
        vetor[i] = (rand()%tamanho)+1;
    }
    printf("Vetor pronto!\n");
    return;
}

/*---------------------*/
// Salvar vetor no arquivo
void salvarVetorNoArquivo(int *vetor, int tamanho, const char *arquivoNome)
{
    FILE *pArquivo = fopen(arquivoNome, "w");
    if(pArquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    for(int i = 0 ; i < tamanho ; i++)
    {
        fprintf(pArquivo, "%d\n", vetor[i]);
    }
    fclose(pArquivo);
    printf("Arquivo salvo com sucesso!\n");
    return ;
}
/*-----------------*/
// Inserir dados do arquivo na árvore

void inserirArquivoNaArvore(const char *arquivoNome, pDArvore arvore, int tamanho)
{
    printf("Passou aqui 2\n");
    FILE* pArquivo = fopen(arquivoNome, "r");
    if (pArquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", arquivoNome);
        return ;
    }
    int value, i = 0;

    int **vetorAux = (int **)malloc(tamanho * sizeof(int *));
    if (vetorAux == NULL)
    {
        printf("Erro ao alocar memória para vetorAux.\n");
        fclose(pArquivo);
        return;
    }

    while(i+1 < tamanho && fscanf(pArquivo, "%d", &value) != EOF)
    {
        vetorAux[i] = (int *)malloc(sizeof(int));
        if (vetorAux[i] == NULL)
        {
            printf("Erro ao alocar memória para vetorAux[%d].\n", i);
            break;
        }
        *vetorAux[i] = value;
        i++;
    }

    fclose(pArquivo);

    for (int j = 0; j < i; j++)
    {
        incluirInfo(arvore, vetorAux[j], compararInt);
        free(vetorAux[j]);  // Libera a memória após a inserção na árvore
    }

    free(vetorAux);
    return;
}


