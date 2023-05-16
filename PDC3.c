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

int life = 3;
int monsterMovement() {
  int monsterMove;
  srand(time(NULL));
  monsterMove = rand() % 4 + 1;

  return monsterMove;
}

int loss(life) {
  system("cls");
  life--;
  printf("Voce morreu! Restam %d vidas!", life);
  printf("\nRetornando em 3...");
  usleep(800000);
  printf("\nRetornando em 2...");
  usleep(800000);
  printf("\nRetornando em 1...");
  usleep(800000);
  return life;
}

int deathScreen() {
  system("cls");
  printf("Voce perdeu todas as vidas! volte para o menu\n");
  system("pause");
  system("cls");
  return main();
}

int levelTwo() {

  int monsterMove;
  bool levelIsFinished = false;
  char a[30][30];
  int x, y, z = 0;
  int px = 27, py = 1, mx = 18, my = 23;
  char saveChar;
  int i = 0;

  for (x = 0; x < 30; x++) {
    for (y = 0; y < 30; y++) {
      if (x == 0 || y == 0 || x == 29 || y == 29 || x == 25 && y <= 17 || x <= 28 && y == 17 || x == 8 && y >= 18 || x == 3 && y >= 4 && y <= 15) {
        a[x][y] = '*';
      } else if (x >= 3 && x <= 12 && y == 3 || x >= 3 && x <= 12 && y == 15 || x == 12 && y >= 4 && y <= 7 || x == 12 && y >= 11 && y <= 15 || x == 17 && y >= 6 && y <= 12) {
        a[x][y] = '*';
      } else if (x == 26 && y <= 17 || x == 28 && y <= 17 || x == 28 && y >= 23 || x == 27 && y >= 24 || x == 26 && y >= 25 || x == 25 && y >= 27 || x == 9 && y >= 18 || x == 3 && y <= 17 && y >= 16) {
        a[x][y] = '#';
      } else if (x == 10 && y >= 18 && y < 22 || x == 11 && y >= 18 && y < 21 || x == 12 && y == 18 || x == 13 && y == 18 || x == 1 && y < 17 || x == 24 && y > 0 && y <= 17 || x < 25 && y < 2) {
        a[x][y] = '#';
      } else if (x == 23 && y <= 5 || x == 22 && y <= 4 || x == 21 && y <= 3 || x == 20 && y <= 2) {
        a[x][y] = '#';
      } else {
        a[x][y] = ' ';
      }
    }
  }
  a[8][23] = closedDoor;
  a[27][17] = closedDoor;
  a[20][17] = openDoor;
  a[6][23] = openDoor;
  a[27][9] = key;
  a[5][9] = key;
  a[2][16] = button;
  a[px][py] = '&';
  a[mx][my] = '$';
  while (i == 0) {
    while (!levelIsFinished) {
      system("cls");
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      for (x = 0; x < 30; x++) {
        printf("\t");
        for (y = 0; y < 30; y++) {
          printf(" %c ", a[x][y]);
        }
        printf("\n");
      }
      printf("\n");
      switch (getch()) {
      case 'W':
      case 'w':
      case 72:

        if (a[px - 1][py] == '#' || a[px - 1][py] == a[mx][my]) {
          life = loss(life);
          if (life <= 0) {
            deathScreen();
          }
          a[px][py] = ' ';
          px = 27;
          py = 1;
          a[px][py] = '&';
          break;
        } else if (a[px - 1][py] == '*' || a[px - 1][py] == a[mx][my]) {
          break;
        }

        a[px][py] = saveChar;
        px--;
        saveChar = a[px][py];
        break;

      case 'A':
      case 'a':
      case 75:

        if (a[px][py - 1] == '#' || a[px][py - 1] == a[mx][my]) {
          life = loss(life);
          if (life <= 0) {
            deathScreen();
          }
          a[px][py] = ' ';
          px = 27;
          py = 1;
          a[px][py] = '&';
          break;
        } else if (a[px][py - 1] == '*' || a[px][py - 1] == 'D') {
          break;
        }
        a[px][py] = saveChar;
        py--;
        saveChar = a[px][py];
        break;

      case 'D':
      case 'd':
      case 77:
        if (a[px][py + 1] == '#' || a[px][py + 1] == a[mx][my]) {
          life = loss(life);
          if (life <= 0) {
            deathScreen();
          }
          a[px][py] = ' ';
          px = 27;
          py = 1;
          a[px][py] = '&';
          break;
        }
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
        if (a[px + 1][py] == '#' || a[px + 1][py] == a[mx][my]) {
          life = loss(life);
          if (life <= 0) {
            deathScreen();
          }
          a[px][py] = ' ';
          px = 27;
          py = 1;
          a[px][py] = '&';
          break;
        }
        if (a[px + 1][py] == '*' || a[px + 1][py] == 'D') {
          break;
        }
        a[px][py] = saveChar;
        px++;
        saveChar = a[px][py];
        break;

      case 'I':
      case 'i':
      	if (saveChar == button)
          {
              if(a[px][py] == a[2][16]){
                  a[3][16] = ' ';
                  a[9][23] = ' ';
              }
        }
        if (saveChar == key) {
          if (a[px][py] == a[27][9]) {
            a[27][17] = openDoor;
          }
          if (a[px][py] == a[5][9]) {
            a[8][23] = openDoor;
          }
          saveChar = ' ';
        }
      }

    
      monsterMove = monsterMovement();
      if (monsterMove == 1) {
        if (a[mx - 1][my] == '*' || a[mx - 1][my] == 'D' || a[mx - 1][my] == '=' || a[mx - 1][my] == '#' || a[mx - 1][my] == '@') {
          break;
        }
        a[mx][my] = ' ';
        mx--;
      }
      if (monsterMove == 2) {
        if (a[mx][my - 1] == '*' || a[mx][my - 1] == 'D' || a[mx][my - 1] == '=' || a[mx][my - 1] == '#' || a[mx][my - 1] == '@') {
          break;
        }
        a[mx][my] = ' ';
        my--;
      }
      if (monsterMove == 3) {
        if (a[mx][my + 1] == '*' || a[mx][my + 1] == 'D' || a[mx][my + 1] == '=' || a[mx][my + 1] == '#' || a[mx][my + 1] == '@') {
          break;
        }
        a[mx][my] = ' ';
        my++;
      }
      if (monsterMove == 4) {
        if (a[mx + 1][my] == '*' || a[mx + 1][my] == 'D' || a[mx + 1][my] == '=' || a[mx + 1][my] == '#' || a[mx + 1][my] == '@') {
          break;
        }
        a[mx][my] = ' ';
        mx++;
      }
      //if (a[px][py] == a[6][23]) {
     // levelIsFinished = true;
   //   i++;
 // }
      a[mx][my] = '$';
      a[px][py] = '&';
      system("cls");
    }
  }

}

