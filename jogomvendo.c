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
    int px = 7, py = 7;

    for (x = 0; x < 15; x++) {
        for (y = 0; y < 15; y++) {
            if (x == 0 || y == 0 || x == 14 || y == 14) {//0 e 14 s�o as bordas do quadrado
                a[x][y] = '*';//aqui estamos preenchendo as bordas da matriz com o caractere "*" 
            }
            else {
                a[x][y] = ' ';//o restante � vazio
            }
        }
    }
   	
    a[px][py] = '&';
    while( 0 != 1){
    	
	for (x = 0; x < 15; x++) {
        printf("\t\t\t");
        for (y = 0; y < 15; y++) {
        	printf(" %c ", a[x][y]);
        }
        printf("\n");
    }
    switch(getch()){
    	case 'w':
    		a[px][py]=' ';
			a[px-1][py] = '&';
    		px--;
    		break;
    		
    	case 'a':
    		a[px][py]=' ';
			a[px][py-1] = '&';
    		py--;
    		break;
    	
    	case 'd':
    		a[px][py]= ' ';
    		a[px][py+1]= '&';
    		py++;
    		break;
    		
    	case 's':
    		a[px][py]=' ';
    		a[px+1][py]='&';
    		px++;
    		break;
	}
    system("cls");
    
	}
}


void tutorial (){
	system("cls");
	printf("O jogo � do estilo aventura/puzzle onde o objetivo � o jogador conseguir passar de tr�s fases.\nEm cada fase o jogador deve se movimentar para pegar uma chave para abrir a porta fechada.\nO jogador possui os seguintes comando:\n");
	printf("\nW: O jogador movimenta uma unidade para cima\nA: O jogador movimenta uma unidade para esquerda\nS: O jogador movimenta uma unidade para baixo\nD: O jogador movimenta uma unidade para direita\nI: O jogador interage com o objeto que est� em cima.\n\n");
	system("pause");
	system("cls");
	printf("O jogo possui os seguintes elementos nas fases:\n\n");
	printf("&: S�mbolo que representa o jogador.\n\n*: S�mbolo que representa uma parede, o jogador ao se movimentar n�o pode passar pela parede.\n\n@: S�mbolo que representa a chave para abrir a porta para finalizar a fase, a porta abre no momento que o jogador interage com a chave.\n\nD: S�mbolo que representa a porta fechada.\n\n");
	printf("=: S�mbolo que representa a porta aberta quando o jogador interage com a chave.\n\n");
	printf("O: S�mbolo que representa um bot�o que o usu�rio pode interagir, o bot�o fica no ch�o e o jogador deve ficar em cima dele para poder interagir.\n\n");
	printf("#: S�mbolo que representa um espinho. A fase � reiniciada quando o jogador toca no espinho, caso a fase seja reiniciada tr�s vezes, o jogo volta para o menu principal.\n\n");
	printf(">: S�mbolo que representa um teletransporte. O teletransporte sempre deve vir em pares, quando o jogador toca em um ele � transportado para o outro e vice-versa.\n\n");
	printf("�: S�mbolo que representa o monstro n�vel 1. O mostro tem um movimento aleat�rio, logo, ele movimenta um bloco para cima ou para direita ou para esquerda ou para baixo. O mostro sempre faz uma movimenta��o depois do usu�rio se movimentar ou interagir com um objeto.\n\n");
	printf("K: S�mbolo que representa o monstro n�vel 2. O mostro n�vel dois tem uma intelig�ncia de se movimentar na dire��o do jogador. O monstro n�o precisa saber desviar de obst�culos, ele sempre vai andar em linha reta em dire��o do jogador.\n\n");
	system("pause");
	system("cls");
	
}


int main (){
	int choice;
while(choice != 3){
	setlocale(LC_ALL, "Portuguese");
	printf("Bem vindo ao blabla!");
	printf("\nescolha uma das op��es abaixo:");
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
