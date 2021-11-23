
/**
* @author �鼺��
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>


// �� ���

// �� ��� ����ü ���� �� ���Ḯ��Ʈ ����

typedef struct struct_node {
	int data;
	struct struct_node* next;
}node;

// ���뿬�Ḯ��Ʈ
node* avail = NULL;

/**
* �� ��带 �����Ͽ� ��ȯ�մϴ�.
* 
* @param node_num : �� ��尡 ���� ����ȣ
*/
node* get_node(int node_num);

/**
* �Էµ� ��带 ��ȯ�մϴ�.
* 
* @param remove_node : ��ȯ�� ���
*/
void ret_node(node* remove_node);

// �� �׷��� ����

/**
* ����� �Է��� �޾� �׷����� �����մϴ�.
* 
* @return ������ �׷����� ǥ���� ���Ḯ��Ʈ �迭
*/
node** make_graph();

// �� �׷��� ����

/**
* ���� ������ ���� ��带 ã��, �ش� ���� ������ ������ ����մϴ�.
* 
* @param graph : �׷���
* @param node_count : ����� ��
*/
void print_maxDegreeNode(node* graph[],int node_count);

/**
* �׷����� DFS ��ȸ�մϴ�.
* 
* @param graph : �׷���
* @param node_count : ����� ��
* @param root_node : ���� Ʈ���� ��Ʈ��� ��ȣ
*/
void DFS(node* graph[], int node_count, int root_node);

/**
* �׷����� BFS ��ȸ�մϴ�.
*
* @param graph : �׷���
* @param node_count : ����� ��
* @param root_node : ���� Ʈ���� ��Ʈ��� ��ȣ
*/
void BFS(node* graph[], int node_count, int root_node);

/**
* �׷������� DFS ���� Ʈ���� ã�� ����մϴ�.
*
* @param graph : �׷���
* @param node_count : ����� ��
* @param root_node : ���� Ʈ���� ��Ʈ��� ��ȣ
*/
void print_spanningTree(node* graph[], int node_count, int root_node);


// �� main

int main() {
	


	printf("\n\n�� �̻� ���α׷��� �����մϴ�.\n�����Ϸ��� �ƹ� ���ڳ� �Է� : ");
	int final_exit_answer;
	scanf_s("%d", &final_exit_answer);

	return 0;
}



// �� ������

node* get_node(int node_num) {

	node* tmp;

	if (avail == NULL) {
		tmp = (node*)malloc(sizeof(node));
		if (tmp == NULL) {
			printf("�޸� ������ �Ҵ��� �� �����ϴ�.\n");
			exit(1);
		}
	}
	else {
		tmp = avail;
		avail = avail->next;
	}

	tmp->data = node_num;
	tmp->next = NULL;
	return tmp;
}

void ret_node(node* remove_node) {

	if (remove_node == NULL)
		return;

	remove_node->data = -1;
	remove_node->next = avail;

	avail = remove_node;
}

node** make_graph() {

	printf("�� �׷����� �����մϴ�.\n");
	printf("����� ���� �������� �Է��ϼ���.\n");

	int node_count, v1, v2;
	scanf_s("%d", &node_count);
	node** graph = (node**)calloc(node_count, sizeof(node*));
	if (graph == NULL) {
		fprintf(stderr,"�޸� ���� �Ҵ� ����\n");
		exit(1);
	}

	node* new_node;
	while (true) {
		scanf_s("%d %d", &v1, &v2);
		if (v1 == -1 || v2 == -1)
			break;

		new_node = get_node(v2);
		new_node->next = graph[v1];
		graph[v1] = new_node;
	}

	return graph;
}

void print_maxDegreeNode(node* graph[], int node_count) {
	int max_node = 0;
	int degree = 0;
	node* nodePtr;
	for (int i = 0,degree_cnt; i < node_count; i++) {
		// ���� ����� ������ ���մϴ�.
		nodePtr = graph[i];
		degree_cnt = 0;
		while (nodePtr != NULL) {
			degree_cnt++;
			nodePtr = nodePtr->next;
		}

		// ū ������ Ȯ���Ͽ� ����մϴ�.
		if (degree < degree_cnt) {
			max_node = i;
			degree = degree_cnt;
		}
	}

	// ��� ���
	printf("��� %d�� �ִ� ���� %d�� �����ϴ�.\n",max_node, degree);
	for (nodePtr = graph[max_node]; nodePtr != NULL; nodePtr = nodePtr->next) 
		printf("%d->",nodePtr->data);
	printf("\n");
}

typedef char boolean;

