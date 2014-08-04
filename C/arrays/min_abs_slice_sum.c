#include <stdio.h>
int
min(int a, int b)
{
	return a > b ? b : a;
}

int
abs(int a)
{
	return a > 0 ? a : (-1 * a);
}


int solution(int A[], int N) {
	int lsum = 0;
	int rsum = 0;
	int currele = 0;
	if (N < 3)
	{
		/* code */
	}
}

int main(int argc, char const *argv[])
{
	int A[] = {2, -4, 6, -3, 9};
	findSolution(A, 5);
	return 0;
}