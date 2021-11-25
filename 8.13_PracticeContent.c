//2019.8.13 실습내용

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//이진트리
//최대 두개 자식을 가지는 구조
//입력과 출력에 전위, 중위, 후위 방식을 사용
//압축, 암호화, 복호화, 탐색, 정렬 등에 사용되는 방식

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
	printf("\n=======전위=======\n");
	pre_view(root);
	printf("\n=======중위=======\n");
	in_view(root);
	printf("\n=======후위=======\n");
	out_view(root);
}

void pre_view(bin*top) { //전위탐색
	printf("%d\n", top->num);
	if (top->left != NULL)
		pre_view(top->left);
	if (top->right != NULL)
		pre_view(top->right);
}

void in_view(bin*top) { //중위탐색
	if (top->left != NULL)
		in_view(top->left);
	printf("%d\n", top->num);
	if (top->right != NULL)
		in_view(top->right);
}

void out_view(bin*top) { //후위탐색
	if (top->left != NULL)
		out_view(top->left);
	if (top->right != NULL)
		out_view(top->right);
	printf("%d\n", top->num);
}

void input(bin* top) {
	bin*data = (bin*)malloc(sizeof(bin));
	printf("정수 = ");
	scanf("%d", &data->num);
	data->left = NULL;
	data->right = NULL;
	if (top->left == NULL) //부모노드(top)의 왼쪽(left)공간이 비어있다면 왼쪽에 새로운 데이터를 추가
		top->left = data;
	else
		top->right = data; //부모노드(top)의 오른쪽(right)공간이 비어있다면 오른쪽에 새로운 데이터를 추가
}
