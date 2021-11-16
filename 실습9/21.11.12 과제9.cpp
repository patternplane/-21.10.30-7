
/**
* @author 백성수
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


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
* @return 생성된 노드의 포인터. 노드는 자식노드를 NULL로 가집니다.
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
* @param tree 노드를 삭제할 이진 탐색 트리의 루트노드 포인터 변수의 주소
* @param key 삭제할 노드의 key값
*/
void withdraw(node** tree, int key);

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
int search_count;

int main() {
	srand(time(NULL));

	// make_bst의 실행시간 측정
	printf("■ make_bst함수의 실행시간을 측정합니다 : \n");
	int test_nums[5] = { 100,1000,10000,100000,1000000 };
	clock_t start, end;
	node* tmp;
	for (int i = 0; i < 5; i++) {
		start = clock();
		tmp = make_bst(test_nums[i]);
		end = clock();
		printf("%7d개 노드의 트리 생성시간 : %f\n", test_nums[i], (end - start) / (double)CLOCKS_PER_SEC);
		printf("노드 수 : %d\n", get_node_count(tmp));
		printf("높이 : %d\n", get_height(tmp));
		printf("단말노드 수 : %d\n", get_leaf_count(tmp));
		delete_tree(tmp);
	}
	printf("\n\n");

	// 트리의 생성
	printf("■ 트리를 생성합니다.\n\n");
	node* tree = NULL;
	int nums[10] = {5,3,8,1,9,2,7,10,6,4};
	for (int i = 0; i < 10; i++)
		insert(&tree,nums[i],1.0/nums[i]);
	show_tree(tree);
	printf("\n\n");

	// inorder 순회
	printf("■ inorder 순회 결과 : \n");
	inorder(tree);
	printf("\n");

	// search함수 사용하기
	int key;
	printf("■ 찾을 데이터의 key값을 입력하세요 : ");
	scanf_s("%d",&key);
	search_count = 0;
	double* result = search(tree, key);
	if (result == NULL)
		printf("■ 항목이 없습니다. (함수 호출 횟수 : %d)\n",search_count);
	else
		printf("■ %d키에 대한 데이터는 %f입니다. (함수 호출 횟수 : %d)\n",key,*search(tree,key),search_count);
	printf("\n");

	// 트리의 추가 연산
	printf("■ 노드 수 : %d\n", get_node_count(tree));
	printf("■ 높이 : %d\n", get_height(tree));
	printf("■ 단말노드 수 : %d\n", get_leaf_count(tree));
	printf("\n");

	// 트리에서 노드 삭제
	printf("■ 삭제할 데이터의 key값을 입력하세요 : ");
	scanf_s("%d", &key);
	withdraw(&tree, key);
	printf("■ 삭제결과 : \n");
	inorder(tree);

	printf("\n\n■ 이상 프로그램을 종료합니다.\n진행하려면 아무 숫자나 입력 : ");
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

double* search(node* tree, int key) {
	search_count++;
	if (!tree) return NULL;
	if (key == tree->key) return &(tree->value);
	if (key < tree->key)
		return search(tree->lchild, key);
	return search(tree->rchild, key);
}

void insert(node** tree, int key, double value) {

	node* ptr, *temp = modified_search(*tree, key);
	if (temp || !(*tree)) {
		ptr = get_node(key, value);

		if (*tree) {
			if (key < temp->key) temp->lchild = ptr;
			else temp->rchild = ptr;
		}
		else *tree = ptr;
	}

}

/**
* ○ 보조함수 (withdraw)
* 특정 키값의 노드를 가리키는 노드포인터 변수의 주소를 반환합니다.
* 
* @param tree 트리의 루트노드를 가리키는 포인터변수의 주소
* @param key 찾을 노드의 키값
* @return 찾으려는 노드를 가리키는 노드포인터 변수의 주소
*/
node** search_node_byKey(node** tree, int key) {

	if (!(*tree))
		return NULL;

	else if ((*tree)->key == key)
		return tree;

	else if ((*tree)->key > key) 
		return search_node_byKey(&((*tree)->lchild),key);

	else // (*tree)->key < key
		return search_node_byKey(&((*tree)->rchild), key);
	
}

void withdraw(node** tree, int key) {
	node** current_node = search_node_byKey(tree,key); // 지울 노드를 가리키는 노드포인터 변수를 찾습니다.
	if (!current_node)
		return;

	node* toBeRemoved = *current_node; // 지울 노드를 기억해둡니다.

	node** takedNode; // 빈 자리를 채울 노드를 가리킬 포인터변수의 주소
	node* tmp;
	// 1. 왼쪽 자식트리의 최대값 노드로 빈자리를 채울 경우
	if ((*current_node)->lchild) {
		// 최대값 노드를 찾고
		for (takedNode = &((*current_node)->lchild); (*takedNode)->rchild; takedNode = &((*takedNode)->rchild));

		// 해당 노드를 그 자리에서 빼온 뒤
		tmp = *takedNode;
		*takedNode = (*takedNode)->lchild;
		
		// 빈자리에 노드를 채워줍니다.
		tmp->lchild = (*current_node)->lchild;
		tmp->rchild = (*current_node)->rchild;
		*current_node = tmp;
	}
	// 2. 오른쪽 자식트리의 최소값 노드로 빈자리를 채울 경우
	else if ((*current_node)->rchild) {
		// 최소값 노드를 찾고
		for (takedNode = &((*current_node)->rchild); (*takedNode)->lchild; takedNode = &((*takedNode)->lchild));

		// 해당 노드를 그 자리에서 빼온 뒤
		tmp = *takedNode;
		*takedNode = (*takedNode)->rchild;

		// 빈자리에 노드를 채워줍니다.
		tmp->lchild = (*current_node)->lchild;
		tmp->rchild = (*current_node)->rchild;
		*current_node = tmp;
	}
	// 3. 자식트리가 없어서 걍 지우면 되는 경우
	else {
		*current_node = NULL;
	}

	// 지우려고 했던 노드를 지웁니다.
	ret_node(toBeRemoved);
}

node* make_bst(int n) {
	node* tree = NULL;

	int key;
	double value;
	for (int i = 0; i < n; i++) {
		key = (int)(100000000 * ((double)rand() / (double)0x7fff));
		value = 1.0 / key;
		insert(&tree, key, value);
	}

	return tree;
}

node* modified_search(node* root, int key) {
	for (node* ptr = root; ptr != NULL; ) {
		if (ptr->key == key) // 기존에 존재하는 키를 입력: 중복 오류
			return NULL;
		if (key < ptr->key) {
			if (ptr->lchild == NULL) return ptr; // 부모를 반환
			else ptr = ptr->lchild;
		}
		else { // key > ptr->data
			if (ptr->rchild == NULL) return ptr; // 부모를 반환
			else ptr = ptr->rchild;
		}
	}
	return NULL; // root가 NULL일 경우
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
		printf("(%d, %f)\n",root->key, root->value);
		inorder(root->rchild);
	}
}

