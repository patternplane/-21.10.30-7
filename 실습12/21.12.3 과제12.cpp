
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

// �� �׽�Ʈ �Լ�

/**
* n���� �Ǽ��� �����Ͽ� �� ���ľ˰����� �ð� ����
*/
void test1();

/**
* �� ���� �˰��� �ð����⵵ ����
*/
void test2();

/**
* test3 �����Լ� : ���� ���� ������ �¿����
* 
* @param array : �迭
* @param n : �׸� ��
*/
void insertSort_invers(double* array, int n);

/**
* �����Ŀ� ���� ���Ĺ�� �׽�Ʈ
*/
void test3();

// �� main

int main() {
	srand(time(NULL));

	int testMode;
	printf("����� �׽�Ʈ�� �Է��ϼ���.\n");
	printf("1 : �Է¹��� n���� �Ǽ��� ���� ���� �˰����� �ð��� �����մϴ�.\n");
	printf("2 : n�� ũ�⸦ Ű������ �˰��� �ð����⵵�� �����մϴ�.\n");
	printf("3 : ���������� ���� �� ���� ���� �˰����� �ð����⵵�� �����մϴ�.\n");
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
		printf("�߸��� �׽�Ʈ ��ȣ\n");
	}
	printf("\n");

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
	"����",
	"����",
	"����"
};
const char* arrayMode[3] = {
	"������",
	"��������",
	"��������"
};

void test1() {

	int n;
	printf("������ �迭�� ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &n);
	printf("\n");

	double* arrayA = makeArray(n);
	double* arrayB = (double*)malloc_s(n * sizeof(double));

	clock_t start, end;
	for (int i = 0; i < 3; i++) {
		printf("%d. %s �迭�� �Ǽ����� ���� �ð� ����\n",i+1, arrayMode[i]);
		for (int j = 0; j < 3; j++) {
			arrayCopy(i, arrayB, arrayA, n);
			start = clock();
			(sortAlgorithm[j])(arrayB, n);
			end = clock();
			if (sortCheck(arrayB, n))
				printf("%s ���� : %0.3f��\n", sortName[j], (end - start) / (double)CLOCKS_PER_SEC);
			else
				printf("%s���� ����! ���ĵ��� �ʾҽ��ϴ�.\n", sortName[j]);
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
		"1. �������� �˰����� �ð����⵵\n",
		"2. �������� �˰����� �ð����⵵\n",
		"3. �������� �迭�� �Ǽ����� ���� �ð� ����\n"
	};
	clock_t start, end;
	for (int i = 0; i < 3; i++) {
		printf("%d. %s���� �˰����� �ð����⵵\n",i+1,sortName[i]);
		for (int j = 0; j < 3; j++) {
			printf("%d. %s �迭�϶�\n",j+1, arrayMode[j]);
			for (int k = 0; k < testCase_len; k++) {
				arrayCopy(j, arrayB, arrayA, testCase[k]);
				start = clock();
				(sortAlgorithm[i])(arrayB, testCase[k]);
				end = clock();
				if (sortCheck(arrayB, testCase[k]))
					printf("%s ���� | %7d�� : %0.3f��\n", sortName[i], testCase[k], (end - start) / (double)CLOCKS_PER_SEC);
				else
					printf("%s���� ����! ���ĵ��� �ʾҽ��ϴ�.\n", sortName[i]);
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
	printf("������ �迭�� ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &n);
	printf("\n");

	double* arrayA = makeArray(n);
	double* arrayB = (double*)malloc_s(n * sizeof(double));

	clock_t start, end;
	printf("%d�� �������� �Ǽ����� �� ���� �����ϴ� �ð� ����\n",n);
		
	arrayCopy(2, arrayB, arrayA, n);
	start = clock();
	insertSort_invers(arrayB, n);
	end = clock();
	if (sortCheck(arrayB, n))
		printf("�� ���� ���� : %0.3f��\n", (end - start) / (double)CLOCKS_PER_SEC);
	else
		printf("�� ���� ���� ����! ���ĵ��� �ʾҽ��ϴ�.\n");
		
	printf("\n");
	

	free(arrayA);
	free(arrayB);

}