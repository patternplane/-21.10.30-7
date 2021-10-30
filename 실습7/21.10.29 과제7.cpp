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

/**
* Ư�� ��带 ����Ʈ�� ���� �ڿ� �ٿ��ݴϴ�.
* 
* @param list ��带 �̾���� ����Ʈ�� ����Ű�� ��� ������ ������ ������
* @param node ����Ʈ�� �̾���� ��带 ����Ű�� ������
*/
void list_attach(polyNode** list, polyNode* node);

// �� 2. ���뿬�Ḯ��Ʈ ����ҿ� �� ����

polyNode* avail;

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
void let_node(polyNode* node);

/**
* ���� ���Ḯ��Ʈ ��ü�� ���뿬�Ḯ��Ʈ�� ���Դϴ�.
* 
* @param list ���뿬�Ḯ��Ʈ�� ���� ����Ʈ�� ����Ű�� ��� ������ ������ ������
*/
void cerase(polyNode** list);

// �� 3. ���׽��� ����

/**
* ����� �Է��� �޾� ���׽��� �����Ͽ� ��ȯ�մϴ�.
* 
* @return ������ ���׽��� ����Ű�� ��� ������
*/
polyNode* create_polynomial();

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
void single_nul(polyNode* poly, polyNode singlePoly);

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
