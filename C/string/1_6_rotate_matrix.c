#include <stdio.h>
#define N 30
void		display_matrix(int matrix[N][N]);

void
rotate_matrix(int matrix[N][N])
{
	int		start = -1;
	int		end = N;
	int		index = 0;
	int		level = 0;
	int		temp1;
	int		temp2;
	int		temp3;
	int		temp4;

	for (level = 0; level < N / 2; level += 1) {
		start += 1;
		end -= 1;
		for (index = start; index < end; index += 1) {
			temp1 = matrix[start][index];
			temp2 = matrix[index][end];
			temp3 = matrix[end][end - index + level];
			temp4 = matrix[end - index + level][start];

			matrix[start][index] = temp4;
			matrix[index][end] = temp1;
			matrix[end][end - index + level] = temp2;
			matrix[end - index + level][start] = temp3;
		}
	}

}

void
display_matrix(int matrix[N][N])
{
	int		xindex = 0;
	int		yindex = 0;
	printf("Display:\n");
	for (yindex = 0; yindex < N; yindex += 1) {
		for (xindex = 0; xindex < N; xindex += 1) {
			printf("%d ", matrix[yindex][xindex]);
		}
		printf("\n");
	}
	printf("\n");
}

void
populate_matrix(int matrix[N][N])
{
	int		xindex = 0;
	int		yindex = 0;
	int		counter = 1;
	for (yindex = 0; yindex < N; yindex += 1) {
		for (xindex = 0; xindex < N; xindex += 1, counter += 1) {
			matrix[yindex][xindex] = counter;
		}
	}
}

int
main(int argc, char const *argv[])
{
	int		matrix     [N][N];
	populate_matrix(matrix);
	display_matrix(matrix);
	rotate_matrix(matrix);
	display_matrix(matrix);
	return 0;
}
