#include <stdio.h>


typedef struct {
    char banda[10];
    int ano, qtds;
    char genero[10];
    float preco;
} CD;

int cpcdEstoque = 10;
CD estoque[10];
int totalCDs = 0;

void cadastrarCD();
void venderCD();
void pesquisarPorGenero(); 
void consultarCD();

int main() {
    int opcao;
    do {
    printf("\033[1;35m");
    printf("--------BANDA DE CDs-------\n");
    printf("\033[0m");
    printf("[1] Cadastrar CD\n");
    printf("[2] Vender CD\n");
    printf("[3] Pesquisar CDs por genero\n");
    printf("[4] Consultar CD\n");
    printf("[0] Sair\n");
    printf("Escolha uma opcao:\n");
    scanf("%d", &opcao);
    
	switch (opcao) {
    case 1: 
	cadastrarCD(); 
	break;
	
    case 2: 
	venderCD(); 
	break;
	
	case 3: 
	pesquisarPorGenero(); 
	break;
	
    case 4: 
	consultarCD(); 
	break;
	
    case 0: 
	printf("Tchau, Tchau baby...\n"); 
	break;
	
    default: 
	printf("Opcao invalida!\n");
    }
    } while (opcao != 0);

    return 0;
}

void cadastrarCD() {
    if (totalCDs >= cpcdEstoque) {
    printf("Estoque cheio!\n");
    return;
    }
    printf("\033[1;33m");
    printf("----------CADASTAR CD----------\n");
    printf("\033[0m");
    printf("Nome da banda:\n");
    scanf(" %[^\n]", estoque[totalCDs].banda);
    printf("Ano:\n");
    scanf("%d", &estoque[totalCDs].ano);
    printf("Genero:\n");
    scanf(" %[^\n]", estoque[totalCDs].genero);
    printf("Quantidade em estoque:\n");
    scanf("%d", &estoque[totalCDs].qtds);
    printf("Preco do CD:\n");
    scanf("%f", &estoque[totalCDs].preco);

    totalCDs++;
    
    printf("\033[1;33m");
    printf("CD cadastrado com sucesso!\n");
    printf("\033[0m");
}

void venderCD() {
	
    char banda[10];
    int qtds; 
    
    printf("\033[1;33m");
    printf("----------VENDER CD----------\n");
    printf("\033[0m");
    
    printf("Banda do CD a ser vendido:\n");
    scanf(" %[^\n]", banda);
    printf("Quantidade a vender:\n");
    scanf("%d", &qtds);

    for (int i = 0; i < totalCDs; i++) {
    if (estoque[i].banda, banda) {
    if (estoque[i].qtds >= qtds) {
    estoque[i].qtds -= qtds;
    
    printf("\033[1;33m");
    printf("----------CARRINHO----------\n");
    printf("\033[0m");
    
    printf("Venda realizada! Total a pagar: R$ %.2f\n", estoque[i].preco * qtds);
    } else {
    printf("Estoque insuficiente!\n");
    }
    return;
    }
    }
    printf("CD nao encontrado!\n");
}

void pesquisarPorGenero() {
	
    char genero[10];
    
    printf("\033[1;33m");
    printf("----------PESQUISAR CDs----------\n");
    printf("\033[0m");
    
    printf("Digite o genero para pesquisar:\n");
    scanf(" %[^\n]", genero);

    int encontrados = 0;
    
    for (int i = 0; i < totalCDs; i++) {
    if (estoque[i].genero, genero) {
    printf("\033[1;33m");
    printf("Banda: %s\nAno: %d\nQuantidade: %d\nPreco: %.2f\n\n",estoque[i].banda, estoque[i].ano, estoque[i].qtds, estoque[i].preco);
    printf("\033[0m");
    
    encontrados++;
    }
    }

    if (encontrados == 0) {
    printf("Nenhum CD encontrado para o genero.\n");
    }
}

void consultarCD() {
	
    char banda[10];
    
    printf("\033[1;33m");
    printf("----------CONSULTAR CDs----------\n");
    printf("\033[0m");
    printf("Digite a banda para consultar:\n");
    scanf(" %[^\n]", banda);

    for (int i = 0; i < totalCDs; i++) {
    if (estoque[i].banda, banda) {
    printf("CD encontrado! Quantidade disponivel: %d\n", estoque[i].qtds);
    return;
    }
    }

    printf("CD nao encontrado.\n");
}
