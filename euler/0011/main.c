#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int read_grid(const char *path, int *grid, int grid_size);
void display_grid(const int *grid, int rows, int cols);
unsigned long find_max_path(const int *grid, int rows, int cols, int len);


int main(void)
{
	const char* filename = "grid.txt";
	int rows = 20;
	int cols = 20;

	int *grid = (int*) malloc(rows * cols * sizeof(int));

	int status;
	if((status = read_grid(filename, grid, rows * cols)) == -1) {
		fprintf(stderr, "Failed to read grid: %s\n", filename);
		return 1;
	}

	display_grid(grid, rows, cols);

	printf("Max product: %ld\n", find_max_path(grid, rows, cols, 4));

	free(grid);

	printf("\n");
	return 0;
}


unsigned long find_max_path(const int *grid, int rows, int cols, int len)
{
	unsigned long max_product = 0;
	unsigned long product = 1;
	int i;
	int j;
	int r;

	/* right */
	for(r = 0; r < rows; r++) {
		for(i = 0; i <= cols - len; i++) {
			product = 1;
			for(j = 0; j < len; j++) {
				product *= grid[i + j + r * cols];
				printf("%2d ", grid[i + j + r * cols]);
			}

			printf(" -> %12ld", product);
			if(product > max_product) {
				max_product = product;
				printf(" *MAX* ");
			}
			printf("\n");
		}
	}

	/* down */
	for(r = 0; r <= rows - len; r++) {
		for(i = 0; i < cols; i++) {
			product = 1;
			for(j = 0; j < len; j++) {
				product *= grid[(r + j) * cols + i];
				printf("%2d ", grid[(r + j) * cols + i]);
			}

			printf(" -> %12ld", product);
			if(product > max_product) {
				max_product = product;
				printf(" *MAX* ");
			}
			printf("\n");
		}
	}

	/* diagonal right down  */
	for(r = 0; r < rows - len + 1; r++) {
		for(i = 0; i <= cols - len; i++) {
			product = 1;
			for(j = 0; j < len; j++) {
				product *= grid[cols * (j + r) + i + j];
				printf("%2d ", grid[cols * (j + r) + i + j]);
			}

			printf(" -> %12ld", product);
			if(product > max_product) {
				max_product = product;
				printf(" *MAX* ");
			}
			printf("\n");
		}
	}

	/* diagonal left down  */
	for(r = 0; r < rows - len + 1; r++) {
		for(i = len - 1; i < cols; i++) {
			product = 1;
			for(j = 0; j < len; j++) {
				product *= grid[cols * (j + r) + i - j];
				printf("%2d ", grid[cols * (j + r) + i - j]);
			}

			printf(" -> %12ld", product);
			if(product > max_product) {
				max_product = product;
				printf(" *MAX* ");
			}
			printf("\n");
		}
	}

	return max_product;
}


int read_grid(const char *path, int *grid, int grid_size)
{
	FILE *fh = fopen(path, "r");

	if(fh == NULL) {
		return -1;
	}

	size_t len;
	int bytes;
	char *line = NULL;

	char *token = NULL;
	int i = 0;

	while((bytes = getline(&line, &len, fh)) != -1) {
		while((token = strsep(&line, " ")) != NULL) {
			grid[i++] = atoi(token);
		}
	}

	fclose(fh);
	return 0;
}


void display_grid(const int *grid, int rows, int cols)
{
	int i;
	int j;

	printf("\t");
	for(i = 0; i < cols; i++) {
		printf(" %3d ", i);
	}

	printf("\n\t");

	for(i = 0; i < cols; i++) {
		printf("-----");
	}

	printf("\n");


	int column_no = 0;
	for(i = 0; i < cols * rows; i += cols, column_no++) {
		printf("%3d\t|", column_no);
		for(j = 0; j < cols; j++) {
			printf(" %3d ", grid[i + j]);
		}
		printf("\n");
	}

	printf("\t");
	for(i = 0; i < cols; i++) {
		printf("-----");
	}

	printf("\n");
}
