
int* alocaInt(int n) {
   int* pi = (int*)malloc(sizeof(int));
   *pi = n;
   return pi;
}


void* AlocaCliente() {
   return malloc(sizeof(struct Cliente));
}

void* AlocaProduto() {
   return malloc(sizeof(struct Produto));
}

void* AlocaVenda() {
   return malloc(sizeof(struct Venda));
}