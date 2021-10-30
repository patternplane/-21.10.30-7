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
* @param node 리스트에 이어붙일 노드를 가리키는 포인터
*/
void list_attach(polyNode** nodePtr, polyNode* node);

// ● 2. 가용연결리스트 저장소와 그 연산

polyNode* avail = nullptr;

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
* 다항식의 각 항에 주어진 항을 곱합니다.
* 
* @param poly 다항식을 가리키는 노드 포인터
* @param singlePoly 곱할 단일항을 가리키는 노드 변수
*/
void single_mul(polyNode* poly, polyNode* singlePoly);

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



}



// ■ 구현부

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
		fprintf(stderr, "메모리공간을 확보할 수 없었습니다.\n");
		exit(1);
	}

	newPoly->next = newPoly;
	newPoly->expon = -1;
	newPoly->coef = -1.0;

	attach_pos = &(newPoly->next);
	while (true) {
		printf("%s(x) 다항식을 입력하세요.(계수 지수) : ", name_result);
		scanf_s("%lf %d", &coef, &expon);

		if (expon < 0)
			break;

		newNode = get_node();
		newNode->expon = expon;
		newNode->coef = coef;

		list_attach(attach_pos, newNode);
		attach_pos = &((*attach_pos)->next); // 이와 같은 코드 : attach_pos = &(newNode->next)
	}

}