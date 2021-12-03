
/**
* @author �鼺��
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// �� ���

// �� �����Ҵ�

void* malloc_s(size_t size);

// �� �Ǽ� �迭 ����

/**
* ���� �Ǽ� �迭�� �����մϴ�.
* 
* @param n : �迭�� ũ��
* @return �迭
*/
double* makeArray(int n);

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
* ����ͷ� �����Ǿ����ϴ�.
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
	srand(time(NULL));

	int n;
	printf("������ �迭�� ���� ���� �Է��ϼ��� : ");
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
		"1. �������� �迭�� �Ǽ����� ���� �ð� ����\n",
		"2. �������� �迭�� �Ǽ����� ���� �ð� ����\n",
		"3. �������� �迭�� �Ǽ����� ���� �ð� ����\n"
	};
	const char* sortName[3] = {
		"����",
		"����",
		"����"
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
				printf("%s ���� : %f��\n", sortName[j], (end - start) / (double)CLOCKS_PER_SEC);
			else
				printf("%s���� ����! ���ĵ��� �ʾҽ��ϴ�.\n", sortName[j]);
		}
		printf("\n");
	}

	printf("�� �̻� ���α׷��� �����մϴ�.\n�����Ϸ��� �ƹ� ���ڳ� �Է� : ");
	int final_exit_answer;
	scanf_s("%d", &final_exit_answer);

	free(arrayA);
	free(arrayB);
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