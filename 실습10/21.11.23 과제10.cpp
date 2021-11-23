
/**
* @author �鼺��
* @studentId
*/

#include <stdio.h>
#include <stdlib.h>


// �� ���

// �� ��� ����ü ���� �� ���Ḯ��Ʈ ����

typedef struct struct_node {
	int node_num;
	struct struct_node* next;
}node;

// ���뿬�Ḯ��Ʈ
node* avail = NULL;

/**
* �� ��带 �����Ͽ� ��ȯ�մϴ�.
* 
* @param node_num : �� ��尡 ���� ����ȣ
*/
node* get_node(int node_num);

/**
* �Էµ� ��带 ��ȯ�մϴ�.
* 
* @param remove_node : ��ȯ�� ���
*/
void ret_node(node* remove_node);




// �� main

int main() {
	


	printf("\n\n�� �̻� ���α׷��� �����մϴ�.\n�����Ϸ��� �ƹ� ���ڳ� �Է� : ");
	int final_exit_answer;
	scanf_s("%d", &final_exit_answer);

	return 0;
}



// �� ������

node* get_node(int node_num) {

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
		avail = avail->next;
	}

	tmp->node_num = node_num;
	tmp->next = NULL;
	return tmp;
}

void ret_node(node* remove_node) {

	if (remove_node == NULL)
		return;

	remove_node->node_num = -1;
	remove_node->next = avail;

	avail = remove_node;
}
