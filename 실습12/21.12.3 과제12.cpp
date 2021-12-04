
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

// ● 테스트 함수

/**
* n개의 실수를 생성하여 각 정렬알고리즘의 시간 측정
*/
void test1();

/**
* 각 정렬 알고리즘별 시간복잡도 측정
*/
void test2();

/**
* test3 보조함수 : 역순 삽입 정렬후 좌우반전
* 
* @param array : 배열
* @param n : 항목 수
*/
void insertSort_invers(double* array, int n);

/**
* 역정렬에 강한 정렬방식 테스트
*/
void test3();

// ■ main

int main() {
	srand(time(NULL));

	int testMode;
	printf("사용할 테스트를 입력하세요.\n");
	printf("1 : 입력받은 n개의 실수에 대해 정렬 알고리즘의 시간을 측정합니다.\n");
	printf("2 : n의 크기를 키워가며 알고리즘별 시간복잡도를 측정합니다.\n");
	printf("3 : 내림차순에 대한 역 삽입 정렬 알고리즘의 시간복잡도를 측정합니다.\n");
	scanf_s("%d",&testMode);
	printf("\n");

	switch (testMode) {
	case 1 :
		test1();
		break;
	case 2:
		test2();
		break;
	case 3:
		test3();
		break;
	default:
		printf("잘못된 테스트 번호\n");
	}
	printf("\n");

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

void (*sortAlgorithm[3])(double*, int) = {
		selectSort,
		insertSort,
		quickSort
};
const char* sortName[3] = {
	"선택",
	"삽입",
	"빠른"
};
const char* arrayMode[3] = {
	"무작위",
	"오름차순",
	"내림차순"
};

void test1() {

	int n;
	printf("정렬할 배열의 원소 수를 입력하세요 : ");
	scanf_s("%d", &n);
	printf("\n");

	double* arrayA = makeArray(n);
	double* arrayB = (double*)malloc_s(n * sizeof(double));

	clock_t start, end;
	for (int i = 0; i < 3; i++) {
		printf("%d. %s 배열된 실수들의 정렬 시간 측정\n",i+1, arrayMode[i]);
		for (int j = 0; j < 3; j++) {
			arrayCopy(i, arrayB, arrayA, n);
			start = clock();
			(sortAlgorithm[j])(arrayB, n);
			end = clock();
			if (sortCheck(arrayB, n))
				printf("%s 정렬 : %0.3f초\n", sortName[j], (end - start) / (double)CLOCKS_PER_SEC);
			else
				printf("%s정렬 오류! 정렬되지 않았습니다.\n", sortName[j]);
		}
		printf("\n");
	}

	free(arrayA);
	free(arrayB);
}

void test2() {

	const int testCase_len = 16;
	int testCase[testCase_len] = {
		1000,
		5000,
		10000,
		25000,
		50000,
		75000,
		100000,
		200000,
		300000,
		400000,
		500000,
		600000,
		700000,
		800000,
		900000,
		1000000
	};

	double* arrayA = makeArray(testCase[testCase_len-1]);
	double* arrayB = (double*)malloc_s(testCase[testCase_len - 1] * sizeof(double));

	const char* userInfo[3] = {
		"1. 선택정렬 알고리즘의 시간복잡도\n",
		"2. 삽입정렬 알고리즘의 시간복잡도\n",
		"3. 내림차순 배열된 실수들의 정렬 시간 측정\n"
	};
	clock_t start, end;
	for (int i = 0; i < 3; i++) {
		printf("%d. %s정렬 알고리즘의 시간복잡도\n",i+1,sortName[i]);
		for (int j = 0; j < 3; j++) {
			printf("%d. %s 배열일때\n",j+1, arrayMode[j]);
			for (int k = 0; k < testCase_len; k++) {
				arrayCopy(j, arrayB, arrayA, testCase[k]);
				start = clock();
				(sortAlgorithm[i])(arrayB, testCase[k]);
				end = clock();
				if (sortCheck(arrayB, testCase[k]))
					printf("%s 정렬 | %7d개 : %0.3f초\n", sortName[i], testCase[k], (end - start) / (double)CLOCKS_PER_SEC);
				else
					printf("%s정렬 오류! 정렬되지 않았습니다.\n", sortName[i]);
			}
		}
		printf("\n");
	}

	free(arrayA);
	free(arrayB);
}

void insertSort_invers(double* array, int n) {
	double currentItem;
	int i, j;

	for (i = 1; i < n; i++) {
		currentItem = array[i];
		for (j = i - 1; j >= 0 && currentItem > array[j]; j--)
			array[j + 1] = array[j];
		array[++j] = currentItem;
	}

	// inverse
	double swap_tmp;
	for (int i = 0; i < (n - 1) - i; i++) {
		swap_tmp = array[i];
		array[i] = array[n - 1 - i];
		array[n - 1 - i] = swap_tmp;
	}
}

void test3() {
	int n;
	printf("정렬할 배열의 원소 수를 입력하세요 : ");
	scanf_s("%d", &n);
	printf("\n");

	double* arrayA = makeArray(n);
	double* arrayB = (double*)malloc_s(n * sizeof(double));

	clock_t start, end;
	printf("%d개 내림차순 실수들을 역 삽입 정렬하는 시간 측정\n",n);
		
	arrayCopy(2, arrayB, arrayA, n);
	start = clock();
	insertSort_invers(arrayB, n);
	end = clock();
	if (sortCheck(arrayB, n))
		printf("역 삽입 정렬 : %0.3f초\n", (end - start) / (double)CLOCKS_PER_SEC);
	else
		printf("역 삽입 정렬 오류! 정렬되지 않았습니다.\n");
		
	printf("\n");
	

	free(arrayA);
	free(arrayB);

}