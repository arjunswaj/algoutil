#include <stdio.h>
#define ARR_SIZE 5

int count_bits(int arr[], int mem[ARR_SIZE][ARR_SIZE], int start, int end) {	
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
		return mem[start][end] = arr[start];
	}	
	for (int mid = start; mid < end; mid += 1)
	{
		val = count_bits(arr, mem, start, mid) + count_bits(arr, mem, mid + 1, end);
	}
	
	return mem[start][end] = val;
}

int flippin_bits(int arr[], int mem[ARR_SIZE][ARR_SIZE], int flipper[ARR_SIZE][ARR_SIZE], int start, int end, int *fs, int *fe) {
	int index = 0;
	int jindex = 0;
	int val = 0;
	int altVal = 0;
	int max = 0;
	int dist = 0;		
	for (index = start; index < end; index += 1)		
	{	
		for (jindex = index; jindex < end; jindex += 1)		
		{
			val = 0;
			if(index - 1 >= 0) {
				val = mem[start][index - 1];
			}
			dist = jindex - index - mem[index][jindex] + 1;
			val += dist;
			if (jindex + 1 < end) {
				val += mem[jindex + 1][end - 1];
			}
			flipper[index][jindex] = val;
			if (val >= max) {
				max = val;
				*fs = index;
				*fe = jindex;
			}
		}		
	}		 
	return max;
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
	int arr[] = {0,0,0,0,0};
	int max = 0;
	int fs, fe;
	int mem[ARR_SIZE][ARR_SIZE];
	int flipper[ARR_SIZE][ARR_SIZE];
	init_mem(mem);
	init_mem(flipper);
	max = count_bits(arr, mem, 0, ARR_SIZE - 1);
	printf("Max Ones = %d\n", max);
	display_mem(mem);
	max = flippin_bits(arr, mem, flipper, 0, ARR_SIZE, &fs, &fe);
	printf("\nMax = %d, when flipped from %d to %d\n", max, fs, fe);	
	display_mem(flipper);
	return 0;
}