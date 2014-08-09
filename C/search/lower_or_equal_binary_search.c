#include <stdio.h>
#define LENGTH 10

int lower_or_equal_binary_search(int arr[LENGTH], int key, int low, int high) {
	int mid = (low + high) / 2;
	int index = 0;
	if (low > high)
	{
		return high;
	}
	if (key == arr[mid])
	{
		index =  mid;
	}
	if (key > arr[mid])
	{
		index = lower_or_equal_binary_search(arr, key, mid + 1, high);
	}
	if (key < arr[mid])
	{
		index = lower_or_equal_binary_search(arr, key, low, mid - 1);
	}
	return index;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1, 2, 9, 10, 12, 36, 38, 40, 90, 117};
	int index = 0;
	int key = 240;
	index = lower_or_equal_binary_search(arr, key, 0, LENGTH - 1);
	printf("Index: %d, Value: %d\n", index, arr[index]);
	return 0;
}