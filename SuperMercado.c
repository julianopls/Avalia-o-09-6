#include <stdio.h>


typedef struct{
    char nome[50];
    float preco;
    int quantidade;
}Produto;

Produto produto;

void cadastrarProduto();
void visualizarProduto();
void realizarCompra();

int main() {
    int opcao;

    do {
    printf("\033[1;35m");
    printf("\n------Menu Super Guarani------\n");
    printf("\033[0m");
    printf("[1]. Cadastrar produto\n");
    printf("[2]. Visualizar produto\n");
    printf("[3]. Realizar compra\n");
    printf("[0]. Sair\n");
    printf("Escolha uma opcao:\n");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
    cadastrarProduto();
    break;
    
    case 2:
    visualizarProduto();
    break;
    
    case 3:
    realizarCompra();
    break;
    
    case 0:
    printf("\nTchau, Tchau baby...\n");
    break;
    
    default:
    printf("Opcao invalida!\n");
    }
    } while (opcao != 0);

    return 0;
}


void cadastrarProduto() {
	printf("\033[1;35m");
    printf("\n------Super Guarani------\n");
    printf("\033[0m");
    printf("Digite o nome do produto:\n");
    scanf("%s", produto.nome);
    printf("Digite o preco do produto $:\n");
    scanf("%f", &produto.preco);
    printf("Digite a quantidade em estoque:\n");
    scanf("%d", &produto.quantidade);
}

void visualizarProduto() {
	printf("\033[1;35m");
    printf("\n------Informacao dos produtos------\n");
    printf("\033[0m");
    printf("Nome: %s\n", produto.nome);
    printf("Preco: R$ %.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
}

void realizarCompra() {
    int qtd;
    
    printf("Digite a quantidade a ser comprada:\n");
    scanf("%d", &qtd);

    if (qtd > 0 && qtd <= produto.quantidade) {
    produto.quantidade -= qtd;
    printf("Compra realizada com sucesso!\n");
    } else {
    printf("Quantidade invalidae ou estoque insuficiente.\n");
    }
}
