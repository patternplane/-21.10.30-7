
/**
* @author 백성수
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>


// ■ 헤더

// ● 노드 구조체 정의 및 연결리스트 연산

typedef struct struct_node {
	int data;
	struct struct_node* next;
}node;

// 가용연결리스트
node* avail = NULL;

/**
* 새 노드를 생성하여 반환합니다.
* 
* @param node_num : 새 노드가 가질 노드번호
*/
node* get_node(int node_num);

/**
* 입력된 노드를 반환합니다.
* 
* @param remove_node : 반환될 노드
*/
void ret_node(node* remove_node);

// ● 그래프 생성

/**
* 사용자 입력을 받아 그래프를 생성합니다.
* 
* @return 생성된 그래프를 표현한 연결리스트 배열
*/
node** make_graph();

// ● 그래프 연산

/**
* 가장 차수가 높은 노드를 찾고, 해당 노드와 인접한 노드들을 출력합니다.
* 
* @param graph : 그래프
* @param node_count : 노드의 수
*/
void print_maxDegreeNode(node* graph[],int node_count);

/**
* 그래프를 DFS 순회합니다.
* 
* @param graph : 그래프
* @param node_count : 노드의 수
* @param root_node : 신장 트리의 루트노드 번호
*/
void DFS(node* graph[], int node_count, int root_node);

/**
* 그래프를 BFS 순회합니다.
*
* @param graph : 그래프
* @param node_count : 노드의 수
* @param root_node : 신장 트리의 루트노드 번호
*/
void BFS(node* graph[], int node_count, int root_node);

/**
* 그래프에서 DFS 신장 트리를 찾아 출력합니다.
*
* @param graph : 그래프
* @param node_count : 노드의 수
* @param root_node : 신장 트리의 루트노드 번호
*/
void print_spanningTree(node* graph[], int node_count, int root_node);


// ■ main

int main() {
	


	printf("\n\n■ 이상 프로그램을 종료합니다.\n진행하려면 아무 숫자나 입력 : ");
	int final_exit_answer;
	scanf_s("%d", &final_exit_answer);

	return 0;
}



// ■ 구현부

node* get_node(int node_num) {

	node* tmp;

	if (avail == NULL) {
		tmp = (node*)malloc(sizeof(node));
		if (tmp == NULL) {
			printf("메모리 공간을 할당할 수 없습니다.\n");
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
