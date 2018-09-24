#include <stdio.h>
#include <stdlib.h>


void left_rotate(int arr[], int size, int turns)
{
	for(int turn = 0; turn < turns; turn++) {
		int first = arr[0];
		for(int i = 0; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[size - 1] = first;
	}
}


void print_array(int arr[], int size)
{
	for(int i = 0; i < size; i++) {
		printf("%d, ", arr[i]);
	}	
	printf("\n");
}


void reverse_array(int arr[], int size, int offset)
{
	int half = ((size - offset) / 2) + offset;
	int r = 0;
	for(int i = offset; i < half; i++) {
		r = size - 1 - i + offset;
		arr[i] = arr[i] + arr[r];
		arr[r] = arr[i] - arr[r];
		arr[i] = arr[i] - arr[r];
	}
}


int find(const int arr[], const int value, int start, int end)
{
	if(end < start) {
		return -1;
	}

	int middle = (start + end) / 2;
	if(value == arr[middle]) {
		return middle;
	}

	if(value > arr[middle]) {
		return find(arr, value, middle + 1, end);
	}

	return find(arr, value, start, middle - 1);
}


int main(int argc, char** argv)
{
	(void) argc;
	(void) argv;
	
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


	
	left_rotate(arr, sizeof(arr) / sizeof(arr[0]), 4);
	print_array(arr, sizeof(arr) / sizeof(arr[0]));

	reverse_array(arr, sizeof(arr) / sizeof(arr[0]), 0);
	print_array(arr, sizeof(arr) / sizeof(arr[0]));

	left_rotate(arr, sizeof(arr) / sizeof(arr[0]), 4);
	print_array(arr, sizeof(arr) / sizeof(arr[0]));
	
	reverse_array(arr, sizeof(arr) / sizeof(arr[0]), 0);
	print_array(arr, sizeof(arr) / sizeof(arr[0]));

	int q = 17;
	int idx = find(arr, q, 0, sizeof(arr) / sizeof(arr[0]));
	printf("Index of %d: %d\n", q, idx);

	q = 8;
	idx = find(arr, q, 0, sizeof(arr) / sizeof(arr[0]));
	printf("Index of %d: %d\n", q, idx);
	
	return 0;
}

