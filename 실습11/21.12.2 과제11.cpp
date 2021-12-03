
/**
* @author 백성수
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>


// ■ 헤더

// ● 상수

// bool
#define TRUE 1
#define FALSE 0

// 그래프의 가중치 최대값
#define COST_MAX 100000

// ● 동적할당

void* malloc_s(size_t size);

// ● 그래프 생성

/**
* 사용자 입력을 받아 그래프를 생성합니다.
* 
* @param node_count : 그래프의 노드 수
* @return 생성된 그래프를 표현한 인접 행렬 배열
*/
int** make_graph(int node_count);

// ● 최단경로 찾기

/**
* 특정 노드로부터 다른 노드들의 최단경로를 찾습니다.
* 
* @param v : 시작 노드
* @param cost : 간선 정보 (가중치)
* @param n : 총 노드 수
* @return 최단 경로를 기록한 배열
*/
int* shortestPath(int v, int** cost, int n);

/**
* 최단경로가 확정되지 않은 노드 중 경로의 비용이 최소인 노드를 찾습니다.
* 
* @param found : 노드별로 최단경로가 확정되었는지 여부 기록 배열
* @param distance : 현재까지 기록된 노드별 최단경로
* @param n : 총 노드 수
* @return 노드
*/
int choose(short* found, int* distance, int n);

/**
* 모든 노드들에 대해 다른 노드들과의 최단 경로를 찾습니다.
* 
* @param cost : 간선 정보 (가중치)
* @param n : 총 노드 수
* @return 노드별 최단 경로를 기록한 배열
*/
int** allCosts(int** cost, int n);

// ■ main

int main() {

	int n, start_v;
	printf("■ 단일 출발점에서 최단 경로를 찾습니다.\n");
	printf("노드 수 : ");
	scanf_s("%d",&n);
	int** graph = make_graph(n);
	printf("■ 시작 노드 : ");
	scanf_s("%d",&start_v);
	int* distance = shortestPath(start_v, graph, n);
	for (int i = 0; i < n; i++) {
		if (distance[i] == COST_MAX)
			printf("∞ ");
		else
			printf("%d ", distance[i]);
	}
	printf("\n\n");

	printf("■ 모든 출발점에 대해 최단 경로를 찾습니다.\n");
	int** distance_all = allCosts(graph, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (distance_all[i][j] == COST_MAX)
				printf("∞ ");
			else
				printf("%d ", distance_all[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	// ■ 동적할당 해제하기

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

int** make_graph(int node_count) {
	// 그래프를 생성하여 초기화
	int** graph = (int**)malloc_s(node_count*sizeof(int*));
	for (int i = 0; i < node_count; i++) {
		graph[i] = (int*)malloc_s(node_count * sizeof(int));
		for (int j = 0; j < node_count; j++)
			graph[i][j] = ((i == j)?0:COST_MAX); // 자기 자신에게 돌아가는 cost는 일반적으로 0, 그 외에는 아직 간선이 없으므로 ∞로 설정
	}

	// 간선 정보를 입력받음
	int start, end, cost;
	printf("■ (시작 정점, 종료 정점, 가중치)를 입력하세요.\n종료하려면 -1 -1 -1을 입력.\n");
	while (true) {
		scanf_s("%d %d %d",&start, &end, &cost);

		if (start == -1 || end == -1 || cost == -1) // 종료상황
			break;
		if (start < 0 || start >= node_count || end < 0 || end >= node_count) { // 잘못된 정점 기입
			printf("정점 번호가 잘못되었습니다, 확인해주세요.\n");
			continue;
		}
		if (cost < 0) { // 잘못된 가중치 기입
			printf("가중치 값이 잘못되었습니다, 확인해주세요.\n");
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