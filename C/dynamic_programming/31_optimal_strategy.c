//http://www.geeksforgeeks.org/dynamic-programming-set-31-optimal-strategy-for-a-game/
#include "stdio.h"
#define SIZE 4

int min(int a, int b) {
	return a > b ? b : a;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int gimme_max_money(int coins[SIZE], int i, int j) {
	int my_choice_1 = 0;
	int my_choice_2 = 0;
	int my_next_choice_1 = 0;
	int my_next_choice_2 = 0;
	if (i == j)
	{
		//There's only one coin, take it and go home
		return coins[i];
	} else if ((i + 1) == j)
	{
		// Oooh, only, 2 coins, take the bigger one!
		return max(coins[i], coins[j]);
	} else {
		// I have chosen i

		//He'll choose i+1
		my_next_choice_1 = gimme_max_money(coins, i+2, j);
		//He'll choose j
		my_next_choice_2 = gimme_max_money(coins, i+1, j-1);
		my_choice_1 = coins[i] + min(my_next_choice_1, my_next_choice_2);

		// I have chosen j

		//He'll choose j-1
		my_next_choice_1 = gimme_max_money(coins, i, j-2);
		//He'll choose i
		my_next_choice_2 = gimme_max_money(coins, i+1, j-1);
		my_choice_2 = coins[j] + min(my_next_choice_1, my_next_choice_2);

		return max(my_choice_1, my_choice_2);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int i = 0;
	int j = SIZE - 1;
	int  coins[SIZE] = {5, 3, 7, 10};
	int max_i_can_make = 0;
	max_i_can_make = gimme_max_money(coins, i, j);
	printf("Max I can make is: %d\n", max_i_can_make);
	return 0;
}