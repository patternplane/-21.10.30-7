
/**
* @author �鼺��
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
* @return ������ ����� ������
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
* @param tree ��带 ������ ���� Ž�� Ʈ��
* @param key ������ ����� key��
*/
void withdraw(node* tree, int key);

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

int main() {


	printf("�̻� ���α׷��� �����մϴ�.\n�����Ϸ��� �ƹ� ���ڳ� �Է� : ");
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
* �� �����Լ� (show_tree)
* show_tree�� �����Ҷ� ����ϴ� ����� ������ �߰� ����
*
* @param pre_blank : �̸� �տ� ����� �ϴ� ���� / ������ �� ����
* @param blank_bitmap : 15�� ĭ �� � ĭ�� �������� �׾�� �ϴ��� ������ 16��Ʈ �÷��׷� ��Ƶ� ����
* @param �����ڸ��������� 15��Ʈ���� ����Ѵ�.
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
* �� �����Լ� (show_tree)
* show_tree�� �����ϱ� ���� ����� �Լ�
* 
* @param pre_blank : �̸� �տ� ����� ���� + ������ ���� ����
* @param blank_bitmap : 15�� ĭ �� � ĭ�� �������� �׾�� �ϴ��� ������ 16��Ʈ �÷��׷� ��Ƶ� ����
* @param tree : ����� Ʈ���� ��Ʈ��� ������
*/
void show_tree_r(int pre_blank,short blank_bitmap, node* tree) {
	
	// Ư�� ����� ������ �ڽ��� ���������� ����ϰ�,
	// ���� �ڽ��� �Ʒ��� ����Ѵ�.

	node* stack[15];
	int top = -1;

	// �̸� �տ� ����� ����� �����ٵ� ���
	print_tree_blank(pre_blank, blank_bitmap);
	
	// ������ �ڽĵ� ���
	// "�׸�-�׸�"�� ��� �԰��� ���߱� ���� ���� ù �׸��� "-"���ڸ� ���� ���
	printf("%d", tree->key);
	// push
	stack[++top] = tree;
	tree = tree->rchild;
	// ������ �׸��� "-�׸�" ���·� ���
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

	// ������ �ڽĵ��� ���ƺ��鼭 �߰��� üũ�ؾ� �� �÷��׵� ����ϱ�
	for (int i = 0; i <= top; i++) {
		// ���� ���� �ڽ��� ���� ����� �÷��� �����,
		// �׷��� �ʴٸ� �÷��� ����
		if (stack[i]->lchild != NULL)
			blank_bitmap |= (1 << (i + pre_blank));
		else
			blank_bitmap ^= (blank_bitmap & (1 << (i + pre_blank)));
	}

	// ��� ���������� ���ƺ� �� �ڽĵ鸶�� ���� �ڽĵ� ���
	while (top != -1) {
		if (stack[top]->lchild != NULL) {
			// ���� �ڽ��� ����ϱ� ���� �������� ������ ������ֱ�
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