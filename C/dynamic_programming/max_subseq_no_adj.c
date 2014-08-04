#include <stdio.h>
#define ARR_SIZE 8

int max_subseq_no_adj(int arr[], int mem[8][8], int start, int end) {
	int index = 0;
	int val = 0;
	int altVal = 0;
	int max = 0;	
	if (-1 != mem[start][end])
	{		
		//printf("Hola! Memoization: %d %d\n", start, end);
		return mem[start][end];
	}	
	if (start > end)
	{
		return 0;
	}	
	if (start == end)
	{
		return arr[start];
	}	
	for (index = start; index < end; index += 1)
	{	
		val = max_subseq_no_adj(arr, mem, start, index - 2)
		+ arr[index] 
		+ max_subseq_no_adj(arr, mem, index + 2, end);

		altVal = max_subseq_no_adj(arr, mem, start, index - 1)		
		+ max_subseq_no_adj(arr, mem, index + 1, end);

		max = (max > val) ? max : val;
		max = (max > altVal) ? max : altVal;
	}	
	mem[start][end] = max;
	return mem[start][end];
}

void init_mem(int mem[ARR_SIZE][ARR_SIZE]) {
	int i = 0, j = 0;	
	for (i = 0; i < ARR_SIZE; i += 1) {
		for (j = 0; j < ARR_SIZE; j += 1) {
			mem[i][j] = -1;
		}
	}
}

void diaplay_mem(int mem[ARR_SIZE][ARR_SIZE]) {
	int i = 0, j = 0;	
	for (i = 0; i < ARR_SIZE; i += 1) {
		for (j = 0; j < ARR_SIZE; j += 1) {
			printf("%d ", mem[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {9, 1, 9, 1, 1, 9, 1, 9};
	int max = 0;
	int mem[ARR_SIZE][ARR_SIZE];
	init_mem(mem);
	max = max_subseq_no_adj(arr, mem, 0, ARR_SIZE - 1);
	printf("Max = %d\n", max);
	diaplay_mem(mem);
	return 0;
}