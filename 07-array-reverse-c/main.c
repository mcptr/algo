#include "../c-utils/std.h"
#include "../c-utils/utils.h"


void reverse(int *arr, size_t size)
{
	int left = 0;
	int right = size - 1;

	int tmp;
	while(left < right) {
		debug("# swap: %d <-> %d (%d <-> %d)\n", left, right, arr[left], arr[right]);
		tmp = arr[right];
		arr[right] = arr[left];
		arr[left] = tmp;
		left++;
		right--;
		print_array(arr, size);
	}
}


void print_array(int *arr, size_t size)
{
	printf("{ ");
	for(size_t i = 0; i < size; i++) {
		printf("%d, ", arr[i]);
	}
	printf("}\n");
}

int main()
{
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print_array(array, sizeof(array) / sizeof(int));
	debug("# Even (size=%d)\n", sizeof(array) / sizeof(int));

	reverse(array, sizeof(array)/sizeof(int));

	int array_2[] = {0, 1, 2, 3, 4, 5, 6};
	debug("\n# Odd (size=%d)\n", sizeof(array_2) / sizeof(int));

	print_array(array_2, sizeof(array_2) / sizeof(int));
	reverse(array_2, sizeof(array_2) / sizeof(int));
	
	return 0;
}
