#include <stdio.h>
#define ARR_SIZE 4

int dp_cal (char mat[ARR_SIZE][ARR_SIZE], 
	int mem[ARR_SIZE][ARR_SIZE], int i, int j) {
	if (i >= ARR_SIZE || i < 0 || j >=ARR_SIZE || j < 0)
	{
		return 0;
	}
	
	if ('L' == mat[i][j])
	{
		mat[i][j] = 'X';
		mem[i][j] = dp_cal(mat, mem, i + 1, j) + 
		dp_cal(mat, mem, i, j + 1) +
		dp_cal(mat, mem, i - 1, j) +
		dp_cal(mat, mem, i, j - 1) + 1;
	} else {
		mem[i][j] = 0;
	}
	return mem[i][j];
}


void calculate_land (char mat[ARR_SIZE][ARR_SIZE], 
	int mem[ARR_SIZE][ARR_SIZE]) {
	int i = 0;
	int j = 0;
	for (i = 0; i < ARR_SIZE; i += 1) {
		for (j = 0; j < ARR_SIZE; j += 1) {
			if ('L' == mat[i][j])
			{				
				mem[i][j] = dp_cal(mat, mem, i, j);
			} else {
				mem[i][j] = 0;
			}
		}		
	}
}

void display_mat(char mat[ARR_SIZE][ARR_SIZE]) {
	int i = 0, j = 0;	
	for (i = 0; i < ARR_SIZE; i += 1) {
		for (j = 0; j < ARR_SIZE; j += 1) {
			printf("%c ", mat[i][j]);
		}
		printf("\n");
	}
}

void display_mem(int mem[ARR_SIZE][ARR_SIZE]) {
	int i = 0, j = 0;	
	for (i = 0; i < ARR_SIZE; i += 1) {
		for (j = 0; j < ARR_SIZE; j += 1) {
			printf("%d ", mem[i][j]);
		}
		printf("\n");
	}
}

void init_mem(int mem[ARR_SIZE][ARR_SIZE]) {
	int i = 0, j = 0;	
	for (i = 0; i < ARR_SIZE; i += 1) {
		for (j = 0; j < ARR_SIZE; j += 1) {
			mem[i][j] = -1;
		}
	}
}

int main(int argc, char const *argv[])
{
	int mem[ARR_SIZE][ARR_SIZE];
	char mat[ARR_SIZE][ARR_SIZE] = {
		{'L', 'L', 'L', 'L'},
		{'L', 'L', 'W', 'L'},
		{'L', 'W', 'L', 'W'},
		{'W', 'W', 'L', 'L'}
	};
	init_mem(mem);
	display_mat(mat);
	calculate_land(mat, mem);
	display_mem(mem);
	display_mat(mat);
	return 0;
}