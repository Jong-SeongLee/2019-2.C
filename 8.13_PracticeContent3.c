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
	printf("====이진트리입력====\n");
	for (i = 0; i < 100; i++) {
		input(a[i]);
	}
	printf("====오름차순====\n");
	view(root);
	printf("====내림차순====\n");
	view_rev(root);
	printf("검색할 숫자 입력: ");
}

void search(bin*top,int num) {
	if (top->num == num)
		printf("찾았다\n");
	if (top->num < num) {
		if (top->right == NULL)
			printf("없는 숫자입니다.\n");
		else
			search(top->right, num);
	}
	if (top->num > num) {
		if (top->left == NULL)
			printf("없는 숫자입니다\n");
		else
			search(top->left, num);
	}
}

void view_rev(bin*show) {//중위법
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

void make_tree(bin*top, int num) { //중위법
	bin*data;
	if (top->num > num) { //새로운 숫자와 기준숫자보다 작을때는 왼쪽에
		if (top->left == NULL) { //현재 입력하는 공간의 왼쪽이 비었다면
			data = (bin*)malloc(sizeof(bin));
			data->num = num;
			data->left = NULL;
			data->right = NULL;
			top->left = data;
		}
		else
			make_tree(top->left, num);
	}
	if (top->num <= num) { //새로운 숫자가 기준숫자보다 클때는 오른쪽에
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

void arr_make() { //100크기의 배열에 1~500사이의 숫자를 입력&출력
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