//2019.8.13 �ǽ�����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//����Ʈ��
//�ִ� �ΰ� �ڽ��� ������ ����
//�Է°� ��¿� ����, ����, ���� ����� ���
//����, ��ȣȭ, ��ȣȭ, Ž��, ���� � ���Ǵ� ���

typedef struct bin {
	int num;
	struct bin *left;
	struct bin *right;
}bin;

void input(bin*top);
void pre_view(bin*top);
void in_view(bin*top);
void out_view(bin*top);

int main() {
	bin *root;
	root = (bin*)malloc(sizeof(bin));
	root->num = 0;
	root->left = NULL;
	root->right = NULL;
	input(root);
	input(root);
	input(root->left);
	input(root->left);
	input(root->right);
	input(root->right);
	printf("\n=======����=======\n");
	pre_view(root);
	printf("\n=======����=======\n");
	in_view(root);
	printf("\n=======����=======\n");
	out_view(root);
}

void pre_view(bin*top) { //����Ž��
	printf("%d\n", top->num);
	if (top->left != NULL)
		pre_view(top->left);
	if (top->right != NULL)
		pre_view(top->right);
}

void in_view(bin*top) { //����Ž��
	if (top->left != NULL)
		in_view(top->left);
	printf("%d\n", top->num);
	if (top->right != NULL)
		in_view(top->right);
}

void out_view(bin*top) { //����Ž��
	if (top->left != NULL)
		out_view(top->left);
	if (top->right != NULL)
		out_view(top->right);
	printf("%d\n", top->num);
}

void input(bin* top) {
	bin*data = (bin*)malloc(sizeof(bin));
	printf("���� = ");
	scanf("%d", &data->num);
	data->left = NULL;
	data->right = NULL;
	if (top->left == NULL) //�θ���(top)�� ����(left)������ ����ִٸ� ���ʿ� ���ο� �����͸� �߰�
		top->left = data;
	else
		top->right = data; //�θ���(top)�� ������(right)������ ����ִٸ� �����ʿ� ���ο� �����͸� �߰�
}
