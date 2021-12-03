
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
