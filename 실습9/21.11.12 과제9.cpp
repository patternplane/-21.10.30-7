
/**
* @author 백성수
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// ■ 헤더

// ● 노드 구조체 정의 및 연결리스트 연산

typedef struct node {
	int key;
	double value;
	struct node* lchild;
	struct node* rchild;
}node;

// 가용연결리스트
node* avail = NULL;

/**
* 새 노드를 생성하여 반환합니다.
* 
* @param key : 새 노드가 가질 키
* @param data : 새 노드가 가질 값
* @return 생성된 노드의 포인터
*/
node* get_node(int key, double data);

/**
* 입력된 노드를 반환합니다.
* 
* @param remove_node : 반환될 노드
*/
void ret_node(node* remove_node);

// ● 이진 탐색 트리 조작 함수

/**
* 이진 탐색 트리에서 키로 (해당 키가 가리키는 데이터를 담은)변수를 찾습니다.
* 
* @param tree 검색할 이진 탐색 트리의 루트노드 포인터
* @param key 찾을 키 값
* @return key가 가리키는 데이터를 담은 변수의 포인터. 
* 없으면 NULL을 반환합니다.
*/
double* search(node* tree, int key);

/**
* 이진 탐색 트리에 새로운 값을 추가합니다.
* 
* @param tree 값을 추가할 이진 탐색 트리를 가리키는 노드포인터 변수의 주소
* @param key 추가할 노드의 키
* @param value 추가할 노드의 값
*/
void insert(node** tree, int key, double value);

/**
* 이진 탐색 트리에서 특정 노드를 삭제합니다.
*
* @param tree 노드를 삭제할 이진 탐색 트리
* @param key 삭제할 노드의 key값
*/
void withdraw(node* tree, int key);

/**
* 랜덤한 n개의 값을 이진탐색트리로 구성하여 반환합니다.
* 
* @param n 생성할 값의 갯수
* @return 생성된 이진탐색트리의 루트노드 포인터
*/
node* make_bst(int n);

/**
* 주어진 key값을 가진 노드를 추가할 수 있는 부모노드를 찾습니다.
* 
* @param root 노드를 추가할 트리
* @param key 추가할 노드의 key값
* @return 해당 노드를 붙일 수 있는 노드. key가 겹치거나 root노드가 없어서 추가할 수 없다면 NULL을 반환합니다.
*/
node* modified_search(node* root, int key);

// ● 트리 제거 함수

/**
* 주어진 트리를 제거합니다.
* 
* @param tree : 지울 트리의 루트노드를 가리키는 포인터 변수의 주소
*/
void delete_tree(node* tree);

// ● 트리 순회 함수

/**
* 트리를 중위 순회하여 트리를 출력합니다.
* 
* @param root : 출력할 트리의 루트노드 포인터
*/
void inorder(node* root);

// ● 트리 연산 함수

/**
* 트리의 노드 수를 구합니다.
* 
* @param tree 노드 수를 구할 트리의 루트노드 포인터
* @return 트리의 노드 수
*/
int get_node_count(node* tree);

/**
* 트리의 높이를 구합니다.
* 
* @param tree 높이를 구할 트리의 루트노드 포인터
* @return 트리의 높이
*/
int get_height(node* tree);

/**
* 트리의 리프노드의 수를 구합니다.
* 
* @param tree 리프노드 수를 구할 트리의 루트노드 포인터
* @return 트리의 리프노드 수
*/
int get_leaf_count(node* tree);

// ● 트리 출력 함수

/**
* 트리를 시각적으로 출력합니다.
* 
* @param tree : 출력할 트리의 루트노드 포인터
*/
void show_tree(node* tree);


// ■ main

int main() {


	printf("이상 프로그램을 종료합니다.\n진행하려면 아무 숫자나 입력 : ");
	int final_exit_answer;
	scanf_s("%d", &final_exit_answer);

	return 0;
}



// ■ 구현부

node* get_node(int key, double data) {

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

	tmp->key = key;
	tmp->value = data;
	tmp->lchild = NULL;
	tmp->rchild = NULL;
	return tmp;
}

