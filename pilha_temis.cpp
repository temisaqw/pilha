#include <iostream>
#define TAMANHO 5

typedef struct {
	int topo;
	int item[TAMANHO];
}PILHA;
int menu();
void iniciar(PILHA &pilha);
bool verificarCheio(PILHA &pilha);
bool verificarVazio(PILHA &pilha);
void empilhar(PILHA &pilha, int valor);
int desempilhar(PILHA &pilha);
void imprimir(PILHA &pilha);


int main(int argc, char** argv){
	
	int opcao = 0;
	int valor;
	PILHA pilha;
	
	
	do{
		opcao = menu();	
		switch(opcao){
			case 0:{
				printf("Encerrando...");
				break;
			}
			case 1:{
				iniciar(pilha);
				printf("\nPilha inicializada!");
				break;
			}
			case 2:{
				int valor = 0;
				printf("\nInsira um valor: ");
				scanf("%i", &valor);
				empilhar(pilha, valor);
				break;
			}
			case 3:{
				desempilhar(pilha);
				break;
			}
			case 4:{
				printf("\nPilha atual:");
				imprimir(pilha);
				break;
			}
			default:{
				printf("\nNão encontrado...");
				break;
			}
		}
	}while(opcao != 0);
	
	return 0;
}

int menu(){
	int opcao;
	printf("\n1 - iniciar pilha");
	printf("\n2 - Empilhar");
	printf("\n3 - tirar");
	printf("\n4 - Mostrar pilha");
	printf("\n0 - sair\n");
	scanf("\n%i", &opcao);
	return opcao;
}

void iniciar(PILHA &pilha){
	pilha.topo = -1;
}

bool verificarVazio(PILHA &pilha){
	return pilha.topo == -1;
}

bool verificarCheio(PILHA &pilha){
	return pilha.topo == (TAMANHO - 1);
}

void empilhar(PILHA &pilha, int valor){
	if(verificarCheio(pilha)){
		printf("\n Pilha cheia!");
	} else{
		pilha.topo += 1;
		pilha.item[pilha.topo] = valor;
		printf("\nValor empilhado!");
	}
}

int desempilhar(PILHA &pilha){
	if(verificarVazio(pilha)){
		printf("\n Pilha vazia");
		return 0;
	}
	int valor = pilha.item[pilha.topo];
	pilha.topo -= 1;
	printf("\nValor removido!");
	return valor;
}

void imprimir(PILHA &pilha){
	if (verificarVazio(pilha)){
		printf("\nPilha vazia!");
		return;
	}
	
	for(int i = 0; i<=pilha.topo; i++){
		printf("\n%i", pilha.item[i]);
	}	
}
