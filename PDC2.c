#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

enum{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE,
};


//Cores de fundo
enum{
	_BLACK=0,
	_BLUE=16,
	_GREEN=32,
	_CYAN=48,
	_RED=64,
	_MAGENTA=80,
	_BROWN=96,
	_LIGHTGRAY=112,
	_DARKGRAY=128,
	_LIGHTBLUE=144,
	_LIGHTGREEN=160,
	_LIGHTCYAN=176,
	_LIGHTRED=192,
	_LIGHTMAGENTA=208,
	_YELLOW=224,
	_WHITE=240,
};

void Cores (int letras, int fundo){
	//Juntar as cores
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), letras + fundo);
}

void slow_print(char* str, int delay) {
    int i;
	for (i = 0; str[i] != '\0'; i++) {
    putchar(str[i]);
    fflush(stdout);
    usleep(delay * 600);
	}
}
void levelOne() {
    char a[15][15];
    int x, y;
    char key= '@';
    char closedDoor = 'D';
    char button = 'O';
    char openDoor = '=';
    int px = 2, py = 3;

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
   	
   	for(x=0; x < 15; x++){
   		for(y=0;y<15;y++){
   			if(y==7 && x < 8){
   				a[x][y] = '*';
			   }
			else if(x==7){
				a[x][y] = '*';
			}
		   }
	   }
	a[3][13] = key;
	a[4][7]= openDoor;
    a[7][3] = closedDoor;
    a[px][py] = '&';
    while( 0 != 1){
    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	for (x = 0; x < 15; x++) {
        printf("\t\t\t\t\t\t\t\t\t\t\t\t");
        for (y = 0; y < 15; y++) {
        	printf(" %c ", a[x][y]);
        }
        printf("\n");
        
    }
    switch(getch()){
    	case 'W':
    	case 'w':
    	case 72:
    		if(a[px-1][py]=='*' || a[px-1][py]=='D'){
    			break;
			}
			
    		a[px][py]=' ';
			a[px-1][py] = '&';
    		px--;
    		break;
    	
		case 'A':	
    	case 'a':
    	case 75:
    		if(a[px][py-1]=='*' || a[px][py-1]=='D'){
    			break;
			}
    		a[px][py]=' ';
    		py--;
    		break;
    	
    	case 'D':
    	case 'd':
    	case 77:
			if(a[px][py+1]=='*' || a[px][py+1]=='D'){
    			break;
			}
    		a[px][py]= ' ';
    		py++;
    		break;
    	
		case 'S':	
    	case 's':
    	case 80:
    		if(a[px+1][py]=='*' || a[px+1][py]=='D'){
    			break;
			}
    		a[px][py]=' ';
    		px++;
    		break;
    		
    	case 'I':	
    	case 'i':
    		if(a[px][py] == a[3][13]){
    			a[7][3] = openDoor;
			}
    		
	}
	
	a[px][py] = '&';
	
    system("cls");
    
	}
}


void tutorial (){
	system("cls");
	printf("O jogo é do estilo aventura/puzzle onde o objetivo é o jogador conseguir passar de três fases.\nEm cada fase o jogador deve se movimentar para pegar uma chave para abrir a porta fechada.\nO jogador possui os seguintes comando:\n");
	printf("\nW: O jogador movimenta uma unidade para cima\nA: O jogador movimenta uma unidade para esquerda\nS: O jogador movimenta uma unidade para baixo\nD: O jogador movimenta uma unidade para direita\nI: O jogador interage com o objeto que está em cima.\n\n");
	system("pause");
	system("cls");
	printf("O jogo possui os seguintes elementos nas fases:\n\n");
	printf("&: Símbolo que representa o jogador.\n*: Símbolo que representa uma parede, o jogador ao se movimentar não pode passar pela parede.\n@: Símbolo que representa a chave para abrir a porta para finalizar a fase, a porta abre no momento que o jogador interage com a chave.\nD: Símbolo que representa a porta fechada.\n");
	printf("=: Símbolo que representa a porta aberta quando o jogador interage com a chave.\n");
	printf("O: Símbolo que representa um botão que o usuário pode interagir, o botão fica no chão e o jogador deve ficar em cima dele para poder interagir.\n");
	printf("#: Símbolo que representa um espinho. A fase é reiniciada quando o jogador toca no espinho, caso a fase seja reiniciada três vezes, o jogo volta para o menu principal.\n");
	printf(">: Símbolo que representa um teletransporte. O teletransporte sempre deve vir em pares, quando o jogador toca em um ele é transportado para o outro e vice-versa.\n");
	printf("Z: Símbolo que representa o monstro nível 1. O mostro tem um movimento aleatório, logo, ele movimenta um bloco para cima ou para direita ou para esquerda ou para baixo. O mostro sempre faz uma movimentação depois do usuário se movimentar ou interagir com um objeto.\n");
	printf("K: Símbolo que representa o monstro nível 2. O mostro nível dois tem uma inteligência de se movimentar na direção do jogador. O monstro não precisa saber desviar de obstáculos, ele sempre vai andar em linha reta em direção do jogador.\n");
	system("pause");
	system("cls");
	
}


int main (){
	int choice;
while(choice != 3){
	setlocale(LC_ALL, "Portuguese");
	Cores(RED, _LIGHTGREEN);
	printf("Bem vindo ao Dungeon Crawler!");
	printf("\nEscolha uma das opções abaixo:");
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
		printf("Por favor digite uma opcao válida\n\n");
		system("pause");
	}
	system("cls");
}
	return 0;
}
