// 과제 7부터는 github로 옮깁니다.

/**
* @author 백성수
* @studentId 22012070
*/

#include <stdlib.h>
#include <stdio.h>

// ■ 헤더

// ● 1. 원형 연결리스트와 그 연산

typedef struct polyNode {
	int expon;
	double coef;
	struct polyNode* next;
}polyNode;

/**
* 특정 노드를 특정 노드포인터 변수에 붙여줍니다.
*
* @param nodePtr 노드를 이어붙일 노드 포인터 변수의 포인터
* @param node 이어붙일 노드를 가리키는 포인터
*/
void list_attach(polyNode** nodePtr, polyNode* node);

/**
* 원형연결리스트를 처음 생성합니다.
* 
* @param listPtr 리스트를 가리킬 노드포인터 변수의 주소값
* @param coef 생성할 노드의 계수값
* @param expon 생성할 노드의 지수값
*/
void makeC(polyNode** listPtr, double coef, int expon);

// ● 2. 가용연결리스트 저장소와 그 연산

polyNode* avail = NULL;

/**
* 새로운 노드를 생성하여 반환합니다.
* 
* @return 생성된 노드의 포인터
*/
polyNode* get_node();

/**
* 특정 노드를 가용연결리스트에 붙입니다.
* 
* @param node 가용연결리스트에 붙일 노드를 가리키는 노드 포인터
*/
void ret_node(polyNode* node);

/**
* 원형 연결리스트 전체를 가용연결리스트에 붙입니다.
* 
* @param list 가용연결리스트에 붙일 리스트를 가리키는 노드 포인터 변수의 포인터
*/
void cerase(polyNode** list);

// ● 3. 다항식의 생성

/**
* 리스트의 특정 위치에 새 항을 생성하여 붙여줍니다.
* 
* @param position 생성된 항을 이어붙일 노드를 가리키는 노드포인터 변수의 주소값
* position은 다시 새로 생성된 노드를 가리키도록 변경됩니다.
* @param coefficient 생성할 항의 계수
* @param expon 생성할 항의 지수
*/
void pAttach(polyNode** position, double coefficient, int expon);

/**
* 사용자 입력을 받아 다항식을 생성하여 반환합니다.
* 사용자 입력 실수에 관한 오류는 처리하지 않습니다.
* 
* @param name 다항식의 이름을 입력받습니다. (비우려면 null 기입)
* @return 생성된 다항식을 가리키는 노드 포인터
*/
polyNode* create_polynomial(const char* name);

// ● 4. 다항식의 연산

/**
* 두 다항식의 합을 구하여 반환합니다.
* 
* @param a, b 더할 두개의 다항식을 가리키는 노드 포인터
* @return 다항식의 합의 결과로 생성된 다항식을 가리키는 노드 포인터
*/
polyNode* cpadd(polyNode* a, polyNode* b);

/**
* 다항식과 단일항을 곱합니다.
* 
* @param poly 다항식을 가리키는 노드 포인터
* @param singlePoly 곱할 단일항을 가리키는 노드 변수
* @return 생성된 결과 다항식을 가리키는 노드포인터 반환
*/
polyNode* single_mul(polyNode* singlePoly, polyNode* poly);

/**
* 두 다항식의 곱
* 
* @param a, b 곱해질 두개의 다항식을 가리키는 노드 포인터
* @return 다항식의 곱의 결과로 생성된 다항식을 가리키는 노드 포인터
*/
polyNode* cpmul(polyNode* a, polyNode* b);

// ● 5. 다항식의 출력

/**
* 다항식을 출력합니다.
* 
* @param list 출력할 다항식을 가리키는 노트 포인터
*/
void print_polynomial(polyNode* list);



// ■ 메인함수

void main() {

	polyNode* A, * B, * C, * D;

	A = create_polynomial("A");
	printf("\n");
	B = create_polynomial("B");
	printf("\n");

	printf("다항식 A의 생성 결과 : \n");
	print_polynomial(A);
	printf("다항식 B의 생성 결과 : \n");
	print_polynomial(B);

	C = cpadd(A, B);
	printf("다항식의 합 결과 : \n");
	print_polynomial(C);

	D = cpmul(A, B);
	printf("다항식의 곱 결과 : \n");
	print_polynomial(D);
}



// ■ 구현부

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
			fprintf(stderr,"메모리공간을 확보할 수 없었습니다.\n");
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
		fprintf(stderr, "메모리공간을 확보할 수 없었습니다.\n");
		exit(1);
	}

	newPoly->next = newPoly;
	newPoly->expon = -1;
	newPoly->coef = -1.0;

	attach_pos = &(newPoly->next);
	while (true) {
		printf("%s(x) 다항식을 입력하세요.(계수 지수) : ", name);
		scanf_s("%lf %d", &coef, &expon);

		if (expon < 0)
			break;

		newNode = get_node();
		newNode->expon = expon;
		newNode->coef = coef;

		list_attach(attach_pos, newNode);
		attach_pos = &((*attach_pos)->next); // 이와 같은 코드 : attach_pos = &(newNode->next)
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

			if (sumOfCoef < -0.0001 || sumOfCoef > 0.0001) // coef의 합성이 0인가? - 정확도 : 0.0001 이하일때 0으로 판별
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

	printf("■ 다항식을 출력합니다 : \n");
	printf("   계수    |    지수    \n");
	while (current_poly != startNode) {
		printf("%10.3f | %5d\n", current_poly->coef, current_poly->expon);
		current_poly = current_poly->next;
	}
}
