
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
	int data;
	struct node* lchild;
	struct node* rchild;
}node;

// ���뿬�Ḯ��Ʈ
node* avail = NULL;

/**
* �� ��带 �����Ͽ� ��ȯ�մϴ�.
* 
* @param data : �� ��尡 ���� ��
* @return ������ ����� ������
*/
node* get_node(int data);

/**
* �Էµ� ��带 ��ȯ�մϴ�.
* 
* @param remove_node : ��ȯ�� ���
*/
void ret_node(node* remove_node);

// �� Ʈ�� ���� �Լ�

/**
* �׽�Ʈ�� Ʈ���� �����մϴ�.
* 
* @return ������ Ʈ���� ��Ʈ��� ������
*/
node* make_tree_by_code();

/**
* �������� ��� Ʈ���� �������� �����մϴ�.
* 
* @param n : Ʈ���� ���� ���� ���� (1���� n������ ������ Ʈ���� ����ϴ�.)
* @return ������ Ʈ���� ��Ʈ��� ������
*/
node* make_auto_tree(int n);

// �� Ʈ�� ��ȸ �Լ�

/**
* Ʈ���� ���� ��ȸ�Ͽ� Ʈ���� ����մϴ�.
* 
* @param root : ����� Ʈ���� ��Ʈ��� ������
*/
void inorder(node* root);

/**
* Ʈ���� ���� ��ȸ�Ͽ� Ʈ���� ����մϴ�.
*
* @param root : ����� Ʈ���� ��Ʈ��� ������
*/
void preorder(node* root);

/**
* Ʈ���� ���� ��ȸ�Ͽ� Ʈ���� ����մϴ�.
*
* @param root : ����� Ʈ���� ��Ʈ��� ������
*/
void postorder(node* root);

/**
* �־��� Ʈ���� ����, ����, ���� ��ȸ�Ͽ� ����մϴ�.
* 
* @param tree : ����� Ʈ���� ��Ʈ��� ������
*/
void print_tree(node* tree);

// �� Ʈ�� ���� �Լ�

/**
* �Էµ� Ʈ���� ���� �����Ͽ� ��ȯ�մϴ�.
* 
* @param root : ������ ���� Ʈ���� ��Ʈ��� ������
* @return ����� Ʈ���� ��Ʈ��� ������
*/
node* copy(node* root);

/**
* �� Ʈ���� �Է¹޾� �������� �˻��մϴ�.
* 
* @param A : ù��° �Է�Ʈ���� ��Ʈ��� ������
* @param B : �ι�° �Է�Ʈ���� ��Ʈ��� ������
* @return ������ ���� : ������ 1, �ٸ��� 0
*/
int equal(node* A, node* B);

/**
* �Էµ� Ʈ���� ���� �����ϵ�, �¿� �����Ͽ� ��ȯ�մϴ�.
*
* @param root : �¿� �������� ������ ���� Ʈ���� ��Ʈ��� ������
* @return �¿� �����Ǿ� ����� Ʈ���� ��Ʈ��� ������
*/
node* swap(node* root);



// �� main

int main() {

	printf("1. ��ȸ �˰��� �׽�Ʈ�� �մϴ�.\n");
	node* testNode1 = make_tree_by_code();
	print_tree(testNode1);
	printf("\n\n");

	printf("2. ���� �˰��� �׽�Ʈ�� �մϴ�.\n");
	printf("����� Ʈ���� ��ȸ ��� : \n");
	node* testNode2 = copy(testNode1);
	print_tree(testNode2);
	printf("\n\n");

	printf("3. ���ϼ� �˻� �˰��� �׽�Ʈ�� �մϴ�.\n");
	printf("����� Ʈ���� ���� Ʈ���� ������ : %s\n",(equal(testNode1,testNode2))?("true") : ("false"));
	testNode2->data = 2;
	printf("��Ʈ��尪�� 2�� �ٲپ����� ��� : %s\n", (equal(testNode1, testNode2)) ? ("true") : ("false"));
	testNode2->data = testNode1->data;
	testNode2->lchild->data = 9;
	printf("��Ʈ�� ���� �ڽĳ�尪�� 9�� �ٲپ����� ��� : %s\n", (equal(testNode1, testNode2)) ? ("true") : ("false"));
	printf("\n\n");

	printf("4. swap �˰��� �׽�Ʈ�� �մϴ�.\n");
	printf("swap�� Ʈ���� ��ȸ ��� : \n");
	node* testNode3 = swap(testNode1);
	print_tree(testNode3);
	printf("\n\n");

	printf("5. Ʈ�� �ڵ����� �˰��� �׽�Ʈ�� �մϴ�.\n");
	printf("9���� �������� �����ϴ� Ʈ�� ������ : \n");
	node* testNode4 = make_auto_tree(9);
	print_tree(testNode4);
	printf("\n\n");

	return 0;
}



// �� ������

node* get_node(int data) {

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
	// ������ Ʈ���� ����Ʈ��.
	// ���̴� 3, �� ��� ���� 5��.
	// ��Ʈ��尡 2���� �ڽ��� ������, ��Ʈ����� ���� �ڽĳ�尡 �ٽ� 2���� �ڽ��� ������.
	node* root = get_node(5);
	root->lchild = get_node(3);
	root->rchild = get_node(8);

	root->lchild->lchild = get_node(1);
	root->lchild->rchild = get_node(4);

	return root;
}

node* make_auto_tree(int n) {

	srand(time(NULL));

	// ��Ʈ���� 1�� ����
	node* newTree = get_node(1);

	// nodePtr�� Ư�� ��带 ����Ű�� ��������� ������ �������̸�,
	// �̰��� �� ���� ����� �θ����� lchild ���� Ȥ�� rchild ������ ����Ŵ���ν� ���������մϴ�.
	node** nodePtr;

	// Ʈ���� ��带 �����Ͽ� ������ ���ڵ�(2~n) ����
	for (int i = 2; i <= n; i++) {
		// 1. ��Ʈ���κ��� ��尡 �� ���� ��ġ���� ��������
		nodePtr = &newTree;
		do {
			// �������� ���� �̾�,
			// ¦���̸� ���� ����� ������ �ڽĹ��⿡ ������ ���߸�,
			// Ȧ���̸� ���� ����� ���� �ڽĹ��⿡ ������ �����.
			if (rand()%2)
				nodePtr = &((*nodePtr)->rchild);
			else
				nodePtr = &((*nodePtr)->lchild);
		} while (*nodePtr != NULL);

		// 2. ��尡 �� ���� ��ġ�� �� ��带 �����ϰ� ������ ����
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
	printf("���� ��ȸ : ");
	inorder(tree);
	printf("\n");
	printf("���� ��ȸ : ");
	preorder(tree);
	printf("\n");
	printf("���� ��ȸ : ");
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