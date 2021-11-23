
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