int get_node_count(node* tree) {
	if (!tree)
		return 0;
	
	return get_node_count(tree->lchild) + 1 + get_node_count(tree->rchild);
}

int get_height(node* tree) {
	if (!tree)
		return 0;

	int h1 = get_height(tree->lchild);
	int h2 = get_height(tree->rchild);

	return 1 + ((h1>h2)?h1:h2);
}

int get_leaf_count(node* tree) {

	if (!tree)
		return 0;

	else if (!tree->lchild && !tree->rchild)
		return 1;

	else 
		return get_leaf_count(tree->lchild) + get_leaf_count(tree->rchild);
}

// show_tree 함수 구현을 위한 자료구조와 연산 :
typedef struct struct_blank_data {
	unsigned short* data; // 가장 최하위 비트는 세로줄을 가지는지 여부를 나타내며, 나머지 15비트는 공백의 길이를 나타냅니다.
	int len; // 가용 길이
	int top; // 사용중인 최상위 인덱스
} blank_data;

// 공백정보를 생성합니다.
blank_data* make_blank_data() {
	blank_data* new_data = (blank_data*)malloc(sizeof(blank_data));
	if (new_data == NULL) {
		printf("out of memory");
		exit(1);
	}

	new_data->len = 10;
	new_data->data = (unsigned short*)malloc(new_data->len * sizeof(unsigned short));
	if (new_data->data == NULL) {
		printf("out of memory");
		exit(1);
	}
	new_data->top = -1;

	return new_data;
}

// 공백정보를 추가 및 수정합니다.
void blank_modify(int index, blank_data* data, unsigned short blank_len, char has_col) {
	if (data->top >= index)
		(data->data)[index] = (blank_len << 1) + has_col;

	else {
		++(data->top);

		if (data->top == data->len) {
			data->len += 10;
			unsigned short* tmp = (unsigned short*)realloc(data->data, data->len * sizeof(unsigned short));
			if (tmp == NULL) {
				printf("out of memory");
				exit(1);
			}
			data->data = tmp;
		}
		(data->data)[data->top] = (blank_len << 1) + has_col;
	}
}

