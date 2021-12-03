
/**
* @author 백성수
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// ■ 헤더

// ● 동적할당

void* malloc_s(size_t size);

// ● 실수 배열 생성

/**
* 랜덤 실수 배열을 생성합니다.
* 
* @param n : 배열의 크기
* @return 배열
*/
double* makeArray(int n);

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
	srand(time(NULL));

	int n;
	printf("정렬할 배열의 원소 수를 입력하세요 : ");
	scanf_s("%d",&n);
	printf("\n");

	double* arrayA = makeArray(n);
	double* arrayB = (double*)malloc_s(n * sizeof(double));

	void (*sortAlgorithm[3])(double*, int) = {
		selectSort,
		insertSort,
		quickSort
	};
	const char* userInfo[3] = {
		"1. 무작위로 배열된 실수들의 정렬 시간 측정\n",
		"2. 오름차순 배열된 실수들의 정렬 시간 측정\n",
		"3. 내림차순 배열된 실수들의 정렬 시간 측정\n"
	};
	const char* sortName[3] = {
		"선택",
		"삽입",
		"빠른"
	};
	clock_t start, end;
	for (int i = 0; i < 3; i++) {
		printf("%s",userInfo[i]);
		for (int j = 0; j < 3; j++) {
			arrayCopy(i, arrayB, arrayA, n);
			start = clock();
			(sortAlgorithm[j])(arrayB, n);
			end = clock();
			if (sortCheck(arrayB, n))
				printf("%s 정렬 : %f초\n", sortName[j], (end - start) / (double)CLOCKS_PER_SEC);
			else
				printf("%s정렬 오류! 정렬되지 않았습니다.\n", sortName[j]);
		}
		printf("\n");
	}

	printf("■ 이상 프로그램을 종료합니다.\n진행하려면 아무 숫자나 입력 : ");
	int final_exit_answer;
	scanf_s("%d", &final_exit_answer);

	free(arrayA);
	free(arrayB);
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

double* makeArray(int n) {
	double* array = (double*)malloc_s(n*sizeof(double));
	for (int i = 0; i < n; i++)
		array[i] = (rand() / (0x7fff * 1.0)) * 100000000;
	return array;
}

void selectSort(double* array, int n) {
	double tmp;

	int minIndex;
	for (int i = 0; i < n-1; i++) {
		minIndex = i;
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
	int* boundStack = (int*)malloc_s((n+1) * sizeof(n));
	int top = -1;

	int pivot, front, rear;
	boundStack[++top] = 0;
	boundStack[++top] = n - 1;

	int i, j;
	double swap_tmp;
	while (top != -1) {
		// Current Recursive
		rear = boundStack[top--];
		front = boundStack[top--];

		// Quick Sort
		pivot = front;
		i = front+1, j = rear;
		while (true) {
			while (i <= j && array[i] <= array[pivot])
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
			for (int i = 0; i < (n - 1) - i; i++) {
				swap_tmp = output[i];
				output[i] = output[(n - 1) - i];
				output[(n - 1) - i] = swap_tmp;
			}
		}
	}
}