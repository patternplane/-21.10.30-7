
/**
* @author �鼺��
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// �� ���

// �� ��� ����ü ���� �� ���Ḯ��Ʈ ����

typedef struct node {
	int key;
	double value;
	struct node* lchild;
	struct node* rchild;
}node;

// ���뿬�Ḯ��Ʈ
node* avail = NULL;

/**
* �� ��带 �����Ͽ� ��ȯ�մϴ�.
* 
* @param key : �� ��尡 ���� Ű
* @param data : �� ��尡 ���� ��
* @return ������ ����� ������. ���� �ڽĳ�带 NULL�� �����ϴ�.
*/
node* get_node(int key, double data);

/**
* �Էµ� ��带 ��ȯ�մϴ�.
* 
* @param remove_node : ��ȯ�� ���
*/
void ret_node(node* remove_node);

// �� ���� Ž�� Ʈ�� ���� �Լ�

/**
* ���� Ž�� Ʈ������ Ű�� (�ش� Ű�� ����Ű�� �����͸� ����)������ ã���ϴ�.
* 
* @param tree �˻��� ���� Ž�� Ʈ���� ��Ʈ��� ������
* @param key ã�� Ű ��
* @return key�� ����Ű�� �����͸� ���� ������ ������. 
* ������ NULL�� ��ȯ�մϴ�.
*/
double* search(node* tree, int key);

/**
* ���� Ž�� Ʈ���� ���ο� ���� �߰��մϴ�.
* 
* @param tree ���� �߰��� ���� Ž�� Ʈ���� ����Ű�� ��������� ������ �ּ�
* @param key �߰��� ����� Ű
* @param value �߰��� ����� ��
*/
void insert(node** tree, int key, double value);

/**
* ���� Ž�� Ʈ������ Ư�� ��带 �����մϴ�.
*
* @param tree ��带 ������ ���� Ž�� Ʈ���� ��Ʈ��� ������ ������ �ּ�
* @param key ������ ����� key��
*/
void withdraw(node** tree, int key);

/**
* ������ n���� ���� ����Ž��Ʈ���� �����Ͽ� ��ȯ�մϴ�.
* 
* @param n ������ ���� ����
* @return ������ ����Ž��Ʈ���� ��Ʈ��� ������
*/
node* make_bst(int n);

/**
* �־��� key���� ���� ��带 �߰��� �� �ִ� �θ��带 ã���ϴ�.
* 
* @param root ��带 �߰��� Ʈ��
* @param key �߰��� ����� key��
* @return �ش� ��带 ���� �� �ִ� ���. key�� ��ġ�ų� root��尡 ��� �߰��� �� ���ٸ� NULL�� ��ȯ�մϴ�.
*/
node* modified_search(node* root, int key);

// �� Ʈ�� ���� �Լ�

/**
* �־��� Ʈ���� �����մϴ�.
* 
* @param tree : ���� Ʈ���� ��Ʈ��带 ����Ű�� ������ ������ �ּ�
*/
void delete_tree(node* tree);

// �� Ʈ�� ��ȸ �Լ�

/**
* Ʈ���� ���� ��ȸ�Ͽ� Ʈ���� ����մϴ�.
* 
* @param root : ����� Ʈ���� ��Ʈ��� ������
*/
void inorder(node* root);

// �� Ʈ�� ���� �Լ�

/**
* Ʈ���� ��� ���� ���մϴ�.
* 
* @param tree ��� ���� ���� Ʈ���� ��Ʈ��� ������
* @return Ʈ���� ��� ��
*/
int get_node_count(node* tree);

/**
* Ʈ���� ���̸� ���մϴ�.
* 
* @param tree ���̸� ���� Ʈ���� ��Ʈ��� ������
* @return Ʈ���� ����
*/
int get_height(node* tree);

/**
* Ʈ���� ��������� ���� ���մϴ�.
* 
* @param tree ������� ���� ���� Ʈ���� ��Ʈ��� ������
* @return Ʈ���� ������� ��
*/
int get_leaf_count(node* tree);

// �� Ʈ�� ��� �Լ�

/**
* Ʈ���� �ð������� ����մϴ�.
* 
* @param tree : ����� Ʈ���� ��Ʈ��� ������
*/
void show_tree(node* tree);


// �� main
int search_count;