/**
* ○ 보조함수 (show_tree)
* 공백과 세로줄을 출력해줍니다.
*
* @param blank_num : 미리 앞에 띄워야 하는 공백의 수
* @param blank_data : 공백데이터 구조체
* @param 작은자리에서부터 15비트만을 사용한다.
*/
void print_tree_blank(int blank_num, blank_data* blank_data) {
	printf(" ");

	for (int i = 0; i < blank_num; i++) {
		if ((blank_data->data)[i] % 2) { // 세로줄을 그어야 한다면
			int j = 0;
			for (; j < (blank_data->data)[i] / 2 / 2; j++) // "(blank_data->data)[i] / 2" 은 "공백의 길이"
				printf(" ");
			printf("|");
			j++;
			for (; j < (blank_data->data)[i] / 2; j++)
				printf(" ");

			printf(" ");
		}
		else { // 세로줄 필요없다면
			for (int j = 0; j < (blank_data->data)[i] / 2; j++)
				printf(" ");

			printf(" ");
		}
	}
}

// 공용 스택과 관리 함수

int stack_len;
node** stack;
int top;

void push(node* data) {
	++top;

	// 스택 공간 부족시 재할당
	if (stack_len == top) {
		stack_len += 500;
		node** tmp = (node**)realloc(*stack, (stack_len)*sizeof(node*));
		if (tmp == NULL) {
			printf("out of memory");
			exit(1);
		}
		stack = tmp;
	}

	stack[top] = data;
}

node* pop(int stack_start) {
	if (top - stack_start == -1)
		return NULL;

	return stack[top--];
}

// 출력 데이터 임시저장 버퍼
char* buffer;
int buffer_size;

/**
* ○ 보조함수 (show_tree)
* show_tree를 구현하기 위한 재귀적 함수
* 
* @param pre_blank : 미리 앞에 띄워둘 공백 + 세로줄 묶음 갯수
* @param blank_info : 공백 처리관련 정보를 담은 구조체의 포인터
* @param tree : 출력할 트리의 루트노드 포인터
*/
void show_tree_r(int pre_blank, blank_data* blank_info, node* tree) {
	
	// 특정 노드의 오른쪽 자식은 오른쪽으로 출력하고,
	// 왼쪽 자식은 아래로 출력한다.

	int stack_start = top + 1;

	// 미리 앞에 띄워둘 공백과 세로줄들 출력
	print_tree_blank(pre_blank, blank_info);
	
	// 오른쪽 자식들 출력 및 공백정보 추가
	int blank_start_index = pre_blank;
	do {
		// 자식 출력
		sprintf_s(buffer, buffer_size,"(%d, %f)", tree->key, tree->value);
		printf("%s", buffer);
		push(tree);

		// 공백정보 추가
		blank_modify(blank_start_index++, blank_info, strlen(buffer), ((tree->lchild)?1:0));

		tree = tree->rchild;
		if (tree == NULL)
			break;

		printf("-");
	} while (true);
	printf("\n");

	// 방금 돌아본 각 오른쪽 자식들마다 왼쪽 자식들 출력
	node* child;
	while ((child = pop(stack_start)) != NULL) {
		if (child->lchild) {
			// 왼쪽 자식을 출력하기 전에 보기좋게 세로줄 출력해주기
			// "top - stack_start"이 일반적인 스택에서 top과 동일하다. 공유스택을 사용하기 때문에 이렇게 표현됨.
			// top에 +1을 해주는 이유는, pop을 하여 child를 꺼내오기 때문에 top이 1만큼 적어지기 때문.
			print_tree_blank(pre_blank + (top - stack_start + 1) + 1, blank_info);
			printf("\n");

			show_tree_r(pre_blank + (top - stack_start +1), blank_info, child->lchild);
		}
	}
}

void show_tree(node* tree) {

	if (tree == NULL)
		return;

	buffer_size = 100;
	buffer = (char*)malloc(buffer_size * sizeof(char));
	if (buffer == NULL) {
		printf("out of memory");
		exit(1);
	}

	stack_len = 500;
	top = -1;
	stack = (node**)malloc(stack_len * sizeof(node*));
	if (stack == NULL) {
		printf("out of memory");
		exit(1);
	}

	blank_data* blank_info = make_blank_data();

	show_tree_r(0, blank_info,tree);

	free(blank_info->data);
	free(blank_info);
	free(buffer);
	free(stack);
}