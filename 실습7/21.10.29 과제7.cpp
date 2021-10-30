// 과제 7부터는 github로 옮깁니다.

/**
* @author 백성수
* @studentId 22012070
*/



// ■ 헤더

// ● 1. 원형 연결리스트와 그 연산

typedef struct polyNode {
	int expon;
	double coef;
	struct polyNode* next;
}polyNode;

// 리스트의 가장 뒤에 붙여준다.
void list_attach(polyNode** list, polyNode* node);

// ● 2. 가용연결리스트 저장소와 그 연산

polyNode* avail;

// 새로운 노드를 생성하여 반환합니다.
polyNode* get_node();

// 해당 노드를 가용연결리스트에 붙입니다.
void let_node(polyNode* node);

// 원형연결리스트 전체를 가용연결리스트에 붙입니다.
void cerase(polyNode** list);

// ● 3. 다항식의 생성

// 사용자 입력을 받아 다항식을 생성하여 반환합니다.
polyNode* create_polynomial();

// ● 4. 다항식의 연산

// 두 다항식의 합
polyNode* cpadd(polyNode* a, polyNode* b);

// 단일 항과 다항식의 곱
void single_nul(polyNode* poly, polyNode singlePoly);

// 두 다항식의 곱
polyNode* cpmul(polyNode* a, polyNode* b);

// ● 5. 다항식의 출력

void print_polynomial(polyNode* list);



// ■ 메인함수

void main() {



}



// ■ 구현부