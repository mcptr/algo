#include <stdio.h>
#include <stdlib.h>


void swap(int *x, int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}


int main(int argc, char** argv)
{
	int x, y;

	printf("x: ");
	scanf("%d", &x);
	printf("y: ");
	scanf("%d", &y);

	swap(&x, &y);

	printf("x: %d\n", x);
	printf("y: %d\n", y);

	return 0;
}
