#include <stdio.h>
#define LENGTH 8
#define SIZES 4
#define NOT_POSSIBLE -1

int cut_ribbon(int arr[], int mem[SIZES][LENGTH]) {	
	int index = 0;
	int rem = 0;
	int max = 0;	
	for (int i = 1; i < SIZES; i += 1)
	{
		for (int j = 1; j < LENGTH; j += 1)
		{
			max = 0;
			if (arr[i - 1] > j)
			{
				mem[i][j] = NOT_POSSIBLE;
				if (mem[i-1][j] != 0) // to exclude 1st row
				{
					mem[i][j] = (mem[i][j] > mem[i-1][j]) ? mem[i][j] : mem[i-1][j];	
				}
			} 
			else
			{
				rem = j - arr[i - 1];
				//printf("rem %d, i %d, j %d, arr[i - 1] %d, mem[i][rem] %d\n", rem, i, j, arr[i - 1], mem[i][rem]);
				if (mem[i][rem] == NOT_POSSIBLE)
				{					
					mem[i][j] = NOT_POSSIBLE;
					if (mem[i-1][j] != 0) // to exclude 1st row
					{
						mem[i][j] = (mem[i][j] > mem[i-1][j]) ? mem[i][j] : mem[i-1][j];	
					}
				} else {
					max = mem[i][rem] + 1;
					mem[i][j] = (max > mem[i-1][j]) ? max : mem[i-1][j];					
				}				
			}			
		}
		
	}
	return mem[SIZES - 1][LENGTH - 1];
}

void init_mem(int mem[SIZES][LENGTH]) {
	int i = 0, j = 0;	
	for (i = 0; i < SIZES; i += 1) {
		for (j = 0; j < LENGTH; j += 1) {			
				mem[i][j] = 0;						
		}
	}
}

void display_mem(int mem[SIZES][LENGTH]) {
	int i = 0, j = 0;	
	for (i = 0; i < SIZES; i += 1) {
		for (j = 0; j < LENGTH; j += 1) {
			printf("%3d ", mem[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {2, 5, 5};
	int max = 0;	
	int mem[SIZES][LENGTH];
	init_mem(mem);
	max = cut_ribbon(arr, mem);
	printf("Max Pieces = %d\n", max);
	display_mem(mem);	
	return 0;
}