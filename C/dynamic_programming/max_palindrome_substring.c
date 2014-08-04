#include <stdio.h>
#define ARR_SIZE 10

int max_palindrome_substring(char arr[], int mem[ARR_SIZE][ARR_SIZE], int start, int end) {
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
		return 1;
	}	
	if (start + 1 == end)
	{
		if (arr[start] == arr[end]) {
			return 1;
		} else {
			return 0;
		}
	}
	mem[start][end] = 0;
	if (arr[start] == arr[end])
	{
		val =  max_palindrome_substring(arr, mem, start + 1, end - 1);
		if (val)
		{
			mem[start][end] = 1;
		}
	}
	val = max_palindrome_substring(arr, mem, start + 1, end);
	altVal = max_palindrome_substring(arr, mem, start, end - 1);							
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

void display_mem(int mem[ARR_SIZE][ARR_SIZE]) {
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
	char *arr = "1malayalam";
	int max = 0;
	int mem[ARR_SIZE][ARR_SIZE];
	init_mem(mem);
	max = max_palindrome_substring(arr, mem, 0, ARR_SIZE - 1);
	//printf("Max = %d\n", max);
	display_mem(mem);
	return 0;
}