#include "../c-utils/utils.h"


void change_value(int **p, int value)
{
	**p = value;
}

int main()
{
	int x = 5;
	int *p0 = &x;
	int **p0_ref = &p0;

	int y = 10;
	
	printf("p0    :\t%p, *p0        = %d\n", (void*)p0, *p0);
	printf("&p0   :\t%p  **(&p0)    = %d\n", (void*)&p0, **(&p0));
	printf("p0_ref:\t%p, *(*p0_ref) = %d\n", (void*)p0_ref, *(*p0_ref));

	printf("\n# *p0 = 7\n");
	*p0 = 7;

	printf("p0    :\t%p, *p0        = %d\n", (void*)p0, *p0);
	printf("&p0   :\t%p  **(&p0)    = %d\n", (void*)&p0, **(&p0));
	printf("p0_ref:\t%p, *(*p0_ref) = %d\n", (void*)p0_ref, *(*p0_ref));

	printf("\n# p0 = y\n");
	p0 = &y;

	printf("p0    :\t%p, *p0        = %d\n", (void*)p0, *p0);
	printf("&p0   :\t%p  **(&p0)    = %d\n", (void*)&p0, **(&p0));
	printf("p0_ref:\t%p, *(*p0_ref) = %d\n", (void*)p0_ref, *(*p0_ref));

	printf("\n# *p0_ref = &x\n");
	*p0_ref = &x;

	printf("p0    :\t%p, *p0        = %d\n", (void*)p0, *p0);
	printf("&p0   :\t%p  **(&p0)    = %d\n", (void*)&p0, **(&p0));
	printf("p0_ref:\t%p, *(*p0_ref) = %d\n", (void*)p0_ref, *(*p0_ref));

	printf("\n# **p0_ref = 13\n");
	**p0_ref = 13;

	printf("p0    :\t%p, *p0        = %d\n", (void*)p0, *p0);
	printf("&p0   :\t%p  **(&p0)    = %d\n", (void*)&p0, **(&p0));
	printf("p0_ref:\t%p, *(*p0_ref) = %d\n", (void*)p0_ref, *(*p0_ref));


	printf("\n# change_value(&p0, 17)\n");
	change_value(&p0, 17);

	printf("p0    :\t%p, *p0        = %d\n", (void*)p0, *p0);
	printf("&p0   :\t%p  **(&p0)    = %d\n", (void*)&p0, **(&p0));
	printf("p0_ref:\t%p, *(*p0_ref) = %d\n", (void*)p0_ref, *(*p0_ref));

	printf("\n# change_value(p0_ref, 21)\n");
	change_value(p0_ref, 21);

	printf("p0    :\t%p, *p0        = %d\n", (void*)p0, *p0);
	printf("&p0   :\t%p  **(&p0)    = %d\n", (void*)&p0, **(&p0));
	printf("p0_ref:\t%p, *(*p0_ref) = %d\n", (void*)p0_ref, *(*p0_ref));

	printf("\n# change_value(&(*p0_ref), 21)\n");
	change_value(&(*p0_ref), 23);

	printf("p0    :\t%p, *p0        = %d\n", (void*)p0, *p0);
	printf("&p0   :\t%p  **(&p0)    = %d\n", (void*)&p0, **(&p0));
	printf("p0_ref:\t%p, *(*p0_ref) = %d\n", (void*)p0_ref, *(*p0_ref));
	
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int *arr_ptr = arr;
	printf("arr_ptr: %p, &arr_ptr: %p\n", (void*)arr_ptr, (void*)&arr_ptr);
	printf("*arr_ptr: %d, *(&(*arr_ptr)): %d\n", *arr_ptr, *(&(*arr_ptr)));
	printf("arr_ptr + 3: %p, *(arr_ptr + 3): %d\n", (void*)(arr_ptr + 3), *(arr_ptr + 3));
	printf("*(&(*(arr_ptr + 6))): %d\n", *(&(*(arr_ptr + 6))));

	return 0;
}
