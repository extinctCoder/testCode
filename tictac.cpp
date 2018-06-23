#include <stdio.h>

int board[3][3];

int playerOne = 0;
int playerTwo = 0;

void initBoard();
void drawBoard();
bool putMove(int x, int y, int player);
bool isGameOver(int player);
void scoreBoard(int player);

int main(){
	printf("\nwelcome to tic tac game, script by extinctCoder ... :P\n");
	printf("\n-------------------------------------------------------\n");
play:
	initBoard();
	drawBoard();
	for(int i = 0;; i++){
		int x, y;
	playerOne:
		printf("\nP1 (x y) :>_  ");
		scanf("%d %d", &x, &y);	
		if(x >=1 && x <= 3 && y >=1 && y <= 3){
			if(!putMove(x - 1, y - 1, 0)){
				printf("\nwrong move ...!!!\n");
				goto playerOne;
			}
		}
		else{
			printf("\nwrong move ...!!!\n");
			goto playerOne;
		}
		i++;
		if(isGameOver(0)){
			printf("\nplayer one is win ... :)\n");
			scoreBoard(0);
			break;
		}
		if(i == 8){
			printf("\nno player is win ... :)\n");
			scoreBoard(-1);
			break;
		}
	playerTwo:
		printf("\nP2 (x y) :>_  ");
		scanf("%d %d", &x, &y);	
		if(x >=1 && x <= 3 && y >=1 && y <= 3){
			if(!putMove(x - 1, y - 1, 1)){
				printf("\nwrong move ...!!!\n");
				goto playerTwo;
			}
		}
		else{
			printf("\nwrong move ...!!!\n");
			goto playerTwo;
		}
		if(isGameOver(1)){
			printf("\nplayer two is win ... :)\n");
			scoreBoard(1);
			break;
		}
	}
	printf("\nlet's play again or ^c to exit\n");
	printf("\n-------------------------------------------------------\n");
	goto play;
	return 0;
}

void initBoard(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			board[i][j] = -1;
		}	
	}
	
	playerOne = 0;
	playerTwo = 0;
}
void drawBoard(){
	printf("\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(board[i][j] == 1){
				printf("@");
			}
			else if(board[i][j] == 0){
				printf("$");
			}
			else if(board[i][j] == -1){
				printf("#");
			}
			if(j < 2){
				printf(" | ");
			}
		}
		if(i < 2){
			printf("\n- - - - -\n");
		}
	}
	printf("\n");
}
bool putMove(int x, int y, int player){
	if(board[x][y] == -1){
		if(player == 0){
			board[x][y] = 0;
		}
		else if(player == 1){
			board[x][y] = 1;
		}
	
	}
	else{
		return false;
	}
	drawBoard();
	return true;
}
bool isGameOver(int player){
	if(board[0][0] == player && board[0][1] == player && board[0][2] == player){
		return true;
	}
	else if(board[1][0] == player && board[1][1] == player && board[1][2] == player){
		return true;
	}
	else if(board[2][0] == player && board[2][1] == player && board[2][2] == player){
		return true;
	}
	else if(board[0][0] == player && board[1][0] == player && board[2][0] == player){
		return true;
	}
	else if(board[0][1] == player && board[1][1] == player && board[2][1] == player){
		return true;
	}
	else if(board[0][2] == player && board[1][2] == player && board[2][2] == player){
		return true;
	}
	else if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
		return true;
	}
	else if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
		return true;
	}
	else{
		return false;
	}
}
void scoreBoard(int player){
	if(player == 0){
		playerOne++;
	}
	else if(player == 1){
		playerTwo++;
	}
	else if(player == -1){
		playerOne++;
		playerTwo--;
	}
	printf("\nscoreboard (P1 , P2) :>_ (%d , %d)\n", playerOne, playerTwo);
}
