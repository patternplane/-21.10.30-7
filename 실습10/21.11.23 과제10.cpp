
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

node** make_graph() {

	printf("새 그래프를 생성합니다.\n");
	printf("노드의 수와 에지들을 입력하세요.\n");

	int node_count, v1, v2;
	scanf_s("%d", &node_count);
	node** graph = (node**)calloc(node_count, sizeof(node*));
	if (graph == NULL) {
		fprintf(stderr,"메모리 공간 할당 실패\n");
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
		// 현재 노드의 차수를 구합니다.
		nodePtr = graph[i];
		degree_cnt = 0;
		while (nodePtr != NULL) {
			degree_cnt++;
			nodePtr = nodePtr->next;
		}

		// 큰 값인지 확인하여 기록합니다.
		if (degree < degree_cnt) {
			max_node = i;
			degree = degree_cnt;
		}
	}

	// 결과 출력
	printf("노드 %d이 최대 차수 %d을 가집니다.\n",max_node, degree);
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
		fprintf(stderr, "메모리 공간 할당 실패\n");
		exit(1);
	}

	node* nodePtr;
	for (int current_node = root_node;;) {
		// 노드를 출력한다
		printf("%d ", current_node);
		visit[current_node] = true;
		if (graph[current_node] == NULL) // 만약 연결이 끊어졌으면 종료
			break;
		
		// 다음 처리해야 하는 노드를 찾는다.
		nodePtr = graph[current_node];
		while (nodePtr != NULL && !visit[nodePtr->data]) // 방문하지 않은 인접노드를 찾는다.
			nodePtr = nodePtr->next;
		if (nodePtr == NULL) { // 방문하지 않은 인접노드가 없으면서
			if (top == -1) // 더 이상 처리할 것이 남아있지 않으면 종료
				break;
			nodePtr = stack[top--]->next; // 처리할 노드가 남았다면 스택 pop의 다음노드로 가기
		}

		// 다음 처리해야 하는 노드를 push 후 다시 DFS 처리
		if (nodePtr->next != NULL) // (굳이 마지막 노드이면 다시 돌아와 처리할 필요 없으므로 스택에 넣지 않는다.)
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
		fprintf(stderr, "메모리 공간 할당 실패\n");
		exit(1);
	}

	node* nodePtr;

	// 루트노드를 출력하면서 큐에 기입
	printf("%d ", root_node);
	visit[root_node] = true;
	rear = (rear + 1) % queueSize; // Queue Add
	queue[rear] = graph[root_node];

	for (int current_node;front != rear;) {
		// 큐에서 한 노드를 꺼내어 다시 처리
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
		fprintf(stderr, "메모리 공간 할당 실패\n");
		exit(1);
	}

	node* nodePtr;
	for (int current_node = root_node;;) {
		// 노드 방문
		visit[current_node] = true;
		if (graph[current_node] == NULL) // 만약 연결이 끊어졌으면 종료
			break;

		// 다음 처리해야 하는 노드를 찾는다.
		nodePtr = graph[current_node];
		while (nodePtr != NULL && !visit[nodePtr->data]) // 방문하지 않은 인접노드를 찾는다.
			nodePtr = nodePtr->next;
		if (nodePtr == NULL) { // 방문하지 않은 인접노드가 없으면서
			if (top == -1) // 더 이상 처리할 것이 남아있지 않으면 종료
				break;
			nodePtr = stack[top--]->next; // 처리할 노드가 남았다면 스택 pop의 다음노드로 가기
		}
		else // 방문하지 않은 인접노드가 발견되었다면 에지 출력
			printf("(%d, %d) ", current_node, nodePtr->data);

		// 다음 처리해야 하는 노드를 push 후 다시 DFS 처리
		if (nodePtr->next != NULL) // (굳이 마지막 노드이면 다시 돌아와 처리할 필요 없으므로 스택에 넣지 않는다.)
			stack[++top] = nodePtr;
		current_node = nodePtr->data;
	}

	free(visit);
	free(stack);
}
