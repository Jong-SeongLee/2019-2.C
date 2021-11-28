#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct bin {
	int num;
	struct bin *left;
	struct bin *right;
}bin;

void input();
void view(bin*top);
void make_tree(bin*top, int num);
bin *root = NULL;

int main() {
	input();
	input();
	input();
	input();
	input();
	input();
	input();
	view(root);//����Ž��
}

void view(bin*show) {//������
	if (show->left != NULL)
		view(show->left);
	printf("%d\n", show->num);
	if (show->right != NULL)
		view(show->right);
}

void input() {
	int num;
	printf("���� = ");
	scanf("%d", &num);
	if (root == NULL) { //ó�� �Է¹޴� ���ڿ� ���� ó��
		root = (bin*)malloc(sizeof(bin));
		root->num = num;
		root->left = NULL;
		root->right = NULL;
	}
	else //�ι�° ���ں���
		make_tree(root, num);
}

void make_tree(bin*top, int num) { //������
	bin*data;
	if (top->num > num) { //���ο� ���ڿ� ���ؼ��ں��� �������� ���ʿ�
		if (top->left == NULL) { //���� �Է��ϴ� ������ ������ ����ٸ�
			data = (bin*)malloc(sizeof(bin));
			data->num = num;
			data->left = NULL;
			data->right = NULL;
			top->left = data;
		}
		else
			make_tree(top->left, num);
	}
	if (top->num <= num) { //���ο� ���ڰ� ���ؼ��ں��� Ŭ���� �����ʿ�
		if (top->right == NULL) {
			data = (bin*)malloc(sizeof(bin));
			data->num = num;
			data->left = NULL;
			data->right = NULL;
			top->right = data;
		}
		else
			make_tree(top->right, num);
	}
}