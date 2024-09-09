#include <stdio.h>
#include <strings.h>
#include "Persistencia.h"
#include "../ListsLibrary/Lista.h"
#include "Utils.h"

void imprimePessoa(void* info) {
  struct Cliente* c = (struct Cliente*)info;
  printf("\n- CPF: %d \n- Nome: %s \n- Limite de Credito: %f\n", c->CPF, c->Nome, c->LimiteCredito);
}

int comparaPessoaChave(void* info, void* chave) {
  struct Cliente* p = (struct Cliente*)info;
  int* key = (int*)chave;
  return *key - p->CPF;
}

int main() {
  pDFile ArqCliente;

  ArqCliente = OpenFile("Pessoas.dat", sizeof(struct Cliente));

  // int op = 1;
  // while (op != 0) {
  //  printf("Digite o cpf: \n ");
  //   scanf("%d", &cliente.CPF);
  //   fflush(stdin);
  //  printf("Digite o nome: \n ");

  //   fgets(cliente.Nome, 30, stdin);
  //   fflush(stdin);
  //  printf("Digite o limite de credito: \n ");

  //   scanf("%f", &cliente.LimiteCredito);
  //   fflush(stdin);

  //   CreateRecord(ArqCliente, &cliente);
  //   //update(ArqCliente, alocaInt(456), &p, comparaPessoaChave, alocaPessoa);

  //   printf("Quer cadastrar outra pessoa?88 (0 - Nao, 1 - Sim) = ");
  //   scanf("%d", &op);
  //   fflush(stdin);
  // }

  pDLista listaPessoas = QueryAll(ArqCliente, AlocaCliente);

  int i;
  for (i = 1; i <= listaPessoas->quantidade; i++) {
    struct Cliente* pp = (struct Cliente*)SearchInfoPos(listaPessoas, i);
    imprimePessoa(pp);
  }

  int a;
  printf("\nPesquisa de CPF!\n");
  scanf("%d", &a);

  DeleteRecord(ArqCliente, &a, comparaPessoaChave);


  CloseFile(ArqCliente);
  return 0;
}
