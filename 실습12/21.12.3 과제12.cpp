
/**
* @author 백성수
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>


// ■ 헤더

// ● 동적할당

void* malloc_s(size_t size);

// ● 정렬 알고리즘

/**
* 선택 정렬
* 
* @param array : 배열
* @param n : 항목 수
*/
void selectSort(double* array, int n);

/**
* 삽입 정렬
*
* @param array : 배열
* @param n : 항목 수
*/
void insertSort(double* array, int n);

/**
* 빠른 정렬
* 비재귀로 구현되었습니다.
*
* @param array : 배열
* @param n : 항목 수
*/
void quickSort(double* array, int n);

// ● 정렬 검사

/**
* 배열이 정렬되었는지 검사합니다.
* 
* @param array : 배열
* @param n : 배열의 길이
* @return 정렬되었으면 1, 아니면 0
*/
int sortCheck(double* array, int n);

// ● 배열 복사

/**
* 주어진 배열을 조건대로 복사합니다.
* 
* @param mode : 0 - 복사, 1 - 오름차순 정렬 복사, 2 - 내림차순 정렬 복사
* @param output : 복사받을 배열
* @param base : 원본 배열
* @param n : 배열의 길이
*/
void arrayCopy(int mode, double* output, double* base, int n);

// ■ main

int main() {


	printf("■ 이상 프로그램을 종료합니다.\n진행하려면 아무 숫자나 입력 : ");
	int final_exit_answer;
	scanf_s("%d", &final_exit_answer);

	return 0;
}

// ■ 구현부

void* malloc_s(size_t size) {
	void* tmp = malloc(size);
	if (!tmp) {
		fprintf(stderr,"Out Of Memory\n");
		exit(1);
	}
	return tmp;
}

void selectSort(double* array, int n) {
	double tmp;

	int minIndex = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++)
			if (array[minIndex] > array[j])
				minIndex = j;
		tmp = array[minIndex];
		array[minIndex] = array[i];
		array[i] = tmp;
	}

}

void insertSort(double* array, int n) {
	double currentItem;
	int i, j;

	for (i = 1; i < n; i++) {
		currentItem = array[i];
		for (j = i - 1; j >= 0 && currentItem < array[j]; j--)
			array[j+1] = array[j];
		array[++j] = currentItem;
	}
}

void quickSort(double* array, int n) {
	int* boundStack = (int*)malloc_s(n*sizeof(n));
	int top = -1;

	int pivot, front, rear;
	boundStack[++top] = front;
	boundStack[++top] = rear;

	int i, j;
	double swap_tmp;
	while (top != -1) {
		// Current Recursive
		front = boundStack[top--];
		rear = boundStack[top--];

		// Quick Sort
		pivot = front++;
		i = front, j = rear;
		while (true) {
			while (i < j && array[i] < array[pivot])
				i++;
			while (array[j] > array[pivot])
				j--;
			if (i < j) {
				swap_tmp = array[i];
				array[i] = array[j];
				array[j] = swap_tmp;
			}	
			else
				break;
		}
		swap_tmp = array[i - 1];
		array[i - 1] = array[pivot];
		array[pivot] = swap_tmp;

		// Record Next recursive
		if (front < (i - 2)) {
			boundStack[++top] = front;
			boundStack[++top] = i - 2;
		}
		if (i < rear) {
			boundStack[++top] = i;
			boundStack[++top] = rear;
		}
	}

	free(boundStack);
}

int sortCheck(double* array, int n) {
	for (int i = 0; i < n - 1; i++)
		if (array[i] > array[i + 1])
			return 0;
	return 1;
}

void arrayCopy(int mode, double* output, double* base, int n) {
	for (int i = 0; i < n; i++)
		output[i] = base[i];

	if (mode == 1 || mode == 2) {
		quickSort(output, n); // mode 1 : Ascending sort
		if (mode == 2) { // mode 2 : Descending sort
			double swap_tmp;
			for (int i = 0; i < n - i; i++) {
				swap_tmp = output[i];
				output[i] = output[n - i];
				output[n - i] = swap_tmp;
			}
		}
	}
}