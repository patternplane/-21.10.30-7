
/**
* @author 백성수
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>


// ■ 헤더

// ● 노드 구조체 정의 및 연결리스트 연산

typedef struct node {
	int data;
	struct node* lchild;
	struct node* rchild;
}node;

// 가용연결리스트
node* avail = NULL;

/**
* 새 노드를 생성하여 반환합니다.
* 
* @param data : 새 노드가 가질 값
* @return 생성된 노드의 포인터
*/
node* get_node(int data);

/**
* 입력된 노드를 반환합니다.
* 
* @param remove_node : 반환될 노드
*/
void ret_node(node* remove_node);

// ● 트리 생성 함수

/**
* 테스트용 트리를 생성합니다.
* 
* @return 생성된 트리의 루트노드 포인터
*/
node* make_tree_by_code();

/**
* 정수값을 담는 트리를 무작위로 생성합니다.
* 
* @param n : 트리가 담을 값의 범위 (1부터 n까지의 값들을 트리에 담습니다.)
* @return 생성된 트리의 루트노드 포인터
*/
node* make_auto_tree(int n);

// ● 트리 순회 함수

/**
* 트리를 중위 순회하여 트리를 출력합니다.
* 
* @param root : 출력할 트리의 루트노드 포인터
*/
void inorder(node* root);

/**
* 트리를 전위 순회하여 트리를 출력합니다.
*
* @param root : 출력할 트리의 루트노드 포인터
*/
void preorder(node* root);

/**
* 트리를 후위 순회하여 트리를 출력합니다.
*
* @param root : 출력할 트리의 루트노드 포인터
*/
void postorder(node* root);

// ● 트리 연산 함수

/**
* 입력된 트리를 복사 생성하여 반환합니다.
* 
* @param root : 복사할 원본 트리의 루트노드 포인터
* @return 복사된 트리의 루트노드 포인터
*/
node* copy(node* root);

/**
* 두 트리를 입력받아 동일한지 검사합니다.
* 
* @param A : 첫번째 입력트리의 루트노드 포인터
* @param B : 두번째 입력트리의 루트노드 포인터
* @return 같은지 여부 : 같으면 1, 다르면 0
*/
int equal(node* A, node* B);




// ■ main

int main() {

	return 0;
}



// ■ 구현부

node* get_node(int data) {

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
		avail = avail->lchild;
	}

	tmp->data = data;
	tmp->lchild = NULL;
	tmp->rchild = NULL;
	return tmp;
}

void ret_node(node* remove_node) {

	if (remove_node == NULL)
		return;

	remove_node->data = 0;
	remove_node->lchild = avail;
	remove_node->rchild = NULL;

	avail = remove_node;
}