
/**
* @author �鼺��
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>


// �� ���

// �� ���

// bool
#define TRUE 1
#define FALSE 0

// �׷����� ����ġ �ִ밪
#define COST_MAX 100000

// �� �����Ҵ�

void* malloc_s(size_t size);

// �� �׷��� ����

/**
* ����� �Է��� �޾� �׷����� �����մϴ�.
* 
* @param node_count : �׷����� ��� ��
* @return ������ �׷����� ǥ���� ���� ��� �迭
*/
int** make_graph(int node_count);

// �� �ִܰ�� ã��

/**
* Ư�� ���κ��� �ٸ� ������ �ִܰ�θ� ã���ϴ�.
* 
* @param v : ���� ���
* @param cost : ���� ���� (����ġ)
* @param n : �� ��� ��
* @return �ִ� ��θ� ����� �迭
*/
int* shortestPath(int v, int** cost, int n);

/**
* �ִܰ�ΰ� Ȯ������ ���� ��� �� ����� ����� �ּ��� ��带 ã���ϴ�.
* 
* @param found : ��庰�� �ִܰ�ΰ� Ȯ���Ǿ����� ���� ��� �迭
* @param distance : ������� ��ϵ� ��庰 �ִܰ��
* @param n : �� ��� ��
* @return ���
*/
int choose(short* found, int* distance, int n);

/**
* ��� ���鿡 ���� �ٸ� ������� �ִ� ��θ� ã���ϴ�.
* 
* @param cost : ���� ���� (����ġ)
* @param n : �� ��� ��
* @return ��庰 �ִ� ��θ� ����� �迭
*/
int** allCosts(int** cost, int n);

// �� main

int main() {

	int n, start_v;
	printf("�� ���� ��������� �ִ� ��θ� ã���ϴ�.\n");
	printf("��� �� : ");
	scanf_s("%d",&n);
	int** graph = make_graph(n);
	printf("�� ���� ��� : ");
	scanf_s("%d",&start_v);
	int* distance = shortestPath(start_v, graph, n);
	for (int i = 0; i < n; i++) {
		if (distance[i] == COST_MAX)
			printf("�� ");
		else
			printf("%d ", distance[i]);
	}
	printf("\n\n");

	printf("�� ��� ������� ���� �ִ� ��θ� ã���ϴ�.\n");
	int** distance_all = allCosts(graph, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (distance_all[i][j] == COST_MAX)
				printf("�� ");
			else
				printf("%d ", distance_all[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	// �� �����Ҵ� �����ϱ�

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

int** make_graph(int node_count) {
	// �׷����� �����Ͽ� �ʱ�ȭ
	int** graph = (int**)malloc_s(node_count*sizeof(int*));
	for (int i = 0; i < node_count; i++) {
		graph[i] = (int*)malloc_s(node_count * sizeof(int));
		for (int j = 0; j < node_count; j++)
			graph[i][j] = ((i == j)?0:COST_MAX); // �ڱ� �ڽſ��� ���ư��� cost�� �Ϲ������� 0, �� �ܿ��� ���� ������ �����Ƿ� �ķ� ����
	}

	// ���� ������ �Է¹���
	int start, end, cost;
	printf("�� (���� ����, ���� ����, ����ġ)�� �Է��ϼ���.\n�����Ϸ��� -1 -1 -1�� �Է�.\n");
	while (true) {
		scanf_s("%d %d %d",&start, &end, &cost);

		if (start == -1 || end == -1 || cost == -1) // �����Ȳ
			break;
		if (start < 0 || start >= node_count || end < 0 || end >= node_count) { // �߸��� ���� ����
			printf("���� ��ȣ�� �߸��Ǿ����ϴ�, Ȯ�����ּ���.\n");
			continue;
		}
		if (cost < 0) { // �߸��� ����ġ ����
			printf("����ġ ���� �߸��Ǿ����ϴ�, Ȯ�����ּ���.\n");
			continue;
		}

		graph[start][end] = cost;
	}

	return graph;
}

int* shortestPath(int v, int** cost, int n) {
	int* distance = (int*)malloc_s(n*sizeof(int));
	short* found = (short*)malloc_s(n * sizeof(short));
	for (int i = 0; i < n; i++){
		distance[i] = cost[v][i];
		found[i] = FALSE;
	}
	found[v] = TRUE;
	int u;
	for (int i = 0; i < n - 2; i++) {
		if ((u = choose(found, distance, n)) == -1)
			break;
		found[u] = TRUE;
		for (int w = 0; w < n; w++)
			if (!found[w])
				if (distance[u] + cost[u][w] < distance[w])
					distance[w] = distance[u] + cost[u][w];
	}
	return distance;
}

int choose(short* found, int* distance, int n) {
	int min_i = -1;
	int min = COST_MAX;
	for (int i = 0; i < n; i++)
		if (!found[i] && distance[i] < min) {
			min_i = i;
			min = distance[i];
		}
	return min_i;
}

int** allCosts(int** cost, int n) {
	int** distance = (int**)malloc_s(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		distance[i] = (int*)malloc_s(n * sizeof(int));
		for (int j = 0; j < n; j++)
			distance[i][j] = cost[i][j];
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (distance[i][k] + distance[k][j] < distance[i][j])
					distance[i][j] = distance[i][k] + distance[k][j];

	return distance;
}