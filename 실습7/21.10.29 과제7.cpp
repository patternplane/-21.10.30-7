// ���� 7���ʹ� github�� �ű�ϴ�.

/**
* @author �鼺��
* @studentId 22012070
*/



// �� ���

// �� 1. ���� ���Ḯ��Ʈ�� �� ����

typedef struct polyNode {
	int expon;
	double coef;
	struct polyNode* next;
}polyNode;

// ����Ʈ�� ���� �ڿ� �ٿ��ش�.
void list_attach(polyNode** list, polyNode* node);

// �� 2. ���뿬�Ḯ��Ʈ ����ҿ� �� ����

polyNode* avail;

// ���ο� ��带 �����Ͽ� ��ȯ�մϴ�.
polyNode* get_node();

// �ش� ��带 ���뿬�Ḯ��Ʈ�� ���Դϴ�.
void let_node(polyNode* node);

// �������Ḯ��Ʈ ��ü�� ���뿬�Ḯ��Ʈ�� ���Դϴ�.
void cerase(polyNode** list);

// �� 3. ���׽��� ����

// ����� �Է��� �޾� ���׽��� �����Ͽ� ��ȯ�մϴ�.
polyNode* create_polynomial();

// �� 4. ���׽��� ����

// �� ���׽��� ��
polyNode* cpadd(polyNode* a, polyNode* b);

// ���� �װ� ���׽��� ��
void single_nul(polyNode* poly, polyNode singlePoly);

// �� ���׽��� ��
polyNode* cpmul(polyNode* a, polyNode* b);

// �� 5. ���׽��� ���

void print_polynomial(polyNode* list);



// �� �����Լ�

void main() {



}



// �� ������