int main() {
	srand(time(NULL));

	// make_bst�� ����ð� ����
	printf("�� make_bst�Լ��� ����ð��� �����մϴ� : \n");
	int test_nums[5] = { 100,1000,10000,100000,1000000 };
	clock_t start, end;
	node* tmp;
	for (int i = 0; i < 5; i++) {
		start = clock();
		tmp = make_bst(test_nums[i]);
		end = clock();
		printf("%7d�� ����� Ʈ�� �����ð� : %f\n", test_nums[i], (end - start) / (double)CLOCKS_PER_SEC);
		printf("��� �� : %d\n", get_node_count(tmp));
		printf("���� : %d\n", get_height(tmp));
		printf("�ܸ���� �� : %d\n", get_leaf_count(tmp));
		delete_tree(tmp);
	}
	printf("\n\n");

	// Ʈ���� ����
	printf("�� Ʈ���� �����մϴ�.\n\n");
	node* tree = NULL;
	int nums[10] = {5,3,8,1,9,2,7,10,6,4};
	for (int i = 0; i < 10; i++)
		insert(&tree,nums[i],1.0/nums[i]);
	show_tree(tree);
	printf("\n\n");

	// inorder ��ȸ
	printf("�� inorder ��ȸ ��� : \n");
	inorder(tree);
	printf("\n");

	// search�Լ� ����ϱ�
	int key;
	printf("�� ã�� �������� key���� �Է��ϼ��� : ");
	scanf_s("%d",&key);
	search_count = 0;
	double* result = search(tree, key);
	if (result == NULL)
		printf("�� �׸��� �����ϴ�. (�Լ� ȣ�� Ƚ�� : %d)\n",search_count);
	else
		printf("�� %dŰ�� ���� �����ʹ� %f�Դϴ�. (�Լ� ȣ�� Ƚ�� : %d)\n",key,*search(tree,key),search_count);
	printf("\n");

	// Ʈ���� �߰� ����
	printf("�� ��� �� : %d\n", get_node_count(tree));
	printf("�� ���� : %d\n", get_height(tree));
	printf("�� �ܸ���� �� : %d\n", get_leaf_count(tree));
	printf("\n");

	// Ʈ������ ��� ����
	printf("�� ������ �������� key���� �Է��ϼ��� : ");
	scanf_s("%d", &key);
	withdraw(&tree, key);
	printf("�� ������� : \n");
	inorder(tree);

	printf("\n\n�� �̻� ���α׷��� �����մϴ�.\n�����Ϸ��� �ƹ� ���ڳ� �Է� : ");
	int final_exit_answer;
	scanf_s("%d", &final_exit_answer);

	return 0;
}



// �� ������

node* get_node(int key, double data) {

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
* �� �����Լ� (withdraw)
* Ư�� Ű���� ��带 ����Ű�� ��������� ������ �ּҸ� ��ȯ�մϴ�.
* 
* @param tree Ʈ���� ��Ʈ��带 ����Ű�� �����ͺ����� �ּ�
* @param key ã�� ����� Ű��
* @return ã������ ��带 ����Ű�� ��������� ������ �ּ�
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
	node** current_node = search_node_byKey(tree,key); // ���� ��带 ����Ű�� ��������� ������ ã���ϴ�.
	if (!current_node)
		return;

	node* toBeRemoved = *current_node; // ���� ��带 ����صӴϴ�.

	node** takedNode; // �� �ڸ��� ä�� ��带 ����ų �����ͺ����� �ּ�
	node* tmp;
	// 1. ���� �ڽ�Ʈ���� �ִ밪 ���� ���ڸ��� ä�� ���
	if ((*current_node)->lchild) {
		// �ִ밪 ��带 ã��
		for (takedNode = &((*current_node)->lchild); (*takedNode)->rchild; takedNode = &((*takedNode)->rchild));

		// �ش� ��带 �� �ڸ����� ���� ��
		tmp = *takedNode;
		*takedNode = (*takedNode)->lchild;
		
		// ���ڸ��� ��带 ä���ݴϴ�.
		tmp->lchild = (*current_node)->lchild;
		tmp->rchild = (*current_node)->rchild;
		*current_node = tmp;
	}
	// 2. ������ �ڽ�Ʈ���� �ּҰ� ���� ���ڸ��� ä�� ���
	else if ((*current_node)->rchild) {
		// �ּҰ� ��带 ã��
		for (takedNode = &((*current_node)->rchild); (*takedNode)->lchild; takedNode = &((*takedNode)->lchild));

		// �ش� ��带 �� �ڸ����� ���� ��
		tmp = *takedNode;
		*takedNode = (*takedNode)->rchild;

		// ���ڸ��� ��带 ä���ݴϴ�.
		tmp->lchild = (*current_node)->lchild;
		tmp->rchild = (*current_node)->rchild;
		*current_node = tmp;
	}
	// 3. �ڽ�Ʈ���� ��� �� ����� �Ǵ� ���
	else {
		*current_node = NULL;
	}

	// ������� �ߴ� ��带 ����ϴ�.
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
		if (ptr->key == key) // ������ �����ϴ� Ű�� �Է�: �ߺ� ����
			return NULL;
		if (key < ptr->key) {
			if (ptr->lchild == NULL) return ptr; // �θ� ��ȯ
			else ptr = ptr->lchild;
		}
		else { // key > ptr->data
			if (ptr->rchild == NULL) return ptr; // �θ� ��ȯ
			else ptr = ptr->rchild;
		}
	}
	return NULL; // root�� NULL�� ���
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

