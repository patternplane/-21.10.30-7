
/**
* @author �鼺��
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>


// �� ���

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

	printf("�� �̻� ���α׷��� �����մϴ�.\n�����Ϸ��� �ƹ� ���ڳ� �Է� : ");
	int final_exit_answer;
	scanf_s("%d", &final_exit_answer);

	return 0;
}

// �� ������
