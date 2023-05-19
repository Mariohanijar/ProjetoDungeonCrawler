#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <time.h>
#define closedDoor 'D'
#define key '@'
#define button 'O'
#define openDoor '='
#define monster '$'
#define portal '>'
#define portal1 '|'
void levelOne() {
  int monsterMove;
  char a[15][15];
  int x, y, z = 0;
  int px = 2, py = 3, mx = 10, my = 10;
  char saveChar;

  for (x = 0; x < 15; x++) {
    for (y = 0; y < 15; y++) {
      if (x == 0 || y == 0 || x == 14 || y == 14) { //0 e 14 s?o as bordas do quadrado
        a[x][y] = '*'; //aqui estamos preenchendo as bordas da matriz com o caractere "*"
      } else if (y == 7 && x < 8) {
        a[x][y] = '*';
      } else if (x == 7) {
        a[x][y] = '*';
      } else {
        a[x][y] = ' '; //o restante ? vazio
      }
    }
  }
  a[4][3] = portal;
  a[8][3] = portal;
  a[10][2] = key;
  a[10][14] = closedDoor;
  a[3][13] = key;
  a[4][7] = openDoor;
  a[7][3] = closedDoor;
  a[px][py] = '&';
  a[mx][my] = 'k';
  while (2 != 1){
  
  while (0 != 1) {
    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for (x = 0; x < 15; x++) {
      printf("\t\t\t\t\t\t\t\t\t\t\t\t");
      for (y = 0; y < 15; y++) {
        printf(" %c ", a[x][y]);
      }
      printf("\n");
    }
    switch (getch()) {
    case 'W':
    case 'w':
    case 72:

      if (a[px - 1][py] == '*' || a[px - 1][py] == 'D' ) {
        break;
      }

      a[px][py] = saveChar;
      px--;
      saveChar = a[px][py];
      break;

    case 'A':
    case 'a':
    case 75:
      if (a[px][py - 1] == '*' || a[px][py - 1] == 'D') {
        break;
      }
      a[px][py] = saveChar;
      py--;
      saveChar = a[px][py];
      break;

    case 'D':
    case 'd':
    case 77:
      if (a[px][py + 1] == '*' || a[px][py + 1] == 'D') {
        break;
      }
      a[px][py] = saveChar;
      py++;
      saveChar = a[px][py];
      break;

    case 'S':
    case 's':
    case 80:
      if (a[px + 1][py] == '*' || a[px + 1][py] == 'D') {
        break;
      }
      a[px][py] = saveChar;
      px++;
      saveChar = a[px][py];	  
      break;
      

    case 'I':
    case 'i':
      if (saveChar == key) {
        if (z < 1) {
          a[7][3] = openDoor;
        } else if (z = 1) {
          a[10][14] = openDoor;
        }
        z++;
        saveChar = ' ';

       }
       if(px == 4 && py == 3)
	   {
	   	px = 8;
	   	py = 3;
	   	a[4][3] =  '>';
	    }
	    else if(px == 8 && py == 3)
		{	
		px = 4;
	   	py = 3;
	   	a[8][3] =  '>';
	    }
    }
    if(px > mx){
		if (a[mx + 1][my] == ' ') {
         a[mx][my] = ' ';
		mx++;   
        }
        
	}
	else if(px < mx){
		if (a[mx - 1][my] == ' ') {
          a[mx][my] = ' ';
		mx--;  
        }
        
	}
	else if(px == mx && py > my){
        if(a[mx][my+1] == ' '){
        a[mx][my] = ' ';
		my++;
		}
        
	}
	else if(px == mx && py < my){
		if (a[mx][my - 1] == ' ') {
         a[mx][my] = ' ';
		my--;   
        }
        
	}
    a[mx][my] = 'k';
    a[px][py] = '&';
    if (a[px][py] == a[10][14]) {
      break;
    }
    system("cls");
}
  }
}

int main() {
  int choice;

  while (choice != 3) {
    setlocale(LC_ALL, "Portuguese");
    printf("Bem vindo ao Dungeon Crawler!", 50);
    printf("\nEscolha uma das op??es abaixo:");
    printf("\n1 : Iniciar o jogo\n2 : Tutorial\n3 : Sair\n");
    scanf("%d", & choice);
    system("cls");

    switch (choice) {
    case 1:
      levelOne();
      

      break;
    case 2:
      break;
    case 3:
      printf("Obrigado por jogar!");
      break;
    }
    if (choice > 3) {
      printf("Por favor digite uma opcao v?lida\n\n");
      system("pause");
    }
    system("cls");
  }
  return 0;
}