// show_tree �Լ� ������ ���� �ڷᱸ���� ���� :
typedef struct struct_blank_data {
	unsigned short* data; // ���� ������ ��Ʈ�� �������� �������� ���θ� ��Ÿ����, ������ 15��Ʈ�� ������ ���̸� ��Ÿ���ϴ�.
	int len; // ���� ����
	int top; // ������� �ֻ��� �ε���
} blank_data;

// ���������� �����մϴ�.
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

// ���������� �߰� �� �����մϴ�.
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
* �� �����Լ� (show_tree)
* ����� �������� ������ݴϴ�.
*
* @param blank_num : �̸� �տ� ����� �ϴ� ������ ��
* @param blank_data : ���鵥���� ����ü
* @param �����ڸ��������� 15��Ʈ���� ����Ѵ�.
*/
void print_tree_blank(int blank_num, blank_data* blank_data) {
	printf(" ");

	for (int i = 0; i < blank_num; i++) {
		if ((blank_data->data)[i] % 2) { // �������� �׾�� �Ѵٸ�
			int j = 0;
			for (; j < (blank_data->data)[i] / 2 / 2; j++) // "(blank_data->data)[i] / 2" �� "������ ����"
				printf(" ");
			printf("|");
			j++;
			for (; j < (blank_data->data)[i] / 2; j++)
				printf(" ");

			printf(" ");
		}
		else { // ������ �ʿ���ٸ�
			for (int j = 0; j < (blank_data->data)[i] / 2; j++)
				printf(" ");

			printf(" ");
		}
	}
}

// ���� ���ð� ���� �Լ�

int stack_len;
node** stack;
int top;

void push(node* data) {
	++top;

	// ���� ���� ������ ���Ҵ�
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

// ��� ������ �ӽ����� ����
char* buffer;
int buffer_size;

/**
* �� �����Լ� (show_tree)
* show_tree�� �����ϱ� ���� ����� �Լ�
* 
* @param pre_blank : �̸� �տ� ����� ���� + ������ ���� ����
* @param blank_info : ���� ó������ ������ ���� ����ü�� ������
* @param tree : ����� Ʈ���� ��Ʈ��� ������
*/
void show_tree_r(int pre_blank, blank_data* blank_info, node* tree) {
	
	// Ư�� ����� ������ �ڽ��� ���������� ����ϰ�,
	// ���� �ڽ��� �Ʒ��� ����Ѵ�.

	int stack_start = top + 1;

	// �̸� �տ� ����� ����� �����ٵ� ���
	print_tree_blank(pre_blank, blank_info);
	
	// ������ �ڽĵ� ��� �� �������� �߰�
	int blank_start_index = pre_blank;
	do {
		// �ڽ� ���
		sprintf_s(buffer, buffer_size,"(%d, %f)", tree->key, tree->value);
		printf("%s", buffer);
		push(tree);

		// �������� �߰�
		blank_modify(blank_start_index++, blank_info, strlen(buffer), ((tree->lchild)?1:0));

		tree = tree->rchild;
		if (tree == NULL)
			break;

		printf("-");
	} while (true);
	printf("\n");

	// ��� ���ƺ� �� ������ �ڽĵ鸶�� ���� �ڽĵ� ���
	node* child;
	while ((child = pop(stack_start)) != NULL) {
		if (child->lchild) {
			// ���� �ڽ��� ����ϱ� ���� �������� ������ ������ֱ�
			// "top - stack_start"�� �Ϲ����� ���ÿ��� top�� �����ϴ�. ���������� ����ϱ� ������ �̷��� ǥ����.
			// top�� +1�� ���ִ� ������, pop�� �Ͽ� child�� �������� ������ top�� 1��ŭ �������� ����.
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