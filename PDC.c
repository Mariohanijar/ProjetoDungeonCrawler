#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

void levelOne() {
    char a[15][15];
    int x, y;
    char chave = '@';
    char portaFechada = 'D';
    char botao = 'O';

    for (x = 0; x < 15; x++) {
        for (y = 0; y < 15; y++) {
            if (x == 0 || y == 0 || x == 14 || y == 14) {//0 e 14 são as bordas do quadrado
                a[x][y] = '*';//aqui estamos preenchendo as bordas da matriz com o caractere "*" 
            }
            else {
                a[x][y] = ' ';//o restante é vazio
            }
        }
    }
    for (x = 0; x < 15; x++) {
        printf("\t\t\t");
        for (y = 0; y < 15; y++) {
            if (x == 0 || y == 0 || x == 14 || y == 14) {
                printf("%c ", a[x][y]);//imprimindo o "*" na posição "[x][y]" da matriz "a", o "%c" significa que estamos imprimindo um caractere e não uma string
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    system("pause");
}


void tutorial (){
	system("cls");
	printf("O jogo é do estilo aventura/puzzle onde o objetivo é o jogador conseguir passar de três fases.\nEm cada fase o jogador deve se movimentar para pegar uma chave para abrir a porta fechada.\nO jogador possui os seguintes comando:\n");
	printf("\nW: O jogador movimenta uma unidade para cima\nA: O jogador movimenta uma unidade para esquerda\nS: O jogador movimenta uma unidade para baixo\nD: O jogador movimenta uma unidade para direita\nI: O jogador interage com o objeto que está em cima.\n\n");
	system("pause");
	system("cls");
	printf("O jogo possui os seguintes elementos nas fases:\n\n");
	printf("&: Símbolo que representa o jogador.\n\n*: Símbolo que representa uma parede, o jogador ao se movimentar não pode passar pela parede.\n\n@: Símbolo que representa a chave para abrir a porta para finalizar a fase, a porta abre no momento que o jogador interage com a chave.\n\nD: Símbolo que representa a porta fechada.\n\n");
	printf("=: Símbolo que representa a porta aberta quando o jogador interage com a chave.\n\n");
	printf("O: Símbolo que representa um botão que o usuário pode interagir, o botão fica no chão e o jogador deve ficar em cima dele para poder interagir.\n\n");
	printf("#: Símbolo que representa um espinho. A fase é reiniciada quando o jogador toca no espinho, caso a fase seja reiniciada três vezes, o jogo volta para o menu principal.\n\n");
	printf(">: Símbolo que representa um teletransporte. O teletransporte sempre deve vir em pares, quando o jogador toca em um ele é transportado para o outro e vice-versa.\n\n");
	printf("¬: Símbolo que representa o monstro nível 1. O mostro tem um movimento aleatório, logo, ele movimenta um bloco para cima ou para direita ou para esquerda ou para baixo. O mostro sempre faz uma movimentação depois do usuário se movimentar ou interagir com um objeto.\n\n");
	printf("K: Símbolo que representa o monstro nível 2. O mostro nível dois tem uma inteligência de se movimentar na direção do jogador. O monstro não precisa saber desviar de obstáculos, ele sempre vai andar em linha reta em direção do jogador.\n\n");
	system("pause");
	system("cls");
	
}


int main (){
	int choice;
while(choice != 3){
	setlocale(LC_ALL, "Portuguese");
	printf("Bem vindo ao blabla!");
	printf("\nescolha uma das opções abaixo:");
	printf("\n1 : Iniciar o jogo\n2 : Tutorial\n3 : Sair\n");
	scanf("%d", &choice);
	system("cls");
	
	switch (choice){
		case 1:
			levelOne();
			break;
		case 2:
			tutorial();
			break;
		case 3:
			printf("Obrigado por jogar!");
			break;
	}
	if(choice > 3){
		printf("Por favor digite uma opcao valida\n\n");
		system("pause");
	}
	system("cls");
}
	return 0;
}
