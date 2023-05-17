#include<stdio.h>

int main(){
	char mapa[5][5] = { 
		{ '*', '*', '*', '*', '*'},
		{ '*', ' ', ' ', ' ', '*'},
		{ '*', ' ', ' ', ' ', '*'},
		{ '*', ' ', ' ', ' ', '*'},
		{ '*', '*', '*', '*', '*'},
	
	};
	
	int x, y;
	int px = 1, py = 1;
	
	for(y = 0; y < 5 ;y++){
		for(x = 0; x < 5 ; x++){
			if(px == x && py ==y){
				printf("   &");
			}
			
			else{
				printf("   %c", mapa[y][x]);
			}
		}
		printf("\n\n");	
	}
	
	
	return 0;
}
