#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMS 20
#define SEED 666

int makeNumsArray(int*);
void printArray(int*);
void mergeSort(int, int, int*);
void merge(int, int, int, int*);

int main() {
	int numsArray[MAX_NUMS];
	makeNumsArray(numsArray);
	printArray(numsArray);
	mergeSort(0, MAX_NUMS - 1, numsArray);
	printArray(numsArray);
	return 0;
}

int makeNumsArray(int* array) {
	srand(SEED);

	for (int i = 0; i < MAX_NUMS; i++) {
		int num = rand() % 101;
		array[i] = num;
	}	
	return *array;
}

void printArray(int* array) {
	 for (int i = 0; i < MAX_NUMS; i++) {
                printf("%d ", array[i]);
        }
	printf("\n");
}

void mergeSort(int start,int end,int* array) {
	if (start >= end) {
		return;
	}
	int middle = (start + end) / 2;
	mergeSort(start, middle, array);
	mergeSort(middle + 1, end, array);
	merge(start, middle, end, array);
}

void merge(int start, int middle, int end, int* array) {
	int leftLen = (middle - start) + 1;
	int rightLen = end - middle;
	int left[leftLen];
	int right[rightLen];

	// fill left side array with values from int* array
	for (int i = 0; i < leftLen; i++) {
		left[i] = array[start + i];
	}

	// fill right side array with values from int* array
	for (int i = 0; i < rightLen; i++) {
		right[i] = array[middle + i + 1];
	}

	int l = 0, r = 0, s = start;

	// fill int* array with the smaller of two values from left and right side arrays 
	while(l < leftLen && r < rightLen) {
		if (left[l] <= right[r]) {
			array[s] = left[l];
			l++;
		} else {
			array[s] = right[r];
			r++;
		}
		s++;
	} 

	// fill int* array with any remaining values from left side array
	while (l < leftLen) {
		array[s] = left[l];
		l++;
		s++;
	}

	// fill int* array with any remaining values from right side array
	while (r < rightLen) {
		array[s] = right[r];
		r++;
		s++;
	}
}
