#include <stdio.h>
#define ARR_SIZE 15
// http://codeforces.com/problemset/problem/313/B

int ilya_queries(char *arr, int mem[ARR_SIZE][ARR_SIZE], int start, int end) {	
	int val = 0;	
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
		return mem[start][end] = 0;
	}	
	if (start + 1 == end)
	{
		if (arr[start] == arr[start + 1])
		{
			return mem[start][end] = 1;
		}
		else 
		{
			return mem[start][end] = 0;	
		}
	}	
	for (int mid = start; mid < end; mid += 1)
	{
		val = ilya_queries(arr, mem, start, mid) + ilya_queries(arr, mem, mid + 1, end);
		if (arr[mid] == arr[mid + 1])
		{
			val += 1;
		}
	}
	
	return mem[start][end] = val;
}


void init_mem(int mem[ARR_SIZE][ARR_SIZE]) {
	int i = 0, j = 0;	
	for (i = 0; i < ARR_SIZE; i += 1) {
		for (j = 0; j < ARR_SIZE; j += 1) {
			mem[i][j] = -1;
		}
	}
}

void display_mem(int mem[ARR_SIZE][ARR_SIZE]) {
	int i = 0, j = 0;	
	for (i = 0; i < ARR_SIZE; i += 1) {
		for (j = 0; j < ARR_SIZE; j += 1) {
			printf("%2d ", mem[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	char *arr = ".......###.....";
	int max = 0;	
	int mem[ARR_SIZE][ARR_SIZE];
	init_mem(mem);

	max = ilya_queries(arr, mem, 0, ARR_SIZE - 1);
	printf("Big Query = %d\n", max);
	display_mem(mem);	
	return 0;
}