void ret_node(node* remove_node) {

	if (remove_node == NULL)
		return;

	remove_node->value = 0.0;
	remove_node->key = 0;
	remove_node->lchild = avail;
	remove_node->rchild = NULL;

	avail = remove_node;
}

void delete_tree(node* tree) {
	if (tree != NULL) {
		delete_tree(tree->lchild);
		delete_tree(tree->rchild);
		ret_node(tree);
	}
}

void inorder(node* root) {
	if (root != NULL) {
		inorder(root->lchild);
		printf("(%d, %f)",root->key, root->value);
		inorder(root->rchild);
	}
}

typedef char boolean;

struct blank_data {
	boolean has_line;
	short blank_len;
};

/**
* ○ 보조함수 (show_tree)
* show_tree를 구현할때 사용하는 공백과 세로줄 추가 문자
*
* @param pre_blank : 미리 앞에 띄워야 하는 공백 / 세로줄 총 갯수
* @param blank_bitmap : 15개 칸 중 어떤 칸에 세로줄을 그어야 하는지 정보를 16비트 플래그로 담아둔 정수
* @param 작은자리에서부터 15비트만을 사용한다.
*/
void print_tree_blank(int pre_blank, short blank_bitmap) {
	printf(" ");

	for (int i = 0; i < pre_blank; i++) {
		if ((blank_bitmap >> i) %2)
			printf("| ");
		else
			printf("  ");
	}
}

/**
* ○ 보조함수 (show_tree)
* show_tree를 구현하기 위한 재귀적 함수
* 
* @param pre_blank : 미리 앞에 띄워둘 공백 + 세로줄 묶음 갯수
* @param blank_bitmap : 15개 칸 중 어떤 칸에 세로줄을 그어야 하는지 정보를 16비트 플래그로 담아둔 정수
* @param tree : 출력할 트리의 루트노드 포인터
*/
void show_tree_r(int pre_blank,short blank_bitmap, node* tree) {
	
	// 특정 노드의 오른쪽 자식은 오른쪽으로 출력하고,
	// 왼쪽 자식은 아래로 출력한다.

	node* stack[15];
	int top = -1;

	// 미리 앞에 띄워둘 공백과 세로줄들 출력
	print_tree_blank(pre_blank, blank_bitmap);
	
	// 오른쪽 자식들 출력
	// "항목-항목"의 출력 규격을 맞추기 위해 가장 첫 항목은 "-"문자를 빼고 출력
	printf("%d", tree->key);
	// push
	stack[++top] = tree;
	tree = tree->rchild;
	// 나머지 항목은 "-항목" 형태로 출력
	for (; tree != NULL; tree = tree->rchild) {
		printf("-%d", tree->key);
		
		// push
		if (top == 15) {
			printf("show_tree : stack over\n");
			exit(1);
		}
		stack[++top] = tree;
	}
	printf("\n");

	// 오른쪽 자식들을 돌아보면서 추가로 체크해야 할 플래그들 기록하기
	for (int i = 0; i <= top; i++) {
		// 만약 왼쪽 자식을 가진 노드라면 플래그 세우고,
		// 그렇지 않다면 플래그 내림
		if (stack[i]->lchild != NULL)
			blank_bitmap |= (1 << (i + pre_blank));
		else
			blank_bitmap ^= (blank_bitmap & (1 << (i + pre_blank)));
	}

	// 방금 오른쪽으로 돌아본 각 자식들마다 왼쪽 자식들 출력
	while (top != -1) {
		if (stack[top]->lchild != NULL) {
			// 왼쪽 자식을 출력하기 전에 보기좋게 세로줄 출력해주기
			print_tree_blank(pre_blank + top+1, blank_bitmap);
			printf("\n");

			show_tree_r(pre_blank + top, blank_bitmap, stack[top]->lchild);
		}
		
		top--;
	}
}

void show_tree(node* tree) {
	
	if (tree == NULL)
		return;

	show_tree_r(0,0,tree);

}