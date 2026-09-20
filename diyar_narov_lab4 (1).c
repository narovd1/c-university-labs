#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main() {

	printf("===================\n");
	printf("==    TASK 1:    ==\n");
	printf("===================\n");

	int N;

	printf("Enter N: ");
	scanf("%i", &N);

	for (int i = 2; i <= N; i++) {
		int temp = i;
		int sum = 0;

		while (temp > 0) {
			int digit = temp % 10;
			sum += digit;
			temp /= 10;
		}
		int prime = 1;

		if (sum < 2) {
			prime = 0;
		}

		for (int j = 2; j < sum; j++) {
			if (sum % j == 0) {
				prime = 0;
			}
		}
		if (prime == 1) {
			printf("%d: Sum of digits = %d, which is a prime number.\n", i, sum);
		}
	}




	printf("===================\n");
	printf("==    TASK 2:    ==\n");
	printf("===================\n");

	printf("=========================================\n");
	printf(" Welcome to the Treasure Hunt Adventure! \n");
	printf("=========================================\n");
	printf("\n");
	printf("Rules:\n");
	printf("- You are an adventurer on a 3x3 grid. Each position may contain a treasure,\n");
	printf("  a trap, a potion, or be empty.\n");
	printf("- Your goal is to navigate through the grid, collect treasures, avoid traps,\n");
	printf("  and reach the exit at the bottom-right corner.\n");
	printf("- You start with 100 Health Points (HP) and 0 points.\n");
	printf("- Treasures increase your score, traps reduce your HP, and potions restore\n");
	printf("  your HP up to a maximum of 100.\n");
	printf("- HP cannot fall below 0. If trap damage exceeds your HP, set HP to 0.\n");
	printf("- Potions, treasures, and traps stay in their cells and work on every visit.\n");
	printf("- You can move in four directions: Up (W), Down (S), Left (A), or Right (D).\n");
	printf("- The game ends when you reach the exit, enter 'E' to quit, or your HP drops\n");
	printf("  to 0.\n");
	printf("\n");
	printf("Let's begin! Your adventure starts now.\n");

	
	int HP = 100, Score = 0;
	int location_x = 2, location_y = 2;

	printf("HP: %d\n", HP);
	printf("Score: %d\n", Score);
	printf("Starting position: (%d,%d)\n", location_x, location_y);


	char move;
	int legal_move;

	do { 
		legal_move = 1;
		printf("Your move: ");
		scanf(" %c", &move);


		if (move == 'A') {

			if (location_y == 1) {

				printf("illegal move\n");
				legal_move = 0;

			}
			else {
				location_y--;
			}
	

		}
		else if (move == 'W') {

			if (location_x == 1) {

				printf("illegal move\n");
				legal_move = 0;

			}
			else {
				location_x--;
			}
		}
		else if (move == 'D') {
			if (location_y == 3) {

				printf("illegal move\n");
				legal_move = 0;

			}
			else {
				location_y++;
			}
			
		}
		else if (move == 'S') {

			if (location_x == 3) {

				printf("illegal move\n");
				legal_move = 0;

			}
			else {
				location_x++;
			}
		}
		if (move == 'E') {
			printf("Output: You ended the game.\n");
			printf("HP: %d\n", HP);
			printf("Score: %d\n", Score);
		}
		else if (legal_move == 1) {

			printf("Output:\n");

			if (location_x == 1 && location_y == 1) {

		

				printf("Location (%d,%d): It's empty. Nothing happens.\n", location_x, location_y);
				printf("HP: %d\n", HP);
				printf("Score: %d\n", Score);

			}
			else if (location_x == 1 && location_y == 2) {
			


				printf("Location (%d,%d): Oh no! You stepped on a trap! -20 HP.\n", location_x, location_y);
				HP -= 20;

				if (HP < 0) {
					HP = 0;
				}
				printf("HP: %d\n", HP);
				printf("Score: %d\n", Score);


			}
			else if (location_x == 1 && location_y == 3) {

			

				printf("Location (%d,%d): It's empty. Nothing happens.\n", location_x, location_y);
				printf("HP: %d\n", HP);
				printf("Score: %d\n", Score);

			}
			else if (location_x == 2 && location_y == 1) {

	

				printf("Location (%d,%d): You found a potion! Restore up to 20 HP.\n", location_x, location_y);
				HP += 20;

				if (HP > 100) {
					HP = 100;
				}

				printf("HP: %d\n", HP);
				printf("Score: %d\n", Score);


			}
			else if (location_x == 2 && location_y == 2) {

	
				printf("Location (%i,%i): It's empty. Nothing happens.\n", location_x, location_y);
				printf("HP: %d\n", HP);
				printf("Score: %d\n", Score);
			}


			else if (location_x == 2 && location_y == 3) {


				printf("Location (%d,%d): Oh no! You stepped on a trap! -30 HP.\n", location_x, location_y);
				HP -= 30;
				if (HP < 0) {
					HP = 0;
				}
				printf("HP: %d\n", HP);
				printf("Score: %d\n", Score);


			}
			else if (location_x == 3 && location_y == 1) {

				printf("Location (%d,%d): You found a treasure! +20 points.\n", location_x, location_y);

				printf("HP: %d\n", HP);
				Score += 20;
				printf("Score: %d\n", Score);
			}
			else if (location_x == 3 && location_y == 2) {

				printf("Location (%d,%d): It's empty. Nothing happens.\n", location_x, location_y);
				printf("HP: %d\n", HP);
				printf("Score: %d\n", Score);

			}
			else if (location_x == 3 && location_y == 3) {


				printf("Location (%d,%d): You've found the exit! The game ends.\n", location_x, location_y);
				printf("HP: %d\n", HP);
				printf("Score: %d\n", Score);

			}

		}

		


		} while (move != 'E' && HP > 0 && !(location_x == 3 && location_y == 3));

		printf("Final Score: %d\n", Score);
		printf("Final HP: %d\n", HP);


	return 0;
}