void DFS(node* graph[], int node_count, int root_node) {
	boolean* visit = (boolean*)calloc(node_count, sizeof(boolean));
	node** stack = (node**)malloc(node_count * sizeof(node*));
	int top = -1;
	if (visit == NULL || stack == NULL) {
		fprintf(stderr, "�޸� ���� �Ҵ� ����\n");
		exit(1);
	}

	node* nodePtr;
	for (int current_node = root_node;;) {
		// ��带 ����Ѵ�
		printf("%d ", current_node);
		visit[current_node] = true;
		if (graph[current_node] == NULL) // ���� ������ ���������� ����
			break;
		
		// ���� ó���ؾ� �ϴ� ��带 ã�´�.
		nodePtr = graph[current_node];
		while (nodePtr != NULL && !visit[nodePtr->data]) // �湮���� ���� ������带 ã�´�.
			nodePtr = nodePtr->next;
		if (nodePtr == NULL) { // �湮���� ���� ������尡 �����鼭
			if (top == -1) // �� �̻� ó���� ���� �������� ������ ����
				break;
			nodePtr = stack[top--]->next; // ó���� ��尡 ���Ҵٸ� ���� pop�� �������� ����
		}

		// ���� ó���ؾ� �ϴ� ��带 push �� �ٽ� DFS ó��
		if (nodePtr->next != NULL) // (���� ������ ����̸� �ٽ� ���ƿ� ó���� �ʿ� �����Ƿ� ���ÿ� ���� �ʴ´�.)
			stack[++top] = nodePtr;
		current_node = nodePtr->data;
	}

	free(visit);
	free(stack);
}

void BFS(node* graph[], int node_count, int root_node) {
	boolean* visit = (boolean*)calloc(node_count, sizeof(boolean));
	int queueSize = node_count + 1;
	node** queue = (node**)malloc(queueSize * sizeof(node*));
	int front = 0, rear = 0;
	if (visit == NULL || queue == NULL) {
		fprintf(stderr, "�޸� ���� �Ҵ� ����\n");
		exit(1);
	}

	node* nodePtr;

	// ��Ʈ��带 ����ϸ鼭 ť�� ����
	printf("%d ", root_node);
	visit[root_node] = true;
	rear = (rear + 1) % queueSize; // Queue Add
	queue[rear] = graph[root_node];

	for (int current_node;front != rear;) {
		// ť���� �� ��带 ������ �ٽ� ó��
		front = (front + 1) % queueSize; // Queue Delete
		current_node = queue[rear]->data;
		for (nodePtr = graph[current_node]; nodePtr != NULL; nodePtr = nodePtr->next) 
			if (!visit[nodePtr->data]) {
				printf("%d ", nodePtr->data);
				visit[nodePtr->data] = true;
				rear = (rear + 1) % queueSize; // Queue Add
				queue[rear] = nodePtr;
			}
	}

	free(visit);
	free(queue);
}

void print_spanningTree(node* graph[], int node_count, int root_node) {
	boolean* visit = (boolean*)calloc(node_count, sizeof(boolean));
	node** stack = (node**)malloc(node_count * sizeof(node*));
	int top = -1;
	if (visit == NULL || stack == NULL) {
		fprintf(stderr, "�޸� ���� �Ҵ� ����\n");
		exit(1);
	}

	node* nodePtr;
	for (int current_node = root_node;;) {
		// ��� �湮
		visit[current_node] = true;
		if (graph[current_node] == NULL) // ���� ������ ���������� ����
			break;

		// ���� ó���ؾ� �ϴ� ��带 ã�´�.
		nodePtr = graph[current_node];
		while (nodePtr != NULL && !visit[nodePtr->data]) // �湮���� ���� ������带 ã�´�.
			nodePtr = nodePtr->next;
		if (nodePtr == NULL) { // �湮���� ���� ������尡 �����鼭
			if (top == -1) // �� �̻� ó���� ���� �������� ������ ����
				break;
			nodePtr = stack[top--]->next; // ó���� ��尡 ���Ҵٸ� ���� pop�� �������� ����
		}
		else // �湮���� ���� ������尡 �߰ߵǾ��ٸ� ���� ���
			printf("(%d, %d) ", current_node, nodePtr->data);

		// ���� ó���ؾ� �ϴ� ��带 push �� �ٽ� DFS ó��
		if (nodePtr->next != NULL) // (���� ������ ����̸� �ٽ� ���ƿ� ó���� �ʿ� �����Ƿ� ���ÿ� ���� �ʴ´�.)
			stack[++top] = nodePtr;
		current_node = nodePtr->data;
	}

	free(visit);
	free(stack);
}
