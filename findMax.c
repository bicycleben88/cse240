#include <stdio.h>

int myMax(int[], int);

int main () {
	int nums[] = {1, 2, 6, 3, 4, 5};
	int max = myMax(nums, 6);
	printf("max: %d\n", max);
	return 0;
}

int myMax(int nums[], int i) {
	if (i >= 0) {
		if (i == 1) {
			return nums[i];
		}
		int max = myMax(nums, --i);
		return nums[i] > max ? nums[i] : max;
	} else {
		printf("array is empty\n");
	}
	return -1;
}
