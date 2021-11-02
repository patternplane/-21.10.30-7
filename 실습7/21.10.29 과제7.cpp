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
* @param node �̾���� ��带 ����Ű�� ������
*/
void list_attach(polyNode** nodePtr, polyNode* node);

/**
* �������Ḯ��Ʈ�� ó�� �����մϴ�.
* 
* @param listPtr ����Ʈ�� ����ų ��������� ������ �ּҰ�
* @param coef ������ ����� �����
* @param expon ������ ����� ������
*/
void makeC(polyNode** listPtr, double coef, int expon);

// �� 2. ���뿬�Ḯ��Ʈ ����ҿ� �� ����

polyNode* avail = NULL;

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
* ����Ʈ�� Ư�� ��ġ�� �� ���� �����Ͽ� �ٿ��ݴϴ�.
* 
* @param position ������ ���� �̾���� ��带 ����Ű�� ��������� ������ �ּҰ�
* position�� �ٽ� ���� ������ ��带 ����Ű���� ����˴ϴ�.
* @param coefficient ������ ���� ���
* @param expon ������ ���� ����
*/
void pAttach(polyNode** position, double coefficient, int expon);

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
* ���׽İ� �������� ���մϴ�.
* 
* @param poly ���׽��� ����Ű�� ��� ������
* @param singlePoly ���� �������� ����Ű�� ��� ����
* @return ������ ��� ���׽��� ����Ű�� ��������� ��ȯ
*/
polyNode* single_mul(polyNode* singlePoly, polyNode* poly);

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

	polyNode* A, * B, * C, * D;

	A = create_polynomial("A");
	printf("\n");
	B = create_polynomial("B");
	printf("\n");

	printf("���׽� A�� ���� ��� : \n");
	print_polynomial(A);
	printf("���׽� B�� ���� ��� : \n");
	print_polynomial(B);

	C = cpadd(A, B);
	printf("���׽��� �� ��� : \n");
	print_polynomial(C);

	D = cpmul(A, B);
	printf("���׽��� �� ��� : \n");
	print_polynomial(D);
}



// �� ������

void list_attach(polyNode** nodePtr, polyNode* node) {

	if (*nodePtr == NULL) 
		node->next = node;
	else 
		node->next = *nodePtr;

	*nodePtr = node;
}

void makeC(polyNode** listPtr, double coef, int expon) {
	
	polyNode* newNode;
	newNode = get_node();

	newNode->coef = coef;
	newNode->expon = expon;
	newNode->next = newNode;

	*listPtr = newNode;
	
}

polyNode* get_node() {

	polyNode* tmp;

	if (avail == NULL) {

		tmp = (polyNode*)malloc(sizeof(polyNode));
		if (tmp == NULL) {
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
	if (*list != NULL) {
		polyNode* tmp = (*list)->next;
		(*list)->next = avail;
		avail = tmp;

		*list = NULL;
	}
}

void pAttach(polyNode** position, double coefficient, int expon) {

	polyNode* newNode;

	newNode = get_node();
	newNode->expon = expon;
	newNode->coef = coefficient;

	list_attach(&((*position)->next), newNode);

	*position = newNode;
}

polyNode* create_polynomial(const char* name_input) {

	const char* name;
	if (name_input == NULL)
		name = "UntitledPoly";
	else
		name = name_input;

	int expon;
	double coef;

	polyNode** attach_pos;
	polyNode* newNode;

	polyNode* newPoly = (polyNode*)malloc(sizeof(polyNode));
	if (newPoly == NULL) {
		fprintf(stderr, "�޸𸮰����� Ȯ���� �� �������ϴ�.\n");
		exit(1);
	}

	newPoly->next = newPoly;
	newPoly->expon = -1;
	newPoly->coef = -1.0;

	attach_pos = &(newPoly->next);
	while (true) {
		printf("%s(x) ���׽��� �Է��ϼ���.(��� ����) : ", name);
		scanf_s("%lf %d", &coef, &expon);

		if (expon < 0)
			break;

		newNode = get_node();
		newNode->expon = expon;
		newNode->coef = coef;

		list_attach(attach_pos, newNode);
		attach_pos = &((*attach_pos)->next); // �̿� ���� �ڵ� : attach_pos = &(newNode->next)
	}

	return newPoly;
}

polyNode* cpadd(polyNode* a, polyNode* b) {

	polyNode* startA = a;
	polyNode* c, * cRear;

	makeC(&c, -1, -1);
	cRear = c;

	a = a->next;
	b = b->next;
	double sumOfCoef;
	while (a->expon != b->expon || a != startA) {
		if (a->expon > b->expon) {
			pAttach(&cRear, a->coef, a->expon);
			a = a->next;
		}
		else if (a->expon == b->expon) {
			sumOfCoef = a->coef + b->coef;

			if (sumOfCoef < -0.0001 || sumOfCoef > 0.0001) // coef�� �ռ��� 0�ΰ�? - ��Ȯ�� : 0.0001 �����϶� 0���� �Ǻ�
				pAttach(&cRear, sumOfCoef, a->expon);
			a = a->next;
			b = b->next;
		}
		else { // a->expon < b->expon
			pAttach(&cRear, b->coef, b->expon);
			b = b->next;
		}
	}

	return c;
}

polyNode* single_mul(polyNode* singlePoly, polyNode* poly) {
	
	polyNode* c, * cRear;
	makeC(&c, -1, -1);
	cRear = c;

	polyNode* current_poly = poly->next;
	while (current_poly != poly) {
		pAttach(&cRear,current_poly->coef * singlePoly->coef,current_poly->expon + singlePoly->expon);
		current_poly = current_poly->next;
	}

	return c;
}

polyNode* cpmul(polyNode* a, polyNode* b) {

	polyNode* c, * cRear;
	makeC(&c, -1, -1);
	cRear = c;

	polyNode* mul_poly, *add_poly;
	polyNode* current_a = a->next;
	while (current_a != a) {
		mul_poly = single_mul(current_a,b);
		add_poly = cpadd(c, mul_poly);
		cerase(&mul_poly);
		cerase(&c);
		c = add_poly;

		current_a = current_a->next;
	}

	return c;
}

void print_polynomial(polyNode* list) {

	polyNode* current_poly = list->next;
	polyNode* startNode = list;

	printf("�� ���׽��� ����մϴ� : \n");
	printf("   ���    |    ����    \n");
	while (current_poly != startNode) {
		printf("%10.3f | %5d\n", current_poly->coef, current_poly->expon);
		current_poly = current_poly->next;
	}
}
