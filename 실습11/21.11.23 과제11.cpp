
/**
* @author 백성수
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>


// ■ 헤더

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

	printf("■ 이상 프로그램을 종료합니다.\n진행하려면 아무 숫자나 입력 : ");
	int final_exit_answer;
	scanf_s("%d", &final_exit_answer);

	return 0;
}

// ■ 구현부
