
/**
* @author �鼺��
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>


// �� ���

// �� �����Ҵ�

void* malloc_s(size_t size);

// �� ���� �˰���

/**
* ���� ����
* 
* @param array : �迭
* @param n : �׸� ��
*/
void selectSort(double* array, int n);

/**
* ���� ����
*
* @param array : �迭
* @param n : �׸� ��
*/
void insertSort(double* array, int n);

/**
* ���� ����
*
* @param array : �迭
* @param n : �׸� ��
*/
void quickSort(double* array, int n);

// �� ���� �˻�

/**
* �迭�� ���ĵǾ����� �˻��մϴ�.
* 
* @param array : �迭
* @param n : �迭�� ����
* @return ���ĵǾ����� 1, �ƴϸ� 0
*/
int sortCheck(double* array, int n);

// �� �迭 ����

/**
* �־��� �迭�� ���Ǵ�� �����մϴ�.
* 
* @param mode : 0 - ����, 1 - �������� ���� ����, 2 - �������� ���� ����
* @param output : ������� �迭
* @param base : ���� �迭
* @param n : �迭�� ����
*/
void arrayCopy(int mode, double* output, double* base, int n);

// �� main

int main() {


	printf("�� �̻� ���α׷��� �����մϴ�.\n�����Ϸ��� �ƹ� ���ڳ� �Է� : ");
	int final_exit_answer;
	scanf_s("%d", &final_exit_answer);

	return 0;
}

// �� ������

void* malloc_s(size_t size) {
	void* tmp = malloc(size);
	if (!tmp) {
		fprintf(stderr,"Out Of Memory\n");
		exit(1);
	}
	return tmp;
}
