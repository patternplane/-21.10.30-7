
/**
* @author �鼺��
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>


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




// �� main

int main() {

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