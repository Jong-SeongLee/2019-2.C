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
void view_rev(bin*top);
void make_tree(bin*top, int num);
void arr_make();
void search();
bin *root =NULL;

int main() {
	int i, num;
	arr_make();
	printf("====����Ʈ���Է�====\n");
	for (i = 0; i < 100; i++) {
		input(a[i]);
	}
	printf("====��������====\n");
	view(root);
	printf("====��������====\n");
	view_rev(root);
	printf("�˻��� ���� �Է�: ");
}

void search(bin*top,int num) {
	if (top->num == num)
		printf("ã�Ҵ�\n");
	if (top->num < num) {
		if (top->right == NULL)
			printf("���� �����Դϴ�.\n");
		else
			search(top->right, num);
	}
	if (top->num > num) {
		if (top->left == NULL)
			printf("���� �����Դϴ�\n");
		else
			search(top->left, num);
	}
}

void view_rev(bin*show) {//������
	if (show->right != NULL)
		view_rev(show->right);
	printf("%d\n", show->num);
	if (show->left != NULL)
		view_rev(show->left);
}

void input(int num) {
	if (root == NULL) {
		root = (bin*)malloc(sizeof(bin));
		root->num = num;
		root->left = NULL;
		root->right = NULL;
	}
	else
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

void arr_make() { //100ũ���� �迭�� 1~500������ ���ڸ� �Է�&���
	int i, j;
	srand((int)time(NULL));
	for (i = 0; i < 100; i++) {
		a[i] = rand() % 500 + 1;
		for (j = 0; j < i; j++) {
			if (a[i] == a[j]) {
				i--;
				break;
			}
		}
	}
	for (i = 0; i < 100; i++) {
		printf("%d\n", a[i]);
	}
}