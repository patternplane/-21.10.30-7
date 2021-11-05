
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

/**
* 주어진 트리를 중위, 전위, 후위 순회하여 출력합니다.
* 
* @param tree : 출력할 트리의 루트노드 포인터
*/
void print_tree(node* tree);

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

/**
* 입력된 트리를 복사 생성하되, 좌우 반전하여 반환합니다.
*
* @param root : 좌우 반전으로 복사할 원본 트리의 루트노드 포인터
* @return 좌우 반전되어 복사된 트리의 루트노드 포인터
*/
node* swap(node* root);

// ● 트리 출력 함수

/**
* 트리를 시각적으로 출력합니다.
* 
* @param tree : 출력할 트리의 루트노드 포인터
*/
void show_tree(node* tree);


// ■ main

int main() {

	printf("1. 순회 알고리즘 테스트를 합니다.\n");
	node* testNode1 = make_tree_by_code();
	print_tree(testNode1);
	printf("\n\n");

	printf("2. 복사 알고리즘 테스트를 합니다.\n");
	printf("복사된 트리의 순회 결과 : \n");
	node* testNode2 = copy(testNode1);
	print_tree(testNode2);
	printf("\n\n");

	printf("3. 동일성 검사 알고리즘 테스트를 합니다.\n");
	printf("복사된 트리와 원본 트리는 같은가 : %s\n",(equal(testNode1,testNode2))?("true") : ("false"));
	testNode2->data = 2;
	printf("루트노드값을 2로 바꾸었을때 결과 : %s\n", (equal(testNode1, testNode2)) ? ("true") : ("false"));
	testNode2->data = testNode1->data;
	testNode2->lchild->data = 9;
	printf("루트의 왼쪽 자식노드값을 9로 바꾸었을때 결과 : %s\n", (equal(testNode1, testNode2)) ? ("true") : ("false"));
	printf("\n\n");

	printf("4. swap 알고리즘 테스트를 합니다.\n");
	printf("swap된 트리의 순회 결과 : \n");
	node* testNode3 = swap(testNode1);
	print_tree(testNode3);
	printf("\n\n");

	printf("5. 트리 자동생성 알고리즘 테스트를 합니다.\n");
	printf("9개의 정수값을 저장하는 트리 생성됨 : \n");
	node* testNode4 = make_auto_tree(9);
	print_tree(testNode4);
	printf("\n");

	printf("위 트리의 시각화 : \n(특정 노드에서 왼쪽은 부모, 오른쪽은 오른쪽 자식, 아래는 왼쪽 자식)\n");
	show_tree(testNode4);
	printf("\n\n");

	printf("이상 프로그램을 종료합니다.\n진행하려면 아무 숫자나 입력 : ");
	int final_exit_answer;
	scanf_s("%d", &final_exit_answer);

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

node* make_tree_by_code() {
	// 생성할 트리는 이진트리.
	// 깊이는 3, 총 노드 수는 5개.
	// 루트노드가 2개의 자식을 가지며, 루트노드의 좌측 자식노드가 다시 2개의 자식을 가진다.
	node* root = get_node(5);
	root->lchild = get_node(3);
	root->rchild = get_node(8);

	root->lchild->lchild = get_node(1);
	root->lchild->rchild = get_node(4);

	return root;
}

node* make_auto_tree(int n) {

	srand(time(NULL));

	// 루트노드는 1을 가짐
	node* newTree = get_node(1);

	// nodePtr은 특정 노드를 가리키는 노드포인터 변수의 포인터이며,
	// 이것은 곧 현재 노드의 부모노드의 lchild 변수 혹은 rchild 변수를 가리킴으로써 구현가능합니다.
	node** nodePtr;

	// 트리에 노드를 생성하여 나머지 숫자들(2~n) 기입
	for (int i = 2; i <= n; i++) {
		// 1. 루트노드로부터 노드가 안 붙은 위치까지 내려가기
		nodePtr = &newTree;
		do {
			// 랜덤으로 값을 뽑아,
			// 짝수이면 현재 노드의 오른쪽 자식방향에 집중을 맞추며,
			// 홀수이면 현재 노드의 왼쪽 자식방향에 집중을 맞춘다.
			if (rand()%2)
				nodePtr = &((*nodePtr)->rchild);
			else
				nodePtr = &((*nodePtr)->lchild);
		} while (*nodePtr != NULL);

		// 2. 노드가 안 붙은 위치에 새 노드를 생성하고 데이터 기입
		*nodePtr = get_node(i);
	}

	return newTree;
}

void inorder(node* root) {
	if (root != NULL) {
		inorder(root->lchild);
		printf("%d",root->data);
		inorder(root->rchild);
	}
}

void preorder(node* root) {
	if (root != NULL) {
		printf("%d", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void postorder(node* root) {
	if (root != NULL) {
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d", root->data);
	}
}

void print_tree(node* tree) {
	printf("중위 순회 : ");
	inorder(tree);
	printf("\n");
	printf("전위 순회 : ");
	preorder(tree);
	printf("\n");
	printf("후위 순회 : ");
	postorder(tree);
	printf("\n");
}

node* copy(node* root) {
	
	node* newNode;

	if (root != NULL) {
		newNode = get_node(root->data);
		newNode->lchild = copy(root->lchild);
		newNode->rchild = copy(root->rchild);
	}
	else {
		newNode = NULL;
	}

	return newNode;
}

int equal(node* A, node* B) {

	return ((!A && !B) || (A && B && (A->data == B->data) && equal(A->lchild, B->lchild) && equal(A->rchild, B->rchild)));

}

node* swap(node* root) {

	node* newNode;

	if (root != NULL) {
		newNode = get_node(root->data);
		newNode->lchild = swap(root->rchild);
		newNode->rchild = swap(root->lchild);
	}
	else {
		newNode = NULL;
	}

	return newNode;
}

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
	printf("%d", tree->data);
	// push
	stack[++top] = tree;
	tree = tree->rchild;
	// 나머지 항목은 "-항목" 형태로 출력
	for (; tree != NULL; tree = tree->rchild) {
		printf("-%d", tree->data);
		
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