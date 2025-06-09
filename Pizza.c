#include <stdio.h>
#include<stdlib.h>

typedef struct {
	char nome[30];
	float preco;
}Pizza;

typedef struct{
	char nome[50], telefone[11];
;}Cliente;

Cliente clientes[10];
Pizza pizzas[30];
void cadastrarCliente();
void cadastrarProduto();
void listarCliente();
void listarPizza();
void venderPizzas();

int c=0, p=0;

int main() {
	
	int op;
	
	do{
	system("cls");
	printf("\033[1;35m");
    printf("--------HOT PIZZA-------\n");
    printf("\033[0m");
	printf("[1]. Cadastrar Cliente\n");
	printf("[2]. Cadastrar Pizza\n");
	printf("[3]. Listar Clientes\n");
	printf("[4]. Listar Produtos\n");
	printf("[5]. Vender Pizzas\n");
	printf("[0]. Sair\n");
	scanf("%d", &op);
		
	switch(op) {
	case 1:
    cadastrarCliente();
    break;
    
    case 2:
    cadastrarProduto();
    break;
    
    case 3:
    listarCliente();
    break;
    
    case 4:
    listarPizza();
    break;
    
    case 5:
    venderPizzas();
    break;
    
    case 0:
    printf("Fechando sistema...\n");
    break;
    
    default:
    printf("Opcao invalida!\n");
    break;
    }
    printf("\nENTER para continuar\n");
    getchar();
    getchar();
    }while (op!=0);
    return 0;
}

void cadastrarCliente() {
	system("cls");	
	printf("\033[1;33m");
	printf("Cliente %d - ", c+1);
	printf("\033[0m");
	printf("Informe o nome:\n");
	scanf("%s", clientes[c].nome);
	printf("Informe o telefone:\n");
	scanf("%s", clientes[c].telefone);	
	printf("Cliente Cadastrado!\n");
	printf("\nAperte ENTER para Voltar...\n");
	getchar();
	getchar();
	c++;
}

void cadastrarProduto() {
	printf("\033[1;33m");
	printf("Pizza %d - ", p+1);	
	printf("\033[0m");
	printf("Informe o sabor:\n");
	scanf("%s", pizzas[p].nome);
	printf("Informe o preco:\n");
	scanf("%f", &pizzas[p].preco);
	printf("Produto Cadastrado!\n");
	printf("\nAperte ENTER para Voltar...\n");
	getchar();
	getchar();
	p++;
}

void listarCliente() {
	for(int i=0; i<c; i++) {
	printf("\033[1;35m");
	printf("\n-----Cliente %d----\n", i+1);
	printf("\033[0m");
	printf("Nome: %s\n", clientes[i].nome);
	printf("Telefone: %s\n", clientes[i].telefone);
	}
	
	printf("\nAperte ENTER para Voltar...\n");		
	getchar();
	getchar();
}

void listarPizza() {
	for(int i=0; i<p; i++) {
	printf("\033[1;35m");
	printf("\n----Pizza---%d\n", i+1);
	printf("\033[0m");
	printf("Nome: %s\n", pizzas[i].nome);
	printf("Preço: %.2f\n", pizzas[i].preco);
	}
	
	printf("\nAperte ENTER para Voltar...\n");		
	getchar();
	getchar();
}

void venderPizzas() {
	int op1, i, q;

    do {
    system("cls");
    
    printf("\033[1;35m");
    printf("--------HOT PIZZA-------\n");
    printf("\033[0m");
    
    for(i = 0; i < p; i++) {
    printf("%d. %s - R$%.2f\n", i + 1, pizzas[i].nome, pizzas[i].preco);
    }
    printf("%d. Voltar\n", p + 1);
    scanf("%d", &op1);
    
    if(op1 == p + 1) {
    break;
    } 
	else if(op1 >= 1 && op1 <= p) {
	
    int v = op1 - 1;
    
    printf("Digite a quantidade desejada:\n");
    scanf("%d", &q);
    if(q <= 0) {
    printf("Quantidade invalida.\n");
    } 
	else {
    float total = pizzas[v].preco * q;
    printf("%dx. %s\n", q, pizzas[v].nome);
    printf("Total: R$%.2f\n", total);
    }
    printf("\nAperte ENTER para continuar...\n");
    getchar(); 
	getchar();
    } 
	else {
    printf("\nOpcao invalida!\n");
    printf("Aperte ENTER para continuar...\n");
    getchar(); 
	getchar();
    }

    } while(1);
}
