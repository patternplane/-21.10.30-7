// ���� 7���ʹ� github�� �ű�ϴ�.

/**
* @author �鼺��
* @studentId 22012070
*/

#include <stdlib.h>
#include <stdio.h>

// �� ���

// �� 1. ���� ���Ḯ��Ʈ�� �� ����

typedef struct polyNode {
	int expon;
	double coef;
	struct polyNode* next;
}polyNode;

/**
* Ư�� ��带 Ư�� ��������� ������ �ٿ��ݴϴ�.
* 
* @param nodePtr ��带 �̾���� ��� ������ ������ ������
* @param node ����Ʈ�� �̾���� ��带 ����Ű�� ������
*/
void list_attach(polyNode** nodePtr, polyNode* node);

// �� 2. ���뿬�Ḯ��Ʈ ����ҿ� �� ����

polyNode* avail = nullptr;

/**
* ���ο� ��带 �����Ͽ� ��ȯ�մϴ�.
* 
* @return ������ ����� ������
*/
polyNode* get_node();

/**
* Ư�� ��带 ���뿬�Ḯ��Ʈ�� ���Դϴ�.
* 
* @param node ���뿬�Ḯ��Ʈ�� ���� ��带 ����Ű�� ��� ������
*/
void ret_node(polyNode* node);

/**
* ���� ���Ḯ��Ʈ ��ü�� ���뿬�Ḯ��Ʈ�� ���Դϴ�.
* 
* @param list ���뿬�Ḯ��Ʈ�� ���� ����Ʈ�� ����Ű�� ��� ������ ������ ������
*/
void cerase(polyNode** list);

// �� 3. ���׽��� ����

/**
* ����� �Է��� �޾� ���׽��� �����Ͽ� ��ȯ�մϴ�.
* ����� �Է� �Ǽ��� ���� ������ ó������ �ʽ��ϴ�.
* 
* @param name ���׽��� �̸��� �Է¹޽��ϴ�. (������ null ����)
* @return ������ ���׽��� ����Ű�� ��� ������
*/
polyNode* create_polynomial(const char* name);

// �� 4. ���׽��� ����

/**
* �� ���׽��� ���� ���Ͽ� ��ȯ�մϴ�.
* 
* @param a, b ���� �ΰ��� ���׽��� ����Ű�� ��� ������
* @return ���׽��� ���� ����� ������ ���׽��� ����Ű�� ��� ������
*/
polyNode* cpadd(polyNode* a, polyNode* b);

/**
* ���׽��� �� �׿� �־��� ���� ���մϴ�.
* 
* @param poly ���׽��� ����Ű�� ��� ������
* @param singlePoly ���� �������� ����Ű�� ��� ����
*/
void single_mul(polyNode* poly, polyNode* singlePoly);

/**
* �� ���׽��� ��
* 
* @param a, b ������ �ΰ��� ���׽��� ����Ű�� ��� ������
* @return ���׽��� ���� ����� ������ ���׽��� ����Ű�� ��� ������
*/
polyNode* cpmul(polyNode* a, polyNode* b);

// �� 5. ���׽��� ���

/**
* ���׽��� ����մϴ�.
* 
* @param list ����� ���׽��� ����Ű�� ��Ʈ ������
*/
void print_polynomial(polyNode* list);



// �� �����Լ�

void main() {



}



// �� ������

void list_attach(polyNode** list, polyNode* node) {


	if (*list == nullptr) {
		node->next = node;
		*list = node;
	}
	else {
		node->next = (*list)->next;
		(*list)->next = node;
		*list = node;
	}

}

polyNode* get_node() {

	polyNode* tmp;

	if (avail == nullptr) {

		tmp = (polyNode*)malloc(sizeof(polyNode));
		if (tmp == nullptr) {
			fprintf(stderr,"�޸𸮰����� Ȯ���� �� �������ϴ�.\n");
			exit(1);
		}

	}
	else {

		tmp = avail;
		avail = avail->next;

	}

	return tmp;

}

void ret_node(polyNode* node) {

	node->next = avail;
	avail = node;
}

void cerase(polyNode** list) {

	polyNode* tmp = (*list)->next;
	(*list)->next = avail;
	avail = tmp;

	*list = nullptr;
}

polyNode* create_polynomial(const char* name) {

	const char* name_result;
	if (name == NULL)
		name_result = "UntitledPoly";

	int expon;
	double coef;

	polyNode** attach_pos;
	polyNode* newNode;

	polyNode* newPoly = (polyNode*)malloc(sizeof(polyNode));
	if (newPoly == nullptr) {
		fprintf(stderr, "�޸𸮰����� Ȯ���� �� �������ϴ�.\n");
		exit(1);
	}

	newPoly->next = newPoly;
	newPoly->expon = -1;
	newPoly->coef = -1.0;

	attach_pos = &(newPoly->next);
	while (true) {
		printf("%s(x) ���׽��� �Է��ϼ���.(��� ����) : ", name_result);
		scanf_s("%lf %d", &coef, &expon);

		if (expon < 0)
			break;

		newNode = get_node();
		newNode->expon = expon;
		newNode->coef = coef;

		list_attach(attach_pos, newNode);
		attach_pos = &((*attach_pos)->next); // �̿� ���� �ڵ� : attach_pos = &(newNode->next)
	}

}