#include <stdio.h>
#include <stdlib.h>

char casas[3][3];
char res;
int contjogadas, linha, coluna, vez;

void tabuleiro() {
	system("cls");
	printf("\tJogo da Velha\n");
	printf("\n\t %c | %c | %c \n", casas[0][0], casas[0][1], casas[0][2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %c \n", casas[1][0], casas[1][1], casas[1][2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %c \n", casas[2][0], casas[2][1], casas[2][2]);
}

int finaldojogo() {
	if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X'){contjogadas = 11;}
	if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X'){contjogadas = 11;}
	if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X'){contjogadas = 11;}
	if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X'){contjogadas = 11;}
	if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X'){contjogadas = 11;}
	if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X'){contjogadas = 11;}
	if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){contjogadas = 11;}
	if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){contjogadas = 11;}
			
	if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O'){contjogadas = 12;}
	if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O'){contjogadas = 12;}
	if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O'){contjogadas = 12;}
	if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O'){contjogadas = 12;}
	if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O'){contjogadas = 12;}
	if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O'){contjogadas = 12;}
	if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){contjogadas = 12;}
	if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){contjogadas = 12;}
	
	return contjogadas;			
}

void resultado() {
		if(contjogadas == 10){
			printf("\nJogo Empatado!\n");
		}
		else if(contjogadas == 11) {
			printf("\nVencedor X\n");
		}
		else if(contjogadas == 12) {
			printf("\nVencedor O\n");
		}
}

void iniciojogo() {
	contjogadas = 1;
	int i, j;
	for(i = 0; i <= 2; i++){
		for(j = 0; j <= 2; j++) {
			casas[i][j] = ' ';
		}
	}
}

void jogada() {
	if(vez%2 == 0) {
		printf("\nJogador X\n");
	} 
	else {
		printf("\nJogador O\n");
	}
	printf("Digite a linha: ");
	scanf("%d", &linha);
	printf("Digite a coluna: ");
	scanf("%d", &coluna);
	
	if(linha < 1 || coluna < 1 || linha > 3 || coluna > 3) {
		while(linha < 1 || coluna < 1 || linha > 3 || coluna > 3) {
			printf("\nJogada invalida!\n");
			printf("Digite a linha: ");
			scanf("%d", &linha);
			printf("Digite a coluna: ");
			scanf("%d", &coluna);
		}
	}
	if(casas[linha-1][coluna-1] != ' '){
		while(casas[linha-1][coluna-1] != ' ') {
			printf("\nJogada invalida!\n");
			printf("Digite a linha: ");
			scanf("%d", &linha);
			printf("Digite a coluna: ");
			scanf("%d", &coluna);
		}
	}
	if(vez%2 == 0) {
			casas[linha-1][coluna-1] = 'X';
	} else {
		casas[linha-1][coluna-1] = 'O';
	}
	
	vez++;
	contjogadas++;
}

void jogarnovamente() {
	printf("\nJogar novamente? [S/N] ");
	scanf(" %s", &res);
}

int main() {
	
	do {
		iniciojogo();
		do {
			
			tabuleiro();
			jogada();
			finaldojogo();
		
		}while(contjogadas <= 9);
		
		tabuleiro();
		resultado();			
		
		jogarnovamente();
	}while(res == 'S');
}

