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
	view(root);//중위탐색
}

void view(bin*show) {//중위법
	if (show->left != NULL)
		view(show->left);
	printf("%d\n", show->num);
	if (show->right != NULL)
		view(show->right);
}

void input() {
	int num;
	printf("정수 = ");
	scanf("%d", &num);
	if (root == NULL) { //처음 입력받는 숫자에 대한 처리
		root = (bin*)malloc(sizeof(bin));
		root->num = num;
		root->left = NULL;
		root->right = NULL;
	}
	else //두번째 숫자부터
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