void levelOne() {
  int monsterMove;
  char a[15][15];
  int x, y, z = 0;
  int px = 2, py = 3;
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

  a[10][2] = key;
  a[10][14] = closedDoor;
  a[3][13] = key;
  a[4][7] = openDoor;
  a[7][3] = closedDoor;
  a[px][py] = '&';
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

      if (a[px - 1][py] == '*' || a[px - 1][py] == 'D') {
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

    }
    a[px][py] = '&';
    if (a[px][py] == a[10][14]) {
      break;
    }
    system("cls");

  }
}

void tutorial() {
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

int main() {
  int choice;

  while (choice != 3) {
    setlocale(LC_ALL, "Portuguese");
    printf("Bem vindo ao Dungeon Crawler!");
    printf("\nEscolha uma das opções abaixo:");
    printf("\n1 : Iniciar o jogo\n2 : Tutorial\n3 : Sair\n");
    scanf("%d", & choice);
    system("cls");

    switch (choice) {
    case 1:
      life = 3;
      levelTwo();
      if (life == 0) {
        return main();
      }

      break;
    case 2:
      tutorial();
      break;
    case 3:
      printf("Obrigado por jogar!");
      break;
    }
    if (choice > 3) {
      printf("Por favor digite uma opcao válida\n\n");
      system("pause");
    }
    system("cls");
  }
  return 0;
}

